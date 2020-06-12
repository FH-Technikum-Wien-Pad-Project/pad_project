#include <time.h>
#include "displayLibrary.h"

int Logging(int wert)
{
    int stunden = 9;
    int minuten = 34;

    time_t stamp;
    time(&stamp);

	struct tm *myTm;
	myTm = localtime(&stamp);

    FILE *datei;
    char *dateiname="O2Log.txt";

    datei = fopen(dateiname, "ab");

    if(NULL == datei)
    {
        printf("\n-----------------------\n");
        printf("Error! Could not open %s", dateiname);
        printf("\n-----------------------\n");

        exit(-1);
    }
    else
    {
        fprintf(datei, "Wert: %3d%%\t|\tUhrzeit: %02d:%02d\n", wert, myTm->tm_hour, myTm->tm_min);
        download();
        printf("\n-----------------------\n");
        printf("Daten wurden eingetragen");
        printf("\n-----------------------\n");
    }
    fclose(datei);

    return 0;
}

void DeleteLog()
{

    FILE *datei_del;
    char *dateiname_del="O2Log.txt";

    remove(dateiname_del);
    printf("\n-----------------------\n");
    printf("Log geloescht!\n");
    printf("\n-----------------------\n");
}
