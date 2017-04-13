#pragma once
#include <vector>
#include "Master.hpp"
#include <stdio.h>

namespace MasterData
{
	std::vector<DataInfo> Data ;

	void LoadData( const char* s )
	{
		char path[256] ;
		char buf[1024] ;

		sprintf( path , "%s/Data.csv" , s ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		Data.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				DataInfo Info ;

				Info.Load( buf ) ;
				Data.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	void ReLoad( const char* s )
	{
		LoadData( s ) ;
	}

}


