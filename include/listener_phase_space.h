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
#include <ros/package.h>
#include <std_msgs/String.h>
#include <phasespace_imu_integration/PhaseSpaceMarkerArray.h>



class phase_space
{



public:


	phase_space();

	~phase_space();

	void showData(phasespace_imu_integration::PhaseSpaceMarkerArray p);

	void openFile(std::string s);

	void closeFile();

	ros::NodeHandle ph_sp_;

	ros::Subscriber subscribe_phace_;

	FILE* fileMarkers_;

	bool flag_write_;

	std::string pkg_path_;	

	
};