#ifndef displayLibrary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supportFunctionLibrary.h"
//definitions
#define SIZE 8
//ARRARYS

//functions
void inputError()
{
  //InputError - No signal comming from Sensor -
  //Display NI on 8x8 LedMatrix color red

  char ledMatrixInputError[SIZE][SIZE] =
  {
  {'-','-','-','-','-','-','-','-'},
  {'-','-','-','-','-','-','-','-'},
  {'-','-','-','-','-','-','-','-'},
  {'-','R','-','-','R','-','R','-'},
  {'-','R','R','-','R','-','R','-'},
  {'-','R','-','R','R','-','R','-'},
  {'-','R','-','-','R','-','R','-'},
  {'-','R','-','-','R','-','R','-'}
};
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      printf("%c", ledMatrixInputError[i][j]);
      printf("  ");
    }
    printf("\n");
  }
}

  


void download()
{
  char ledMatrixDownloadArrow[SIZE][SIZE] =
  {
  {'-','-','-','G','G','-','-','-'},
  {'-','-','-','G','G','-','-','-'},
  {'-','-','-','G','G','-','-','-'},
  {'G','-','-','G','G','-','-','G'},
  {'-','G','-','G','G','-','G','-'},
  {'-','-','G','G','G','G','-','-'},
  {'-','-','-','G','G','-','-','-'}
};
    for (size_t i = 0; i < SIZE; i++) {
      for (size_t j = 0; j < SIZE; j++) {
        printf("%c", ledMatrixDownloadArrow[i][j]);
        printf("  ");
      }
      printf("\n");
    }
  }
void zahlenAusgabe(int zahl)
  {
     
    int zahlLeft;
    int zahlRight;
    char leftArray[5][3];
    char rightArray[5][3];

    //Defining number Array for Matrix
    char displayNumberZero[5][3] = {{'O','O','O'}, {'O','-','O'},{'O','-','O'},{'O','-','O'},{'O','O','O'}};
    char displayNumberOne[5][3] = {{'-','-','O'}, {'-','-','O'},{'-','-','O'},{'-','-','O'},{'-','-','O'}};
    char displayNumberTwo[5][3] = {{'O','O','O'}, {'-','-','O'},{'O','O','O'},{'O','-','-'},{'O','O','O'}};
    char displayNumberThree[5][3] = {{'O','O','O'}, {'-','-','O'},{'-','O','O'},{'-','-','O'},{'O','O','O'}};
    char displayNumberFour[5][3] = {{'O','-','O'}, {'O','-','O'},{'O','O','O'},{'-','-','O'},{'-','-','O'}};
    char displayNumberFive[5][3] = {{'O','O','O'}, {'O','-','-'},{'O','O','O'},{'-','-','O'},{'O','O','O'}};
    char displayNumberSix[5][3] = {{'O','O','O'}, {'O','-','-'},{'O','O','O'},{'O','-','O'},{'O','O','O'}};
    char displayNumberSeven[5][3] = {{'O','O','O'}, {'-','-','O'},{'-','-','O'},{'-','-','O'},{'-','-','O'}};
    char displayNumberEight[5][3] = {{'O','O','O'}, {'O','-','O'},{'O','O','O'},{'O','-','O'},{'O','O','O'}};
    char displayNumberNine[5][3] = {{'O','O','O'}, {'O','-','O'},{'O','O','O'},{'-','-','O'},{'O','O','O'}};

    //Defining basic 8x8 Matrix
    char ledMatrix[SIZE][SIZE] =
    {
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'}
    };

  //Spliting number
    numberSplitFunction(zahl);
    zahlLeft =+ splitArray[0];
    zahlRight =+ splitArray[1];
    int *ptrL;
    int *ptrR;

  //Switch for left nummber
  switch (zahlLeft) {
  case 0:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberZero[i][j];
      }
    }
    break;
  case 1:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberOne[i][j];
      }
    }
    break;
  case 2:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberTwo[i][j];
      }
    }
    break;
  case 3:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberThree[i][j];
      }
    }
    break;
  case 4:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberFour[i][j];
      }
    }
    break;
  case 5:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberFive[i][j];
      }
    }
    break;
  case 6:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberSix[i][j];
      }
    }
    break;
  case 7:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberSeven[i][j];
      }
    }
    break;
  case 8:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberEight[i][j];
      }
    }
    break;
  case 9:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        leftArray[i][j] = displayNumberNine[i][j];
      }
    }
  default:
    printf("Error! Falsche eingabe!\n");
  }

  //Switch for right nummber
  switch (zahlRight) {
    case 0:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberZero[i][j];
      }
    }
    break;
  case 1:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberOne[i][j];
      }
    }
    break;
  case 2:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberTwo[i][j];
      }
    }
    break;
  case 3:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberThree[i][j];
      }
    }
    break;
  case 4:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberFour[i][j];
      }
    }
    break;
  case 5:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberFive[i][j];
      }
    }
    break;
  case 6:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberSix[i][j];
      }
    }
    break;
  case 7:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberSeven[i][j];
      }
    }
    break;
  case 8:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberEight[i][j];
      }
    }
    break;
  case 9:
    for (size_t i = 0; i < 5; i++) {
      for (size_t j = 0; j < 3; j++) {
        rightArray[i][j] = displayNumberNine[i][j];
      }
    }
  default:
    printf("Error! Falsche eingabe!\n");
  }

  //Ausgabe der fertigen Matrix
  for (size_t l = 0; l < 3; l++) {
    for (size_t m = 0; m < SIZE; m++) {
      printf("%c", ledMatrix[l][m]);
      printf("  ");
    }
    printf("\n");
  }
  for (size_t i = 0; i < 5; i++)
  {
    for (size_t o = 0; o < 2; o++) {
      printf("%c", ledMatrix[i][o]);
      printf("  ");
    }
    for (size_t j = 0; j < 3; j++)
    {
      printf("%c", leftArray[i][j]);
      printf("  ");
    }
    for (size_t k = 0; k < 3; k++)
    {
      printf("%c", rightArray[i][k]);
      printf("  ");
    }
    printf("\n");
  }
  }


void download()
{
  char ledMatrixDownloadArrow[SIZE][SIZE] =
  {
  {'-','-','-','G','G','-','-','-'},
  {'-','-','-','G','G','-','-','-'},
  {'-','-','-','G','G','-','-','-'},
  {'G','-','-','G','G','-','-','G'},
  {'-','G','-','G','G','-','G','-'},
  {'-','-','G','G','G','G','-','-'},
  {'-','-','-','G','G','-','-','-'}
};
    for (size_t i = 0; i < SIZE; i++) {
      for (size_t j = 0; j < SIZE; j++) {
        printf("%c", ledMatrixDownloadArrow[i][j]);
        printf("  ");
      }
      printf("\n");
    }
  }


void lowOxygen()
{
    //Array definieren
  char ledMatrixLowOxygen[SIZE][SIZE] =
  {
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-'},
    {'-','O','-','-','-','O','O','O'},
    {'-','O','-','-','-','O','-','O'},
    {'-','O','-','-','-','O','-','O'},
    {'-','O','-','-','-','O','-','O'},
    {'-','O','O','O','-','O','O','O'}
};
    //Array ausgeben
    for (size_t i = 0; i < SIZE; i++) {
      for (size_t j = 0; j < SIZE; j++) {
        printf("%c", ledMatrixLowOxygen[i][j]);
        printf("  ");
      }
      printf("\n");
    }

}

void lowOxygenAlarm()
{
  //Array definieren
  char ledMatrixLowOxygen[SIZE][SIZE] =
  {
    {'R','R','R','R','R','R','R','R'},
    {'R','R','-','-','-','-','R','R'},
    {'R','-','R','-','-','R','-','R'},
    {'R','-','-','R','R','-','-','R'},
    {'R','-','-','R','R','-','-','R'},
    {'R','-','R','-','-','R','-','R'},
    {'R','R','-','-','-','-','R','R'},
    {'R','R','R','R','R','R','R','R'}
};
  //Array Ausgeben
    for (size_t i = 0; i < SIZE; i++) {
      for (size_t j = 0; j < SIZE; j++) {
        printf("%c", ledMatrixLowOxygen[i][j]);
        printf("  ");
      }
      printf("\n");
    }
}

//Ende Library
#define displayLibrary
#endif
