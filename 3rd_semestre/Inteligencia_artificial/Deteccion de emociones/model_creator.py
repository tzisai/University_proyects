import os
import numpy as np
from PIL import Image

# Function to load images from a folder and subfolders
def load_images_from_folder(folder, label_map):
    images = []
    labels = []
    for label_name, label in label_map.items():
        label_folder = os.path.join(folder, label_name)
        for subfolder_name in os.listdir(label_folder):
            subfolder_path = os.path.join(label_folder, subfolder_name)
            if os.path.isdir(subfolder_path):
                for idx, filename in enumerate(os.listdir(subfolder_path)):
                    img_path = os.path.join(subfolder_path, filename)
                    img = Image.open(img_path).convert('L')
                    img = img.resize((48, 48))
                    img_array = np.array(img).astype(np.float32).flatten()
                    images.append(img_array)
                    labels.append(label)
    return np.array(images), np.array(labels)

# Neural Network Class Definition
class SimpleNN:
    def __init__(self, input_size, hidden_size, output_size):
        self.W1 = np.random.randn(input_size, hidden_size) * 0.01
        self.b1 = np.zeros((1, hidden_size))
        self.W2 = np.random.randn(hidden_size, output_size) * 0.01
        self.b2 = np.zeros((1, output_size))

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def sigmoid_derivative(self, z):
        s = self.sigmoid(z)
        return s * (1 - s)

    def forward(self, X):
        self.Z1 = np.dot(X, self.W1) + self.b1
        self.A1 = self.sigmoid(self.Z1)
        self.Z2 = np.dot(self.A1, self.W2) + self.b2
        self.A2 = self.sigmoid(self.Z2)
        return self.A2

    def compute_cost(self, Y, A2):
        m = Y.shape[0]
        cost = -np.sum(Y * np.log(A2) + (1 - Y) * np.log(1 - A2)) / m
        return cost

    def backward(self, X, Y):
        m = X.shape[0]
        dZ2 = self.A2 - Y
        dW2 = np.dot(self.A1.T, dZ2) / m
        db2 = np.sum(dZ2, axis=0, keepdims=True) / m
        dA1 = np.dot(dZ2, self.W2.T)
        dZ1 = dA1 * self.sigmoid_derivative(self.Z1)
        dW1 = np.dot(X.T, dZ1) / m
        db1 = np.sum(dZ1, axis=0, keepdims=True) / m

        self.W1 -= self.learning_rate * dW1
        self.b1 -= self.learning_rate * db1
        self.W2 -= self.learning_rate * dW2
        self.b2 -= self.learning_rate * db2

    def train(self, X, Y, epochs, learning_rate):
        self.learning_rate = learning_rate
        for i in range(epochs):
            A2 = self.forward(X)
            cost = self.compute_cost(Y, A2)
            self.backward(X, Y)
            if i % 100 == 0:
                print(f"Iteration {i}, Cost: {cost}")

    def save_model(self, file_path):
        np.savez(file_path, W1=self.W1, b1=self.b1, W2=self.W2, b2=self.b2)

    @staticmethod
    def load_model(file_path):
        data = np.load(file_path)
        model = SimpleNN(data['W1'].shape[0], data['W1'].shape[1], data['W2'].shape[1])
        model.W1 = data['W1']
        model.b1 = data['b1']
        model.W2 = data['W2']
        model.b2 = data['b2']
        return model

# Main Execution **********************************************************************************

# Load and preprocess dataset
dataset_folder = 'Extraccion_Emociones'  # Change this to your dataset folder path
label_map = {'Feliz': 0, 'Triste': 1, 'Enojado': 2}
X, y = load_images_from_folder(dataset_folder, label_map)
X = X / 255.0
y = np.eye(len(label_map))[y]

# Split the data into training and testing sets
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize and train the neural network
input_size = 48 * 48
hidden_size = 64
output_size = 3
nn = SimpleNN(input_size, hidden_size, output_size)
learning_rate = 0.01
epochs = 10000
nn.train(X_train, y_train, epochs, learning_rate)

# Predict function
def predict(X, model):
    A2 = model.forward(X)
    return np.argmax(A2, axis=1)

# Evaluate the model
train_predictions = predict(X_train, nn)
test_predictions = predict(X_test, nn)
train_accuracy = np.mean(np.argmax(y_train, axis=1) == train_predictions)
test_accuracy = np.mean(np.argmax(y_test, axis=1) == test_predictions)
print(f"Train Accuracy: {train_accuracy * 100}%")
print(f"Test Accuracy: {test_accuracy * 100}%")

# Save the trained model
nn.save_model('emotion_detection_model.npz')
