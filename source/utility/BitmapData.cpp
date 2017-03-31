/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp

	________/ Explanation of file /___________________________________________________________

		BitmapData ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
BitmapData::~BitmapData( )
{
	// --- g—p‚³‚ê‚Ä‚¢‚½‚çƒIƒuƒWƒFƒNƒg”jŠü
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		if( bmpDataTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpDataTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	‰Šú‰»
/*/
void BitmapData::Initialize( )
{
	// --- g—p‚³‚ê‚Ä‚¢‚½‚çƒIƒuƒWƒFƒNƒg”jŠü
	for ( int i = 0 ; i < MAX_BMP_IMAGES ; ++i )
	{
		if( bmpDataTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpDataTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	‰æ‘œƒf[ƒ^‚ÌƒNƒŠƒA
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	setBmpWH( arg_bmpNo , 0 , 0 ) ;

	return( true ) ;
}

/*/
/*	ƒCƒ[ƒW“Ç‚İ‚İ
/*/
int BitmapData::loadData( int arg_bmpNo , LPCTSTR arg_pStr , int arg_width , int arg_height , int arg_cx , int arg_cy )
{
	// g—p‚³‚ê‚Ä‚¢‚½‚çƒIƒuƒWƒFƒNƒg”jŠü
	clearData( arg_bmpNo ) ;

	// ƒf[ƒ^‚Ì“Ç‚İ‚İ‚Æ•‚Æ‚‚³‚ğƒZƒbƒg
	bmpDataTable_[ arg_bmpNo ]._hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , arg_cx , arg_cy , LR_LOADFROMFILE ) ;

	setBmpWH( arg_bmpNo , arg_width , arg_height ) ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	•A‚‚³‚ÌƒZƒbƒg
/*/
int BitmapData::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpDataTable_[ arg_bmpNo ]._w = arg_w ;
	bmpDataTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}


