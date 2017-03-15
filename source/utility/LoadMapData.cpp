#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include "Common.h"
#include "LoadMapData.h"

namespace LoadMapData
{
	std::vector<DataInfo> mapData ;

	void LoadMapData( const TCHAR* s , size_t arg_size )
	{
		char path[ 256 ] ;
		char buf[ 5 ] ;

		//���P�[���w��
		setlocale(LC_ALL,"japanese") ;
		size_t wLen = 0 ;
		wcstombs_s( &wLen , path , arg_size , s  , _TRUNCATE) ;
		printf( "�ǂݍ��񂾃t�@�C�� : %s\n" , path ) ;

		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			printf( "�ǂݍ��ݎ��s������I\n" ) ;
			return ;
		}
		mapData.clear( ) ;

		printf( "�ǂݍ��ݐ����I\n" ) ;
		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			DataInfo Info ;

			Info.Load( buf ) ;
			mapData.push_back( Info ) ;
		}
		printf( "�ǂݏI���I\n" ) ;

		int i = 0 , min = 0 ;
		for ( auto it = mapData.begin() ; it != mapData.end() ; ++it )
		{
			if ( (0 == i % Chip::GetInstance()->getMapSizeX()) && (i != 0) )
			{
				++min ;
			} else  {
				g_mapData01[ i - min ] = it->getChipNo() ;
			}
			++i ;
		}

		fclose( fp ) ;
	}

	void ReLoad( )
	{
		LoadMapData( TEXT("data/map/mapData.txt") , 21 ) ;
	}
}																						
																						
																						
																						
