#pragma once

#include <vector>
#include "Master.hpp"
#include <stdio.h>

namespace MasterData
{
	std::vector<DataInfo> Data ;

	void Load( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	ChipData
		/*/
		sprintf( path , "data/masterdata/ChipData.csv" ) ;
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

	void ReLoad( )
	{
		Load( ) ;
	}

}


