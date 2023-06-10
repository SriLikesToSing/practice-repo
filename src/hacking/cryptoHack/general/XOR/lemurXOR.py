import numpy as np
from PIL import Image, ImageChops
import PIL.ImageOps


im1 = Image.open("flag.png", mode='r').convert("1")
im2 = Image.open("lemur.png", mode='r').convert("1")

result = ImageChops.logical_xor(im2, im1)
result = ImageChops.invert(result)

result.save('BRO.png')




'''
g.png lemur.png 
-fx "(((255*u)&(255*(1-v)))|((255*(1-u))&(255*v)))/255" img_out

'''
