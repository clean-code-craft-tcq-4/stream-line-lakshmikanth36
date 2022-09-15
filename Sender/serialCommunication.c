#include "Generate_BMS_Data.h"

int config_PIPE(int *tempFD)
{
	
	if(pipe(tempFD) == -1) {
		printf("an error occured with opening the pipe \n");
		
		return FALSE;
	}
	return TRUE;
}

int writeToFileDirectory(sensorValue *sensorData)
{
  	char dataArray[MAX_NOOF_BMSDATA];
	
	id = fork();
	memset(dataArray, '\0', MAX_NOOF_BMSDATA);
  	for (int dataIndex = 0; dataIndex < MAX_VALUE; dataIndex++) {
            char tempArray[MAX_VALUE];
            memset(tempArray, '\0', sizeof(tempArray));
            sprintf(tempArray, "%d,%d\n", sensorData->Temperature[dataIndex], sensorData->Soc[dataIndex]);
            strcat(dataArray, tempArray);
  	}
        
	if(id > FALSE)
	{
		sender(Temp_fileDirectory, dataArray, strlen(dataArray));
		return TRUE;
	}
	else
	{
	  //isDataSend_toPIPE = TRUE;
		return TRUE;
	}
	return FALSE;
}

void sender(int fd[], char senderdata[], int length)
{
  	close(fd[0]);
		
	write(fd[1], senderdata, len);
		
	close(fd[1]);
	printf("sender: %s",senderdata);
}
