
#include <Windows.h>
#include "main.h"
#include "ConsoleWindow.h"
#include "BitmapData.h"
#include "BackDropScreen.h"
#include "Renderer.h"

ConsoleWindow console ;

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
	printf( "MainApp �̃v���V�[�W��\n" ) ;

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-�p��-> ������
/*/
void MainApp::Initalize( )
{
	// �摜�̓ǂݍ���
	Renderer::GetInstance()->setHWindow( GetHWindow( ) ) ;
	Renderer::GetInstance()->setHDC( GetBackHDC( ) ) ;

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
	// �V�[���̍X�V
	Renderer::GetInstance()->setRender( 
		(HBITMAP)LoadImage( NULL , TEXT("C:/work/Sisters/data/image/bg/bg01.bmp") , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE ) ,
		0 ,
		0 , 0 ,
		0 , 0 ,
		1000 , 1000
		) ;

}

/*/
/*	�`��
/*/
void MainApp::Render_( )
{
	printf( "���C���`��\n" ) ;
	// ��ʂ̃N���A


	// �V�[���`��̔z�u
	Renderer::GetInstance()->draw( ) ;

	// �f�o�b�O�̕\��


}



