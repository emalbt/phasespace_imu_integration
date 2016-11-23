#include <listener_phase_space.h>


phase_space::phase_space()
{

    subscribe_phace_ = ph_sp_.subscribe("/phase_space_markers",10000,showData);

}

/*********************************************************************/


phase_space::~phase_space()
{

}

/*********************************************************************/

void phase_space::showData(phasespace_imu_integration::PhaseSpaceMarkerArray p)
{

  for(int i=0; i<p.markers.size(); i++)
    std::cout<<"marker: " << p.markers[i].id << std::endl;
    // ROS_INFO("point %d : %f %f %f", p.markers[i].id, p.markers[i].point.x, p.markers[i].point.y, p.markers[i].point.z);


}




// int  main(int argc, char **argv)
// {

// 	ros::init(argc, argv, "listener_phase_space_node");

// 	ros::NodeHandle ph_sp;


// 	ros::Subscriber subscribe_phace = ph_sp.subscribe("/phase_space_markers",10000,showData);

// 	ros::spin();

// }


