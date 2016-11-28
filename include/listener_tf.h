#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <std_msgs/String.h>
#include <csignal>
#include <ros/console.h>
#include <ros/ros.h>
#include <ros/package.h>
#include <tf/transform_listener.h>

#include <qb_interface/inertialSensorArray.h>


class phase_space_tf
{
public:

	ros::NodeHandle n_;

	phase_space_tf();

	~phase_space_tf();

	void saveData();

	void openFile(std::string s);

	void closeFile();

	void checkGlove(qb_interface::inertialSensorArray imu);


	tf::TransformListener listener_;

	bool flag_write_;
	bool flag_glove_;

	std::string pkg_path_;	

	FILE* fileTf_rotation_;
	FILE* fileTf_traslation_;


};