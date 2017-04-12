/*
________________________________________________________________________________________________________________

	FILE : SceneCut.cpp

	________/ Explanation of file /___________________________________________________________

		SceneCut �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>

#include "SceneCut.h"

/*/
/*	�f�X�g���N�^
/*/
SceneCut::~SceneCut( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP ; ++i )
	{
		if( bmpTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	������
/*/
void SceneCut::Initialize( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP ; ++i )
	{
		if( bmpTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	�摜�f�[�^�̃N���A
/*/
int SceneCut::clearData( int arg_bmpNo )
{
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0.0f , 0.0f ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;
	setAlpha( arg_bmpNo , 255 ) ;
	setUseAlpha( arg_bmpNo , false ) ;

	return( true ) ;
}

/*/
/*	�C���[�W�ǂݍ���
/*/
int SceneCut::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( arg_bmpNo ) ;

	// �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	bmpTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}


/*/
/*	�`�悷�邩�ǂ����̃t���O���Z�b�g
/*/
int SceneCut::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	�������������邩�ǂ����̃t���O���Z�b�g
/*/
int SceneCut::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	�|�W�V�����̃Z�b�g
/*/
int SceneCut::setBmpXY( int arg_bmpNo , float arg_x , float arg_y )
{
	bmpTable_[ arg_bmpNo ]._x = arg_x ;
	bmpTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	���A�����̃Z�b�g
/*/
int SceneCut::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpTable_[ arg_bmpNo ]._w = arg_w ;
	bmpTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	�����x�̃Z�b�g
/*/
int SceneCut::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	�`�悷������Z�b�g
/*/
int SceneCut::setBmpData(
		int arg_bmpNo ,
		float arg_x , float arg_y ,
		int arg_w , int arg_h ,
		int arg_alpha
	) 
{
	setUseFlg( arg_bmpNo , true ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;
	if ( arg_alpha < 255 )
	{
		setUseAlpha( arg_bmpNo , true ) ;
		setAlpha( arg_bmpNo , arg_alpha ) ;
	}

	return( true ) ;
}

int SceneCut::fadeIn( )
{
	int iRet = -1 ;

	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	alphaCnt_ += 6 ;

	if ( alphaCnt_ >= 255 )
	{
		alphaCnt_ = 255 ;
		iRet = 1 ;
	}

	return( iRet ) ;
}

int SceneCut::BlackOut( )
{
	int iRet = -1 ;

	alphaCnt_ = 255 ;
	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	iRet = 1 ;

	return( iRet ) ;
}

int SceneCut::fadeOut( )
{
	int iRet = -1 ;

	SceneCut::GetInstance()->setBmpData( 0 , 0 , 0 , 800 , 700 , alphaCnt_ ) ;
	alphaCnt_ -= 8 ;

	if ( alphaCnt_ <= 0 )
	{
		alphaCnt_ = 0 ;
		iRet = 1 ;
	}

	return( iRet ) ;
}


