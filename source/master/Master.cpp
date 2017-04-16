#pragma once

#include <vector>
#include "Master.hpp"
#include <stdio.h>

namespace MasterData
{
	std::vector<ChipDataInfo> ChipData ;
	std::vector<SceneGame01Info> SceneGame01 ;

	void LoadChipData( )
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
		ChipData.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				ChipDataInfo Info ;

				Info.Load( buf ) ;
				ChipData.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	void LoadSceneGame01( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	GimmickData
		/*/
		sprintf( path , "data/masterdata/SceneGame01.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		SceneGame01.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				SceneGame01Info Info ;

				Info.Load( buf ) ;
				SceneGame01.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	void ReLoad( )
	{
		LoadChipData( ) ;
		LoadSceneGame01( ) ;
	}

}


