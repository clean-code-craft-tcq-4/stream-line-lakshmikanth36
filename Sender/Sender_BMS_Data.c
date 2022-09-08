#include "Sender_BMS_Data.h"

int DisplayToConsole(char* buffer)
{
	int flag=0;
	if(buffer!=0)
	{
	flag=1;
	printf("%s",buffer);
	}
	return flag;
}
int GenerateSensorData(int Datasize,sensorValue *sensorData)
{
    char buffer[CHAR_MAX] = {0};
    if((Datasize > 0) && (sensorData!=NULL))
    {
        for(int i=0;i<Datasize;i++)
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
