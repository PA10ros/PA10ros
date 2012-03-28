#ifndef _PA10_INTERFACE
#def _PA10_INTERFACE

struct pa10controlaxismessage
{
  unsigned char state; // 1 Byte
  /*
   * Description of state byte:
   * bit 0: mechanical breake 1 = ON/ 0 = OFF
   * bit 1: servo 1 = ON / 0 = OFF
   * bit 2: torque/speed select. 1 = Torque, 0 = Speed
   * bit 3: emergency breake
   */
  short int torque; // 2 Bytes
  short int speed; // 2 Bytes
};
struct pa10controlmessage
{
  pa10controlaxismessage s1, s2, e1, e2, e3, w1, w2;
};
struct pa10statusaxismessage
{
  short int status; // 2 Bytes  - documented on page 63 in the operating manual
  double angle; // In degrees (from resolver)
  double torque; // (Current)
};
struct pa10statusmessage
{
  pa10statusaxismessage s1, s2, e1, e2, e3, w1, w2;
  short int driverstatus; // 2 Bytes - Needs documentation
};

int pa10open(void);



/*
 * Initialize pa10 interface
 * Returns: 0 on success, -1 on fail
 */

int pa10close(void);
/*
 * Close the pa10 interface
 * Returns: 0 on success, -1 on fail
 */

int pa10control(struct pa10controlmessage);
/*
 * Send control message to pa10 robot
 * Returns: 0 on success, -1 on fail
 */

pa10statusmessage pa10status(void);
/*
 * If the robot is in break release mode, this status is received from the robot when the function is called. Otherwise the latest reply from the control message is returned.
 */

void pa10breakerelease();
/*
 * Breake release mode.
 * This mode is exited by using the pa10control function.
 */

#endif
