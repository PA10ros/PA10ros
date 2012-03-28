/* Anders Boegild 2007 */ 
/* Scans the PCI bus for device and vendor id */
/* This is based on the example.c found in the 'pciutils' package by Martin Mares that implements userspace functions to scan the PCI bus for devices */
/* compile with -lpci  */
/* iopl() requires superuser priviledges when executing this program */



#include "drv_pci22.h"


/* --- Globals --- */
struct pci_access *pacc;
struct pci_dev *pci22_dev = NULL;



/* --- prototypes --- */
int pci22_com20022init(unsigned char nodeid);



/* --- implementations --- */
int detect_pci22(void){
  
  unsigned int c;
  char counter=0;

  
  pacc = pci_alloc();           /* Get the pci_access structure */
  
  pci_init(pacc);               /* Initialize the PCI library */
  pci_scan_bus(pacc);           /* We want to get the list of devices */


  /* Iterate over all PCI devices */
  for(pci22_dev=pacc->devices; pci22_dev; pci22_dev=pci22_dev->next){
    
    pci_fill_info(pci22_dev, PCI_FILL_IDENT | PCI_FILL_BASES); 
    
    // Detect the specified device
    if( (pci22_dev->vendor_id == PCI22_PCI_VENDOR_ID) && 
	(pci22_dev->device_id == PCI22_PCI_DEVICE_ID) 
	){
      break;
    }

  }
  if (pci22_dev==NULL){
    printf("\n\nERROR: PCI22 card not detected\n\n\n");
    exit(0);
  }


  printf("\n\nPCI22 card detected on %02x:%02x.%d\nVendorID=%04x DeviceID=%04x irq=%d\n",
	 pci22_dev->bus,pci22_dev->dev,
	 pci22_dev->func,pci22_dev->vendor_id,
	 pci22_dev->device_id,
	 pci22_dev->irq);


  printf("\n\n--- Baseaddresses ---\n");
  printf("BAR1 %x\n",pci22_dev->base_addr[0]);
  printf("BAR2 %x\n",pci22_dev->base_addr[1]);
  printf("BAR3 %x\n",pci22_dev->base_addr[2]);
  printf("BAR4 %x\n",pci22_dev->base_addr[3]);
  printf("BAR5 %x\n",pci22_dev->base_addr[4]);
  printf("BAR6 %x\n",pci22_dev->base_addr[6]);
  printf("\n");


  //printPCIDevice(pci22_dev);

/* The baseaddress of the COM20022 is at BAR2 */

//g_pci22dipswitch = pci22_dev->base_addr[1]; //Nonworking
g_pci22base = pci22_dev->base_addr[2];

  /* Close everything */
  pci_cleanup(pacc);

  return 0;
}


/* initialization from scratch, inspired by the initialization sequence described in the COM20022 datasheet p55-56*/
int pci22_com20022init(unsigned char nodeid)
{
	unsigned char tmp;

	iopl(3); //application must be executed as root

	//outb(0xff,0x378);

/* debugging */
//printf("g_pci22base is %x\n",g_pci22base);
//printf("nodeid is %x\n",nodeid);

	/* reading and writing to an odd register address on com20022 */
	/* makes the internal logic detect the interface type */
	outb(0,g_pci22base+3);		// ADDRESS PTR LOW = 0
	usleep(10);
	tmp=inb(g_pci22base+3);		// read ADDRESS PTR LOW
	usleep(10);

	/* perform soft reset */
	outb(0x80,g_pci22base+6); // CONFIGURATION: set reset bit
	usleep(10);
	outb(0x0,g_pci22base+6);  // CONFIGURATION: clear reset bit
	usleep(10);

	outb(0x2,g_pci22base+5);	// SUBADR: select SETUP1	
	usleep(10);
	outb(0x81,g_pci22base+7); // SETUP1: P1 mode, slowarb
	usleep(10);
	outb(0x4,g_pci22base+5); 	// SUBADR: select SETUP2	
	usleep(10);
	outb(0x1c,g_pci22base+7); // SETUP2: 40MHz, EF=1, NOSYNC=1, upto255 nodes
	usleep(60);
	outb(0x18,g_pci22base+1);	// COMMAND: restart core to enable 40MHz
	usleep(600);					// wait for PLL to stabilize
	outb(0x5,g_pci22base+5); 	// SUBADR: select BUSCONTROL	
	usleep(10);
	outb(0x0,g_pci22base+7); 	// BUSCONTROL: 8bit interface, no dma
	usleep(10);
	outb(0x1c,g_pci22base+6); // CONFIGURATION: BackPlane, ET1,ET2=1,1 TXEN=0
	usleep(10);
	outb(0x1,g_pci22base+5);	// SUBADR: select NODEID	
	usleep(10);
	outb(nodeid,g_pci22base+7); // NODEID: write nodeid (wakes up core)
	usleep(10);


	/* check if there is a token on the network and if there is a nodeid confict */
	tmp=inb(g_pci22base+1);	// STATUS: clear DUPID et. al. by reading register
	usleep(600);		// wait to ensure any possible doublicate ID is seen (max 840mS)
	tmp=inb(g_pci22base+1);	// STATUS: read valid DUPID flag et.al.   
	if(tmp & 0x20) printf("com20022_init() :[GOOD] There is activity on the network\n");
	else {printf("com20022_init() :[ERROR] There is no activity on the network\n");}
	if(tmp & 0x10) printf("com20022_init() :[GOOD] TOKEN detected\n");
	else {printf("com20022_init() :[ERROR] No TOKEN\n");}
	if(tmp & 0x40){printf("com20022_init() :[ERROR] Duplicate ID detected\n");}
	else printf("com20022_init() :[GOOD] No dublicate ID\n");

	/* check that com20020 is started properly */
	outb(0xC0,g_pci22base+2); // ADDRESS PTR HIGH=0, read, autoinc
	usleep(10);
	outb(0x0,g_pci22base+3);  // ADDRESS PTR LOW=0
	usleep(10);
	if((inb(g_pci22base+4) == 0xd1) && (inb(g_pci22base+4) == nodeid )) \
	printf("com20022_init() :[GOOD] COM20022 core is ready with ID=%3d\n",nodeid);
	else {printf("com20022_init() :[ERROR] signature bytes 0xd1 and %2x not found\n",nodeid);}

	/* enable transmitter and join the network */
	outb(0x3c,g_pci22base+6); // CONFIGURATION: BackPlane, ET1,ET2=1,1 TXEN=1
	usleep(10);

	/* good to go */
	return 1;

}
