#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Generate_BMS_Data.h"

#include <stdlib.h>
#include <math.h>

sensorValue sensorData;

TEST_CASE("Generate BMS temperature and soc data") {
    
    for(int i=0; i<MAX_VALUE; i++)
    {
        	sensorData.Temperature[i] = '\0';
        	sensorData.Soc[i] = '\0';
    }
    
    GenerateSensorData(sensorData);
    
    for(int i=0; i<MAX_VALUE; i++)
    {
        	REQUIRE(sensorData.Temperature[i] != '\0');
        	REQUIRE(sensorData.Soc[i] != '\0');
    }
    
    //REQUIRE(isDataGenerated == DATA_OK);
}
