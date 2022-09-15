#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 	    1
#define FALSE       0

#define MAX_VALUE   50
#define TEMP_RANGE  50
#define SOC_RANGE   50
#define CHAR_MAX    256
#define DATA_OK     0 
#define DATA_NOT_OK 1

#define MAXSENSORCNT   2
#define BMSDATA         8
#define MAX_NOOF_BMSDATA  (MAXSENSORCNT * MAX_VALUE * BMSDATA)

typedef struct {
	int Temperature[MAX_VALUE];
	int Soc[MAX_VALUE];
} sensorValue;

sensorValue bmsData;

int Temp_fileDirectory[2];
int id; 

int GenerateSensorData(int datasize,sensorValue *sensorData);
void DisplayToConsole(char* buffer);
int config_PIPE(int *tempFD);
int writeToFileDirectory(sensorValue *sensorData);
void sender(int fd[], char senderdata[], int length);

