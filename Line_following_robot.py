import cv2
import numpy as np

#so in this project we are gonna make the robot to follow line!
# the special thing is we are gonna make small small adjustmets in the robot  so it wont go out of the straight line
# so basicly we want to make the robot follow a straight line! without moving out of it

#so what we are gonna do is get the image, convrt the image into grayscale,
# do the preprocessing and then we gonna find the black line.
# then we will draw a box in center of our cam
# and we will make sure that the robot moves exactly on the straight line
# so one of the challenge we may face is when find the  juncitons the entire thing may go wrong!
# so we have to take care of it!
def boxes(video):
    ret,contour,heirarchy = cv2.findContours(video,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    from imutils import contours
    (contour,_) = contours.sort_contours(contour)
    box = []
    for c in contour:
        if cv2.contourArea(c) > 5000:
            rotating_box = cv2.minAreaRect(c)
            rotating_boxs = cv2.boxPoints(rotating_box)
            rotating_boxs = np.int0(rotating_boxs)
            box.append(rotating_boxs)
    return box


camera = cv2.VideoCapture(0)

while(True):
    ret,frame = camera.read()
    cv2.imshow("Original_video",frame)
    #so we got the original video
    #now we have to convert into grayscale
    gray_video = cv2.cvtColor(frame,cv2.COLOR_RGB2GRAY)
    cv2.imshow("gray_video",gray_video)
    #now we have to apply thresholding and binary inversion
    ret,threshold_video = cv2.threshold(gray_video,200,255,cv2.THRESH_BINARY_INV)
    cv2.imshow("threshold_video",threshold_video)
    kerenel = np.ones(5,5),np.uint8
    dialeted_video = cv2.dilate(threshold_video,kerenel,iterations=2)
    #here we have dialeted the image so that we will get more info
    # now we have to ignore all the small small things
    open_video = cv2.morphologyEx(dialeted_video,cv2.MORPH_CLOSE,kerenel)
    # now we are gonna get the edges of the image
    edges_video = cv2.Canny(open_video,200,255)
    cv2.imshow("edges_video",edges_video)
    #here we are gonna call a fuction to find box (here also we are finding the rotating_box)
    video_box = boxes(edges_video)