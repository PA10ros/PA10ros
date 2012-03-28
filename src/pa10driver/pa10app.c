/* Requires that the vme_universe kernel module is loaded (probably done automatically at boot) */

/* $Date: 2007/03/21 19:19:40 $ */
/* $Author: sredna $ */
/* $Revision: 1.2 $ */


#include "pa10app.h"
#include "drv_pa10.h"

void getEEPROM(void)
{
    pa10_send_R(0,1);
    get_PA10_response();
    pa10_send_R(1,1);
    get_PA10_response();

    pa10_send_R(0,2);
    get_PA10_response();
    pa10_send_R(1,2);
    get_PA10_response();

    pa10_send_R(0,3);
    get_PA10_response();
    pa10_send_R(1,3);
    get_PA10_response();

    pa10_send_R(0,4);
    get_PA10_response();
}
void breake_release(void)
{
    int i;
    char response_type;
    pa10_send_T();

    for(i=0; 100; i++)
    {
        pa10_send_C0();
        response_type=print_PA10_response();
        printf("%d response recieved %x ('%c')\n",i, response_type,response_type);
        usleep(500); 	// wait 500 uS
    }

    pa10_send_E();
}
void reset_mechanical_zero(void)
{
    char response_type;

    printf("send m... ");
	pa10_send_M(0x01);
	usleep(2000);
	response_type=get_PA10_response();
	pa10_send_M(0x02);
	usleep(2000);
	response_type=get_PA10_response();
	pa10_send_M(0x03);
	usleep(2000);
	response_type=get_PA10_response();
	pa10_send_M(0x00);
	usleep(2000);
	response_type=get_PA10_response();

}
int main(){

	unsigned char* ptr = NULL;
	double tgt_ang[7]={0,0,0,0,0,0,0}; // PA10 arm joint angles in degrees. (all zeroes means straight up in the air)
	char response_type;
	int j;
	unsigned int i;


	/* Detect the PCI22 ARCnet card on the PCI bus */
	detect_pci22();

	pci22_com20022init(0xff);
	test_com20022_imem();

    printf(" the char 'C' 'c' has hexcode %x %x \n",'C','c');

    //getEEPROM();

    //reset_mechanical_zero();

    //breake_release();

//return(0);
	/* ---  Example PA10 code ---  */

	// Send 'S' packet to get the PA10 controller in to control mode
//printf("send e... ");
//	pa10_send_E();

	//for(i=0; i<2000;i++)
    //    usleep(1000); 	// wait 100 uS

    pa10_send_S();
	response_type=get_PA10_response();
	printf("response recieved %x ('%c')\n",response_type,response_type);
	usleep(500); 	// wait 100 uS

    pa10_send_C0();
    print_PA10_response();

//return(0);
	// Get the current position of the PA10 arm
/*printf("send c0\n");
	pa10_send_C0();
	response_type=print_PA10_response();
	printf("response recieved %x ('%c')\n",response_type,response_type);
	usleep(100); 	// wait 100 uS
*/
	// Move the PA10 arm to specified postion in degrees
/**/
    for(i=0; i<7; i++)
    {
        int j;

        gp_pa10CommandPackC->velocity[i] = 350;

        for (j=0; j<1000; j++)
        {
            pa10_send_C();
            response_type=print_PA10_response();
            printf("%d response recieved %x ('%c')\n",i, response_type,response_type);
            usleep(500); 	// wait 500 uS
        }

        gp_pa10CommandPackC->velocity[i] = -350;

        for (j=0; j<1000; j++)
        {
            pa10_send_C();
            response_type=print_PA10_response();
            printf("%d response recieved %x ('%c')\n",i, response_type,response_type);
            usleep(500); 	// wait 500 uS
        }
        gp_pa10CommandPackC->velocity[i] = 0;

    }
/**/


	// End communications to the PA10 controller
	pa10_send_E();


	return(1);
}
