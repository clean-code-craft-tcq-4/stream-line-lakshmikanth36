#include "Generate_BMS_Data.h"

int Temp_fileDirectory[2];
int id; 

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
  	char BMS_Data[MAX_NOOF_BMSDATA];
	
	id = fork();
	
	convertInt_To_String(BMS_Data, sensorData);
        
	if(id > FALSE)
	{
		sender(BMS_fileDirectory, BMS_Data, strlen(BMS_Data));
		return TRUE;
	}
	else
	{
	  //isDataSend_toPIPE = TRUE;
		return TRUE;
	}
	return FALSE;
}

void convertInt_To_String(char dataArray[], sensorValue *sensorData)
{
    memset(dataArray, '\0', MAX_NOOF_BMSDATA);
  	for (int dataIndex = 0; dataIndex < MAX_VALUE; dataIndex++) {
            char tempArray[LENGTH_OF_BMSDATA];
            memset(tempArray, '\0', sizeof(tempArray));
            sprintf(tempArray, "%d,%d\n", sensorData->Temperature[dataIndex], sensorData->Soc[dataIndex]);
            strcat(dataArray, tempArray);
  	}  
}

void sender(int fd[], char BMSdatas[], int length)
{
  	close(fd[0]);
		
	write(fd[1], BMSdatas, length);
		
	close(fd[1]);
	//printf("sender: %s",BMSdatas);
}
