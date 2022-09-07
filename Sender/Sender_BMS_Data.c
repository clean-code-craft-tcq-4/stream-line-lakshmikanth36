#include <stdio.h>
#include <stdlib.h>
#include "Sender_BMS_Data.h"

int GenerateSensorData(int Datasize,sensorValue *sensorData)
{
    char buffer[CHAR_MAX] = {0};
    if(Datasize && (sensorData!=NULL))
    {
        for(int i=0;i<Datasize;i++)
        {
        sensorData->Temperature[i] = rand()%TEMP_RANGE;
        sensorData->Soc[i] = rand()%SOC_RANGE;
        printf("%d,%d\n",sensorData->Temperature[i],sensorData->Soc[i]);
        }
     }
 }
