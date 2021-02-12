import cv2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

img_night = cv2.imread('C:/Users/hml76/Downloads/night11.jpg', cv2.IMREAD_GRAYSCALE)
equalized = cv2.equalizeHist(img_night) # 불러온 이미지에 histogram equalization을 적용.
original_img = cv2.calcHist(images = [img_night], channels = [0], mask = None, histSize = [256], ranges = [0, 256])
equalized_img = cv2.calcHist(images = [equalized], channels = [0], mask = None, histSize = [256], ranges = [0, 256])

#print("Vect : ", img_night.shape)
#print("Vect_img : ", equalized.shape)
cv2.imshow('Original image', img_night)
cv2.imshow('Equalized image', equalized)

plt.title('Grayscale histogram')
plt.plot(original_img, label ='Original')
plt.plot(equalized_img, label ='Equalized')
#plt.legend()
plt.show()
cv2.waitKey()
cv2.destroyAllWindows()
