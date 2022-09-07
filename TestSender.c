#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE   50
#define TEMP_RANGE  50
#define SOC_RANGE   50
#define CHAR_MAX    256
#define DATA_OK     0 
#define DATA_NOT_OK 1
#define NULL        0

typedef struct {
	int Temperature[MAX_VALUE];
	int Soc[MAX_VALUE];
} sensorValue;

void DisplayToConsole(char* buffer)
{
	printf("%s",buffer);
}

int GenerateSensorData(int Datasize,sensorValue *sensorData)
{
    char buffer[CHAR_MAX] = {NULL};
    if(Datasize && (sensorData!=NULL))
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
    else
    {
        return DATA_NOT_OK;
    }
}


int main()
{
    sensorValue sensorData[MAX_VALUE];
    GenerateSensorData(MAX_VALUE,sensorData);
    return 0;
}
