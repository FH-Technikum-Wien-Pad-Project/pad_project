#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <termios.h>
#include "displayLibrary.h"
#include "hardwareLibrary.h"
#include "loggingLibrary.h"
#include "supportFunctionLibrary.h"

//CONSTANTS
#define SIZE 8
#define LOG 5

//STRUCTS
typedef struct
{
  int hour;
  int min;
  int sec;
} Time;

typedef struct
{
  Time time;
  int spO2;
  int altitude;
} Logg;

//VARIABLES

int h;
int m;
int s;
//ARRAYS
Logg array[LOG];
int Sp20Array[] = {100,99,98,97,96,95,94,93,92,91,90,90,90,90,89,88,87,86,85,85,84,83,82,81,80,79,78,77,76,75,74,73,72};
//PROTOTYPES

int main(void) {

      int index = 0;

      for (size_t i = 0; i < LOG; i++)
      {
        sleep(1);
        time_t s, val = 1;
        struct tm* current_time;
        s = time(NULL);
        current_time = localtime(&s);

        printf("[%d] %02d:%02d:%02d\n",
               index,
               current_time->tm_hour,
               current_time->tm_min,
               current_time->tm_sec);

               h =+ current_time->tm_hour;
               m =+ current_time->tm_min;
               s =+ current_time->tm_sec;

               array[index].time.hour = h;
               array[index].time.min = m;
               array[index].time.sec = s;
        index++;
      }
      printf("--FLIGHT LOGG--\n");
      printf("################################\n");
      printf("[Time]       [SpO2]        [QNH]\n");
      printf("--------------------------------\n");
      for (size_t i = 0; i < LOG; i++) {
          printf("%02d:%02d:%02d  --  ", array[i].time);
          printf("%d%%  --    ", Sp20Array[i]);
          printf("N/A\n");
      }
}
