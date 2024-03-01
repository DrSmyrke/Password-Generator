//----------- INCLUDES ---------------------------------------------------------------------
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//----------- DEFINES ----------------------------------------------------------------------
//----------- VARIABLES --------------------------------------------------------------------
//----------- FUNCTIONS---------------------------------------------------------------------
void argsProcessing(int argc, char * argv[])
{
	for( uint8_t i = 0 ; i < argc; i++ ){
		// printf( "Argument %d/%d: %s\n", i, argc, argv[i] );
		uint8_t r = i + 1;
		
		if( r >= argc ) break;

		char* curr = argv[ i ];
		char* next = argv[ r ];
		
		if( strcmp( curr, "--min" ) == 0 ){
			app.min = atoi( next );
		}else if( strcmp( curr, "--max" ) == 0 ){
			app.max = atoi( next );
		}else if( strcmp( curr, "--type" ) == 0 ){
			app.type = atoi( next );
		}
	}

	printf( "Min: %d, Max: %d\n", app.min, app.max );
}

//------------------------------------------------------------------------------------------
void createKey(const uint8_t length)
{
	// void *ptr = NULL;

	// if( app.key != nullptr ) free( app.key );

	// ptr = malloc( length );

	// app.key = ( ptr != NULL ) ? (uint8_t*) ptr : nullptr;

	// if( app.key == nullptr ) return;

	if( length > sizeof( app.key ) ) return;

	for( uint8_t i = 0; i < length; i++ ) app.key[ i ] = app.symbols.indxMin;
}

//------------------------------------------------------------------------------------------
void printKey(void)
{
	// printf( ">: [%u/%u]", app.step, app.max );
	for( uint8_t i = 0; i < app.step; i++ ){
		printf( "%c", app.symbols.list[ app.key[ i ] ] );
		// printf( "%d", app.key[ i ] );
	}
	printf( "\n" );
}

//------------------------------------------------------------------------------------------
uint8_t processingKey(void)
{
	if( app.step == 0 ) return 0;
	uint8_t i = app.step - 1;
	uint8_t comleteIndx = 0;

	app.key[ i ]++;
	
	//Проверка на переполнение
	if( app.key[ i ] >= app.symbols.indxMax ){
		app.key[ i ] = app.symbols.indxMin;
		if( i > 0 ) app.key[ i - 1 ]++;
		comleteIndx++;

		//Увеличение следующего разряда ключа
		while( i > 0 ){
			i--;
			if( app.key[ i ] >= app.symbols.indxMax ){
				app.key[ i ] = app.symbols.indxMin;
				app.key[ i - 1 ]++;
				comleteIndx++;
			}
		}
	}

	return comleteIndx;
}

//------------------------------------------------------------------------------------------
