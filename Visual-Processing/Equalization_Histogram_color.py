import cv2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

original_img = cv2.imread('C:/Users/hml76/Downloads/night1.jpg')

hsv = cv2.cvtColor(original_img, cv2.COLOR_BGR2HSV)  # hsv 컬러 형태로 변형합니다.
h, s, v = cv2.split(hsv)  # h, s, v로 컬러 영상을 분리 합니다.

equalized_img = cv2.equalizeHist(v)  # v값을 히스토그램 평활화를 합니다.

hsv2 = cv2.merge([h, s, equalized_img])  # h,s,equalizedV를 합쳐서 새로운 hsv 이미지를 만듭니다.

hsvDst = cv2.cvtColor(hsv2, cv2.COLOR_HSV2BGR) # 마지막으로 hsv2를 다시 BGR 형태로 변경합니다.

yCrCb = cv2.cvtColor(original_img, cv2.COLOR_BGR2YCrCb) # YCrCb 컬러 형태로 변환합니다.

y, Cr, Cb = cv2.split(yCrCb)  # y, Cr, Cb로 컬러 영상을 분리 합니다.
equalizedY = cv2.equalizeHist(y)  # y값을 히스토그램 평활화를 합니다.

yCrCb2 = cv2.merge([equalizedY, Cr, Cb])  # equalizedY, Cr, Cb를 합쳐서 새로운 yCrCb 이미지를 만듭니다.
yCrCbDst = cv2.cvtColor(yCrCb2, cv2.COLOR_YCrCb2BGR)  # 마지막으로 yCrCb2를 다시 BGR 형태로 변경합니다.

print("shape1 : ",hsv2.shape, "shape2 : ",hsvDst.shape,"shape3 : ",yCrCbDst.shape,)

plt.title('Grayscale histogram')
plt.plot(hsv2[1], label ='1')
plt.plot(hsv2[1,:,1], label ='2')
plt.plot(hsv2[1,:,2], label ='3')
plt.show()
# src, hsv, YCrCb 각각을 출력합니다.

cv2.imshow('Original image', original_img)
cv2.imshow('hsv dst', hsvDst)
cv2.imshow('YCrCb dst', yCrCbDst)
cv2.waitKey()
cv2.destroyAllWindows()
