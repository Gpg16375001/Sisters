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
		// file�ۑ��p�̍\���̂̏����Z�b�g
		if ( ofn.lStructSize == 0 )
		{
			ofn.lStructSize         = sizeof(OPENFILENAME) ;
			ofn.hwndOwner           = g_hWindow ;
			ofn.lpstrInitialDir     = szPath ;       // �����t�H���_�ʒu
			ofn.lpstrFile           = szFile ;       // �I���t�@�C���i�[
			ofn.nMaxFile            = MAX_PATH ;
			ofn.lpstrDefExt         = TEXT(".txt") ;
			ofn.lpstrFilter         = TEXT("txt�t�@�C��(*.txt)\0*.txt\0") ;
			ofn.lpstrTitle          = TEXT("�}�b�v�t�@�C�����t�@�C�����J���܂��B") ;
			ofn.Flags               = OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT ;
		}

		if ( GetOpenFileName( &ofn ) )
		{
			g_CBG.clearChip( ) ;
			g_scroll = 0 ;
			MessageBox( g_hWindow , szFile , TEXT("�t�@�C�����J��") , MB_OK ) ;
			LoadMapData( szFile , ofn.nFileExtension + 4 ) ;
		}
	}																					
}																						
																						
																						
																						
