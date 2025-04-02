cmake_minimum_required(VERSION 2.8.3)
project(pub_sub)
add_message_files(FILES
  Num.msg
)
## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)

generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package. It provides important metadata about your package and specifies what your
## package exports to other packages that depend on it.
catkin_package(CATKIN_DEPENDS message_runtime)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})
## pub is the name of the node visible to rosmaster
add_executable(pub src/pub.cpp)
target_link_libraries(pub ${catkin_LIBRARIES})
add_dependencies(pub pub_sub_generate_messages_cpp)

add_executable(sub src/sub.cpp)
target_link_libraries(sub ${catkin_LIBRARIES})



