#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "displayLibrary.h"
//#include "Schnittstelle.h"
#include "LogO2.h"

int main()
{
    int wert = 0;
    int auswahl;
    int an = true;

    while(an = true)
    {
        printf("\n-----------------------\n");
        printf("Bitte Funktion waehlen [1-4]: ");
        scanf("%d", &auswahl);
        printf("-----------------------\n");


        switch(auswahl)
        {
            case 1:
                printf("\n-----------------------\n");
                printf("Flug starten!");
                printf("\n-----------------------\n");

                //wert = verbindung();

                if(wert == -1)
                {
                    inputError();
                    exit(-1);
                }
                else
                {
                    zahlenAusgabe(wert);
                    //funktionsaufruf Display
                    Logging(wert);

                    if(wert <= 95 && wert > 90)
                    {
                        lowOxygen();
                    }
                    else if(wert <= 90)
                    {
                        lowOxygenAlarm();
                    }
                }
                break;

            case 2:
                printf("Wert Anzeigen");
                //wert = verbindung();

                if(wert == -1)
                {
                    inputError();
                    return 0;
                }
                else
                {
                    zahlenAusgabe(wert);
                }
                break;

            case 3:
                printf("Flug beenden");
                printf("\n-----------------------\n");
                printf("Auf Wiedersehen!");
                printf("\n-----------------------\n");
                return 0;

            case 4:
                printf("Log loeschen\n");
                DeleteLog();
                break;
        }
    }
}
