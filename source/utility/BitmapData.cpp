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
		clearData( i ) ; 
	}
}

/*/
/*	�摜�f�[�^�̃N���A
/*/
int BitmapData::clearData( int arg_bmpNo )
{
	if( bmpDataTable_[ arg_bmpNo ]._hBmp != NULL )
	{
		DeleteObject( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
	}
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0 , 0 ) ;
	setBmpUV( arg_bmpNo , 0 , 0 ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;

	return( true ) ;
}

/*/
/*	�C���[�W�ǂݍ���
/*/
int BitmapData::loadData( int arg_bmpNo , LPCTSTR arg_pStr , int arg_width , int arg_height )
{
	// �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( arg_bmpNo ) ;

	// �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	bmpDataTable_[ arg_bmpNo ]._hBmp = (HBITMAP)LoadImage( NULL , arg_pStr , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ;

	setBmpWH( arg_bmpNo , arg_width , arg_height ) ;

	printf( "%S was loaded.\n" , arg_pStr ) ;

	return ( true ) ;
}

/*/
/*	�|�W�V�����̃Z�b�g
/*/
int BitmapData::setBmpXY( int arg_bmpNo , int arg_x , int arg_y )
{
	bmpDataTable_[ arg_bmpNo ]._x = arg_x ;
	bmpDataTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	�؂���ʒu�̃Z�b�g
/*/
int BitmapData::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpDataTable_[ arg_bmpNo ]._u = arg_u ;
	bmpDataTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
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

/*/
/*	�`�悷�邩�ǂ����̃t���O���Z�b�g
/*/
int BitmapData::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpDataTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	�`�悷������Z�b�g
/*/
int BitmapData::setBmpData(
		int arg_bmpNo ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h
	) 
{
	setUseFlg( arg_bmpNo , true ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpUV( arg_bmpNo , arg_u , arg_v ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;

	return( true ) ;
}


