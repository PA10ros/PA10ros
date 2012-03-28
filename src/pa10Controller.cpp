#define _USE_MATH_DEFINES
#include <math.h>
#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "ros_interface.h"


/*
void pa10open(void);
void pa10close(void);
void pa10control(struct pa10controlmessage);
pa10statusmessage pa10status(void);
void pa10breakerelease();
*/ //We go these knobs to frob
/*
Skal pa10open kun kaldes en gang ?
*/



//Send command message to low level controller
void controlProcess(const sensor_msgs::JointState::ConstPtr& jointState)
{
	for (unsigned int i = 0; i < jointState->name.size();i++)
	{
		ROS_INFO("Jointname: [%s] set to: Position: [%f] Velocity: [%f] Torque [%f]",jointState->name[i].c_str(),jointState->position[i],jointState->velocity[i],jointState->effort[i]);
	}
//  ROS_INFO("I heard: [%s]", jointState->data.c_str());
}


void packStatusMessage(sensor_msgs::JointState &stateMSG, pa10statusmessage &status)
{
                stateMSG.name.clear();
                stateMSG.position.clear();
                stateMSG.velocity.clear();
                stateMSG.effort.clear();
		stateMSG.name.push_back("s1");
		stateMSG.name.push_back("s2");
		stateMSG.name.push_back("e1");
		stateMSG.name.push_back("e2");
		stateMSG.name.push_back("e3");
		stateMSG.name.push_back("w1");
		stateMSG.name.push_back("w2");
		
		stateMSG.position.push_back(status.s1.angle);
		stateMSG.position.push_back(status.s2.angle);
		stateMSG.position.push_back(status.e1.angle);
		stateMSG.position.push_back(status.e2.angle);
		stateMSG.position.push_back(status.e3.angle);
		stateMSG.position.push_back(status.w1.angle);
		stateMSG.position.push_back(status.w2.angle); 
		//stateMSG.velocity.push_back() 
		stateMSG.effort.push_back(status.s1.torque);
		stateMSG.effort.push_back(status.s2.torque);
		stateMSG.effort.push_back(status.e1.torque);
		stateMSG.effort.push_back(status.e2.torque);
		stateMSG.effort.push_back(status.e3.torque);
		stateMSG.effort.push_back(status.w1.torque);
		stateMSG.effort.push_back(status.w2.torque);

}


int main(int argc, char ** argv)
{
	ros::init(argc, argv, "pa10Controller");
	ros::NodeHandle n;
	ros::Publisher status_pub = n.advertise<sensor_msgs::JointState>("pa10status",1000);
	ros::Rate loop_rate(10);
	ros::Subscriber sub = n.subscribe("pa10Commands",1000,controlProcess);
        
        pa10open();
	while(ros::ok())
	{
		//Handle output
		//Variables
		sensor_msgs::JointState stateMSG;
	        struct pa10statusmessage status;
                
                //Poll the driver
		status = pa10status();
		
		//Convert to rosMSG
                packStatusMessage(stateMSG,status);		
		
		//publish status to topic
		status_pub.publish(stateMSG);
		
		
		
		
		
		ros::spinOnce();
		loop_rate.sleep();
	}
	pa10close();
	return 0;
}
