#include "ros/ros.h"
#include "std_msgs/String.h"
#include "pub_sub/Num.h"


void chatterCallback(const std_msgs::String::ConstPtr& msg){
  ROS_INFO("I heard: [%d]", msg->data.c_str());
}

//ConstPtr è un alias per un puntatore costante a un'istanza del messaggio. È definito automaticamente da ROS per ogni tipo di messaggio.
//Significa che il puntatore msg punta a un'istanza immutabile del messaggio ricevuto. 
//Non puoi modificare il contenuto del messaggio all'interno della funzione di callback.
void pubCallback(const pub_sub::Num::ConstPtr& msg){
  ROS_INFO("I heard: [%d]", msg->num);
}
int main(int argc, char **argv){
  	//
	ros::init(argc, argv, "listener");

	ros::NodeHandle n;
  	ros::Subscriber sub = n.subscribe("chatter", 1, pubCallback);

  	ros::spin();

  return 0;
}

<
