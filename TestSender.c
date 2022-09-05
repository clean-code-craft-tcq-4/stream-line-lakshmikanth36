#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sensorData;
int i,count=0;
#define MAX_VALUE 5
int Temperature[MAX_VALUE];
int Soc[MAX_VALUE];
int Generate_SensorData()
{
    for(i=0;i<MAX_VALUE;i++)
    {
    Temperature[i] = rand()%50;
    Soc[i] = rand()%50;
    printf("sendorData_Temperature=%d sendorData_Soc=%d, \n",Temperature[i],Soc[i]);
    }
    return 0;
}

int main()
{
    Generate_SensorData();
    return 0;
}
