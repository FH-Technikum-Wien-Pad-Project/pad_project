#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "displayLibrary.h"
#include "hardwareLibrary.h"
#include "loggingLibrary.h"
#include "supportFunctionLibrary.h"

//WICHTIG!
//In diesem Program sind wurden die funktionen überprüft. Man kann die funktionsfähigkeit einzelner funktionen testen.
//Die main.c ist für den Programablauf zuständig und dient auch als tester für den Programablauf


//STRUCTURES
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
//CONSTANTS
#define SIZE 8
#define LOG 10
//VARIABLES
int a;
//ARRAYS
Logg array[10];
int Sp20Array[] = {80,82,83,84,85,86,85,84,85,86};

//PROTOTYPES
void numberSplitFunctionTest();
void displayLibraryTest();
void clockArray();

int main(void) {
  while (1) {
  printf("\n");
  printf("######################################\n");
  printf("--TESTER--\n");
  printf("What function or library would you like to test?\n");
  printf("[1] numberSplitFunction\n");
  printf("[2] displayLibrary\n");
  printf("[3] clockArray\n");
  printf("[Other number] = EXIT\n");
  printf("######################################\n");
  scanf("%d", &a);
    switch (a) {
      case 1:
        numberSplitFunctionTest();
        break;
      case 2:
        displayLibraryTest();
        break;
      case 3:
        clockArray();
        break;
      default:
        return 0;
        break;
    }
  }
}

void displayLibraryTest() {

  //Testing section for displayLibrary functions
  printf("\n");
  printf("######################################\n");
  printf("--TESTING SECTION FOR displayLibrary FUNCTIONS--\n");
  printf("\n");
  //Tests
      printf("--PROGRAM STATUS TEST--\n");
      printf("[1] = Normal\n");
      printf("[2]= inputError\n");
      printf("[3] = download\n");
      printf("[Other number] = EXIT\n");

    while (1<2) {
      int status;

      printf("Enter status number:  ");
      scanf("%d", &status);

      switch (status) {
        case 1:
          printf("Program Startup!\n");
          break;
        case 2:
          inputError();
          break;
        case 3:
          download();
          break;
        case 4:
          lowOxygen();
          break;
        case 5:
          lowOxygenAlarm();
          break;
        case 6:
          zahlenAusgabe(88);
        default:
          return;
          break;
      }
    }
    printf("\n");
    printf("######################################\n");
    printf("\n");
}

void numberSplitFunctionTest() {

    //Testing section for numberSplitFunction
    printf("\n");
    printf("######################################\n");
    printf("--TESTING SECTION FOR numberSplitFunction--\n");
    printf("\n");
    //Tests
    printf("Enter a number[00-99]: ");
    scanf("%d", &splitNumberVariable);

    numberSplitFunction(splitNumberVariable);
    for (size_t i = 0; i < 2; i++) {
      printf("%d", splitArray[i] );
    }
    printf("\n");
    printf("######################################\n");
    printf("\n");
}
/*
void clockArray() {

  int index = 0;
  int h;
  int m;
  int s;
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
  */
}
