import cv2
import numpy as np
from scipy.spatial import distance

def compare_shapes(img):

    img = cv2.imread(img)

    # Convert image to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Threshold the image to binary
    _, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)

    # Find contours in the binary image
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Select the largest two contours (presumed to be the cheerio and torus)
    contours = sorted(contours, key=cv2.contourArea, reverse=True)[:2]

    # Calculate Hu Moments for each contour
    hu_moments = [cv2.moments(contour) for contour in contours]
    hu_moments = [cv2.HuMoments(moments) for moments in hu_moments]

    # Normalize the Hu Moments to make them invariant to scale and orientation
    hu_moments = [cv2.log(np.abs(hu)) for hu in hu_moments]

    # Calculate the difference between the two sets of Hu Moments
    diff_hu = np.abs(hu_moments[0] - hu_moments[1])

    # Calculate Shape Context for each contour
    shape_contexts = [cv2.createShapeContextDistanceExtractor().computeDistance(contour, cv2.DIST_L2) for contour in contours]

    # Calculate the difference between the two sets of Shape Contexts
    diff_sc = np.abs(shape_contexts[0] - shape_contexts[1])

    # Calculate Frechet Distance between the two contours
    frechet_distance, _ = cv2.freetype.distanceToFront(contours[0], contours[1], cv2.DIST_L2)

    # Set thresholds for each shape descriptor
    threshold_hu = 0.1
    threshold_sc = 10
    threshold_fd = 5

    # Determine if the shapes are similar based on the thresholds
    hu_similar = np.all(diff_hu < threshold_hu)
    sc_similar = np.all(diff_sc < threshold_sc)
    fd_similar = frechet_distance < threshold_fd

    # Combine the results of the shape descriptors to determine overall similarity
    similarity = hu_similar and sc_similar and fd_similar

    return similarity


print(compare_shapes("pic1.jpg"))

