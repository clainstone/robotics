#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <parameter_test/parametersConfig.h>

void callback(parameter_test::parametersConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %d %f %s %s %d", 
            config.int_param, config.double_param, 
            config.str_param.c_str(), 
            config.bool_param?"True":"False", 
            config.size);
            
            ROS_INFO ("%d",level);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "param_second");
  //creaate the parameter server specifying the type of config
  dynamic_reconfigure::Server<parameter_test::parametersConfig> server;
  //The callback function is called when the parameters are changed
  dynamic_reconfigure::Server<parameter_test::parametersConfig>::CallbackType f;
  //boost:bind is used to bind the callback function to the server
  //The _1 and _2 are placeholders for the parameters passed to the callback function
  //The first parameter is the config and the second is the level
  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
