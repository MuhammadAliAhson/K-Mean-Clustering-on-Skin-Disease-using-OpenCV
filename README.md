# OpenCV_K-Mean_Clustering_CPP
Hey Folks!  I have made an "OpenCV" K-mean clustering program in which you can eliminate the non-populated (less or not absolute neighbors) and can convert the colored image into Grey Scale (black and white). It is used in the medical field to analyze infected skin. 
install.packages("bmp")

# README

## Image Segmentation and Evaluation using OpenCV and C++

This project performs image segmentation and evaluation using OpenCV in C++. The code reads grayscale images, performs segmentation using two different methods, and evaluates the results using Dice Coefficient.

### Requirements

- OpenCV
- C++ compiler

### Steps to run the code

1. Set up OpenCV on your system.
2. Compile the code using a C++ compiler.
3. Update the image paths in the code to match the location of the images on your system.
4. Run the compiled executable.

### Description of the code

The code contains three main functions:

#### `int** task1()`



- Reads a grayscale image.
- Performs image segmentation using a custom algorithm based on labeling and finding the most occurring value (label).
- Returns a 2D integer array of the segmented image.

#### `int** task2()`

- Reads a grayscale image.
- Performs image segmentation using K-means clustering algorithm.
- Returns a 2D integer array of the segmented image.

#### `int task3()`

- Reads a ground truth image.
- Calls `task1()` and `task2()` to get the segmented images.
- Calculates True Positive, False Positive, and False Negative values.
- Evaluates the segmentation results using Dice Coefficient.
- Prints the evaluation results.

### Example output

The code will display the following information:

- Rows and columns of the images.
- Value of maximum occurrence (label).
- False Negative, False Positive, and True Positive values for each task.
- Dice Coefficient for each task.
