#ifndef _PCI22_H
#define _PCI22_H

#include <stdio.h>
#include <stdlib.h>
#include <pci/pci.h>
#include <sys/io.h>

#include "com20022.h"

int g_pci22base = 0;
int g_pci22dipswitch = 0;


int detect_pci22(void);
/* --- defines ---  */




#endif
