# phasespace-imu-integration
ROS package for communicate with the IMUGlove and the PhaseSpace. This package read data from the topics and create new files where the data are stored.  

# Setup
The user needs the [phase-space](https://github.com/CentroEPiaggio/phase-space.git) package in order to start the PhaseSpace and the [qb-interface-node](https://github.com/emalbt/qb_interface_node.git) for the IMUGlove. 

While the node is running pressing 'o' on the keyboard it is possible to create the files. 
Insert the number or name of the experiments and then press 'c' when finished. 

In the folder 'measurements' there are the files.  

Now, only the ImuGlove Class is enabled.