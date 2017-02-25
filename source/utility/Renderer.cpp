/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include "Renderer.h"

/*/
/*	�f�X�g���N�^
/*/
Renderer::~Renderer( )
{
	// ����ʂŎg�������̂�����
	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	if ( hDCWork_ != NULL )
	{
		DeleteDC( hDCWork_ ) ;
	}

}

/*/
/*	������
/*/
void Renderer::Initialize( )
{
	bmpData_ = NULL ;
	x_ = 0 ;
	y_ = 0 ;
	u_ = 0 ;
	v_ = 0 ;
	w_ = 0 ;
	h_ = 0 ;
}

/*/
/*	����ʂ̕`��ɕK�v�Ȃ��̂����炤
/*/
int Renderer::setHDC( HDC arg_hDCBack , HDC arg_hDCWork )
{
	hDCBack_ = arg_hDCBack ;
	hDCWork_ = arg_hDCWork ;

	return( true ) ;
}

/*/
/*	�`�悵�����r�b�g�}�b�v���Z�b�g
/*/
int Renderer::selectBmp(
		HGDIOBJ arg_bmpData ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h
	)
{
	bmpData_ = arg_bmpData ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;

	return ( true ) ;
}

/*/
/*	�o�b�N�o�b�t�@�֕`��
/*/
int Renderer::Render( )
{
	SelectObject( hDCWork_ , bmpData_ ) ;

	BitBlt(
		hDCBack_ ,
		x_ ,
		y_ ,
		w_ ,
		h_ ,
		hDCWork_ ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


/*/
/*	X�� ��  Y�� ���Z�b�g
/*/
int Renderer::setPos( int arg_x , int arg_y )
{
	x_ = arg_x ;
	y_ = arg_y ;

	return( true ) ;
}

/*/
/*	�؂�o�����W�̃Z�b�g
/*/
int Renderer::setUV( int arg_u , int arg_v )
{
	u_ = arg_u ;
	v_ = arg_v ;

	return( true ) ;
}

/*/
/*	�؂�o���������̃Z�b�g
/*/
int Renderer::setWH( int arg_w , int arg_h )
{
	w_ = arg_w ;
	h_ = arg_h ;

	return( true ) ;
}



