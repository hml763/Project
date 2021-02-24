import numpy as np
import cv2
from tkinter import * #Tkinter는 Tcl/Tk에 대한 파이썬 Wrapper로서 Tcl/Tk를 파이썬에 사용할 수 있도록 한 Lightweight GUI 모듈
import tkinter.filedialog as f    #이걸로 코드실행 후 원하는 이미지 파일 불러올 수 있음
import matplotlib.pyplot as plt

# Laplacian Guassian

cvgrayimg = cv2.imread('C:/Users/hml76/Downloads/Tom.jpg',0) #cv2.IMREAD_GRAYSCALE = 0

cv2.namedWindow('Original gray')
cv2.imshow('Original gray',cvgrayimg)
cv2.waitKey(0)

msize = 3
sigma = 0.3*((msize-1)*0.5 -1) + 0.8
blurimg = cv2.GaussianBlur(cvgrayimg,(msize,msize),sigma,0)
dstimg = cv2.Laplacian(cvgrayimg,-1) #Src,ddepth,dx,dy = cvgrayimg,-1,0,1

cv2.namedWindow('Laplacian')
cv2.imshow('Laplacian',dstimg)
cv2.waitKey(0)

plt.subplot(121), plt.imshow(cvgrayimg,'gray'), plt.title('Original image')
plt.xticks([]), plt.yticks([])
plt.subplot(122), plt.imshow(dstimg,'gray'), plt.title('Laplacian image')
plt.xticks([]), plt.yticks([])

plt.show()
cv2.waitKey(0)
cv2.destroyAllWindows()