import numpy as np
import matplotlib.pyplot as plt


#histogram creation template for physics experiments and labs 

x = np.random.normal(170, 10, 500)
myData = np.array([9, 11, 7, 15, 27, 21, 6, 2, 11, 7])

print("x")
print(x)

print("myData")
print(myData)


#creates histogram

#histogram for myData
plt.hist(myData)
plt.show()


#histogram for x 
plt.hist(x)
plt.show()




















