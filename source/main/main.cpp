
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
	/*	WinMain�̃v���V�[�W���ŏ���������̂ł����͊֌W�Ȃ��B
	/*	WinMain�̃v���V�[�W�����I��莟��Ă΂��B
	/*/
	printf( "MainApp�̃v���V�[�W�������s����܂����B\n" ) ;

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
	Renderer::GetInstance()->setHDC( GetHWindow( ) , GetHDCBack( ) , GetHDCWork() ) ;

	// Key ���̎擾 ������
	KeyManager::GetInstance()->Initialize( ) ;

	// �摜�f�[�^�ɂ̏�����
	BitmapData::GetInstance()->Initialize( ) ;

	// �摜�̓ǂݍ���
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/grass_default.bmp") , 64 , 64 ) ;

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

static int mkey[2] = {0,0} ;
/*/
/*	�X�V ( �Z�b�g )
/*/
void MainApp::Update_( )
{
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		mkey[ 0 ]-- ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		mkey[ 0 ]++ ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_UP ) )
	{
		mkey[ 1 ]-- ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_DOWN ) )
	{
		mkey[ 1 ] ++ ;
	}

	// �V�[���̍X�V
	BitmapData::GetInstance()->setBmpData(
			0 ,
			0 ,
			0 , 0 ,
			0 , 0 ,
			1000 , 1000 ,
			1.0f , 1.0f
		) ;
	BitmapData::GetInstance()->setBmpData(
			1 ,
			0 ,
			0 , 200 ,
			0 , 0 ,
			2000 , 178 ,
			1.0f , 1.0f ,
			128 + mkey[ 1 ]
		) ;
	BitmapData::GetInstance()->setBmpData(
			2 ,
			0 ,
			200 + mkey[ 0 ] , 378 + mkey[ 1 ] ,
			0 , 0 ,
			64 , 64 ,
			0.5f , 0.5f ,
			128
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
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , BitmapData::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4d \n" , BitmapData::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					BitmapData::GetInstance()->getBmpData( i ) ,
					BitmapData::GetInstance()->getBmpAnchor( i ) ,
					BitmapData::GetInstance()->getBmpXPos( i ) ,
					BitmapData::GetInstance()->getBmpYPos( i ) ,
					BitmapData::GetInstance()->getBmpUPos( i ) ,
					BitmapData::GetInstance()->getBmpVPos( i ) ,
					BitmapData::GetInstance()->getBmpWidth( i ) ,
					BitmapData::GetInstance()->getBmpHeight( i ) ,
					BitmapData::GetInstance()->getBmpScaleX( i ) ,
					BitmapData::GetInstance()->getBmpScaleY( i ) ,
					BitmapData::GetInstance()->getBmpAlpha( i ) ,
					BitmapData::GetInstance()->getBmpAngle( i )
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



