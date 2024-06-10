import cv2
from ultralytics import YOLO
model =YOLO(".pt")

cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    if not ret:
        print("open camera")
        break
    result = model(frame)
    frame2 = result[0].plot()
    cv2.imshow('Camera video', frame2)
    if cv2.waitKey(1) == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()