#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "BMS_Statistics.h"

#include <stdlib.h>
#include <math.h>

#define MAXSENSORCNT   2
#define LENGTH_OF_BMSDATA         8
#define MAX_NOOF_RECEIVED_BMSDATA  (MAXSENSORCNT * MAX_VALUE * LENGTH_OF_BMSDATA)

char Received_BMSdata[MAX_NOOF_RECEIVED_BMSDATA] = {"33,36\n27,15\n43,35\n36,42\n49,21\n12,27\n40,9\n13,26\n40,26\n22,36\n11,18\n17,29\n32,30\n12,23\n17,35\n29,2\n22,8\n19,17\n43,6\n11,42\n29,23\n21,19\n34,37\n48,24\n15,20\n13,26\n41,30\n6,23\n12,20\n46,31\n5,25\n34,27\n36,5\n46,29\n13,7\n24,45\n32,45\n14,17\n34,14\n43,0\n37,8\n26,28\n38,34\n3,1\n4,49\n32,10\n26,18\n39,12\n26,36\n44,39\n"};

int convertedTempdata[MAX_RECEIVE_DATA] = {33,27,43,36,49,12,40,13,40,22,11,17,32,12,17,29,22,19,43,11,29,21,34,48,15,13,41,6,12,46,5,34,36,46,13,24,32,14,34,43,37,26,38,3,4,32,26,39,26,44};
int convertedSOCdata[MAX_RECEIVE_DATA] = {36,15,35,42,21,27,9,26,26,36,18,29,30,23,35,2,8,17,6,42,23,19,37,24,20,26,30,23,20,31,25,27,5,29,7,45,45,17,14,0,8,28,34,1,49,10,18,12,36,39};

int SortedTempdata[MAX_RECEIVE_DATA] = {3,4,5,6,11,11,12,12,12,13,13,13,14,15,17,17,19,21,22,22,24,26,26,26,27,29,29,32,32,32,33,34,34,34,36,36,37,38,39,40,40,41,43,43,43,44,46,46,48,49};
int SortedSOCdata[MAX_RECEIVE_DATA] = {0,1,2,5,6,7,8,8,9,10,12,14,15,17,17,18,18,19,20,20,21,23,23,23,24,25,26,26,26,27,27,28,29,29,30,30,31,34,35,35,36,36,36,37,39,42,42,45,45,49};

int BatteryTempdata[MAX_RECEIVE_DATA];
int BatterySOCdata[MAX_RECEIVE_DATA];
int AvgofTemp = 0, AvgofSOC = 0;


TEST_CASE("converting BMS string data into init which is received through PIPE") {
    convertString_To_Int(receive_BMSdata, MAX_NOOF_RECEIVED_BMSDATA, BatteryTempdata, BatterySOCdata);

    for(int BMSdata = 0; BMSdata < MAX_RECEIVE_DATA; BMSdata++)
    {
      REQUIRE(BatteryTempdata[BMSdata] == convertedTempdata[BMSdata]);
      REQUIRE(BatterySOCdata[BMSdata] == convertedSOCdata[BMSdata]);
    }
}

TEST_CASE("Moving average of BMS temperature data") {
    AvgofTemp = movingAverage_of_Tempdata(BatteryTempdata);
    
    REQUIRE(AvgofTemp == 33);
}

TEST_CASE("Moving average of BMS SOC data") {
    AvgofTemp = movingAverage_of_SOCdata(BatterySOCdata);
    
    REQUIRE(AvgofTemp == 23);
}

TEST_CASE("Get BMS min and max temp and soc data") {
    sortBmsData(BatteryTempdata, BatterySOCdata);
    
    REQUIRE(BatteryTempdata[0] == SortedTempdata[0]);
    REQUIRE(BatteryTempdata[MAX_RECEIVE_DATA] == SortedTempdata[MAX_RECEIVE_DATA-1]);
    
    REQUIRE(BatterySOCdata[0] == SortedSOCdata[0]);
    REQUIRE(BatterySOCdata[MAX_RECEIVE_DATA] == SortedSOCdata[MAX_RECEIVE_DATA-1]);
}


