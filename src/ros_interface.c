#include "ros_interface.h"
#include "drv_pci22.h"
#include "drv_pa10.h"
int isInitialized = 0;
char currentMode;


int pa10open(void)
{
  // Find pci card address
  detect_pci22(); // From drv_pci22.h

  // Test hardware
  pci22_com20022init(0xff); // From drv_pci22.h
  test_com20022_imem(); // From drv_pa10.h

  // Initialize buffers
  gp_pa10CommandPackC = (pa10CommandPackC)malloc(sizeof(pa10CommandPackC));
  gp_pa10ResponsePackC = (pa10ResponsePackC)malloc(sizeof(pa10ResponsePackC));
  currentMode = ' ';

  // Initialization done
  isInitialized = 1;

  // Return
  if (1 == isInitialized)
    {
      return 0;
    }
  else
    {
      return -1;
    }
}
int pa10close(void)
{
  // Deallocate mem
  free(gp_pa10CommandPackC);
  free(gp_pa10ResponsePackC);

  // Library is no longer initialized
  isInitialized = 0;

  return 0;
}

int pa10control(struct pa10controlmessage controlMessage)
{
  char response;
  pa10_send_E();
  currentMode = 'C';
  // Put into control mode
  pa10_send_S();

  // Copy content from controlMessage to gp_pa10CommandPackC
  gp_pa10CommandPackC->servoCmdMask[0] = controlMessage.s1.state;
  gp_pa10CommandPackC->servoCmdMask[1] = controlMessage.s2.state;
  gp_pa10CommandPackC->servoCmdMask[2] = controlMessage.e1.state;
  gp_pa10CommandPackC->servoCmdMask[3] = controlMessage.e2.state;
  gp_pa10CommandPackC->servoCmdMask[4] = controlMessage.e3.state;
  gp_pa10CommandPackC->servoCmdMask[5] = controlMessage.w1.state;
  gp_pa10CommandPackC->servoCmdMask[6] = controlMessage.w2.state;

  gp_pa10CommandPackC->torque[0] = controlMessage.s1.torque;
  gp_pa10CommandPackC->torque[1] = controlMessage.s2.torque;
  gp_pa10CommandPackC->torque[2] = controlMessage.e1.torque;
  gp_pa10CommandPackC->torque[3] = controlMessage.e2.torque;
  gp_pa10CommandPackC->torque[4] = controlMessage.e3.torque;
  gp_pa10CommandPackC->torque[5] = controlMessage.w1.torque;
  gp_pa10CommandPackC->torque[6] = controlMessage.w2.torque;
  
  gp_pa10CommandPackC->speed[0] = controlMessage.s1.speed;
  gp_pa10CommandPackC->speed[1] = controlMessage.s2.speed;
  gp_pa10CommandPackC->speed[2] = controlMessage.e1.speed;
  gp_pa10CommandPackC->speed[3] = controlMessage.e2.speed;
  gp_pa10CommandPackC->speed[4] = controlMessage.e3.speed;
  gp_pa10CommandPackC->speed[5] = controlMessage.w1.speed;
  gp_pa10CommandPackC->speed[6] = controlMessage.w2.speed;


  // Send control package
  pa10_send_C();

  // Get response
  response  = get_PA10_response();

  if ('C' == response)
    {
      return 0;
    }
  else
    {
      return -1;
    }
}

pa10statusmessage pa10status(void)
{
  pa10statusmessage statusmessage;
  if ('T' == currentMode)
    {
      // breake release mode - lets update the status from the controller
      pa10_send_C0();
      get_pa10_response();
    }

  // Copy to local status msg
  statusmessage.s1.status = gp_pa10ResponsePackC->servoStatus[0];
  statusmessage.s2.status = gp_pa10ResponsePackC->servoStatus[1];
  statusmessage.e1.status = gp_pa10ResponsePackC->servoStatus[2];
  statusmessage.e2.status = gp_pa10ResponsePackC->servoStatus[3];
  statusmessage.e3.status = gp_pa10ResponsePackC->servoStatus[4];
  statusmessage.w1.status = gp_pa10ResponsePackC->servoStatus[5];
  statusmessage.w2.status = gp_pa10ResponsePackC->servoStatus[6];

  statusmessage.s1.angle = gp_pa10ResponsePackC->jntAngleDeg[0];
  statusmessage.s2.angle = gp_pa10ResponsePackC->jntAngleDeg[1];
  statusmessage.e1.angle = gp_pa10ResponsePackC->jntAngleDeg[2];
  statusmessage.e2.angle = gp_pa10ResponsePackC->jntAngleDeg[3];
  statusmessage.e3.angle = gp_pa10ResponsePackC->jntAngleDeg[4];
  statusmessage.w1.angle = gp_pa10ResponsePackC->jntAngleDeg[5];
  statusmessage.w2.angle = gp_pa10ResponsePackC->jntAngleDeg[6];

  statusmessage.s1.torque = gp_pa10ResponsePackC->jntTorque[0];
  statusmessage.s2.torque = gp_pa10ResponsePackC->jntTorque[1];
  statusmessage.e1.torque = gp_pa10ResponsePackC->jntTorque[2];
  statusmessage.e2.torque = gp_pa10ResponsePackC->jntTorque[3];
  statusmessage.e3.torque = gp_pa10ResponsePackC->jntTorque[4];
  statusmessage.w1.torque = gp_pa10ResponsePackC->jntTorque[5];
  statusmessage.w2.torque = gp_pa10ResponsePackC->jntTorque[6];

  return statusmessage;
}

void pa10breakerelease(void)
{
  pa10_send_E();
  currentMode = 'T';
  pa10_send_T();
}
