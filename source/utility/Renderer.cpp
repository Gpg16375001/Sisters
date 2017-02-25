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
	setPos( 0 , 0 ) ;
	setUV( 0 , 0 ) ;
	setWH( 0 , 0 ) ;
	setScale( 1.0f , 1.0f ) ;

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
		HGDIOBJ arg_bmpData ,						// . �摜�f�[�^
		int arg_anchor ,							 // . �A���J�[
		int arg_x , int arg_y ,						// . �z�u���W
		int arg_u , int arg_v ,						// . �؂���ʒu
		int arg_w , int arg_h ,						// . ������
		float arg_scaleX , float arg_scaleY			// . �g�嗦
	)
{
	bmpData_ = arg_bmpData ;
	setAnchor( arg_anchor ) ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;
	setScale( arg_scaleX , arg_scaleY ) ;

	return ( true ) ;
}

/*/
/*	�o�b�N�o�b�t�@�֕`��
/*/
int Renderer::Render( )
{
	SelectObject( hDCWork_ , bmpData_ ) ;

	TransparentBlt(
		hDCBack_ ,
		(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
		(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
		hDCWork_ ,
		u_ , v_ ,
		w_ , h_ ,
		RGB( 0 , 255 , 0 )
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

/*/
/*	�g�嗦�̃Z�b�g
/*/
int Renderer::setScale( float arg_w , float arg_h )
{
	scaleX_ = arg_w ;
	scaleY_ = arg_h ;

	return( true ) ;
}

/*/
/*	�A���J�[�̃Z�b�g
/*/
int Renderer::setAnchor( int arg_anchor )
{
	anchorX_ = arg_anchor % 3 ;
	anchorY_ = arg_anchor / 3 ;

	return( true ) ;
}


