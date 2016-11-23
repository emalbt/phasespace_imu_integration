#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <csignal>
#include <boost/asio.hpp>
#include <ros/ros.h>
#include <ros/package.h>

#include <qb_interface/inertialSensorArray.h>

using namespace std;

class imu_glove
{

public:

	imu_glove();

	~imu_glove();

	int kbhit(void);

	void openFiles();

	void closeFiles();

	void saveDataAcc(qb_interface::inertialSensorArray imu);

	void saveDataGyro(qb_interface::inertialSensorArray imu);

	FILE *fileAcc_;
	FILE *fileGyro_;

	ros::NodeHandle n_;

	ros::Subscriber sub_acc_;
	ros::Subscriber sub_gyro_;

	bool flag_write_;

	std::string pkg_path_;	
};