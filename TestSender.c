#include <assert.h>
#include "Sender/Generate_BMS_Data.h"
int main()
{
    sensorValue sensorData[MAX_VALUE];
    assert(GenerateSensorData(sensorData)==0);
    assert(GenerateSensorData(NULL)==1);
    return 0;
}

