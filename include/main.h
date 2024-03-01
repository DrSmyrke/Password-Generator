#ifndef __MAIN_H__
#define __MAIN_H__
//----------- INCLUDES ---------------------------------------------------------------------
#include <stdint.h>

#include "functions.h"
//----------- DEFINES ----------------------------------------------------------------------
//----------- STRUCTURES -------------------------------------------------------------------
struct ApplicationData{
	uint8_t min;
	uint8_t max;
	uint8_t step;
	uint8_t key[ 32 ];
	struct {
		uint8_t indxMin;
		uint8_t indxMax;
		char* list;
	}symbols;
	uint8_t type;

	// struct {
	// 	unsigned char weater							: 1;	// Флаг наличие влажности
	// } status;
	// struct {
	// 	IO out1;												// Cтруктура выхода1
	// 	IO out2;												// Cтруктура выхода2
	// 	IO out3;												// Cтруктура выхода3
	// 	IO out4;												// Cтруктура выхода4
	// 	IO out5;												// Cтруктура выхода5
	// 	IO out6;												// Cтруктура выхода6
	// 	IO out7;												// Cтруктура выхода7
	// 	IO out8;												// Cтруктура выхода8
	// } outputs;
	// uint8_t uploadData[ RAW_DATA_BUFF_SIZE ];
	// uint8_t rawData[ RAW_DATA_BUFF_SIZE ];
	// uint16_t rawDataIndx;										// Счетчик или индекс для массива сырых данных
	// uint16_t uploadDataIndx;									// Счетчик или индекс для массива загруженных сырых данных
	// struct {
	// 	unsigned char timer0							: 1;	// Флаг указывающий, что сработал таймер0
	// 	unsigned char timer2							: 1;	// Флаг указывающий, что сработал таймер2
	// 	unsigned char configOK							: 1;	// Флаг указывающий что конфиг есть, нормально распарсен и можно работать
	// 	unsigned char configF							: 1;	// Флаг указывающий что конфиг есть
	// 	unsigned char broken							: 1;	// Флаг указывающий что конфиг есть, но он испорчен
	// } flags;
	// struct {
	// 	uint8_t mode;											// Режим работы (0-конфигурация из файла, 1-ручное управление)
	// 	struct {
	// 		uint16_t input1;									// Вход1
	// 		uint16_t input2;									// Вход2
	// 		uint16_t input3;									// Вход3
	// 		uint16_t input4;									// Вход4
	// 		uint16_t input5;									// Вход5
	// 		uint16_t input6;									// Вход6
	// 		uint16_t input7;									// Вход7
	// 		uint16_t input8;									// Вход8
	// 		uint16_t input9;									// Вход9
	// 		uint16_t input10;									// Вход10
	// 		uint16_t input11;									// Вход11
	// 		uint16_t input12;									// Вход12
	// 	} manual_inputs;
	// 	struct {
	// 		unsigned char delme							: 1;	// Флаг указывающий DELME
	// 	} flags;
	// } param;

	// uint8_t inputNum;											// Счетчик входов для обхода алгоритма
};

//----------- VARIABLES --------------------------------------------------------------------
extern ApplicationData app;

//----------- FUNCTIONS---------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#endif //__MAIN_H__