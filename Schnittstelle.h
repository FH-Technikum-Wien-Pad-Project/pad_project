int verbindung() {

int uart0_filestream = -1;							//Kontrollbit
uart0_filestream = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);		//öffnet Serielle Schnittstelle;
										//O_RDWR - Modus; O_NOCTTY - nicht Master; O_NDELAY - State egal
if (uart0_filestream == -1) {							//falls Kontrollbit weiterhin -1, Fehler
	printf("\n-----------------------\n");
	printf("[ERROR] UART open()\n");
   	printf("\n-----------------------\n");
	return -1;
}

struct termios options;
tcgetattr(uart0_filestream, &options);						//get attributes
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; 			//Baudrate
	options.c_iflag = IGNPAR;						//Input option; Ignore framing errors and parity errors
	options.c_oflag = 0;							//Output option
	options.c_lflag = 0;							//Local mode
tcflush(uart0_filestream, TCIFLUSH);						//clean the data lines
tcsetattr(uart0_filestream, TCSANOW, &options);					//set all parameters


// Bytes empfangen
if (uart0_filestream != -1) {
	unsigned char BUF_RX[50];
	int rx_length = read(uart0_filestream, (void*)BUF_RX, 50);		//Daten lesen + länge in rx_length speichern

	if (rx_length < 0) {							//Abfragen ob Daten erhalten wurden mit jeweiliger Meldung
		printf("[ERROR] UART RX\n");
	} else if (rx_length == 0) {
		printf("[ERROR] UART RX - no data\n");
	} else {
		BUF_RX[rx_length] = '\0';					//letzes Zeichen zu \0 ändern, wenn Daten empfangen wurden
	}
}

close(uart0_filestream);							//Schließt Serielle Schnittstelle


//Aufbereitung der Daten, Eigentlichen Wert herausfiltern und zurückgeben an aufrufende funktion
return BUF_RX;

}
				
