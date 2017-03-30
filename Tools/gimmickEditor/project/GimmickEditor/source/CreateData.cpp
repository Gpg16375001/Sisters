/*__________________________________________________________________________________________________________________*/
/*																													*/
/*													 CREATEDATA CPP													*/
/*																													*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include "Common.h"

void CreateData::CreateMapData( const char* fname ) {
	sprintf( buf , "%s" , fname ) ;
	FILE *fp = fopen( buf , "w" ) ;

	if ( fp == nullptr )
	{
		return ;
	}

//	fprintf( fp , "int g_mapData01[ %d * %d ] = {\n" , MAP_X , MAP_Y) ;
	for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
		fprintf( fp , "%3d," , g_mapData01[ i ] ) ;
		if ( (i % MAP_X) == (MAP_X - 1) ) {
			fprintf( fp , "\n" ) ;
		}
	}
//	fprintf( fp , "} ;\n") ;

	fclose( fp ) ;

}



