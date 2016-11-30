#include <listener_phase_space.h>


phase_space::phase_space()
{

    subscribe_phace_ = ph_sp_.subscribe("/phase_space_markers",10000, &phase_space::showData, this);

    pkg_path_ = ros::package::getPath("phasespace_imu_integration");

    flag_write_ = false;
    flag_glove_ = false;


}

/*********************************************************************/


phase_space::~phase_space()
{

}


/*********************************************************************/

void phase_space::saveData()
{

	if(flag_write_)
	{
	    for(int i=0; i<m_.markers.size(); i++)
		{	
			std::cout<<"marker: " << m_.markers[i].id << std::endl;
			// ROS_INFO("point %d : %f %f %f", p.markers[i].id, p.markers[i].point.x, p.markers[i].point.y, p.markers[i].point.z);
			fprintf(fileMarkers_, "%d\t%f\t%f\t%f", m_.markers[i].id, m_.markers[i].point.x, m_.markers[i].point.y, m_.markers[i].point.z );
			
		}	
		fprintf(fileMarkers_, "\n");
	}

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
	m_ = p;
}




