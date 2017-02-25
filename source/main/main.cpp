
#include <Windows.h>
#include "main.h"
#include "Common.h"

int WINAPI WinMain( HINSTANCE , HINSTANCE , LPSTR , int )
{
	// �N���X���ƃ^�C�g���̐ݒ�
	MainApp app( TEXT("Sisters") , TEXT("Sisters") ) ;

	// �A�v�����X�^�[�g
	app.Start( ) ;

	return 0;
}


/*/
/*	�R���X�g���N�^
/*/
MainApp::MainApp( TCHAR* szClassName , TCHAR* szTitleName )
	: WinMain( szClassName , szTitleName )
	, is_debug_render_( true )
{
	printf( "�n�܂�����!\n" ) ;

}

/*/
/*	�f�X�g���N�^
/*/
MainApp::~MainApp( )
{

}

/*/
/*	<-�p��-> �E�C���h�v���V�[�W��
/*/
LRESULT MainApp::WndProc( HWND hWnd , UINT msg , UINT wParam , LONG lParam )
{
	/*/
	/*	WinMain�̃v���V�[�W���ŏ���������̂ł����͊֌W�Ȃ�
	/*	window���}�����Ă���Ƃ������
	/*/

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-�p��-> ������
/*/
void MainApp::Initalize( )
{
	
	// ���Ԃ̏�����
	old_time_ = timeGetTime( ) ;
	start_time_ = old_time_ ;

	/*
	// ����ʐ���
	HDC hDC = GetDC( hWnd_ ) ;
	hDCBack_ = CreateCompatibleDC( hDC ) ;
	bitmap_ = CreateCompatibleBitmap( hDC , wSize_w_ , wSize_h_ ) ;
	SelectObject( hDCBack_ , bitmap_ ) ;							// �f�X�g���N�^�ŉ�������
	ReleaseDC( hWnd_ , hDC ) ;
	*/

	static HBITMAP s_hBackBufBmp ;
	// ����ʂ̍쐬
	HDC hDC = GetDC( hWnd_ ) ;													// �w��E�B���h�E�N���X�̃f�o�C�X�R���e�L�X�g�̎擾
	g_hWorkBuf = CreateCompatibleDC( hDC ) ;								// ���p�̃f�o�C�X�R���e�L�X�g
	s_hBackBufBmp = CreateCompatibleBitmap( hDC , wSize_w_, wSize_h_ ) ;	// �N���C�A���g�̈�̃r�b�g�}�b�v�𐶐�
	g_hBackBuf = CreateCompatibleDC( hDC ) ;								// �o�b�N�o�b�t�@�p�̃f�o�C�X�R���e�L�X�g
	SelectObject( g_hBackBuf , s_hBackBufBmp ) ;							// �o�b�N�o�b�t�@��DC��BMP���Z�b�g����
	ReleaseDC( hWnd_ , hDC ) ;												// �f�o�C�X�R���e�L�X�g�̉��

	// �摜�̓ǂݍ���
	g_bDataBGTable[ 0 ].loadData( TEXT("data/image/bg/bg01.bmp") , 960 , 540 ) ;

}

/*/
/*	<-�p��-> �I����
/*/
void MainApp::Finalize( )
{

}

/*/
/*	<-�p��-> ���C�����[�v
/*/
void MainApp::Update( )
{
	// �L�[���X�V
	printf( "���C�����[�v\n" ) ;

	// �X�V
	Update_( ) ;

	// �`��
	Render_( ) ;
}

/*/
/*	�X�V ( �Z�b�g )
/*/
void MainApp::Update_( )
{
	g_bds.selectBmp( 0 ) ;

}

/*/
/*	�`��
/*/
void MainApp::Render_( )
{
	printf( "���C���`��\n" ) ;
	// ��ʂ̃N���A


	// �V�[���`��̔z�u
	g_bds.Render( ) ;

	// �f�o�b�O�̕\��


}



