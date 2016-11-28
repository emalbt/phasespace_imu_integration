#include <ros/ros.h>
#include <boost/asio.hpp>

// my headers
// #include "listener_phase_space.h"
#include "listener_imu_glove.h"



//-----------------------------------------------------
//                                             	  kbhit
//-----------------------------------------------------
int kbhit(void) 
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}





//-----------------------------------------------------
//                                             	   main
//-----------------------------------------------------
int main(int argc, char **argv)
{
	char x;

	ros::init(argc, argv, "phasespace_imu_integration_node");

	ros::NodeHandle n;

	// phase_space PS;
	imu_glove IG;


	while(ros::ok())
	{

		if (kbhit())
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