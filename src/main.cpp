// #include "listener_phase_space.h"
#include "listener_imu_glove.h"

#include <ros/ros.h>





int main(int argc, char **argv)
{
	char x;

	ros::init(argc, argv, "phasespace_imu_integration_node");

	ros::NodeHandle n;

	// phase_space PS;
	imu_glove IG;


	while(ros::ok())
	{

		if (IG.kbhit())
		{
        	x = getchar();
        	if(x == 'o') 
                IG.openFiles();
            
        	if(x == 'c')
        	    IG.closeFiles();
    	}

        ros::spinOnce();
	}// end while()

}