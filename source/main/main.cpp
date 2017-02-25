
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
/*	WM_CREATE �Ɠ����B( ������̕������� )
/*/
void MainApp::Initalize( )
{
	// �`��ꏊ�̊m��
	Renderer::GetInstance()->Initialize( ) ;
	Renderer::GetInstance()->setHDC( GetHDCBack( ) , GetHDCWork() ) ;

	// Key ���̎擾 ������
	KeyManager::GetInstance()->Initialize( ) ;

	// �摜�f�[�^�ɂ̏�����
	BitmapData::GetInstance()->Initialize( ) ;

	// �摜�̓ǂݍ���
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bg/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/bg/bg01.bmp") , 2000 , 1000 ) ;
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
	printf( "���C�����[�v\n" ) ;
	// �L�[���X�V
	KeyManager::GetInstance()->update( ) ;

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
	BitmapData::GetInstance()->setBmpData(
			0 ,
			0 , 0 ,
			0 , 0 ,
			1000 , 1000
		) ;
	BitmapData::GetInstance()->setBmpData(
			1 ,
			200 , 200 ,
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

	// �V�[���`��̔z�u
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BitmapData::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��FBMP�ԍ�%4d \n" , i ) ;
			Renderer::GetInstance()->selectBmp(
					BitmapData::GetInstance()->getBmpData( i ) ,
					BitmapData::GetInstance()->getBmpXPos( i ) ,
					BitmapData::GetInstance()->getBmpYPos( i ) ,
					BitmapData::GetInstance()->getBmpUPos( i ) ,
					BitmapData::GetInstance()->getBmpVPos( i ) ,
					BitmapData::GetInstance()->getBmpWidth( i ) ,
					BitmapData::GetInstance()->getBmpHeight( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	// ��ʂ̃N���A
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BitmapData::GetInstance()->clearData( i ) ;
	}

	// �f�o�b�O�̕\��


}



