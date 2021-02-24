import numpy as np
import cv2
from tkinter import * #Tkinter는 Tcl/Tk에 대한 파이썬 Wrapper로서 Tcl/Tk를 파이썬에 사용할 수 있도록 한 Lightweight GUI 모듈
import tkinter.filedialog as f    #이걸로 코드실행 후 원하는 이미지 파일 불러올 수 있음
import matplotlib.pyplot as plt

#  Vertical Mirroring

cvgrayimg = cv2.imread('C:/Users/hml76/Downloads/Tom.jpg',0) #cv2.IMREAD_GRAYSCALE = 0

cv2.namedWindow('Original gray')
cv2.imshow('Original gray',cvgrayimg)
cv2.waitKey(0)

dstimg = cv2.flip(cvgrayimg,0) #0 : vertical flipping around the x-axis, 0보다 크면 y-axis, 0보다 작으면 both axis

cv2.namedWindow('Vertical Flipping')
cv2.imshow('Vertical Flipping',dstimg)
cv2.waitKey(0)

plt.subplot(121), plt.imshow(cvgrayimg,'gray'), plt.title('Original image')
plt.xticks([]), plt.yticks([])
plt.subplot(122), plt.imshow(dstimg,'gray'), plt.title('Vertical Flipping image')
plt.xticks([]), plt.yticks([])

plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()