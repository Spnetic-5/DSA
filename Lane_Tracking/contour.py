import matplotlib.pylab as plt
import cv2
import numpy as np


def region_of_interest(img, vertices):
    mask = np.zeros_like(img)
    #channel_count = img.shape[2]
    match_mask_color = 160
    cv2.fillPoly(mask, vertices, match_mask_color)
    masked_image = cv2.bitwise_and(img, mask)
    return masked_image


def draw_the_lines(img, contours, height, width):
    img = np.copy(img)
    blank_image = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)

    for pic, contour in enumerate(contours):
        area = cv2.contourArea(contour)
        # print(contours)
        if(area > 500):
            cv2.drawContours(img, contours, -1,(0, 255, 0), 2)
    # img = cv2.addWeighted(img, 0.8, blank_image, 1, 0.0)
    
    px1, py1, px2, py2 = 250, 750, width-250, height-250
    
    img = cv2.rectangle(img, (px1, py1), (px2, py2) , (0, 0, 255), 1)
    img2 = cv2.rectangle(img, (px1, py1+85), (px2, py2+85) , (0, 0, 255), 1)
    # img3 = cv2.rectangle(img2, (250, 100), (width-250, height-900) , (0, 0, 255), 2)

    # if px1 >= x1 and py1 >= y1 and px2 <= x2 and py2 <=y2:
    #     print("Hi")

    # img3 = cv2.bitwise_not(img2)
    # res = cv2.bitwise_and(img_line, img)
    # res2 = cv2.bitwise_and(img_line, img2)
    # res3 = cv2.bitwise_and(img_line, img3)
    # print("res", res) 
    # print("res2", res2) 
    # print("res3", res3)
    return img2
    
# = cv2.imread('road.jpg')
#image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)


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
    canny_image = cv2.Canny(gray_image, 100, 120)
    cropped_image = region_of_interest(canny_image,
                                       np.array([region_of_interest_vertices], np.int32),)
    
    # lines = cv2.HoughLinesP(cropped_image,
    #                         rho=2,
    #                         theta=np.pi/180,
    #                         threshold=200,
    #                         lines=np.array([]),
    #                         minLineLength=40,
    #                         maxLineGap=100)
    contours, hierarchy = cv2.findContours(cropped_image,
       cv2.RETR_TREE,
       cv2.CHAIN_APPROX_SIMPLE)
    image_with_lines = draw_the_lines(image, contours, height, width)
    return image_with_lines


cap = cv2.VideoCapture('assets/test.mp4')

while cap.isOpened():
    ret, frame = cap.read()
    frame = process(frame)
    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
