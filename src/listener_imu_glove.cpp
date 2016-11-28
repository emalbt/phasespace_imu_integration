#include <listener_imu_glove.h>



imu_glove::imu_glove()
{
	flag_write_ = false;

	sub_acc_ = n_.subscribe("/qb_class_imu/acc", 1000, &imu_glove::callbackAcc, this);
	sub_gyro_ = n_.subscribe("/qb_class_imu/gyro", 1000, &imu_glove::callbackGyro, this);

  pkg_path_ = ros::package::getPath("phasespace_imu_integration");

}


/*********************************************************************/

imu_glove::~imu_glove()
{
}

/*********************************************************************/

void imu_glove::openFiles(std::string s)
{
  std::string s1, s2;

  flag_write_ = true;

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
}


/*********************************************************************/


void imu_glove::saveDataAcc()
{
  if(flag_write_)
  {
    for (int i = 0; i<acc_.m.size(); i++)
    {
        fprintf(fileAcc_, "%f\t", acc_.m[i].x);
        fprintf(fileAcc_, "%f\t", acc_.m[i].y);
        fprintf(fileAcc_, "%f\t", acc_.m[i].z);
    }
      fprintf(fileAcc_, "\n");
  }

}


/*********************************************************************/


void imu_glove::saveDataGyro()
{
  if(flag_write_)
  {
    for (int j = 0; j<gyro_.m.size(); j++)
    {
        fprintf(fileGyro_, "%f\t", gyro_.m[j].x);
        fprintf(fileGyro_, "%f\t", gyro_.m[j].y);
        fprintf(fileGyro_, "%f\t", gyro_.m[j].z);
      }
      fprintf(fileGyro_, "\n");
  }
}


/*********************************************************************/


void imu_glove::callbackAcc(qb_interface::inertialSensorArray imu_tmp)
{
    acc_ = imu_tmp;
}

/*********************************************************************/


void imu_glove::callbackGyro(qb_interface::inertialSensorArray imu_tmp)
{
    gyro_=imu_tmp;	
}
