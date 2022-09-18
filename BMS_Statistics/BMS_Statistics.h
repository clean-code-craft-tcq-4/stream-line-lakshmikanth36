#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define   MAX_RECEIVE_DATA   50

void BMSData_Statistics(char receive_BMSdata[], int datasize);
void movingAverage_of_BMSdata(int BatteryTempdata[], int BatterySOCdata[]);
void sortBmsData(int BatteryTempdata[], int BatterySOCdata[]);
void sortGivenIndexPosition(int *BatteryTempdata, int *BatterySOCdata, int noOfElements, int received_position);
void convertString_To_Int(char receive_BMSdata[], int len, int BatteryTempdata[], int BatterySOCdata[]);
void convertBatteryTempData_To_Int(int receive_BMSdata, int BatteryTempdata[], char BMSdata[], int BMSData_length);
void convertBatterySocData_To_Int(int receive_BMSdata, int BatterySOCdata[], char BMSdata[], int BMSData_length);

