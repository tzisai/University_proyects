import pandas as pd
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.model_selection import train_test_split, KFold
from sklearn.metrics import classification_report, confusion_matrix, precision_score
from sklearn.cluster import KMeans
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from tensorflow.keras.optimizers import Adam
import matplotlib.pyplot as plt

# Paso 1: Clustering con Datos Sin Etiquetar
# Load the original dataset without labels
file_path = 'dataset_2.xlsx'
df_unlabeled = pd.read_excel(file_path)

# Agrupar y preparar las características para el clustering
grouped_unlabeled = df_unlabeled.groupby('Elemento').agg({
    'Count': list,
    'Percentage': list
}).reset_index()

# Create feature vectors by unrolling the lists into columns dynamically
feature_list_unlabeled = ['Count', 'Percentage']
features_unlabeled = pd.DataFrame({
    f'{col}_{i}': grouped_unlabeled[col].apply(lambda x: x[i] if i < len(x) else 0)
    for col in feature_list_unlabeled
    for i in range(max(grouped_unlabeled[col].apply(len)))
})

# Normalize the features
scaler_unlabeled = StandardScaler()
X_unlabeled = scaler_unlabeled.fit_transform(features_unlabeled.fillna(0))  # Fill NaN with 0

# KMeans Clustering
k = 3  # Number of clusters
kmeans = KMeans(n_clusters=k, random_state=42)
cluster_labels = kmeans.fit_predict(X_unlabeled)

# Add cluster labels to the dataset as an additional feature
features_unlabeled['Cluster'] = cluster_labels

# Assign cluster labels as inferred R5X4 labels
# Note: This is an inference based on clustering, adjust as needed.
features_unlabeled['Inferred_Type'] = features_unlabeled['Cluster'].apply(lambda x: 'R5X4' if x == 2 else ('R5' if x == 0 else 'X4'))

# Visualization of Clusters (optional)
plt.scatter(X_unlabeled[:, 0], X_unlabeled[:, 1], c=cluster_labels, cmap='viridis', s=50)
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=200, c='red', marker='X')
plt.title("KMeans Clustering")
plt.xlabel("Feature 1 (Count)")
plt.ylabel("Feature 2 (Percentage)")
plt.show()

# Paso 2: Aprendizaje Supervisado con Datos Etiquetados
# Load the datasets for R5 and X4
r5_file_path = 'r5_dataset.xlsx'
x4_file_path = 'x4_dataset.xlsx'

df_r5 = pd.read_excel(r5_file_path, header=None)
df_x4 = pd.read_excel(x4_file_path, header=None)

# Asumir que las columnas están organizadas horizontalmente y necesitan ser separadas
r5_counts = df_r5.iloc[:, [i for i in range(1, df_r5.shape[1], 3)]]
r5_weights = df_r5.iloc[:, [i for i in range(2, df_r5.shape[1], 3)]]
x4_counts = df_x4.iloc[:, [i for i in range(1, df_x4.shape[1], 3)]]
x4_weights = df_x4.iloc[:, [i for i in range(2, df_x4.shape[1], 3)]]

# Combine counts and weights into DataFrames
df_r5_combined = pd.concat([r5_counts, r5_weights], axis=1)
df_x4_combined = pd.concat([x4_counts, x4_weights], axis=1)

# Add a column to indicate the virus type
df_r5_combined['Type'] = 'R5'
df_x4_combined['Type'] = 'X4'

# Combine the datasets with inferred R5X4 labels from clustering
df_combined = pd.concat([df_r5_combined, df_x4_combined, features_unlabeled])

# Convert columns to string to avoid mixed types error
df_combined.columns = df_combined.columns.astype(str)

# Eliminar filas que contienen valores no numéricos
features_supervised = df_combined.apply(pd.to_numeric, errors='coerce')
features_supervised = features_supervised.dropna()

# Add the 'Type' column back as the target variable
features_supervised['Type'] = pd.concat([df_r5_combined['Type'], df_x4_combined['Type'], features_unlabeled['Inferred_Type']], ignore_index=True)

# Verificar el contenido de features_supervised
print(features_supervised.head())
print(features_supervised.info())

# Normalizar las características
scaler_supervised = StandardScaler()
X_supervised = scaler_supervised.fit_transform(features_supervised.drop('Type', axis=1))

y_supervised = features_supervised['Type'].values

# One-hot encode the target labels
encoder = OneHotEncoder()
y_encoded_supervised = encoder.fit_transform(y_supervised.reshape(-1, 1)).toarray()

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X_supervised, y_encoded_supervised, test_size=0.2, random_state=42)

# --------------- Neural Network for Classification ---------------
model = Sequential([
    Dense(256, input_dim=X_train.shape[1], activation='relu'),
    Dropout(0.3),
    Dense(128, activation='relu'),
    Dropout(0.3),
    Dense(64, activation='relu'),
    Dropout(0.3),
    Dense(y_train.shape[1], activation='softmax')
])

# Compile the model
optimizer = Adam(learning_rate=0.001)
model.compile(optimizer=optimizer, loss='categorical_crossentropy', metrics=['accuracy'])

# Train the model
history = model.fit(X_train, y_train, epochs=200, batch_size=32, validation_split=0.2)

# Evaluate the model
loss, accuracy = model.evaluate(X_test, y_test)
print(f"Test Accuracy: {accuracy * 100:.2f}%")

# Predict on the test set
y_pred = model.predict(X_test)
y_pred_labels = np.argmax(y_pred, axis=1)
y_true_labels = np.argmax(y_test, axis=1)

# Classification report
labels = encoder.categories_[0]
report = classification_report(y_true_labels, y_pred_labels, labels=np.arange(len(labels)), target_names=labels)
print(report)

# Precision for each class
precision = precision_score(y_true_labels, y_pred_labels, average=None)
for i, label in enumerate(labels):
    print(f"Precision for {label}: {precision[i] * 100:.2f}%")

# Confusion matrix
conf_matrix = confusion_matrix(y_true_labels, y_pred_labels)
print("Confusion Matrix:")
print(conf_matrix)

# Cross-validation for precision (optional)
def cross_validate_model(X, y, folds=5):
    results = []
    kf = KFold(n_splits=folds)
    for train_idx, test_idx in kf.split(X):
        X_train, X_test = X[train_idx], X[test_idx]
        y_train, y_test = y[train_idx], y[test_idx]

        model.fit(X_train, y_train, epochs=10, batch_size=32, verbose=0)
        y_pred = np.argmax(model.predict(X_test), axis=1)
        y_true = np.argmax(y_test, axis=1)

        precision = precision_score(y_true, y_pred, average='macro')
        results.append(precision)
    return np.mean(results)

cross_val_precision = cross_validate_model(X_supervised, y_encoded_supervised)
print(f"Cross-validated Precision: {cross_val_precision * 100:.2f}%")
