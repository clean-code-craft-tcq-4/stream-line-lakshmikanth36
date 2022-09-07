#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Sender/Sender_BMS_Data.h"

int main()
{
    sensorValue sensorData[MAX_VALUE];
    GenerateSensorData(MAX_VALUE,sensorData);
    return 0;
}
