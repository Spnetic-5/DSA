import numpy as np
import cv2
from helper import *
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import os
from pipeline import process_image, LaneMemory
 
def region_of_interest(img, vertices):
    mask = np.zeros_like(img)   
    
    #defining a 3 channel or 1 channel color to fill the mask with depending on the input image
    if len(img.shape) > 2:
        channel_count = img.shape[2]  # i.e. 3 or 4 depending on your image
        ignore_mask_color = (255,) * channel_count
    else:
        ignore_mask_color = 255
        
    cv2.fillPoly(mask, vertices, ignore_mask_color)
    masked_image = cv2.bitwise_and(img, mask)
    
    return masked_image

def crop_roi(image, top_left, top_right, bottom_right, bottom_left):
    roi = [np.array([top_left, top_right, bottom_right, bottom_left], dtype=np.int32)]
    return region_of_interest(image, roi)

def crop_by_ref(img, ref_width, ref_height, ref_top_x, ref_top_y, ref_bot_x, ref_bot_y):
    width = img.shape[1]
    image_height = img.shape[0]
    middle_x = int(width / 2)
    image_offset_bottom_x = int(width * ref_bot_x / ref_width)
    image_offset_bottom_y = int(image_height * ref_bot_y / ref_height)
    image_offset_top_x = int(width * ref_top_x / ref_width)
    image_offset_top_y = int(image_height * ref_top_y / ref_height)
    top_left = [middle_x - image_offset_top_x, image_offset_top_y]
    top_right = [middle_x + image_offset_top_x, image_offset_top_y]
    bottom_right = [width - image_offset_bottom_x, image_offset_bottom_y]
    bottom_left = [image_offset_bottom_x, image_offset_bottom_y]

    return crop_roi(img, top_left, top_right, bottom_right, bottom_left)

def crop(image, bottom_offset = 0, top_offset = 0):
    ref_width = 960
    ref_height =540
    ref_top_x = 50
    ref_top_y = 300
    ref_bottom_x = 70 - top_offset
    ref_bottom_y = 540 - bottom_offset

    return crop_by_ref(image, ref_width, ref_height, ref_top_x, ref_top_y, ref_bottom_x, ref_bottom_y)

# def region_of_interest(img, vertices):
#     mask = np.zeros_like(img)
#     #channel_count = img.shape[2]
#     match_mask_color = 160
#     cv2.fillPoly(mask, vertices, match_mask_color)
#     masked_image = cv2.bitwise_and(img, mask)
#     return masked_image

 
def draw_the_lines(img, lines, height, width):
    img = np.copy(img)
    blank_image = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)

    if lines is not None:
        
        print(len(lines))
        if len(lines) < 2: 
            print("------------------------------ NO LANE MARKING DETECTED ----------------------------------")
            fps = cap.get(cv2.CAP_PROP_POS_FRAMES)
            print(str(fps)+" frames")
        else:
            print("------------------------------ LANE DETECTED ----------------------------------")
        for line in lines:
            for x1, y1, x2, y2 in line:
                cv2.line(blank_image, (x1,y1), (x2,y2), (0, 255, 0), thickness=3)
    
    img = cv2.addWeighted(img, 1, blank_image, 0.95, 0.0)

    # for pic, contour in enumerate(contours):
    #     area = cv2.contourArea(contour)
    #     # print(contours)
    #     if(area > 500):
    #         cv2.drawContours(img, contours, -1,(0, 255, 0), 2)
    # # img = cv2.addWeighted(img, 0.8, blank_image, 1, 0.0)
    
    px1, py1, px2, py2 = 250, 750, width-250, height-250
    
    # img = cv2.rectangle(img, (px1, py1), (px2, py2) , (0, 0, 255), 1)
    # img2 = cv2.rectangle(img, (px1, py1+85), (px2, py2+85) , (0, 0, 255), 1)
    # img3 = cv2.rectangle(img2, (250, 100), (width-250, height-900) , (0, 0, 255), 2)

    # if px1 >= x1 and py1 >= y1 and px2 <= x2 and py2 <=y2:
    #     print("Hi")

    # img3 = cv2.bitwise_not(img2)
    # res = cv2.bitwise_and(img_line, img)q
    # res2 = cv2.bitwise_and(img_line, img2)
    # res3 = cv2.bitwise_and(img_line, img3)
    # print("res", res) 
    # print("res2", res2) 
    # print("res3", res3)
    return img
    
# = cv2.imread('road.jpg')
#image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

def get_aoi(img):
    rows, cols = img.shape[:2]
    mask = np.zeros_like(img)
        
    left_bottom = [cols * 0.1, rows]
    right_bottom = [cols * 0.95, rows]
    left_top = [cols * 0.4, rows * 0.6]
    right_top = [cols * 0.6, rows * 0.6]
        
    vertices = np.array([[left_bottom, left_top, right_top, right_bottom]], dtype=np.int32)
        
    if len(mask.shape) == 2:
        cv2.fillPoly(mask, vertices, 255)
    else:
        cv2.fillPoly(mask, vertices, (255, ) * mask.shape[2])
    return cv2.bitwise_and(img, mask)


def process(image):
    print(image.shape)
    height = image.shape[0]
    width = image.shape[1]
    region_of_interest_vertices = [
        (0, height),
        (width/2, height/2),
        (width, height)
    ]
    gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    gcropped_image = crop(gray_image, bottom_offset = 100)
    canny_image = cv2.Canny(gray_image, 100, 120)
    cropped_image = crop(canny_image)
    # cropped_image = region_of_interest(canny_image,
    #                                    np.array([region_of_interest_vertices], np.int32),)
    
    cv2.imshow("gc", gcropped_image)
    lines = cv2.HoughLinesP(cropped_image,
                            rho=2,
                            theta=np.pi/180,
                            threshold=200,
                            lines=np.array([]),
                            minLineLength=10,
                            maxLineGap=250)
    # contours, hierarchy = cv2.findContours(cropped_image,
    #    cv2.RETR_TREE,
    #    cv2.CHAIN_APPROX_SIMPLE)
    image_with_lines = draw_the_lines(image, lines, height, width)
    return image_with_lines


cap = cv2.VideoCapture('assets/test.mp4')

while cap.isOpened():
    ret, frame = cap.read()
    frame = process(frame)
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
