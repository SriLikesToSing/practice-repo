import cv2
import numpy as np
cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()
#    grayedFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurredFrame = cv2.GaussianBlur(frame, (5, 5), 0)

    ret, thresh = cv2.threshold(blurredFrame, 127, 255, cv2.THRESH_BINARY)
    #thresh2 = cv2.adaptiveThreshold(blurredFrame, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 21, 4)

    hsv = cv2.cvtColor(blurredFrame, cv2.COLOR_BGR2HSV)
    #_FULL)


    lower_blue = np.array([38, 86, 0])
    upper_blue = np.array([121, 255, 255])
    #mask = cv2.inRange(hsv, lower_blue, upper_blue)
    #mask = cv2.inRange(hsv, (36,0,0), (70,255,255))
    mask= cv2.inRange(hsv, (15,0,0), (36, 255, 255))
    #maskRed = cv2.inRange(hsv, (0, 50, 50), (180, 255, 255))

    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)

    for contour in contours:
        cv2.drawContours(frame, contour, -1, (0, 255, 0), 3)

    cv2.imshow("Frame", frame)
    cv2.imshow("Mask", mask)
    cv2.imshow("res", cv2.bitwise_and(frame,frame, mask=mask))
    key = cv2.waitKey(1)
    if key == 27:
        break
        
cap.release()
cv2.destroyAllWindows()