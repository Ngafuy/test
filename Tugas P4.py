# Tugas 1

import numpy as np
from matplotlib import pyplot as plt
import matplotlib.image as mpimg

def my_threshold(img, threshold_value, threshold_type):
    if len(img.shape) > 2:
        img = np.dot(img[...,:3], [0.2989, 0.5870, 0.1140])

    # Inisialisasi array untuk hasil
    result = np.zeros(img.shape, dtype=np.uint8)

    # Thresholding
    if threshold_type == 1: # Binary thresholding
        result[img <= threshold_value] = 0
        result[img > threshold_value] = 255
        
    elif threshold_type == 2: # Binary inverted thresholding
        result[img <= threshold_value] = 255
        result[img > threshold_value] = 0

    elif threshold_type == 3: # Truncate thresholding
        result[img <= threshold_value] = img[img <= threshold_value]
        result[img > threshold_value] = threshold_value

    elif threshold_type == 4: # Truncate to zero thresholding
        result[img <= threshold_value] = 0
        result[img > threshold_value] = img[img > threshold_value]
 
    elif threshold_type == 5: # Truncate to zero inverted thresholding
        result[img <= threshold_value] = img[img <= threshold_value]
        result[img > threshold_value] = 0

    return result
    
img = mpimg.imread('gradient.jpg', 0)

titles = ['Original Image','BINARY','BINARY_INV','TRUNC','TOZERO','TOZERO_INV']
images = [img, my_threshold(img, 127, 1), my_threshold(img, 127, 2),
               my_threshold(img, 127, 3), my_threshold(img, 127, 4), 
               my_threshold(img, 127, 5)]
for i in range(6):
    plt.subplot(2,3,i+1),plt.imshow(images[i], 'gray')
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])
plt.show()