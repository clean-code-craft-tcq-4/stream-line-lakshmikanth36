#include <assert.h>
#include "Sender/Sender_BMS_Data.h"
int main()
{
    sensorValue sensorData[MAX_VALUE];
    assert(GenerateSensorData(MAX_VALUE,sensorData)==0);
    assert(!GenerateSensorData(MAX_VALUE,NULL));
    assert(!GenerateSensorData(-1,NULL));
    return 0;
}
