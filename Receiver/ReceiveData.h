#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE   50

#define MAXSENSORCNT   2
#define LENGTH_OF_BMSDATA         8
#define MAX_NOOF_RECEIVED_BMSDATA  (MAXSENSORCNT * MAX_VALUE * LENGTH_OF_BMSDATA)

void Receiver(int file_directory[]);
