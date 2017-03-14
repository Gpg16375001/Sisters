/*__________________________________________________________________________________________________________________*/
/*																													*/
/*													 CREATEDATA CPP													*/
/*																													*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/

#include <windows.h>
#include <stdio.h>	// --- ÉRÉìÉ\Å[Éãóp
#include "Common.h"

void CreateData::CreateMapData( const char* fname ) {
	sprintf( buf , "source/MapData/%s.txt" , fname ) ;
	FILE *fp = fopen( buf , "w" ) ;

	if ( fp == nullptr )
	{
		return ;
	}

	fprintf( fp , "int g_mapData01[ MAP_X * MAP_Y ] = {\n") ;
	for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
		fprintf( fp , "%3d," , g_mapData01[ i ] ) ;
		if ( (i % MAP_X) == 24 ) {
			fprintf( fp , "\n" ) ;
		}
	}
	fprintf( fp , "} ;\n") ;

	fclose( fp ) ;

}



