#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "Rx_BMS_Data.h"

char receive_BMSdata[MAX_NOOF_RECEIVED_BMSDATA];

void Receiver(int file_directory[])
{
	memset(receive_BMSdata, '\0', MAX_NOOF_RECEIVED_BMSDATA);
		
	close(file_directory[1]);
		
	read(file_directory[0], receive_BMSdata, MAX_NOOF_RECEIVED_BMSDATA);
		
	close(file_directory[0]);
	//printf("Receiver: %s",receive_BMSdata);
}
