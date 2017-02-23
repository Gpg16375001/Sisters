/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <math.h>

#include "ConsoleWindow.h"
#include "Renderer.h"

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
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// �g�p����Ă�����
	if ( useFlg_ ) {
	printf( "�o�b�N�o�b�t�@�֓]��\n" ) ;

		/*/
		/*	��]����
		/*/
		if ( rotateFlg_ ) {
			// �p�x�� radian �ɕϊ�
			radian = degree_ * 3.14f / 180.0f ;

			// ���㒸�_����]�ϊ�
			// �_�̈ʒu�����߂�
			rotatePoint[ 0 ].x = -( w_ / 2 ) ;
			rotatePoint[ 0 ].y = -( h_ / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			// ���@�̒藝
			rotatePoint[ 0 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// �E�㒸�_����]�ϊ�
			rotatePoint[ 1 ].x = ( w_ / 2 ) ;
			rotatePoint[ 1 ].y = -( h_ / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// �������_����]�ϊ�
			rotatePoint[ 2 ].x = -( w_ / 2 ) ;
			rotatePoint[ 2 ].y = ( h_ / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// ���s�ړ��Œ��S�ʒu��߂�
			for ( i = 0 ; i < 3 ; i++ ) {
				rotatePoint[ i ].x += ( w_ / 2 ) ;
				rotatePoint[ i ].y += ( h_ / 2 ) ;
			}

			// �r�b�g�}�b�v��I��
			SelectObject( hDCWork_ , bmp_ ) ;

			// ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( hWnd_ ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , w_ , h_ ) ;	// �傫��������Ȃ��ꍇ�ς���
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
			ReleaseDC( hWnd_ , hDC ) ;

			// ��ƃf�o�C�X�R���e�L�X�g���J���[�L�[�œh��Ԃ�
			RECT fillBox ;
			fillBox.left = 0 ;
			fillBox.top = 0 ;
			fillBox.right = w_ ;
			fillBox.bottom = h_ ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// ��Ɨp�ɓ]��
			PlgBlt( s_tRBWorkHDC , rotatePoint , hDCWork_ , u_ , v_ , w_ , h_ , NULL , 0 , 0 ) ;

			// �o�b�N�o�b�t�@�ɓ]��
			TransparentBlt(
					hDCWork_ ,
					x_ , y_ ,
					w_ , h_ ,
					s_tRBWorkHDC ,
					u_ , v_ ,
					w_ , h_ ,
					RGB( 0 , 255 , 0 )
				) ;

			// DC �� �r�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;

		} 

		/*/
		/*	�o�b�N�o�b�t�@�֓]��
		/*/
		// �w�肳��Ă���X�v���C�g�̑I��
		SelectObject( hDCWork_ , bmp_ ) ;

		TransparentBlt(
				*hDCBack_ ,
				x_ , y_ ,
				(int)(w_ * scaleX_) ,
				(int)(h_ * scaleY_) ,
				hDCWork_ ,
				u_ , v_ ,
				w_ , h_ ,
				RGB( 0 , 255 , 0 )
			) ;

		/*/
		/*	����������������ꍇ
		/*/
		if ( alphaFlg_ ) {
			// �w�肳��Ă���X�v���C�g�̑I��
			SelectObject( hDCWork_ , bmp_ ) ;

			// ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( hWnd_ ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , w_ , h_ ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
			ReleaseDC( hWnd_ , hDC ) ;

			// �`�悩��o�b�N�o�b�t�@��؂��� (�w�i)
			BitBlt( s_tRBWorkHDC , 0 , 0 , w_ , h_ , *hDCBack_ , x_ , y_ , SRCCOPY ) ;

			// �؂�����DC�ɕ`�悵�����摜�𒣂�t����y�����ŏ�ɒ���t����r�b�g�}�b�v����������z
			TransparentBlt(
					s_tRBWorkHDC ,
					0 , 0 ,
					w_ , h_ ,
					hDCWork_ ,
					u_ , v_ ,
					w_ , h_ ,
					RGB( 0 , 255 , 0 )
				) ;

			// �A���t�@�u�����h�y�����������z
			s_blendFunc.SourceConstantAlpha = alpha_ ;		// �A���t�@�l������
			AlphaBlend(
					*hDCBack_ ,
					x_ , y_ ,
					w_ , h_ ,
					s_tRBWorkHDC ,
					0 , 0 ,
					w_ , h_ ,
					s_blendFunc
				) ;

			// DC �� �r�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			
			printf("setAlpha was true ! \n") ;

		}

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



