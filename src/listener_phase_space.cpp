#include <listener_phase_space.h>


phase_space::phase_space()
{

    subscribe_phace_ = ph_sp_.subscribe("/phase_space_markers",10000, &phase_space::showData, this);

    pkg_path_ = ros::package::getPath("phasespace_imu_integration");

    flag_write_ = false;

}

/*********************************************************************/


phase_space::~phase_space()
{

}


/*********************************************************************/

void phase_space::openFile(std::string s)
{
  std::string s1;

  flag_write_ = true;

  s1 = pkg_path_ + "/measurements/" + s + "_markers.txt";
  fileMarkers_ = fopen(s1.c_str(),"w");
}

/*********************************************************************/

void phase_space::closeFile()
{
  flag_write_ = false;
          
  fclose(fileMarkers_);
}



/*********************************************************************/

void phase_space::showData(phasespace_imu_integration::PhaseSpaceMarkerArray p)
{

	for(int i=0; i<p.markers.size(); i++)
	{	
		std::cout<<"marker: " << p.markers[i].id << std::endl;
		// ROS_INFO("point %d : %f %f %f", p.markers[i].id, p.markers[i].point.x, p.markers[i].point.y, p.markers[i].point.z);
		if(flag_write_)
		{
			fprintf(fileMarkers_, "%d\t%f\t%f\t%f", p.markers[i].id, p.markers[i].point.x, p.markers[i].point.y, p.markers[i].point.z );
		}
	}

	if(flag_write_)
		fprintf(fileMarkers_, "\n");

}




