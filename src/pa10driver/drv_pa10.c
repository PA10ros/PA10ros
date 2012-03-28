/* Functions to assmeble ARCnet packets for the Mitsubishi PA10 7DOF industrial robotic arm */

/* $Date: 2007/02/23 17:19:40 $ */
/* $Author: sredna $ */
/* $Revision: 1.2 $ */

#include "com20022.h"
#define drv_main
#include "drv_pa10.h"

/*
// Send a 'S' packet to make the PA10 controller go in to control mode
int pa10_send_S(void){
  uint8_t timeout = 0;

  // allocate memory to the global 'C'-pack structs.
  //TODO: put this in some other initalize function... otherwise memory will be allocatede every time this function is executed
  pRespC=(pa10ResponsePackC*)malloc(sizeof(pa10ResponsePackC));
  pCmdC=(pa10CommandPackC*)malloc(sizeof(pa10CommandPackC));

  // Construct packet data in the internal memory of the COM20020
  gARC->hiadr=0x40; //write, autoinc, page 0
  gARC->loadr=0;

  gARC->data=IP_ARC_ID;   // SID
  gARC->data=PA10_ARC_ID; //PA10_ARC_ID;  // DID (0xFE  = servocontroller)
  gARC->data=254;  // adress of sequence no byte in package (implys) short package

  gARC->loadr=254;  // jump to data section (starts at adress of sequence no byte)
  gARC->data=g_PA10packet_serialno++;
  gARC->data='S';   // TYPE

  gARC->dstatus_command=0x03; // enable transmit fra page 0, zero offset


  // Check to se if the packet has been transmitted and acknowledget
  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x01) && timeout);
  if (!timeout) {printf("pa10_send_S(): Transmit complete TIMEOUT\n"); return(0);}

  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x02) && timeout);
  if (!timeout) {printf("pa10_send_S(): Transmit completed, but acknowledge TIMEOUT\n"); return(0);}

  return(1);
}
*/

/* send S packet (start of communication sequence)*/
int pa10_send_S(void){

	unsigned char timeout=0;
	int j=0;

	// initialize pa10 struct -allocate memory to the global 'C'-pack structs.
	if ( ! gp_pa10ResponsePackC)
        gp_pa10ResponsePackC=(pa10ResponsePackC*)malloc(sizeof(pa10ResponsePackC));
    if ( ! gp_pa10CommandPackC )
        gp_pa10CommandPackC=(pa10CommandPackC*)malloc(sizeof(pa10CommandPackC));

	for(j=0;j<7;j++){
		gp_pa10CommandPackC->velocity[j]=0;
		gp_pa10CommandPackC->torque[j]=0;
	}


	//
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);//write, autoinc, page 0
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// Sender ID
	outb(PA10_ARC_ID,g_pci22base+4);// Destination ID
	outb(254,g_pci22base+4);// adress of sequence no byte in package (implies) short package

	outb(254,g_pci22base+3);// jump to data section (starts at adress of sequence no byte)
	outb(g_PA10packet_serialno++,g_pci22base+4);
	outb('S',g_pci22base+4);// TYPE

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_S(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_S(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}


  return 1;
} // send_S

int pa10_send_T(void){

	unsigned char timeout=0;
	int j=0;

	// initialize pa10 struct -allocate memory to the global 'C'-pack structs.
	if ( ! gp_pa10ResponsePackC)
        gp_pa10ResponsePackC=(pa10ResponsePackC*)malloc(sizeof(pa10ResponsePackC));
    if ( ! gp_pa10CommandPackC )
        gp_pa10CommandPackC=(pa10CommandPackC*)malloc(sizeof(pa10CommandPackC));

	for(j=0;j<7;j++){
		gp_pa10CommandPackC->velocity[j]=0;
		gp_pa10CommandPackC->torque[j]=0;
	}

	//
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);//write, autoinc, page 0
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// Sender ID
	outb(PA10_ARC_ID,g_pci22base+4);// Destination ID
	outb(254,g_pci22base+4);// adress of sequence no byte in package (implies) short package

	outb(254,g_pci22base+3);// jump to data section (starts at adress of sequence no byte)
	outb(g_PA10packet_serialno++,g_pci22base+4);
	outb('T',g_pci22base+4);// TYPE

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_T(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_T(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}


  return 1;
} // send_t


int pa10_send_M(char driver_no){

	unsigned char timeout=0;
	int j=0;

	// initialize pa10 struct -allocate memory to the global 'C'-pack structs.
	if ( ! gp_pa10ResponsePackC)
        gp_pa10ResponsePackC=(pa10ResponsePackC*)malloc(sizeof(pa10ResponsePackC));
    if ( ! gp_pa10CommandPackC )
        gp_pa10CommandPackC=(pa10CommandPackC*)malloc(sizeof(pa10CommandPackC));

	for(j=0;j<7;j++){
		gp_pa10CommandPackC->velocity[j]=0;
		gp_pa10CommandPackC->torque[j]=0;
	}

	//
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);//write, autoinc, page 0
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// Sender ID
	outb(PA10_ARC_ID,g_pci22base+4);// Destination ID
	outb(252,g_pci22base+4);// adress of sequence no byte in package (implies) short package

	outb(252,g_pci22base+3);// jump to data section (starts at adress of sequence no byte)
	outb(g_PA10packet_serialno++,g_pci22base+4);
	outb('M',g_pci22base+4);// TYPE
	outb(driver_no,g_pci22base+4);// Driver no
	outb(0x00,g_pci22base+4);//

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_T(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=200;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_T(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}


  return 1;
} // send_M


/* old send C0
// Send a neutral 'C' packet (all velocities = 0) to the PA10 controller
// this will trigger a 'C response packet from the controller  wich contains the current position of the joints
int pa10_send_C0(void){
  uint8_t tmp,b1,b2,b3,b4,b5;
  uint8_t timeout=0;

  b1=0x02;
  b3=0x00;b2=0x00; // torque H-L order
  b5=0x00;b4=0x00; // speed  H-L order (forward)

  // Construct packet data in the internal memory of the COM20020
  gARC->hiadr=0x40; //write, autoinc, page 1
  gARC->loadr=0;
  gARC->data=IP_ARC_ID;   // SID
  gARC->data=PA10_ARC_ID;   // DID (0xFE  = servocontroller)
  gARC->data=219;   // adress of sequence no byte in package
  gARC->loadr=219;
  gARC->data=g_PA10packet_serialno++;      //sequence no
  gARC->data='C';   // This is a control packet

  for(tmp=0;tmp<7;tmp++){
    gARC->data=b1; //byte 1 bitmask
    gARC->data=b2; //byte 2 trq command byte 1 (L)
    gARC->data=b3; //byte 3 trq command byte 2 (H)
    gARC->data=b4; //byte 4 joint spd command byte 1 (L)
    gARC->data=b5; //byte 5 joint spd command byte 1 (H)
  }

  gARC->dstatus_command=0x03; // enable transmit fra page 0, zero offset

  // Check to se if the packet has been transmitted and acknowledget
  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x01) && timeout);
  if (!timeout) {printf("pa10_send_C(): Transmit complete TIMEOUT\n"); return(0);}

  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x02) && timeout);
  if (!timeout) {printf("pa10_send_C(): Transmit completed, but acknowledge TIMEOUT\n"); return(0);}

  return(1);
}
*/

/* send a command packet to the PA10 */
/* the velocity command is read from the global struct pointer gp_pa10CommandPackC*/
int pa10_send_C0(void){

  	unsigned char tmp,b1,b2,b3,b4,b5;
	int timeout = 0;

  	b1=0x02;
  	b3=0x00;b2=0x00; // torque H-L order
 	b5=0x00;b4=0x00; // speed  H-L order (forward)
	int j;

	//write to com20022
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// SID
	outb(PA10_ARC_ID,g_pci22base+4);// DID
	outb(219,g_pci22base+4);// adress of sequence no byte in package
	outb(219,g_pci22base+3);// ADDRESS PTR LOW
	outb(g_PA10packet_serialno++,g_pci22base+4);//sequence no
	outb('C',g_pci22base+4);// This is a control packet

	for(j=0;j<7;j++){
		outb(b1,g_pci22base+4);// spd, brake off, servo on
		outb(b2,g_pci22base+4);//byte 2 trq command byte 1 (L)
		outb(b3,g_pci22base+4);//byte 3 trq command byte 2 (H)
		outb(b4,g_pci22base+4);//byte 4 joint spd command byte 1 (L)
		outb(b5,g_pci22base+4);//byte 5 joint spd command byte 1 (H)
	}

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=100;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_C0(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=100;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_C0(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}

	return 1;
}

int pa10_send_C0_X(void){

  	unsigned char tmp,b1,b2,b3,b4,b5;
	int timeout = 0;

  	b1=0x02;
  	b3=0x00;b2=0x00; // torque H-L order
 	b5=0x00;b4=0x00; // speed  H-L order (forward)
	int j;

	//write to com20022
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// SID
	outb(PA10_ARC_ID,g_pci22base+4);// DID
	outb(219,g_pci22base+4);// adress of sequence no byte in package
	outb(219,g_pci22base+3);// ADDRESS PTR LOW
	outb(g_PA10packet_serialno++,g_pci22base+4);//sequence no
	outb('C',g_pci22base+4);// This is a control packet

	for(j=0;j<7;j++){
		outb(b1,g_pci22base+4);// spd, brake off, servo on
		outb(b2,g_pci22base+4);//byte 2 trq command byte 1 (L)
		outb(b3,g_pci22base+4);//byte 3 trq command byte 2 (H)
		outb(b4,g_pci22base+4);//byte 4 joint spd command byte 1 (L)
		outb(b5,g_pci22base+4);//byte 5 joint spd command byte 1 (H)
	}

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=100;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_C0(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=100;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_C0(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}

	return 1;
} // pa10_send_C0_X

/* old send C
// Sends a 'C' packet with a velocity command to the PA10 controller
// Warning: The robot will continue to move with the specified velocity until another 'C' packet is send
int pa10_send_C(short int vel[7]){
  uint8_t j,timeout;

  // Construct packet data in the internal memory of the COM20020
  gARC->hiadr=0x40; //write, autoinc, page 1
  gARC->loadr=0;
  gARC->data=IP_ARC_ID;   // SID
  gARC->data=PA10_ARC_ID;   // DID (0xFE  = servocontroller)
  gARC->data=219;   // adress of sequence no byte in package
  gARC->loadr=219;
  gARC->data=g_PA10packet_serialno++;      //sequence no
  gARC->data='C';   // This is a control packet

  for(j=0;j<7;j++){
    if (vel[j]!=0) gARC->data=0x02; // spd cmd, brake off servo on (0x02)
    if (vel[j]==0) gARC->data=0x02; // spd cmd, brake on servo off (0x01)
    gARC->data=0;   //byte 2 trq command byte 1 (L)
    gARC->data=0;   //byte 3 trq command byte 2 (H)
    gARC->data=(vel[j] & 0x00FF);          //byte 4 joint spd command byte 1 (L)
    gARC->data=((vel[j] >> 8) & 0x00FF);   //byte 5 joint spd command byte 1 (H)
  }

  gARC->dstatus_command=0x03; // enable transmit fra page 0, zero offset

  // Check to se if the packet has been transmitted and acknowledget
  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x01) && timeout);
  if (!timeout) {printf("pa10_send_C(): Transmit complete TIMEOUT\n"); return(0);}

  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x02) && timeout);
  if (!timeout) {printf("pa10_send_C(): Transmit completed, but acknowledge TIMEOUT\n"); return(0);}

  return(1);
}
*/

/* send a command packet to the PA10 */
/* the velocity command is read from the global struct pointer gp_pa10CommandPackC*/
int pa10_send_C(void){

	unsigned char timeout=0;
	int j;

	//write to com20022
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// SID
	outb(PA10_ARC_ID,g_pci22base+4);// DID
	outb(219,g_pci22base+4);// adress of sequence no byte in package
	outb(219,g_pci22base+3);// ADDRESS PTR LOW
	outb(g_PA10packet_serialno++,g_pci22base+4);//sequence no
	outb('C',g_pci22base+4);// This is a control packet

	for(j=0;j<7;j++){
		//outb(gp_pa10CommandPackC->servoCmdMask[j],g_pci22base+4);// spd, brake off, servo on
		outb(0x2,g_pci22base+4);// spd, brake off, servo on

		outb(0x0,g_pci22base+4);//byte 2 trq command byte 1 (L)
		outb(0x0,g_pci22base+4);//byte 3 trq command byte 2 (H)

		outb(gp_pa10CommandPackC->velocity[j] & 0x00FF,g_pci22base+4);//byte 4 joint spd command byte 1 (L)
		outb((gp_pa10CommandPackC->velocity[j] >> 8) & 0x00FF,g_pci22base+4);//byte 5 joint spd command byte 1 (H)
	}

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=100;do{usleep(100);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_C(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=100;do{usleep(100);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_C(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}


	return 1;
}



/* old send E
// Sends a 'E' packet to end controlmode to the PA10 controller
int pa10_send_E(void){
  uint8_t timeout = 0;

  //free the global structs since the control data stream is about to end TODO: move this to another function
  free(pRespC);
  free(pCmdC);

  // Construct packet data in the internal memory of the COM20020
  gARC->hiadr=0x40; //write, autoinc, page 0
  gARC->loadr=0;

  gARC->data=IP_ARC_ID;  // SID
  gARC->data=PA10_ARC_ID;  // DID (0xFE  = servocontroller)
  gARC->data=254;   // adress of sequence no byte in package (implys) short package

  gARC->loadr=254;  // jump to data section (starts at adress of sequence no byte)
  gARC->data=g_PA10packet_serialno++;
  gARC->data='E';   // TYPE

  gARC->dstatus_command=0x03; // enable transmit fra page 0, zero offset

  // Check to se if the packet has been transmitted and acknowledget
  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x01) && timeout);
  if (!timeout) {printf("pa10_send_E(): Transmit complete TIMEOUT\n"); return(0);}

  timeout=255;do{usleep(5);timeout--;}while(!(gARC->status_imask & 0x02) && timeout);
  if (!timeout) {printf("pa10_send_E(): Transmit completed, but acknowledge TIMEOUT\n"); return(0);}

  return(1);
}
*/

// send E packet
int pa10_send_E(void){
	unsigned char timeout = 0;

	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);//write, autoinc, page 0
	outb(0x0,g_pci22base+3);  // ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// SID
	outb(PA10_ARC_ID,g_pci22base+4);// DID
	outb(254,g_pci22base+4);// adress of sequence no byte in package (implys) short package
	outb(254,g_pci22base+4);// jump to data section (starts at adress of sequence no byte)
	outb(g_PA10packet_serialno++,g_pci22base+4);
	outb('E',g_pci22base+4);// TYPE

	outb(TX_P0,g_pci22base+1);/* enable transmit fra page 0, zero offset*/

	timeout=100;do{usleep(100);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_E(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=100;do{usleep(100);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_E(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}

  return 1;
}


int pa10_send_R(unsigned int jointNumber, unsigned int servo)
{
	unsigned char timeout=0;
	int j=0;

	// initialize pa10 struct -allocate memory to the global 'C'-pack structs.
	if ( ! gp_pa10ResponsePackC)
        gp_pa10ResponsePackC=(pa10ResponsePackC*)malloc(sizeof(pa10ResponsePackC));
    if ( ! gp_pa10CommandPackC )
        gp_pa10CommandPackC=(pa10CommandPackC*)malloc(sizeof(pa10CommandPackC));

	for(j=0;j<7;j++){
		gp_pa10CommandPackC->velocity[j]=0;
		gp_pa10CommandPackC->torque[j]=0;
	}

	//
	outb(COM20022_WRITEAUTO|0x0,g_pci22base+2);//write, autoinc, page 0
	outb(0x0,g_pci22base+3);// ADDRESS PTR LOW=0

	outb(IP_ARC_ID,g_pci22base+4);// Sender ID
	outb(PA10_ARC_ID,g_pci22base+4);// Destination ID
	outb(252,g_pci22base+4);// adress of sequence no byte in package (implies) short package

	outb(252,g_pci22base+3);// jump to data section (starts at adress of sequence no byte)
	outb(g_PA10packet_serialno++,g_pci22base+4);
	outb('R',g_pci22base+4);// TYPE
	outb(servo,g_pci22base+4);// Servo address
	outb(jointNumber*32,g_pci22base+4);// Read address

	outb(TX_P0,g_pci22base+1);// enable transmit fra page 0, zero offset

	timeout=250;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x01) && timeout);
	if (!timeout) {printf("pa10_send_R(): Transmit complete TIMEOUT\n"); return 0;}

	timeout=250;do{usleep(1);timeout--;}while(!(inb(g_pci22base)  & 0x02) && timeout);
	if (!timeout) {printf("pa10_send_R(): Transmit completed, but acknowledge TIMEOUT\n"); return 0;}


  return 1;
} // send_t
/* old get pa10response
// Function that waits for a response packet from the PA10 controller
// when a response is recieved, the global struct pRespC is updated
char get_PA10_response(void){
  uint8_t timeout,length,j;
  int black_hole;
  char response_type;
  int joint_angle_rv=0;

  gARC->dstatus_command=0x0c; //enable recieve to page 1

  // Wait for incomming packet
  timeout=255;do{usleep(1);timeout--;}while(!(gARC->status_imask & 0x80) && timeout);
  if(!timeout){printf("get_pa10_response(): TIMEOUT (status=0x%.2x)\n",gARC->status_imask);return(0);}

  // Read packet data from the internal memory of the COM20020
  gARC->hiadr=0xc2; // read, autoinc, page 1
  gARC->loadr=0x00;
  black_hole=gARC->data; //sid
  black_hole=gARC->data; //did
  length=gARC->data;
  gARC->loadr=length;
  pRespC->serialNo=gARC->data;
  switch(gARC->data){
  case 'S': // start control sequence response
    response_type='S';
    break;

  case 'E': // end control sequence response
    response_type='E';
    break;

  case 'C': // control packet response
    response_type='C';
    for(j=0;j<7;j++){
      pRespC->servoStatus[j] = gARC->data | (gARC->data << 8);

      //calculate angle
      joint_angle_rv=((int)(gARC->data | gARC->data << 8 | gARC->data << 16 | gARC->data << 24 ));
      pRespC->jntAngleDeg[j]=joint_angle_rv*(double)0.0004394531250;
      pRespC->jntAngleRad[j]=joint_angle_rv*(double)7.669903939e-6;

      //calculate torque
      pRespC->jntTorque[j]=(double)((int)(gARC->data | (gARC->data << 8)));
      pRespC->jntTorque[j]=pRespC->jntTorque[j]/1000; // 0.001 Nm / digit
    }
    pRespC->servoDriverStatus=gARC->data | (gARC->data << 8);
    break;

  default:
    printf("get_pa10_response(): Unrecognized packet recieved from PA10\n");
    response_type=0;
    break;
  }
  return(response_type);
}
*/


char get_PA10_response(void){
	unsigned char length,j;
	unsigned char timeout;
	int black_hole;
	char response_type, i;
	int joint_angle_rv=0;
	int angle_limit_positive=0, angle_limit_negative=0, mech_offset=0, poles=0, recv=0;

	outb(RX_P1,g_pci22base+1);
	//usleep(5); //wait

	timeout=255;do{usleep(4);timeout--;}while(!(inb(g_pci22base) & 0x80) && timeout);
	if (timeout==0) {printf("get_pa10_response(): TIMEOUT\n");return 0;}

	//printf("timeout value = %i\n",timeout);

	//outb(0xC2,g_pci22base+2); // ADDRESS PTR HIGH=2, read, autoinc
	outb(COM20022_READAUTO|0x02,g_pci22base+2); // Page1, read, autoinc

	outb(0x0,g_pci22base+3);  // ADDRESS PTR LOW=0

	black_hole=inb(g_pci22base+4);//printf("SID = %x\n",inb(g_pci22base+4));//sid
	//printf("SID = %x\n",inb(g_pci22base+4));
	black_hole=inb(g_pci22base+4);//printf("DID = %x\n",inb(g_pci22base+4));//did
	//printf("DID = %x\n",inb(g_pci22base+4));

	length=inb(g_pci22base+4);
	//printf("length = %x\n",length);

	outb(length,g_pci22base+3); //Address Low = length is where the data starts

	gp_pa10ResponsePackC->serialNo=inb(g_pci22base+4);
	//printf("serial no = %i\n",inb(g_pci22base+4));


	response_type=inb(g_pci22base+4);
	printf("type = %c\n",response_type);

	switch(response_type){
	    case 'R':
            printf("R received length %d\n",length);
            printf("Servo: 0x%x\n", inb(g_pci22base+4));
            printf("Data start: 0x%x\n", inb(g_pci22base+4));
            for (i = 2; length+i < 254; i+=2)
            {
                recv = inb(g_pci22base+4)| (inb(g_pci22base+4)<<8);
                printf("word %i: 0x%x\n", (i-2)/2+1, recv);
                switch ((i-2)/2+1)
                {
                    case 19:
                        // Software angle limit H_WORD
                        angle_limit_positive = (recv<<16);
                    break;
                    case 20:
                        // Software angle limit H_WORD
                        angle_limit_positive |= recv;
                    break;
                    case 21:
                        // Software angle limit H_WORD
                        angle_limit_negative = (recv<<16);
                    break;
                    case 22:
                        // Software angle limit H_WORD
                        angle_limit_negative |= recv;
                    break;
                    case 23:
                        // L_WORD
                        mech_offset = recv;
                    break;
                    case 24:
                        // H_WORD
                        mech_offset |= (recv<<16);
                    break;
                    case 28:
                        poles = recv;
                    break;

                    //

                }
            }
            //printf("Angle postive: %lf", (360.0*angle_limit_positive*(poles/2))/65536.0);
            printf("Angle postive: %lf\n", (360.0*angle_limit_positive*4)/(65536.0*50));
            printf("Angle negative: %lf\n", (360.0*angle_limit_negative*4)/(65536.0*50));
            printf("Mechanical zero point offset: %lf\n", (360.0*mech_offset*4)/(65536.0*50));

            break;
		case 'S': // start control sequence response
			//response_type='S';
			break;

		case 'E': // end control sequence response
			//response_type='E';
			break;

		case 'M': // end control sequence response
            printf("M package\n");
			//response_type='M';
			break;

		case 'T': // end control sequence response
			//response_type='M';
			break;

		case 'C': // control packet response
			//response_type='C';
			for(j=0;j<7;j++){
				gp_pa10ResponsePackC->servoStatus[j] = inb(g_pci22base+4)|(inb(g_pci22base+4) << 8);

				//calculate angle
				joint_angle_rv = ((int)(inb(g_pci22base+4) | inb(g_pci22base+4) << 8 | inb(g_pci22base+4) << 16 | inb(g_pci22base+4) << 24 ));

				//gp_pa10ResponsePackC->jntAngleRV[j]=joint_angle_rv;
				gp_pa10ResponsePackC->jntAngleDeg[j]=joint_angle_rv*(double)0.0004394531250;
				gp_pa10ResponsePackC->jntAngleRad[j]=joint_angle_rv*(double)7.669903939e-6;

				//calculate torque
				gp_pa10ResponsePackC->jntTorque[j] = (double)((int)(inb(g_pci22base+4) | (inb(g_pci22base+4) << 8)));
				gp_pa10ResponsePackC->jntTorque[j] = gp_pa10ResponsePackC->jntTorque[j]/1000; // 0.001 Nm / digit
			}
			gp_pa10ResponsePackC->servoDriverStatus = inb(g_pci22base+4) | (inb(g_pci22base+4) << 8);

			break;

		default:
			printf("get_pa10_response(): Unknown reponse type '%c' (%x) recieved from PA10 lowlevel controller\n",response_type,response_type);
			exit(0);
			break;
	}

	return(response_type);
} /* get_pa10_response */

char print_PA10_response(void){
	unsigned char length,j;
	unsigned char timeout;
	int black_hole;
	char response_type;
	int joint_angle_rv=0;

	outb(RX_P1,g_pci22base+1);
	usleep(5); //wait

	timeout=100;do{usleep(1);timeout--;}while(!(inb(g_pci22base) & 0x80) && timeout);
	if (!timeout) {printf("get_pa10_response(): TIMEOUT");return 0;}

	//outb(0xC2,g_pci22base+2); // ADDRESS PTR HIGH=2, read, autoinc
	outb(COM20022_READAUTO|0x02,g_pci22base+2); // Page1, read, autoinc

	outb(0x0,g_pci22base+3);  // ADDRESS PTR LOW=0

	printf("SID = %x\n",inb(g_pci22base+4));//sid
	printf("DID = %x\n",inb(g_pci22base+4));//did

	length=inb(g_pci22base+4);
	printf("length = %x\n",length);
	outb(length,g_pci22base+3); //Address Low = length is where the data starts

	printf("serial no = %x\n",inb(g_pci22base+4));

	response_type=inb(g_pci22base+4);
	printf("response type %x ('%c')\n",response_type,response_type);

	for(j=0;j<7;j++){
		int status_l = inb(g_pci22base+4)|(inb(g_pci22base+4) << 8);
		gp_pa10ResponsePackC->servoStatus[j] = status_l;
		//calculate angle
		joint_angle_rv = ((int)(inb(g_pci22base+4) | inb(g_pci22base+4) << 8 | inb(g_pci22base+4) << 16 | inb(g_pci22base+4) << 24 ));

		//gp_pa10ResponsePackC->jntAngleRV[j]=joint_angle_rv;
		printf("joint %i status 0x%x angle = %f deg",j,status_l, joint_angle_rv*(double)0.0004394531250);
		printf("  %f rad\n",joint_angle_rv*(double)7.669903939e-6);

		//calculate torque
		gp_pa10ResponsePackC->jntTorque[j] = (double)((int)(inb(g_pci22base+4) | (inb(g_pci22base+4) << 8)));
		gp_pa10ResponsePackC->jntTorque[j] = gp_pa10ResponsePackC->jntTorque[j]/1000; // 0.001 Nm / digit
	}
	gp_pa10ResponsePackC->servoDriverStatus = inb(g_pci22base+4) | (inb(g_pci22base+4) << 8);

	return(response_type);
} /* get_pa10_response */

// Function that moves the PA10 arm to the specified angle in degrees
int pa10_setpos_deg(double tgt_ang[7]){

	unsigned char j;
	char response_type;

	//Get current joint angles from the PA10 controller
	pa10_send_C0();
	response_type=get_PA10_response();

	if( response_type != 'C' ){
		printf("setpos_deg(): unexpected response %x '%c'\n",response_type,response_type);
		return(1);
	}

	// Calculate the direction to zero for each joint of the PA10, and set the velocity we want to move the joints with
	for(j=0;j<7;j++){
		if (gp_pa10ResponsePackC->jntAngleDeg[j]>tgt_ang[j]) gp_pa10CommandPackC->velocity[j]=-100;
		else if(gp_pa10ResponsePackC->jntAngleDeg[j]<tgt_ang[j]) gp_pa10CommandPackC->velocity[j]=100;
	}

	// Loop until all joints are at approx. the specified angle
	while( gp_pa10CommandPackC->velocity[0] || gp_pa10CommandPackC->velocity[1] || gp_pa10CommandPackC->velocity[2] || gp_pa10CommandPackC->velocity[3] || gp_pa10CommandPackC->velocity[4] || gp_pa10CommandPackC->velocity[5] || gp_pa10CommandPackC->velocity[6] ){

		// Send a 'C' packet to the PA10 controller with a velocity command, and get the response
		pa10_send_C();

		// Check for each joint of the PA10 if the target angle has been reached, and if so then set joint velocity to zero
		for(j=0;j<7;j++){
			if(gp_pa10CommandPackC->velocity[j]>0 && gp_pa10ResponsePackC->jntAngleDeg[j]>tgt_ang[j]) gp_pa10CommandPackC->velocity[j]=0;
			if(gp_pa10CommandPackC->velocity[j]<0 && gp_pa10ResponsePackC->jntAngleDeg[j]<tgt_ang[j]) gp_pa10CommandPackC->velocity[j]=0;
		}
	}

	return(1);
}
/* Write and read back a sequence of bytes to the com20022 ARC net chip internal memory */
/* Output: 1=test successful 0=test failed     */
int test_com20022_imem(void){

	int i=0;
	int error0=0;
	int error_count0=0;
	int error1=0;
	int error_count1=0;
	//char testbytes[15]={'t','e','s','t','s','u','c','c','e','s','s','w','w','w','i'};
	char testbytes[15]={'t','j','w','u','d','u','g','y','q','q','q','w','w','w','i'};

	/* Sanity check */
	if (g_pci22base==0){
		printf("test_com20022_imem() : baseaddress not initialized !!! ");
		return 0;
	}

	/*write to page 0*/
	outb(0x0|COM20022_WRITEAUTO,g_pci22base+2);
	outb(0x0,g_pci22base+3);
	for (i=0;i<15;i++) outb(testbytes[i],g_pci22base+4);

	/*write to page 1*/
	outb(0x2|COM20022_WRITEAUTO,g_pci22base+2);
	outb(0x0,g_pci22base+3);
	for (i=0;i<15;i++) outb(testbytes[i],g_pci22base+4);

	/*read from page 0*/
	outb(0x0|COM20022_READAUTO,g_pci22base+2); /*read from page 0*/
	outb(0x0,g_pci22base+3);
	for (i=0;i<15;i++){
		if (inb(g_pci22base+4) != testbytes[i]){
			error0=1;
			error_count0++;
		}
	}

	if (error0!=0) printf("test_com20022_imem() : [ERROR] %i errors reading from com20022 internal memory page 0\n",error_count0);
	else printf("test_com20022_imem() : [GOOD] com20022 internal memory page 0 is good to go\n");

	/*read from page 1*/
	outb(0x2|COM20022_READAUTO,g_pci22base+2); /*read from page 1*/
	outb(0x0,g_pci22base+3);
	for (i=0;i<15;i++){
		if (inb(g_pci22base+4) != testbytes[i]){
			error1=1;
			error_count1++;
		}
	}

	if (error1!=0) printf("test_com20022_imem() : [ERROR] %i errors reading from com20022 internal memory page 1\n",error_count1);
	else printf("test_com20022_imem() : [GOOD] com20022 internal memory page 1 is good to go\n");

	if ( (error0!=0) || (error1!=0) ) return 0;
	else return 1;

}

