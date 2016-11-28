cmake_minimum_required(VERSION 2.8.3)
project(phasespace_imu_integration)

# add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "-std=c++0x")


find_package(catkin REQUIRED
	message_generation
	visualization_msgs 
	std_msgs 
	geometry_msgs 
	roscpp
	tf
	std_msgs
	cmake_modules
	roslib
	)

find_package(Eigen REQUIRED)



add_message_files(
	FILES
  	PhaseSpaceMarker.msg
  	PhaseSpaceMarkerArray.msg
  	inertialSensor.msg
)



generate_messages(
  DEPENDENCIES
	geometry_msgs
   	std_msgs
   	visualization_msgs
)



catkin_package(

)

include_directories(
	${catkin_INCLUDE_DIRS}
	include
)

add_executable(phasespace_imu_integration_node src/main.cpp src/listener_imu_glove.cpp src/listener_tf.cpp )

add_dependencies(phasespace_imu_integration_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(phasespace_imu_integration_node
  ${catkin_LIBRARIES}
)