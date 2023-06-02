import os
import cv2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

img = cv2.imread('./pic1.jpg')



lower = np.array([60, 60, 60])
higher = np.array([250, 250, 250])

mask = cv2.inRange(img, lower, higher)

cont,_ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

contImg = cv2.drawContours(img, cont, -1, 255, 3)

plt.imshow(contImg)

#plt.imshow(img)
#plt.imshow(mask, 'gray')
plt.show()
