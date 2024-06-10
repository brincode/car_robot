import cvzone as cv
from ultralytics import YOLO
import cv2
import math
import pygame
import serial

pygame.init()
pygame.mixer.init()

#load file sound 
fire_sound = pygame.mixer.Sound(r"C:\Users\Technology\Desktop\fire-alarm-33770.mp3")

cap = cv2.VideoCapture(0)

ser = serial.Serial("COM4",9600)

model = YOLO(r"C:\Users\Technology\Desktop\fire.pt")


classnames = ["fire"]
while True:
    ret, frame = cap.read()
    frame = cv2.resize(frame, (640, 480))
    result = model(frame, stream=True)
    
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
                cvzone.putTextRect(frame, f'{classnames[Class]} {confidence}%', (x1, y1), scale=1.5, thickness=2)
                
                ser.write(b'1')
                fire_sound.play()
            else:
                fire_sound.stop()
                ser.write(b'0')

    cv2.imshow("Fire Detection System", frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()