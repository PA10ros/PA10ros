#ifndef _COM20022_h_
#define _COM20022_h_

#define IP_ARC_ID 0xFF		// Sender ID
#define PA10_ARC_ID 0xFE	// Destination ID		

#define COM20022_READ		0x80 // Prepare read from internal mem
#define COM20022_WRITE		0x00 // Prepare write to internal mem
#define COM20022_WRITEAUTO	0x40 // Autoincrement on
#define COM20022_READAUTO	0xC0 // Autoincrement on

#define TX_P0	0x03 // Enable transmit from page0
#define RX_P1	0x0c // Enable recieve to page 1

#define PCI22_PCI_VENDOR_ID 0x1571
#define PCI22_PCI_DEVICE_ID 0xa205

#endif
