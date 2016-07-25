// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
/*To avoid _WINSOCK_DEPRECATED_NO_WARNINGS error while compiling*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <fstream>
#pragma comment(lib, "ws2_32.lib")


using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
/*Defines*/
#define PORT 23
#define BOARDNAME1 'B'
#define BOARDNAME2 '0'
#define ADC1 '1'
#define ADC2 '2'
#define ADC3 '3'


int main()
{



	char buffer[32];
	SYSTEMTIME t;
	GetSystemTime(&t);
	int nbPacket = 12452;
	int numberTotalOfPackets = 1234553;
	
	/*Configuring the buffers*/
	buffer[0] = BOARDNAME1;
	buffer[1] = BOARDNAME2;
	buffer[2] = ADC1;
	int index = 3;
	char buf[6];
	sprintf(buf,"%d", nbPacket);
	for (int i = 0; i < 6; i++) {
		printf("%c", buf[i]);
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", numberTotalOfPackets);
	for (int i = 0; i < 6; i++) {
		printf("%c", buf[i]);
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wDay);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wMonth);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wYear);
	for (int i = 0; i < 4; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wHour);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wMinute);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wSecond);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}
	sprintf(buf, "%d", t.wMilliseconds);
	for (int i = 0; i < 2; i++) {
		buffer[index] = buf[i];
		index++;
	}


	printf("\n");
	for (int i = 0; i < 32; i++) {
		//printf("%c\t", bufferADC1[i]);
		printf("%d ", i);
		cout << buffer[i];
		printf("\n");
	}
	printf("\n");
	getchar();
    return 0;
}

