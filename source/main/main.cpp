
#include <Windows.h>
#include "main.h"
#include "ConsoleWindow.h"

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
	ConsoleWindow console ;

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

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-�p��-> ������
/*/
void MainApp::Initalize( )
{

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


	// �X�V
	Update_( ) ;

	// �`��
	Render_( ) ;
}

/*/
/*	�X�V
/*/
void MainApp::Update_( )
{
	// �V�[���̍X�V

}

/*/
/*	�`��
/*/
void MainApp::Render_( )
{
	// ��ʂ̃N���A

	// �V�[���`��̔z�u

	// �f�o�b�O�̕\��


}



