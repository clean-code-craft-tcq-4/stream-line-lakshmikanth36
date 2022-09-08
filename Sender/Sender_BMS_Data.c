#include "Sender_BMS_Data.h"

/********This Function will prints the battery parameters & displayed in console************************/
void DisplayToConsole(char* buffer)
{
	printf("%s",buffer);
}

/******* This Function will Generate battery parameter & process for display **************************/
int GenerateSensorData(int datasize,sensorValue *sensorData)
{
    char buffer[CHAR_MAX] = {0};
    if((datasize > 0) && (sensorData!=NULL))
    {
        for(int i=0;i<datasize;i++)
        {
        	sensorData->Temperature[i] = rand()%TEMP_RANGE;
        	sensorData->Soc[i] = rand()%SOC_RANGE;
        	sprintf(buffer,"%d,%d\n",sensorData->Temperature[i],sensorData->Soc[i]);
		DisplayToConsole(buffer);
        }
        return DATA_OK;
    }
    return DATA_NOT_OK;
}
