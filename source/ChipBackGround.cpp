/*
______________________________________________________________________________________________

	FILE : ChipBackGround.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		ChipBackGround �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

// �R���X�g���N�^
ChipBackGround::ChipBackGround( ) {
	// �C���X�^���X�����̏�����
	m_bmpNo = 0 ;
	m_x		= 0 ;
	m_y		= 0 ;
	clearChip( ) ;
}

// �f�X�g���N�^
ChipBackGround::~ChipBackGround( ) {	}

// �`�悵�����w�i�̔ԍ����Z�b�g
int ChipBackGround::selectBmp( int arg_bmpNo ) {
	m_bmpNo = arg_bmpNo ;

	return( true ) ;
}

// �`��J�n�n�_�̍��W�̃Z�b�g
int ChipBackGround::setPos( int arg_x , int arg_y ) {
	m_x = arg_x ;
	m_y = arg_y ;
	return( true ) ;
}

// �`�b�v�̃Z�b�g
int ChipBackGround::setChip( int arg_x , int arg_y , int arg_chipNo ) {
	m_chipTable[ (CHIP_X * arg_y) + arg_x ] = arg_chipNo ;
	return( true ) ;
}

// �`�b�v�f�[�^�̍����R�s�[
int ChipBackGround::setFastChip( int *arg_chipData ) {
	memcpy( m_chipTable , arg_chipData , CHIP_X * CHIP_Y * sizeof(int) ) ;
	return( true ) ;
}

// �`�b�v�f�[�^�̃N���A�[
int ChipBackGround::clearChip( ) {
	memset( m_chipTable , 0 , CHIP_X * CHIP_Y * sizeof(int) ) ;
	return( true ) ;
}

// �X�V
int ChipBackGround::Update( )
{
	for ( int i = 0 ; i < ( CHIP_X * CHIP_Y ) ; i++ ) {
		if ( m_chipTable[ i ] != 0 ) {
			BitmapData::GetInstance()->setBmpData(
					2 ,
					0 ,
					( i % CHIP_X ) * CHIP_W + m_x ,
					( i / CHIP_Y ) * CHIP_H + m_y ,
					0 , 0 ,
					CHIP_W ,
					CHIP_H ,
					1.0f , 1.0f
				) ;
		}
	}

	return( true ) ;
}

// �`�b�v�̕`��
int ChipBackGround::Render( ) {

	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BitmapData::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , BitmapData::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4.0f \n" , BitmapData::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					BitmapData::GetInstance()->getBmpData( i ) ,
					BitmapData::GetInstance()->getBmpAnchor( i ) ,
					BitmapData::GetInstance()->getBmpXPos( i ) ,
					BitmapData::GetInstance()->getBmpYPos( i ) ,
					BitmapData::GetInstance()->getBmpUPos( i ) ,
					BitmapData::GetInstance()->getBmpVPos( i ) ,
					BitmapData::GetInstance()->getBmpWidth( i ) ,
					BitmapData::GetInstance()->getBmpHeight( i ) ,
					BitmapData::GetInstance()->getBmpScaleX( i ) ,
					BitmapData::GetInstance()->getBmpScaleY( i ) ,
					BitmapData::GetInstance()->getBmpAlpha( i ) ,
					BitmapData::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	return( true ) ;
}


