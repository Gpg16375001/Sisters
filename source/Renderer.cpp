/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <math.h>

#include "Common.h"

// �f�X�g���N�^
Renderer::~Renderer( ) {	}

// �X�v���C�g�̃Z�b�g
int Renderer::setRender(
		HBITMAP arg_bmp ,								// . �X�v���C�g�̃p�X
		int anchor ,									// . �A���J�[ ( �z�u�ʒu )
		int arg_x , int arg_y ,							// . ����̍��W
		int arg_u , int arg_v ,							// . �؂�o�����W
		int arg_w , int arg_h ,							// . ���ƍ���
		float arg_scaleX , float arg_scaleY ,			// . �X�P�[���{��
		float arg_degree ,								// . ��]����p�x
		float arg_alpha									// . �����x
	) {
	// ���ׂĂ̏������Z�b�g
	printf( "BMP File Was Set\n" ) ;
	setFlg( true ) ;									// �t���O�̃Z�b�g
	selectBmp( arg_bmp ) ;								// �X�v���C�g�̃Z�b�g
	setPos( arg_x , arg_y ) ;							// ���W�̃Z�b�g
	setUV( arg_u , arg_v ) ;							// �؂�o�����W�̃Z�b�g
	setWH( arg_w , arg_h ) ;							// �؂�o���������̃Z�b�g
	setScaleXY( arg_scaleX , arg_scaleY ) ;				// �X�P�[���̃Z�b�g

	if ( arg_degree != 0 )
	{
		setRotate( arg_degree ) ;						// ��]�����̃Z�b�g
	}
	if ( arg_alpha != 0 )
	{
		setAlpha( arg_alpha ) ;							// �A���t�@�����̃Z�b�g
	}
	return( true ) ;
}

// �X�v���C�g�̃N���A
int Renderer::clearScreen( ) {
	// ���ׂĂ̏����N���A
	selectBmp( NULL ) ;				// �X�v���C�g�̃Z�b�g
	setPos( 0 , 0 ) ;				// ���W�̃Z�b�g
	setUV( 0 , 0 ) ;				// �؂�o�����W�̃Z�b�g
	setWH( 0 , 0 ) ;				// �؂�o���������̃Z�b�g
	setScaleXY( 1.0f , 1.0f ) ;		// �X�P�[���̃Z�b�g
	setAlpha( 0 ) ;					// �A���t�@�����̃Z�b�g
	setRotate( 0.0f ) ;				// ��]�����̃Z�b�g
	setFlg( false ) ;				// �t���O�̃Z�b�g
	setAlphaFlg( false ) ;			// �t���O�̃Z�b�g
	setRotateFlg( false ) ;			// �t���O�̃Z�b�g
	return( true ) ;
}

// �g�p�t���O�̃Z�b�g
int Renderer::setFlg( int arg_flg ) {
	useFlg_ = arg_flg ;
	return( true ) ;
}

// �`�悵�����X�v���C�g���Z�b�g
int Renderer::selectBmp( HBITMAP arg_bmp ) {
	bmp_ = arg_bmp ;
	return( true ) ;
}

// �`����W�y����z
int Renderer::setPos( int arg_x , int arg_y ) {
	x_ = arg_x ;
	y_ = arg_y ;
	return( true ) ;
}

// �؂�o�����W
int Renderer::setUV( int arg_u , int arg_v ) {
	u_ = arg_u ;
	v_ = arg_v ;
	return( true ) ;
}

// �؂�o��������
int Renderer::setWH( int arg_w , int arg_h ) {
	w_ = arg_w ;
	h_ = arg_h ;
	return( true ) ;
}

// BMP�̕`��
int Renderer::draw( ) {
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;

/*
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;
*/

	// �g�p����Ă�����
	if ( useFlg_ ) {
		printf( "�o�b�N�o�b�t�@�֓]��\n" ) ;

		// ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
		hDC = GetDC( hWnd_ ) ;
		hDCWork_ = CreateCompatibleDC( hDC ) ;
		bmp_ = CreateCompatibleBitmap( hDC , w_ , h_ ) ;
		SelectObject( hDCWork_ , bmp_ ) ;
		ReleaseDC( hWnd_ , hDC ) ;

		TransparentBlt(
			*hDCBack_ ,
			x_ , y_ ,
			w_ , h_ ,
			hDCWork_ ,
			u_ , v_ ,
			w_ , h_ ,
			RGB( 0 , 255 , 0 )
			) ;

	}

	return( true ) ;
}

// �X�P�[�� (�g�嗦)
int Renderer::setScaleXY( float arg_scaleX , float arg_scaleY ) {
	scaleX_ = arg_scaleX ;
	scaleY_ = arg_scaleY ;
	return( true ) ;
}

// �������̃t���O�Z�b�g
int Renderer::setAlphaFlg( int arg_alphaFlg ) {
	alphaFlg_ = arg_alphaFlg ;
	return( true ) ;
}

// �������̒l�Z�b�g
int Renderer::setAlpha( float arg_alpha ) {
	setAlphaFlg( true ) ;

	alpha_ = (int)( 255 * arg_alpha ) ;

	if ( alpha_ > 255 ) {
		alpha_ = 255 ;
	}

	return( true ) ;
}

// ��]�̃t���O�Z�b�g
int Renderer::setRotateFlg( int arg_rotateFlg ) {
	rotateFlg_ = arg_rotateFlg ;
	return( true ) ;
}

// ��]�p�x���Z�b�g
int Renderer::setRotate( float arg_degree ) {
	setRotateFlg( true ) ;
	degree_ = arg_degree ;
	return( true ) ;
}



