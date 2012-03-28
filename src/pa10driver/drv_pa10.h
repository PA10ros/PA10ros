/* Functions to assmeble ARCnet packets for the Mitsubishi PA10 7DOF industrial robotic arm */

/* $Date: 2007/02/23 17:19:40 $ */
/* $Author: sredna $ */
/* $Revision: 1.2 $ */

#ifndef drv_pa10_h
#define drv_pa10_h

#include <stdio.h>
#include <unistd.h> // usleep()
#include <math.h>
#include <malloc.h>
#include <sys/io.h> // inb() and outb()
#include <stdlib.h> // exit()

// Defines
#define PRETTY_PRINT0 0
#define PRETTY_PRINT1 1
#define PRETTY_PRINT2 2
//pa10move()
#define DUMP_ANGLE_ON 1
#define DUMP_ANGLE_OFF 0

#define IP_ARC_ID 0xFF
#define PA10_ARC_ID 0xFE

extern int g_pci22base;

/*  Struct implementing the PA10 'C' response packet */
typedef struct{
  unsigned char serialNo;
  short int servoStatus[7];
  double jntAngleRad[7];
  double jntAngleDeg[7];
  double jntTorque[7];
  short int servoDriverStatus;
} pa10ResponsePackC;

/*  Struct implementing the PA10 'C' command packet */
typedef struct{
  unsigned char serialNo;
  unsigned char servoCmdMask[7];
  short int torque[7];
  short int velocity[7];
} pa10CommandPackC;

/* global variables  */
#ifdef drv_main

char *g_jointname[7]={"S1","S2","E1","E2","E3","W1","W2"};
unsigned char g_PA10packet_serialno = 0;

pa10ResponsePackC *gp_pa10ResponsePackC = 0; //Global pointer to the struct containing the newest 'C' response packet from the PA10 controller
pa10CommandPackC *gp_pa10CommandPackC = 0;	//Global pointer to the struct containing the newest 'C' command packet from the PA10 controller

double gjoint_angle_rad[7]={0,0,0,0,0,0,0}; // updated by get_PA10_response()
double gjoint_angle_deg[7]={0,0,0,0,0,0,0};
double gjoint_torque[7]={0,0,0,0,0,0,0};

#else
extern char *g_jointname[7];
extern unsigned char g_PA10packet_serialno;

extern pa10ResponsePackC *gp_pa10ResponsePackC; //Global pointer to the struct containing the newest 'C' response packet from the PA10 controller
extern pa10CommandPackC *gp_pa10CommandPackC;	//Global pointer to the struct containing the newest 'C' command packet from the PA10 controller

extern double gjoint_angle_rad[7];
extern double gjoint_angle_deg[7];
extern double gjoint_torque[7];

#endif

/*  Forward declarations */
int  pa10_send_S(void);
int  pa10_send_T(void);
int  pa10_send_M(char driverno);
int  pa10_send_C0(void);
int pa10_send_C0_X(void); // for misc. test, sending specific data
//int  pa10_send_C(short int vel[7]);
int  pa10_send_C(void);
//int  pa10_play_gnu(char *fileName);
//int  pa10_play_jnt(char *fileName);
int  pa10_send_E(void);
int pa10_send_R(unsigned int jointNumber, unsigned int servo);
//int  dump_pa10_packet(unsigned char pretty_print_level);
char get_PA10_response(void);
//void pa10sine(unsigned char dump_angle);
//void pa10sine2(unsigned char dump_angle);
int  pa10_setpos_deg(double angles[7]);
//int  pa10zero_pos(unsigned char dump_angle);
int test_com20022_imem(void);

#endif
