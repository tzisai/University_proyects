import pandas as pd
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.model_selection import train_test_split, KFold
from sklearn.metrics import classification_report, confusion_matrix, precision_score
from sklearn.cluster import KMeans
from sklearn.impute import SimpleImputer
from imblearn.over_sampling import SMOTE
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from tensorflow.keras.optimizers import Adam
import matplotlib.pyplot as plt

# Step 1: Clustering with Unlabeled Data
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
    f'{col}_{i}': grouped_unlabeled[col].apply(lambda x: x[i] if i < len(x) else np.nan)
    for col in feature_list_unlabeled
    for i in range(max(grouped_unlabeled[col].apply(len)))
})

# Eliminar columnas vacías
features_unlabeled = features_unlabeled.dropna(axis=1, how='all')

# Normalize the features
scaler_unlabeled = StandardScaler()
X_unlabeled = scaler_unlabeled.fit_transform(features_unlabeled.fillna(0))

# KMeans Clustering
k = 3  # Number of clusters
kmeans = KMeans(n_clusters=k, random_state=42)
cluster_labels = kmeans.fit_predict(X_unlabeled)

# Add cluster labels to the dataset as an additional feature
features_unlabeled['Cluster'] = cluster_labels

# Assign cluster labels as inferred R5X4 labels
features_unlabeled['Inferred_Type'] = features_unlabeled['Cluster'].apply(lambda x: 'R5X4' if x == 2 else ('R5' if x == 0 else 'X4'))

# Visualization of Clusters (optional)
plt.scatter(X_unlabeled[:, 0], X_unlabeled[:, 1], c=cluster_labels, cmap='viridis', s=50)
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=200, c='red', marker='X')
plt.title("KMeans Clustering")
plt.xlabel("Feature 1 (Count)")
plt.ylabel("Feature 2 (Percentage)")
plt.show()

# Step 2: Supervised Learning with Labeled Data
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

# Ensure Type is present in features_unlabeled
features_unlabeled['Type'] = features_unlabeled['Inferred_Type']

# Combine the datasets with inferred R5X4 labels from clustering
df_combined = pd.concat([df_r5_combined, df_x4_combined, features_unlabeled])

# Convert columns to string to avoid mixed types error
df_combined.columns = df_combined.columns.astype(str)

# Filter for numeric columns and handle missing values
numeric_cols = df_combined.select_dtypes(include=np.number).columns
features_supervised = df_combined[numeric_cols]

# Impute missing values with mean
imputer = SimpleImputer(strategy='mean')
X_supervised = imputer.fit_transform(features_supervised)
y_supervised = df_combined['Type']

# Balance the dataset using SMOTE
smote = SMOTE(random_state=42)
X_resampled, y_resampled = smote.fit_resample(X_supervised, y_supervised)

# One-hot encode the resampled target labels
encoder = OneHotEncoder()
y_resampled = y_resampled.to_numpy()  # Convert Series to numpy array
y_encoded_resampled = encoder.fit_transform(y_resampled.reshape(-1, 1)).toarray()

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X_resampled, y_encoded_resampled, test_size=0.2, random_state=42)

# Create and compile the neural network model
model = Sequential([
    Dense(256, input_dim=X_train.shape[1], activation='relu'),
    Dropout(0.3),
    Dense(128, activation='relu'),
    Dropout(0.3),
    Dense(64, activation='relu'),
    Dropout(0.3),
    Dense(y_train.shape[1], activation='softmax')
])

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

cross_val_precision = cross_validate_model(X_resampled, y_encoded_resampled)
print(f"Cross-validated Precision: {cross_val_precision * 100:.2f}%")
