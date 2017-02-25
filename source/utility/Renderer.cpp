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
	width_ = 0 ;
	height_ = 0 ;
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
int Renderer::selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height )
{
	bmpData_ = arg_bmpData ;
	width_ = arg_width ;
	height_ = arg_height ;

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
		width_ ,
		height_ ,
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


