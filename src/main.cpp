//----------- INCLUDES ---------------------------------------------------------------------
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
//----------- DEFINES ----------------------------------------------------------------------
//----------- VARIABLES --------------------------------------------------------------------
ApplicationData app;
//----------- FUNCTIONS---------------------------------------------------------------------
int main(int argc, char *argv[])
{
	app.symbols.list		= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()[]";
	app.symbols.indxMin		= 0;
	app.symbols.indxMax		= 10;
	app.min					= 1;
	app.max					= 1;
	app.type				= 1;

	// char *argv2[] = { "--min", "1", "--max", "3" };
	argsProcessing( argc, argv );
	// argsProcessing( 4, argv2 );

	app.step				= app.min;

	//Нарушена логика
	if( app.max == 0 || app.min == 0 ) return 0;
	if( app.max < app.min ) return 0;

	while( app.step <= app.max ){
		//Создаем ключевой массив
		createKey( app.step );

		//Процессинг ключа
		uint8_t res = 0;
		while( res < app.step ){
			printKey();
			res = processingKey();
			// printf( "[%u]\n", res );
			if( app.step > app.max ) break;
		}

		app.step++;
	}

	return 0;
}

//------------------------------------------------------------------------------------------
