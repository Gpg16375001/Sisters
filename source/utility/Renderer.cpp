/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include <DxLib.h>
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
	sceneCut = 0 ;

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
		float arg_x , float arg_y ,					// . �z�u���W
		float arg_u , float arg_v ,					// . �؂���ʒu
		float arg_w , float arg_h ,					// . ������
		float arg_scaleX , float arg_scaleY ,		// . �g�嗦
		int arg_alpha ,								// . �����x
		float arg_degree							// . �p�x
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
		setAlphaFlg( true ) ;
		setAlpha( arg_alpha ) ;
	}
	if ( arg_degree != 0 )
	{
		setRotateFlg( true ) ;
		setAngle( arg_degree ) ;
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
	float	radian , x , y ;
	POS		rotatePoint[ 3 ] ;
	POINT	rotateP[ 3 ] ;
	int i ;

	// �w�肳��Ă���X�v���C�g�̑I��
	SelectObject( hDCWork_ , bmpData_ ) ;

	if ( alphaFlg_ ) {

		// �V�K��Ɨp�f�o�C�X�R���e�L�X�g�̐��� ( �傫�߂ɍ�� )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)(w_ * scaleX_) , (int)(h_ * scaleY_) ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
		ReleaseDC( hWnd_ , hDC ) ;

		// �`�悩��o�b�N�o�b�t�@��؂��� ( �w�i )
		BitBlt( s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
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
				(int)u_ , (int)v_ ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				RGB( 0 , 255 , 0 )
			) ;

		// �A���t�@�u�����h�y�����������z
		s_blendFunc.SourceConstantAlpha = alpha_ ;		// �A���t�@�l������
		AlphaBlend(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				s_tRBWorkHDC ,
				0 , 0 ,
				(int)(w_ * scaleX_) , (int)(h_ * scaleY_) ,
				s_blendFunc
			) ;

		// DC �� �r�b�g�}�b�v�̈�̉��
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;
	}
	else if ( rotateFlg_ )
	{
		// �p�x�� radian �ɕϊ�
		radian = degree_ * 3.14f / 180.0f ;

		// ���㒸�_����]�ϊ�
		// �_�̈ʒu�����߂�
		rotatePoint[ 0 ].x = -( w_ / 2.0f ) ;
		rotatePoint[ 0 ].y = -( h_ / 2.0f ) ;
		x = rotatePoint[ 0 ].x ;
		y = rotatePoint[ 0 ].y ;
		// ���@�̒藝
		rotatePoint[ 0 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 0 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// �E�㒸�_����]�ϊ�
		rotatePoint[ 1 ].x = ( w_ / 2.0f ) ;
		rotatePoint[ 1 ].y = -( h_ / 2.0f ) ;
		x = rotatePoint[ 1 ].x ;
		y = rotatePoint[ 1 ].y ;
		rotatePoint[ 1 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 1 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// �������_����]�ϊ�
		rotatePoint[ 2 ].x = -( w_ / 2.0f ) ;
		rotatePoint[ 2 ].y = ( h_ / 2.0f ) ;
		x = rotatePoint[ 2 ].x ;
		y = rotatePoint[ 2 ].y ;
		rotatePoint[ 2 ].x = ( x * cos(radian) - y * sin(radian) ) ;
		rotatePoint[ 2 ].y = ( x * sin(radian) + y * cos(radian) ) ;

		// ���s�ړ��Œ��S�ʒu��߂�
		for ( i = 0 ; i < 3 ; i++ )
		{
			rotatePoint[ i ].x += ( w_ / 2.0f ) ;
			rotatePoint[ i ].y += ( h_ / 2.0f ) ;
		}

		// ��Ɨp�f�o�C�X�R���e�L�X�g�̐��� ( �傫�߂ɍ�� )
		hDC = GetDC( hWnd_ ) ;
		s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
		s_tRBWorkBmp = CreateCompatibleBitmap( hDC , (int)w_ , (int)h_ ) ;
		SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
		ReleaseDC( hWnd_ , hDC ) ;

		// ��ƃf�o�C�X�R���e�L�X�g���J���[�L�[�œh��Ԃ�
		RECT fillBox ;
		fillBox.left = 0 ;
		fillBox.top = 0 ;
		fillBox.right = (LONG)w_ ;
		fillBox.bottom = (LONG)h_ ;
		HBRUSH hBrush ;
		hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
		FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
		DeleteObject( hBrush ) ;

		// POINT�^�ɂ���
		for ( i = 0 ; i < 3 ; i++ )
		{
			rotateP[ i ].x = ( int )rotatePoint[ i ].x ;
			rotateP[ i ].y = ( int )rotatePoint[ i ].y ;
		}

		// ��Ɨp�ɓ]��
		PlgBlt( s_tRBWorkHDC ,
				rotateP ,
				hDCWork_ ,
				0 , 0 ,
				(int)w_ ,
				(int)h_ ,
				NULL ,
				0 , 0
			) ;

		// �o�b�N�o�b�t�@�ɓ]��
		TransparentBlt(
				hDCBack_ ,
				(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
				(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
				s_tRBWorkHDC ,
				(int)u_ , (int)v_ ,
				(int)w_ , (int)h_ ,
				RGB( 0 , 255 , 0 )
			) ;

		// DC �� �r�b�g�}�b�v�̈�̉��
		DeleteDC( s_tRBWorkHDC ) ;
		DeleteObject( s_tRBWorkBmp ) ;

	} else {

		// �o�b�N�o�b�t�@�֓]��
		TransparentBlt(
			hDCBack_ ,
			(int)( x_ - ((w_*scaleX_/2)*anchorX_) ) , (int)( y_ - ((h_*scaleX_/2)*anchorY_) ) ,
			(int)( w_ * scaleX_ ) , (int)( h_ * scaleY_ ) ,
			hDCWork_ ,
			(int)u_ , (int)v_ ,
			(int)w_ , (int)h_ ,
			RGB( 0 , 255 , 0 )
		) ;

	}

	// �I�������̂ŏ�����
	Initialize( ) ;

	return ( true ) ;
}

int Renderer::DrawRote( const TCHAR* url )
{
	int Handle;     // �摜�i�[�p�n���h��
	Handle = LoadGraph( url ) ;
	DrawRotaGraph( x_ ,  y_ , 1.0f , degree_ , Handle , FALSE ) ;

	return( true ) ;

}


/*/
/*	X�� ��  Y�� ���Z�b�g
/*/
int Renderer::setPos( float arg_x , float arg_y )
{
	x_ = arg_x ;
	y_ = arg_y ;

	return( true ) ;
}

/*/
/*	�؂�o�����W�̃Z�b�g
/*/
int Renderer::setUV( float arg_u , float arg_v )
{
	u_ = arg_u ;
	v_ = arg_v ;

	return( true ) ;
}

/*/
/*	�؂�o���������̃Z�b�g
/*/
int Renderer::setWH( float arg_w , float arg_h )
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
	setAlphaFlg( true ) ;
	alpha_ = arg_alpha ;	

	return( true ) ;
}

/*/
/*	�p�x�̃Z�b�g
/*/
int Renderer::setAngle( float arg_degree )
{
	setRotateFlg( true ) ;
	degree_ = arg_degree ;

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


