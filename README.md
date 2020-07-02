# image_proc_tutorial
This repository is used for the training of students in the field of mobile robotics with ros. This example is free to use and can be modified for your needs. 

## Inspect the code
Have a look at the node itself, as well as the used class which is used in the main routine. 



## ROS Topic
At the start, only the image_publisher_node is publishing the image. The image convert node does not do anything, because it currently does not subscribe to the necessary topic. Find the relevant topic's name and modify the code so a connection is possible. 



## Drawing
From the start, a circle is published in the image. Do some modifications, e.g. move the circle to the center of the image, or change the circle to a rectangle. 


## Do image processing

### Gaussian Smoothing
Apply a gaussian filter to the image. This can be used to remove noise or unnecessary details from an image. Use this example as an orientation: https://docs.opencv.org/2.4/doc/tutorials/imgproc/gausian_median_blur_bilateral_filter/gausian_median_blur_bilateral_filter.html


### Canny Edge
Extract the edges from the image based on the Canny Edge algorithm. Use this example as an orientation: https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html


