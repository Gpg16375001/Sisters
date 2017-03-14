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
		char path[512] ;
		char buf[ 5 ] ;

		//ロケール指定
		setlocale(LC_ALL,"japanese") ;
		size_t wLen = 0 ;
		wcstombs_s( &wLen , path , arg_size , s  , _TRUNCATE) ;
		printf( "読み込んだファイル : %s\n" , path ) ;

		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			printf( "読み込み失敗したよ！\n" ) ;
			return ;
		}
		mapData.clear( ) ;

		printf( "読み込み成功！\n" ) ;
		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			DataInfo Info ;

			Info.Load( buf ) ;
			mapData.push_back( Info ) ;
		}
		printf( "読み終了！\n" ) ;

		int i = 0 , min = 0 ;
		for ( auto it = mapData.begin() ; it != mapData.end() ; ++it )
		{
			if ( (0 == i % 1024) && (i != 0) )
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
		static OPENFILENAME    ofn ;
		static TCHAR           szPath[ MAX_PATH ] ;
		static TCHAR           szFile[ MAX_PATH ] ;

		if ( szPath[0] == TEXT('\0') )
		{
			GetCurrentDirectory( MAX_PATH , szPath ) ;
		}
		// file保存用の構造体の初期セット
		if ( ofn.lStructSize == 0 )
		{
			ofn.lStructSize         = sizeof(OPENFILENAME) ;
			ofn.hwndOwner           = g_hWindow ;
			ofn.lpstrInitialDir     = szPath ;       // 初期フォルダ位置
			ofn.lpstrFile           = szFile ;       // 選択ファイル格納
			ofn.nMaxFile            = MAX_PATH ;
			ofn.lpstrDefExt         = TEXT(".txt") ;
			ofn.lpstrFilter         = TEXT("txtファイル(*.txt)\0*.txt\0") ;
			ofn.lpstrTitle          = TEXT("マップファイルをファイルを開きます。") ;
			ofn.Flags               = OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT ;
		}

		if ( GetOpenFileName( &ofn ) )
		{
			g_CBG.clearChip( ) ;
			g_scroll = 0 ;
			MessageBox( g_hWindow , szFile , TEXT("ファイルを開く") , MB_OK ) ;
			LoadMapData( szFile , ofn.nFileExtension + 4 ) ;
		}
	}																					
}																						
																						
																						
																						
