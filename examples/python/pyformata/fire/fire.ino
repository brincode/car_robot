import pyfirmata 
import pygame 
import cv2
from ultralytics import YOLO 


comport='COM4' 
board=pyfirmata.Arduino (comport)
control-board.get_pin('d:7:0') 


pygame.init() 
pygame.mixer.init() 
fire_sound = pygame.mixer.Sound(r"C:\Users\abohamam\Downloads\fire-alarm-331")


cap = cv2.VideoCapture (0) 

model = YOLO (r"C:\Users\abohamam\Downloads\fire.pt") 

while True: 
  ret, frame = cap.read() 
  if not ret: 
    print("open camera") 
    break

  results= model (frame) 
  for result in results: 
    boxes = result.boxes 
    cls = boxes.cls.tolist()


    if len(cls) != 0 and result.boxes.conf[0] >=0.5: 
      fire_sound.play() 
      control.write(1) 


    else: 
    fire_sound.stop() 
    control.write(0) 

  frame2 = results[0].plot() 
  cv2.imshow('Camera video', frame2) 

  if cv2.waitKey(1) == ord('q'): 
    break 
cap.release() 
cv2.destroyAllWindows() 