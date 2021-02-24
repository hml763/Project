import numpy as np
import cv2
from tkinter import * #Tkinter는 Tcl/Tk에 대한 파이썬 Wrapper로서 Tcl/Tk를 파이썬에 사용할 수 있도록 한 Lightweight GUI 모듈
import tkinter.filedialog as f    #이걸로 코드실행 후 원하는 이미지 파일 불러올 수 있음

# 오목 파라볼라 함수 적용

root = Tk()
root.filename = f.askopenfilename(filetypes=(("JPEG files",".jpg"),("ALL files", "*.*")))

cvgrayimg = cv2.imread(root.filename, cv2.IMREAD_GRAYSCALE) #cv2.IMREAD_GRAYSCALE = 0

cv2.namedWindow('source gray')
cv2.imshow('source gray',cvgrayimg)
cv2.waitKey(0)

LUT = np.zeros(256, dtype=np.uint8)

for i in range(256):
    nv = i/127 - 1
    nv = 255 * nv * nv
    nv = 255-nv
    if(nv > 255): nv = 255
    if(nv < 0): nv = 0
    LUT[i] = nv

cvgrayimg = cv2.LUT(cvgrayimg,LUT)

cv2.namedWindow('Concave parabola gray img')
cv2.imshow('Concave parabola img',cvgrayimg)
cv2.waitKey(0)

cv2.destroyAllWindows()