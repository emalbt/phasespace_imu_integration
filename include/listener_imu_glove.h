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

	void openFiles(std::string s);
	void closeFiles();

	void callbackAcc(qb_interface::inertialSensorArray imu);
	void callbackGyro(qb_interface::inertialSensorArray imu);

	void saveDataAcc();
	void saveDataGyro();

	FILE *fileAcc_;
	FILE *fileGyro_;

	qb_interface::inertialSensorArray acc_, gyro_;

	ros::NodeHandle n_;

	ros::Subscriber sub_acc_;
	ros::Subscriber sub_gyro_;

	bool flag_write_;

	std::string pkg_path_;	
};