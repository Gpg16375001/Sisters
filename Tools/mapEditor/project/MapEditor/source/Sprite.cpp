/*
______________________________________________________________________________________________

	FILE : Sprite.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		Sprite �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

// �R���X�g���N�^
Sprite::Sprite( ) {
	// �C���X�^���X�����̏�����
	clearSprite( ) ;
}

// �f�X�g���N�^
Sprite::~Sprite( ) {	}

// �X�v���C�g�̃Z�b�g
int Sprite::setSprite(
		int arg_bmpNo ,				// �X�v���C�g�̔ԍ�
		int arg_x , int arg_y ,		// ����̍��W
		int arg_u , int arg_v ,		// �؂�o�����W
		int arg_w , int arg_h 		// ���ƍ���
	) {								 
	// ���ׂĂ̏������Z�b�g
	setFlg( true ) ;				// �t���O�̃Z�b�g
	selectBmp( arg_bmpNo ) ;		// �X�v���C�g�̃Z�b�g
	setPos( arg_x , arg_y ) ;		// ���W�̃Z�b�g
	setUV( arg_u , arg_v ) ;		// �؂�o�����W�̃Z�b�g
	setWH( arg_w , arg_h ) ;		// �؂�o���������̃Z�b�g
	return( true ) ;
}

// �X�v���C�g�̃N���A
int Sprite::clearSprite( ) {
	// ���ׂĂ̏����N���A
	selectBmp( 0 ) ;				// �X�v���C�g�̃Z�b�g
	setPos( 0 , 0 ) ;				// ���W�̃Z�b�g
	setUV( 0 , 0 ) ;				// �؂�o�����W�̃Z�b�g
	setWH( 0 , 0 ) ;				// �؂�o���������̃Z�b�g
	setScaleXY( 0.0 , 0.0 ) ;		// �X�P�[���̃Z�b�g
	setAlpha( 0 ) ;					// �A���t�@�����̃Z�b�g
	setRotate( 0.0f ) ;				// ��]�����̃Z�b�g
	setFlg( false ) ;				// �t���O�̃Z�b�g
	setScaleFlg( false ) ;			// �t���O�̃Z�b�g
	setAlphaFlg( false ) ;			// �t���O�̃Z�b�g
	setRotateFlg( false ) ;			// �t���O�̃Z�b�g
	return( true ) ;
}

// �g�p�t���O�̃Z�b�g
int Sprite::setFlg( int arg_flg ) {
	m_useFlg = arg_flg ;
	return( true ) ;
}

// �`�悵�����X�v���C�g�ԍ����Z�b�g
int Sprite::selectBmp( int arg_bmpNo ) {
	m_bmpNo = arg_bmpNo ;
	return( true ) ;
}

// �`����W�y����z
int Sprite::setPos( int arg_x , int arg_y ) {
	m_x = arg_x ;
	m_y = arg_y ;
	return( true ) ;
}

// �؂�o�����W
int Sprite::setUV( int arg_u , int arg_v ) {
	m_u = arg_u ;
	m_v = arg_v ;
	return( true ) ;
}

// �؂�o��������
int Sprite::setWH( int arg_w , int arg_h ) {
	m_w = arg_w ;
	m_h = arg_h ;
	return( true ) ;
}

// BMP�̕`��
int Sprite::draw( ) {
	HDC hDC ;
	static HDC				s_tRBWorkHDC ;
	static HBITMAP			s_tRBWorkBmp ;
	static BLENDFUNCTION	s_blendFunc = { AC_SRC_OVER , 0 , 255 , 0 } ;
	float radian , x , y ;
	POINT rotatePoint[ 3 ] ;
	int i ;

	// �g�p����Ă�����
	if ( m_useFlg ) {

		if ( m_rotateFlg == (int)true ) {
			// �p�x�� radian �ɕϊ�
			radian = m_degree * 3.14f / 180.0f ;

			// ���㒸�_����]�ϊ�
			// �_�̈ʒu�����߂�
			rotatePoint[ 0 ].x = -( m_w / 2 ) ;
			rotatePoint[ 0 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 0 ].x ;
			y = ( float )rotatePoint[ 0 ].y ;
			// ���@�̒藝
			rotatePoint[ 0 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 0 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// �E�㒸�_����]�ϊ�
			rotatePoint[ 1 ].x = ( m_w / 2 ) ;
			rotatePoint[ 1 ].y = -( m_h / 2 ) ;
			x = ( float )rotatePoint[ 1 ].x ;
			y = ( float )rotatePoint[ 1 ].y ;
			rotatePoint[ 1 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 1 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// �������_����]�ϊ�
			rotatePoint[ 2 ].x = -( m_w / 2 ) ;
			rotatePoint[ 2 ].y = ( m_h / 2 ) ;
			x = ( float )rotatePoint[ 2 ].x ;
			y = ( float )rotatePoint[ 2 ].y ;
			rotatePoint[ 2 ].x = ( int )( x * cos(radian) - y * sin(radian)  ) ;
			rotatePoint[ 2 ].y = ( int )( x * sin(radian) + y * cos(radian)  ) ;

			// ���s�ړ��Œ��S�ʒu��߂�
			for ( i = 0 ; i < 3 ; i++ ) {
				rotatePoint[ i ].x += ( m_w / 2 ) ;
				rotatePoint[ i ].y += ( m_h / 2 ) ;
			}

			// �r�b�g�}�b�v��I��
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
			ReleaseDC( g_hWindow , hDC ) ;

			// ��ƃf�o�C�X�R���e�L�X�g���J���[�L�[�œh��Ԃ�
			RECT fillBox ;
			fillBox.left = 0 ;
			fillBox.top = 0 ;
			fillBox.right = m_w ;
			fillBox.bottom = m_h ;
			HBRUSH hBrush ;
			hBrush = CreateSolidBrush( RGB(0 , 255 , 0) ) ;
			FillRect( s_tRBWorkHDC , &fillBox , hBrush ) ;
			DeleteObject( hBrush ) ;

			// ��Ɨp�ɓ]��
			PlgBlt( s_tRBWorkHDC , rotatePoint , g_hWorkBuf , m_u , m_v , m_w , m_h , NULL , 0 , 0 ) ;

			// �o�b�N�o�b�t�@�ɓ]��
			TransparentBlt(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					s_tRBWorkHDC ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

			// DC �� �r�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;

		} else if ( m_alphaFlg == (int)true ) {		// ����������������ꍇ
			// �w�肳��Ă���X�v���C�g�̑I��
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			// ��Ɨp�f�o�C�X�R���e�L�X�g�̐���
			hDC = GetDC( g_hWindow ) ;
			s_tRBWorkHDC = CreateCompatibleDC( hDC ) ;
			s_tRBWorkBmp = CreateCompatibleBitmap( hDC , m_w , m_h ) ;
			SelectObject( s_tRBWorkHDC , s_tRBWorkBmp ) ;	// �^����
			ReleaseDC( g_hWindow , hDC ) ;

			// �`�悩��o�b�N�o�b�t�@��؂��� (�w�i)
			BitBlt( s_tRBWorkHDC , 0 , 0 , m_w , m_h , g_hBackBuf , m_x , m_y , SRCCOPY ) ;

			// �؂�����DC�ɕ`�悵�����摜�𒣂�t����y�����ŏ�ɒ���t����r�b�g�}�b�v����������z
			TransparentBlt(
					s_tRBWorkHDC ,
					0 , 0 ,
					m_w , m_h ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

			// �A���t�@�u�����h�y�����������z
			s_blendFunc.SourceConstantAlpha = m_alpha ;		// �A���t�@�l������
			AlphaBlend(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					s_tRBWorkHDC ,
					0 , 0 ,
					m_w , m_h ,
					s_blendFunc
				) ;

			// DC �� �r�b�g�}�b�v�̈�̉��
			DeleteDC( s_tRBWorkHDC ) ;
			DeleteObject( s_tRBWorkBmp ) ;
			
			printf("setAlpha was true ! \n") ;

		} else if ( m_scaleFlg == (int)true ) {		// �g�傷��`��
			// �w�肳��Ă���X�v���C�g�̑I��
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			TransparentBlt(
					g_hBackBuf ,
					(m_x / 2) , (m_y / 2) ,
					(int)(m_w * m_scaleX) ,
					(int)(m_h * m_scaleY) ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;

		} else {	// �ʏ�̕`��

			// �w�肳��Ă���X�v���C�g�̑I��
			SelectObject( g_hWorkBuf , g_bDataSprTable[ m_bmpNo ].getBmpData( ) ) ;

			TransparentBlt(
					g_hBackBuf ,
					m_x , m_y ,
					m_w , m_h ,
					g_hWorkBuf ,
					m_u , m_v ,
					m_w , m_h ,
					RGB( 0 , 255 , 0 )
				) ;
		}
	}

	return( true ) ;
}

// �X�P�[���t���O�̃Z�b�g
int Sprite::setScaleFlg( int arg_scaleFlg ) {
	m_scaleFlg = arg_scaleFlg ;
	return( true ) ;
}

// �X�P�[�� (�g�嗦)
int Sprite::setScaleXY( float arg_scaleX , float arg_scaleY ) {
	setScaleFlg( true ) ;
	m_scaleX = arg_scaleX ;
	m_scaleY = arg_scaleY ;
	return( true ) ;
}

// �������̃t���O�Z�b�g
int Sprite::setAlphaFlg( int arg_alphaFlg ) {
	m_alphaFlg = arg_alphaFlg ;
	return( true ) ;
}

// �������̒l�Z�b�g
int Sprite::setAlpha( float arg_alpha ) {
	setAlphaFlg( true ) ;

	m_alpha = (int)( 255 * arg_alpha ) ;

	if ( m_alpha > 255 ) {
		m_alpha = 255 ;
	}

	return( true ) ;
}

// ��]�̃t���O�Z�b�g
int Sprite::setRotateFlg( int arg_rotateFlg ) {
	m_rotateFlg = arg_rotateFlg ;
	return( true ) ;
}

// ��]�p�x���Z�b�g
int Sprite::setRotate( float arg_degree ) {
	setRotateFlg( true ) ;
	m_degree = arg_degree ;
	return( true ) ;
}



