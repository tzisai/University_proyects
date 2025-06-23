import cv2
import numpy as np
import tkinter as tk
from tkinter import messagebox
import os
from datetime import datetime

root = tk.Tk()
root.title("Emotion Detection Recopiler")

selected_option = tk.StringVar()
source_option = tk.StringVar(value="Camera")

# Define variables to store the path and type globally
ruta_base = "Extraccion_Emociones/"
ruta = ""
tipo = ""

def on_go_button():
    global ruta, tipo
    option = selected_option.get()
    if option:
        tipo = process_selected_option(option)
        create_directory()  # Create directory based on the current date and time
        messagebox.showinfo("Selected Option", f"You selected: {option}")
        root.destroy()  # Close the main window after selection
    else:
        messagebox.showwarning("No Selection", "Please select an option")

def process_selected_option(option):
    global tipo
    if option == "Happy":
        print("Processing Happy images...")
        tipo = "Feliz"
    elif option == "Sad":
        print("Processing Sad images...")
        tipo = "Triste"
    elif option == "Angry":
        print("Processing Angry images...")
        tipo = "Enojado"

    return tipo

def create_directory():
    global ruta
    # Get the current date and time
    now = datetime.now()
    # Format the date and time as a string
    directory_name = now.strftime("%Y-%m-%d_%H-%M-%S")
    # Create the full path
    ruta = os.path.join(ruta_base, tipo, directory_name)
    # Create the directory
    os.makedirs(ruta, exist_ok=True)

# Create radio buttons for emotion selection
radio1 = tk.Radiobutton(root, text="Happy", variable=selected_option, value="Happy", bg='black', fg='white')
radio2 = tk.Radiobutton(root, text="Sad", variable=selected_option, value="Sad", bg='black', fg='white')
radio3 = tk.Radiobutton(root, text="Angry", variable=selected_option, value="Angry", bg='black', fg='white')

# Pack the radio buttons
radio1.pack(anchor=tk.W)
radio2.pack(anchor=tk.W)
radio3.pack(anchor=tk.W)

# Create radio buttons for source selection
camera_radio = tk.Radiobutton(root, text="Camera", variable=source_option, value="Camera", bg='black', fg='white')
video_radio = tk.Radiobutton(root, text="Video", variable=source_option, value="Video", bg='black', fg='white')

# Pack the source radio buttons
camera_radio.pack(anchor=tk.W)
video_radio.pack(anchor=tk.W)

# Create and pack the "Go" button
go_button = tk.Button(root, text="Go", command=on_go_button, bg='orange', fg='white')
go_button.pack()

# Run the application
root.mainloop()

# Decide the video source based on user's choice
if source_option.get() == "Camera":
    cap = cv2.VideoCapture(0)
else:
    cap = cv2.VideoCapture("truste_2.mp4")

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

i = 0

while True:
    ret, frame = cap.read()
    if not ret:
        break
    
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    framecopy = frame.copy()
    
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=5)
    
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 255), 2)
        rostro = framecopy[y:y+h, x:x+w]
        rostro = cv2.resize(rostro, (150, 150), interpolation=cv2.INTER_CUBIC)
        # Save the image with a correct path and file name
        cv2.imwrite(f"{ruta}/{tipo}_{i}.jpg", rostro)
        i += 1
    
    cv2.imshow("Video", frame)
          
    k = cv2.waitKey(1)
    if k == ord("q") or i >= 300:
        break
    
cap.release()
cv2.destroyAllWindows()
