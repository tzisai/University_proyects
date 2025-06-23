import cv2

# Load the cascade classifier
face_cascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

# Create a video capture object
cap = cv2.VideoCapture(0)


while True:
    # Read a frame from the video stream
    ret, frame = cap.read()
    
    mirror = cv2.flip(frame,1) 

    # Convert the frame to grayscale
    gray = cv2.cvtColor(mirror, cv2.COLOR_BGR2GRAY)

    # Detect faces in the grayscale frame
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=5)

    # Draw rectangles around the detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(mirror, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Display the output frame
    cv2.imshow('frame', mirror)

    # Exit the loop if the 'q' key is pressed
    if cv2.waitKey(1) == ord('q'):
        break

# Release the video capture object and close all windows
cap.release()
cv2.destroyAllWindows()
