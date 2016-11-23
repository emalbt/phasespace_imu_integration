#include <listener_imu_glove.h>



imu_glove::imu_glove()
{
	flag_write_ = false;

	sub_acc_ = n_.subscribe("/qb_class_imu/acc", 1000, &imu_glove::saveDataAcc, this);
	sub_gyro_ = n_.subscribe("/qb_class_imu/gyro", 1000, &imu_glove::saveDataGyro, this);

  pkg_path_ = ros::package::getPath("phasespace_imu_integration");

}


/*********************************************************************/

imu_glove::~imu_glove()
{
}

/*********************************************************************/

int imu_glove::kbhit(void) {
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

/*********************************************************************/

void imu_glove::openFiles()
{
  std::string s, s1, s2;

  flag_write_ = true;

  std::cout<<"\n\n# Experiment"<<::endl;
  cin >> s;
  s1 = pkg_path_ + "/measurements/" + s + "_acc.txt";
  s2 = pkg_path_ + "/measurements/" + s + "_gyro.txt";
  fileAcc_ = fopen(s1.c_str(),"w");
  fileGyro_ = fopen(s2.c_str(),"w");

}

/*********************************************************************/

void imu_glove::closeFiles()
{
  flag_write_ = false;
          
  fclose(fileAcc_);
  fclose(fileGyro_);
  std::cout << "\n\nCLOSE FILE" <<std::endl;

}

/*********************************************************************/


void imu_glove::saveDataAcc(qb_interface::inertialSensorArray imu)
{
	int i=0;

	if(flag_write_)
	{
		for (i = 0; i<imu.m.size(); i++)
		{
    		fprintf(fileAcc_, "%f\t", imu.m[i].x);
    		fprintf(fileAcc_, "%f\t", imu.m[i].y);
    		fprintf(fileAcc_, "%f\t", imu.m[i].z);
		}
  		fprintf(fileAcc_, "\n");
	}

}

/*********************************************************************/


void imu_glove::saveDataGyro(qb_interface::inertialSensorArray imu)
{
	int j=0;

	if(flag_write_)
	{
		for (j = 0; j<imu.m.size(); j++)
		{
    		fprintf(fileGyro_, "%f\t", imu.m[j].x);
    		fprintf(fileGyro_, "%f\t", imu.m[j].y);
    		fprintf(fileGyro_, "%f\t", imu.m[j].z);
  		}
  		fprintf(fileGyro_, "\n");
  }
}

/*********************************************************************/
/*
void imu_glove::choseFileName()
{
	std::string s;


	if (kbhit())
    {
                 
        x_ = getchar();
        if(x_ == 'o') 
        {
        	flag_write_ = true;

            std::cout<<"\n\nInserire nome/numero esperimento"<<::endl;
            cin >> s;
            s1_=pkg_path + "/measurements/" + s + ".txt";
            s2_=pkg_path + "/measurements/" + s + ".txt";
            fileAcc_ = fopen(s1_.c_str(),"w");
            fileGyro_ = fopen(s2_.c_str(),"w");
            x_ ='?';
        }

        if(x_ == 'c')
        {
          flag_write_ = false;
          
          fclose(fileAcc_);
          fclose(fileGyro_);
          std::cout << "\n\nCLOSE FILE" <<std::endl;
          getchar();
          x_ ='?';
        }

    } 

}
*/

/*********************************************************************/

