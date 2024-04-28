import cvzone
from ultralytics import YOLO
import cv2
import math
import pygame
import serial  # Import the serial library for communication

# Initialize Pygame
pygame.init()
pygame.mixer.init()

# Load the sound file (replace 'fire_alert.wav' with the path to your sound file)
fire_sound = pygame.mixer.Sound(r"C:\Users\abdel\Desktop\fire-alarm-33770.mp3")

# Running real-time from webcam
cap = cv2.VideoCapture(0)  # 0 corresponds to the default camera
# Initialize serial communication with Arduino
ser = serial.Serial('COM12', 9600)

model = YOLO(r"C:\Users\abdel\Desktop\fire.pt")

# Reading the classes
classnames = ['fire']

while True:
    ret, frame = cap.read()
    frame = cv2.resize(frame, (640, 480))
    result = model(frame, stream=True)

    # Getting bbox, confidence, and class names information to work with
    for info in result:
        boxes = info.boxes
        for box in boxes:
            confidence = box.conf[0]
            confidence = math.ceil(confidence * 100)
            Class = int(box.cls[0])
            if confidence > 50:
                
                x1, y1, x2, y2 = box.xyxy[0]
                
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 0, 255), 5)
                cvzone.putTextRect(frame, f'{classnames[Class]} {confidence}%', [x1 + 8, y1 + 100],
                                   scale=1.5, thickness=2)

                # Send message to Arduino
                ser.write(b'1')  # Send '1' to Arduino

                # Read data from Arduino
                if ser.in_waiting > 0:
                    arduino_data = ser.readline().decode().strip()
                    print("Data from Arduino:", arduino_data)

                # Play the fire alert sound
                fire_sound.play()
            else:
                fire_sound.stop()
                ser.write(b'0')

    cv2.imshow('CommanDo', frame)
    if cv2.waitKey(1) == ord('q'):  # Press 'q' to exit the loop
        break

# Release the camera and close all OpenCV windows
cap.release()
cv2.destroyAllWindows()
