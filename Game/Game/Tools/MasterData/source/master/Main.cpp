#include <stdio.h>
#include <iostream>
#include "master/Master.hpp"

int main( void )
{
	char fname[31] ;

	printf( "Input csv File Name ->" ) ;
	fgets( fname , sizeof(fname) , stdin ) ;
	fname[strlen(fname) - 1] = '\0' ;

	while ( true )
	{
		MasterData::ReLoad("./") ;

		if ( (strcmp(fname , "Data") == 0) || (strcmp(fname , "Data.csv") == 0) )
		{
			for ( size_t i = 0 ; i < MasterData::Data.size( ) ; ++i )
			{
				auto& Data = MasterData::Data[i] ;

				Data.output( ) ;
			}
		}
		if ( (strcmp(fname , "Title") == 0) || (strcmp(fname , "Title.csv") == 0) )
		{
			for ( size_t i = 0 ; i < MasterData::Title.size( ) ; ++i )
			{
				auto& Title = MasterData::Title[i] ;

				Title.output( ) ;
			}
		}

		printf( "---------------------------------------" ) ;
		getchar( ) ;
	}

	return 0 ;

}
