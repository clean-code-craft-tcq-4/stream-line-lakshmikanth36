#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "Rx_BMS_Data.h"

#include <stdlib.h>
#include <math.h>

int Rx_status = FALSE;
char Rx_BMSdata[MAX_NOOF_RECEIVED_BMSDATA] = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};

TEST_CASE("Read mock BMS data") {
    Rx_status = ReadData_From_Console(READ_FROM_MOCK_DATA,Rx_BMSdata);
    
    for(int BMSdata = 0; BMSdata < 200; BMSdata++)
    {
        REQUIRE(Rx_BMSdata[BMSdata] != '\0');
        REQUIRE(Rx_status == ACK_RX_DATA);
    }
}

TEST_CASE("Read real time data from PIPE: Test fails because Tx is not processed") {
    Rx_status = ReadData_From_Console(READ_FROM_PIPE,Rx_BMSdata);
    REQUIRE(Rx_status == NACK_RX_DATA);
}
