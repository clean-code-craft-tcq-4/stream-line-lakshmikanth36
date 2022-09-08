#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE   50
#define TEMP_RANGE  50
#define SOC_RANGE   50
#define CHAR_MAX    256
#define DATA_OK     0 
#define DATA_NOT_OK 1

typedef struct {
	int Temperature[MAX_VALUE];
	int Soc[MAX_VALUE];
} sensorValue;

int GenerateSensorData(int datasize,sensorValue *sensorData);
void DisplayToConsole(char* buffer);
