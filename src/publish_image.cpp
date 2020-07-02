

// ros includes
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>


// opencv includes
// this is necessary for th ui which pops up when the node is started
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char** argv)
{        
  // check if the number of arguments to call this rosnode is sufficient                                                     
  if(argc < 2)
  {
    ROS_ERROR_STREAM("Not enough arguments. Please provide the path to the image which should be published.");
    ROS_ERROR_STREAM("Going to abort start of ROS node.");
    exit(1);
  }
  

  // initialize ros node and node handle
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;

  // initialize the image transport handle for compressed image publishing
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("/camera/image", 1);


  cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
  cv::waitKey(30);

  // generate an image based on the cv_bridge
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "rgb8", image).toImageMsg();

  ros::Rate loop_rate(5);
  while (nh.ok()) 
  {
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}