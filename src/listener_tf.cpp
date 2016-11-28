#include <listener_tf.h>


phase_space_tf::phase_space_tf()
{

    flag_write_ = false;

    pkg_path_ = ros::package::getPath("phasespace_imu_integration");

}

/*********************************************************************/


phase_space_tf::~phase_space_tf()
{

}

/*********************************************************************/

void phase_space_tf::saveData()
{

    if(flag_write_)
    {
        tf::StampedTransform transform;
        try
        {
          listener_.lookupTransform("/bracelet", "/phase_space_world", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex) 
        {
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        // std::cout<<"x\t"<<transform.getOrigin().x()<<" y\t"<<transform.getOrigin().y()<<"  z\t"<<transform.getOrigin().z() << std::endl;

        std::cout<<"w\t"<<transform.getRotation().w()<<" y\t"<<transform.getRotation().x()<<"  z\t"<<transform.getRotation().y() << std::endl;


    }
}



void phase_space_tf::openFile(std::string s)
{
    std::string s1,s2;
    flag_write_ = true;
    // TO DO save data
    s1 = pkg_path_ + "/measurements/" + s + "_rotation.txt";
    s2 = pkg_path_ + "/measurements/" + s + "_traslation.txt";
    fileTf_ = fopen(s1.c_str(),"w");
}




void phase_space_tf::closeFile()
{

    flag_write_ = false;
    // TO DO save data
}
