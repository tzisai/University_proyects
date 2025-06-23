import numpy as np
import cv2

# Define the SimpleNN class
class SimpleNN:
    def __init__(self, input_size, hidden_size, output_size):
        self.W1 = np.random.randn(input_size, hidden_size) * 0.01
        self.b1 = np.zeros((1, hidden_size))
        self.W2 = np.random.randn(hidden_size, output_size) * 0.01
        self.b2 = np.zeros((1, output_size))

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def forward(self, X):
        self.Z1 = np.dot(X, self.W1) + self.b1
        self.A1 = self.sigmoid(self.Z1)
        self.Z2 = np.dot(self.A1, self.W2) + self.b2
        self.A2 = self.sigmoid(self.Z2)
        return self.A2

# Load model function
def load_model(file_path, input_size, hidden_size, output_size):
    data = np.load(file_path)
    model = SimpleNN(input_size, hidden_size, output_size)
    model.W1 = data['W1']
    model.b1 = data['b1']
    model.W2 = data['W2']
    model.b2 = data['b2']
    return model

# Parameters (adjust as needed based on your trained model)
input_size = 48 * 48  # Image size (48x48 pixels flattened)
hidden_size = 64      # Number of neurons in the hidden layer
output_size = 3       # Number of output classes (emotions)

# Load the trained model
nn = load_model('emotion_detection_model.npz', input_size, hidden_size, output_size)

# Main testing with real-time video
cap = cv2.VideoCapture(0)
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=5)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        face = gray[y:y+h, x:x+w]
        face = cv2.resize(face, (48, 48)).flatten().astype(np.float32) / 255.0
        face = face.reshape(1, -1)
        
        prediction = nn.forward(face)
        emotion = np.argmax(prediction)
        
        if emotion == 0:
            label = 'Happy'
        elif emotion == 1:
            label = 'Sad'
        elif emotion == 2:
            label = 'Angry'
        
        cv2.putText(frame, label, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
    
    cv2.imshow("Video", frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
