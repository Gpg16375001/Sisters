/*
________________________________________________________________________________________________________________

	FILE : BitmapData.cpp

	________/ Explanation of file /___________________________________________________________

		BitmapData �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>

#include "BitmapData.h"

/*/
/*	�f�X�g���N�^
/*/
BitmapData::~BitmapData( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
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
/*	������
/*/
void BitmapData::Initialize( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
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
/*	�摜�f�[�^�̃N���A
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	setBmpWH( arg_bmpNo , 0 , 0 ) ;

	return( true ) ;
}

/*/
/*	�C���[�W�ǂݍ���
/*/
int BitmapData::loadData( int arg_bmpNo , LPCTSTR arg_pStr , int arg_width , int arg_height , int arg_cx , int arg_cy )
{
	// �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( arg_bmpNo ) ;

	// �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	bmpDataTable_[ arg_bmpNo ]._hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , arg_cx , arg_cy , LR_LOADFROMFILE ) ;

	setBmpWH( arg_bmpNo , arg_width , arg_height ) ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	���A�����̃Z�b�g
/*/
int BitmapData::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpDataTable_[ arg_bmpNo ]._w = arg_w ;
	bmpDataTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}


