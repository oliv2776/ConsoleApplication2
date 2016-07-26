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

void convertIntToChar(char ConvertedInt[], int indexTable, uint32_t numberToConvert) {
	uint32_t modulo;
	int newIndex = 0;
	char tempChar[16];

	do {
		modulo = numberToConvert % 10;
		tempChar[newIndex] = modulo;
		newIndex++;
		numberToConvert /= 10;
	} while (numberToConvert);
	for (int i = 0; i < newIndex; i++) {
		printf("%d ", tempChar[i]);
	}
	printf("\n");
	for (int i = 0; i<newIndex / 2; i++)
	{
		int tampon = tempChar[i];
		tempChar[i] = tempChar[newIndex - 1 - i];
		tempChar[newIndex - 1 - i] = tampon;
	}
	for (int i = 0; i < newIndex; i++) {
		printf("%d ", tempChar[i]);
	}
	printf("\n");

	for (int i = 0; i < newIndex; i++) {
		ConvertedInt[i + indexTable + 1] = tempChar[i];
	}
	ConvertedInt[indexTable] = newIndex;
	for (int i = 0; i < newIndex + indexTable; i++) {
		printf("%c ", ConvertedInt[i]);
	}
	printf("\n");



	/*int modulo;
	uint32_t multiple;
	uint32_t multiple2;
	uint32_t multiple3;
	uint32_t temp;
	temp = numberToConvert / 127;
	int numberOfMultiple = 0;
	multiple = numberToConvert;
	do {
	multiple = multiple / 127;
	numberOfMultiple++;
	} while (multiple/127>127);

	ConvertedInt[indexTable] = numberOfMultiple;
	ConvertedInt[indexTable + 1] = multiple;

	/*for (int i = 2; i < 7; i++) {
	if (multiple / 127 > 127) {
	ConvertedInt[indexTable + i] = multiple / 127;
	multiple = multiple / 127;
	}
	else {
	ConvertedInt[indexTable + i] = multiple % 127;
	multiple = 0;
	}
	numberOfMultiple++;
	}
	ConvertedInt[indexTable + 1] = numberOfMultiple;*/

	/*
	if (temp/127 > 127) {
	multiple3 = temp;
	multiple2 = multiple3 / 127;
	multiple = multiple2 / 127;
	modulo = multiple % 127;
	ConvertedInt[indexTable] = multiple3;
	ConvertedInt[indexTable + 1] = multiple2;
	ConvertedInt[indexTable + 2] = multiple;
	ConvertedInt[indexTable + 3] = modulo;
	}
	else if (temp  > 127) {
	multiple3 = 0;
	multiple2 = temp;
	multiple = multiple2 / 127;
	modulo = multiple % 127;
	ConvertedInt[indexTable] = multiple3;
	ConvertedInt[indexTable + 1] = multiple2;
	ConvertedInt[indexTable + 2] = multiple;
	ConvertedInt[indexTable + 3] = modulo;
	}

	else {
	multiple = numberToConvert / 127;
	modulo = numberToConvert % 127;
	ConvertedInt[indexTable] = 0;
	ConvertedInt[indexTable + 1] = 0;
	ConvertedInt[indexTable + 2] = multiple;
	ConvertedInt[indexTable + 3] = modulo;
	}
	*/
	for (int i = 0; i<7; i++) {
		printf("%d\t", ConvertedInt[i]);
	}
	printf("\n");

}

uint32_t convertCharToInt(char charToConvert[], int index) {
	printf("\n\n");
	for (int i = 0; i < charToConvert[index] + index + 1; i++) {
		printf("%d ", charToConvert[i]);
	}
	printf("\n");
	printf("\n\n");
	uint32_t result = 0;
	uint32_t temp=0;
	int newIndex = charToConvert[index];

	for (int i = index + 1; i < index + 1 + charToConvert[index]; i++) {
		temp = charToConvert[i];
		for (int j = 0; j < newIndex-1; j++) {
			temp = temp * 10;
		}
		newIndex--;
		result += temp;
	}

	return result;

	/*uint32_t result=127;

	for (int i = 0; i <= charToConvert[index]; i++) {
	result = result * 127;
	}
	result = result + charToConvert[index + 1];

	/*switch (index)
	{
	case 1:
	result = charToConvert[index + 1];
	break;
	case 2:
	result = charToConvert[index + 1] * 127 + charToConvert[index + 2];
	break;
	case 3:
	result = charToConvert[index + 1] * 127 * 127 + charToConvert[index + 2] * 127 + charToConvert[index + 3];
	break;
	case 4:
	result = charToConvert[index + 1] * 127 * 127 * 127 + charToConvert[index + 2] * 127 * 127 + charToConvert[index + 3] * 127 + charToConvert[index + 4];
	break;
	case 5:
	result = charToConvert[index + 1] * 127 * 127 * 127 * 127 + charToConvert[index + 2] * 127 * 127 * 127 + charToConvert[index + 3] * 127 * 127 + charToConvert[index + 4] * 127 + charToConvert[index + 5];
	break;
	default:
	printf("error");
	break;
	}*/

	return result;
}

int main()
{



	char buffer[32];
	SYSTEMTIME t;
	GetSystemTime(&t);
	uint32_t nbPacket = 1234567;
	printf("%d\n", nbPacket);
	buffer[0] = 'a';
	int numberTotalOfPackets = 1234553;
	convertIntToChar(buffer, 1, nbPacket);
	for (int i = 0; i<5; i++) {
		printf("%c\t", buffer[i]);
	}
	int temp;
	temp = convertCharToInt(buffer, 1);
	printf("\n%d", temp);
	/*Configuring the buffers*/
	/*buffer[0] = BOARDNAME1;
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
	printf("\n");*/
	getchar();
	return 0;
}

