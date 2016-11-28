#include <listener_tf.h>


phase_space_tf::phase_space_tf()
{



}

/*********************************************************************/


phase_space_tf::~phase_space_tf()
{

}

/*********************************************************************/

void phase_space_tf::saveData()
{

    tf::StampedTransform transform;
    try
    {
      listener_.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) 
    {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    // TO DO save data
}

