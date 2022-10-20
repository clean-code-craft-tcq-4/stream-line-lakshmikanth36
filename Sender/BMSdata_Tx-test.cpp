#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Generate_BMS_Data.h"

#include <stdlib.h>
#include <math.h>

int BMS_fileDirectory[2];

sensorValue sensorData = {{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
                          {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}};

TEST_CASE("Generate BMS temperature and soc data") {
    GenerateSensorData(sensorData);
    
    for(int i=0; i<MAX_VALUE; i++)
    {
        	REQUIRE(sensorData.Temperature[i] != '\0');
        	REQUIRE(sensorData.Soc[i] != '\0');
    }
}

TEST_CASE("config PIPE for data Tx") {
    int isPIPEconfigured = config_PIPE(sensorData);
  
    REQUIRE(isPIPEconfigured == TRUE);
}
