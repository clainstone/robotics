#include "ros/ros.h"
#include "std_msgs/String.h"
#include "pub_sub/Num.h"



int main(int argc, char **argv){

	ros::init(argc, argv, "talker"); //, ros::init_options::AnonymousName);
	ros::NodeHandle n;

	//1 is the buffer size
	//std_msg is a ROS message type, so a template, like generics in java
	//the last argument is the size of the buffer : queue size

	//"chatter" is the name of the topic
	ros::Publisher chatter_pub = n.advertise<pub_sub::Num>("chatter", 1);

	//loop _rate function creates a new object of type Rate
	ros::Rate loop_rate(10);

	while (ros::ok()){
		if(false){
	    	std_msgs::String msg;

                msg.data = "hello world!";

    		ROS_INFO("%s", msg.data.c_str());

    		chatter_pub.publish(msg);

			//it's used to call the callback functions of the subscribers
			
    		ros::spinOnce();

    		loop_rate.sleep();
		}
		else{
			static int i=0;
			i=(i+1)%1000;
			pub_sub::Num msg;
			msg.num =i;
  	}


  	return 0;
}
}
