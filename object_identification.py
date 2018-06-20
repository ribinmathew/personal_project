#here we are gonna identify whether any objct is there! and if there is any object what is the color of the objec

import cv2
import numpy as np

camera = cv2.VideoCapture(0)


while (True):

    # Capture the frames

    ret, frame = camera.read()
    cv2.imshow("original",frame)
    #here we are gonna check for blue_color
    #so lets apply blue filter for the image
    hsv= cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    cv2.imshow("hsv",hsv)
    lower_blue = np.array([100,150,0])
    upper_blue= np.array([180,255,150])
    blue_masked_image = cv2.inRange(hsv,lower_blue,upper_blue)
    res = cv2.bitwise_and(frame,frame,mask=blue_masked_image)
    cv2.imshow('blue_mask',blue_masked_image)
    cv2.imshow('blue_res',res)
    # so we have done the filteration for blue L
    # now we have to find the T-pink shape
    lower_pink = np.array([100,0,180])
    upper_pink = np.array([255,110,255])
    pink_masked_image = cv2.inRange(hsv,lower_pink,upper_pink)
    pink_res = cv2.bitwise_and(frame,frame,mask=pink_masked_image)
    cv2.imshow("pink_masked",pink_masked_image)
    cv2.imshow("pink_res",pink_res)

    #now we have to filter for blue I
    lower_cyan = np.array([90,100,180])
    upper_cyan = np.array([120,160,245])
    cyan_masked = cv2.inRange(hsv,lower_cyan,upper_cyan)
    cyan_res = cv2.bitwise_and(frame,frame,mask=cyan_masked)
    cv2.imshow("cyan_masked",cyan_masked)
    cv2.imshow("cyan_res",cyan_res)


    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

camera.release()
cv2.destroyAllWindows()