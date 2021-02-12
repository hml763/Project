import numpy as np
import cv2

img = cv2.imread('C:/Users/hml76/Downloads/test2.jpg')


#re_img = cv2.resize(img, (450,700))
#resize_image.save('./2.jpg')

#cv2.imshow("img",img)
#cv2.imshow("re_img",re_img)
cv2.imshow("img",img)
cv2.waitKey(0)
cv2.destroyAllWindows()