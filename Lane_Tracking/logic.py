import cv2
from helper import *
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import os
from pipeline import process_image, LaneMemory


def get_Lanes(image):

    print(image.shape)
    gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    darkened_img = adjust_gamma(gray_image, 0.5) 
    white_masks = isolate_color_mask(image, np.array([160, 160, 160], dtype=np.uint8), np.array([255, 255, 255], dtype=np.uint8))
    yellow_masks = isolate_color_mask(image, np.array([190, 190, 0], dtype=np.uint8), np.array([255, 255, 255], dtype=np.uint8))
    mask = cv2.bitwise_or(white_masks, yellow_masks)
    gaus = gaussian_blur(mask, kernel_size=7)
    can = canny(gaus, low_threshold=70, high_threshold=140)
    can = get_aoi(can)
    output = image
    lines = get_hough_lines(can)
    print(lines)
    # output = draw_lines(image, lines)
    if lines is not None:
        left_lane, right_lane = get_lane_lines(image, lines)
        print("Left Lane", left_lane)
        print("Right Lane", right_lane)
        if left_lane is not None:
            output = draw_left_weighted_line(image, left_lane, thickness=15)
        if right_lane is not None:
            output = draw_right_weighted_line(output, right_lane, thickness=15)
        # return output
    # output2 = draw_weighted_lines(image, [left_lane, right_lane], thickness= 15)
    # cv2.imshow("g", can)
    # cv2.imshow("output", output)
    # cv2.imshow("output2", output2)
    return output
    # cv2.waitKey(0)


cap = cv2.VideoCapture('assets/test.mp4')

while cap.isOpened():
    ret, frame = cap.read()
    frame = get_Lanes(frame)
    screen_res = 1280, 720
    scale_width = screen_res[0] / frame.shape[1]
    scale_height = screen_res[1] / frame.shape[0]
    scale = min(scale_width, scale_height)
    #resized window width and height
    window_width = int(frame.shape[1] * scale)
    window_height = int(frame.shape[0] * scale)
    #cv2.WINDOW_NORMAL makes the output window resizealbe
    cv2.namedWindow('Resized Window', cv2.WINDOW_NORMAL)
    #resize the window according to the screen resolution
    cv2.resizeWindow('Resized Window', window_width, window_height)
    # fps = cap.get(cv2.CAP_PROP_POS_FRAMES)
    # print(str(fps)+" frames")
    cv2.imshow('Resized Window', frame)
    

    # cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
