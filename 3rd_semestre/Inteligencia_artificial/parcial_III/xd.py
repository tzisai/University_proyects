import pandas as pd
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import classification_report, confusion_matrix, precision_score
from sklearn.preprocessing import StandardScaler, OneHotEncoder
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from sklearn.model_selection import KFold


# Load the dataset
file_path = 'dataset_2.xlsx'
df = pd.read_excel(file_path)

# Define features and labels
features = ['Count', 'Percentage']  # Use more properties if available
df['Target'] = np.random.choice([0, 1, 2], size=len(df))  # Replace with actual R5/X4/R5X4 labels
X = df[features].values
y = df['Target'].values

# Normalize the features
scaler = StandardScaler()
X = scaler.fit_transform(X)

# One-hot encode the target labels
encoder = OneHotEncoder()
y_encoded = encoder.fit_transform(y.reshape(-1, 1)).toarray()

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y_encoded, test_size=0.2, random_state=42)

# Define the neural network model
model = Sequential([
    Dense(128, input_dim=X_train.shape[1], activation='relu'),
    Dropout(0.3),
    Dense(100, activation='relu'),
    Dropout(0.3),
    Dense(y_train.shape[1], activation='softmax')  # Output layer for multi-class classification
])

# Compile the model
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# Train the model
history = model.fit(X_train, y_train, epochs=100, batch_size=32, validation_split=0.2)

# Evaluate the model
loss, accuracy = model.evaluate(X_test, y_test)
print(f"Test Accuracy: {accuracy * 100:.2f}%")

# Predict on the test set
y_pred = model.predict(X_test)
y_pred_labels = np.argmax(y_pred, axis=1)
y_true_labels = np.argmax(y_test, axis=1)

# Classification report
report = classification_report(y_true_labels, y_pred_labels, target_names=['R5', 'X4', 'R5X4'])
print(report)

# Precision for R5X4 (class 2)
precision = precision_score(y_true_labels, y_pred_labels, average=None)[2]
print(f"Precision for R5X4: {precision * 100:.2f}%")

# Confusion matrix
conf_matrix = confusion_matrix(y_true_labels, y_pred_labels)
print("Confusion Matrix:")
print(conf_matrix)

# Cross-validation for precision
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


# Perform cross-validation
cross_val_precision = cross_validate_model(X, y_encoded)
print(f"Cross-validated Precision: {cross_val_precision * 100:.2f}%")
