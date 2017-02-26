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
	setAnchor( 0 ) ;
	setPos( 0 , 0 ) ;
	setUV( 0 , 0 ) ;
	setWH( 0 , 0 ) ;
	setScale( 1.0f , 1.0f ) ;
	setAlphaFlg( false ) ;
	setRotateFlg( false ) ;

}

/*/
/*	����ʂ̕`��ɕK�v�Ȃ��̂����炤
/*/
int Renderer::setHDC( HWND arg_hWnd , HDC arg_hDCBack , HDC arg_hDCWork )
{
	hWnd_ = arg_hWnd ;
	hDCBack_ = arg_hDCBack ;
	hDCWork_ = arg_hDCWork ;

	return( true ) ;
}

/*/
/*	�`�悵�����r�b�g�}�b�v���Z�b�g
/*/
int Renderer::selectBmp(
		HGDIOBJ arg_bmpData ,						// . �摜�f�[�^
		int arg_anchor ,							// . �A���J�[
		int arg_x , int arg_y ,						// . �z�u���W
		int arg_u , int arg_v ,						// . �؂���ʒu
		int arg_w , int arg_h ,						// . ������
		float arg_scaleX , float arg_scaleY ,		// . �g�嗦
		int arg_alpha ,								// . �����x
		float arg_angle								// . �p�x
	)
{
	bmpData_ = arg_bmpData ;
	setAnchor( arg_anchor ) ;
	setPos( arg_x , arg_y ) ;
	setUV( arg_u , arg_v ) ;
	setWH( arg_w , arg_h ) ;
	setScale( arg_scaleX , arg_scaleY ) ;
	if ( arg_alpha < 255 )
	{
		alphaFlg_ = true ;
		setAlpha( arg_alpha ) ;
	}
	if ( arg_angle != 0 )
	{
		rotateFlg_ = true ;
		setAngle( arg_angle ) ;
	}

	return ( true ) ;
}

/*/
/*	�o�b�N�o�b�t�@�֕`��
/*/
int Renderer::Render( )
{
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	if ( rotateFlg_ )
	{


	} else if ( alphaFlg_ ) {
		// �w�肳��Ă���X�v���C�g�̑I��
		SelectObject( hDCWork_ , bmpData_ ) ;

		// �V�K��Ɨp�f�o�C�X�R���e�L�X�g�̐��� ( �傫�߂ɍ�� )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
		ReleaseDC( hWnd_ , hDC ) ;

		// �`�悩��o�b�N�o�b�t�@��؂��� ( �w�i )
		BitBlt( s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				SRCCOPY
			) ;

		// �؂�����DC�ɕ`�悵�����摜�𒣂�t����y�����ŏ�ɒ���t����r�b�g�}�b�v����������z
		TransparentBlt(
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				hDCWork_ ,
				u_ , v_ ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				RGB( 0 , 255 , 0 )
			) ;

		// �A���t�@�u�����h�y�����������z
		s_blendFunc.SourceConstantAlpha = alpha_ ;		// �A���t�@�l������
		AlphaBlend(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_ * 1.5) , (int)(h_ * scaleY_ * 1.5) ,
				s_blendFunc
			) ;

		// DC �� �r�b�g�}�b�v�̈�̉��
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;

	} else {
		// �摜�̑I��
		SelectObject( hDCWork_ , bmpData_ ) ;

		// �o�b�N�o�b�t�@�֓]��
		TransparentBlt(
			hDCBack_ ,
			(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
			(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
			hDCWork_ ,
			u_ , v_ ,
			w_ , h_ ,
			RGB( 0 , 255 , 0 )
		) ;

	}

	// �I�������̂ŏ�����
	Initialize( ) ;

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

/*/
/*	�����x�̃Z�b�g
/*/
int Renderer::setAlpha( int arg_alpha )
{
	alpha_ = arg_alpha ;	

	return( true ) ;
}

/*/
/*	�p�x�̃Z�b�g
/*/
int Renderer::setAngle( float arg_angle )
{
	angle_ = arg_angle ;

	return( true ) ;
}

/*/
/*	�����x�̃t���O���Z�b�g
/*/
int Renderer::setAlphaFlg( bool arg_alphaFlg )
{
	alphaFlg_ = arg_alphaFlg ;	

	return( true ) ;
}

/*/
/*	�p�x�̃t���O���Z�b�g
/*/
int Renderer::setRotateFlg( bool arg_rotateFlg )
{
	rotateFlg_ = arg_rotateFlg ;

	return( true ) ;
}


