#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <csignal>
#include <boost/asio.hpp>

#include <ros/console.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <phasespace_imu_integration/PhaseSpaceMarkerArray.h>



class phase_space
{
	ros::NodeHandle ph_sp_;

	ros::Subscriber subscribe_phace_;



public:


	phase_space();

	~phase_space();

	showData(phasespace_imu_integration::PhaseSpaceMarkerArray p);


	
};