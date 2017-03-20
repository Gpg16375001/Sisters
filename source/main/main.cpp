
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
//	printf( "MainApp�̃v���V�[�W�������s����܂����B\n" ) ;

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-�p��-> ������
/*	WM_CREATE �Ɠ����B( ������̕������� )
/*/
void MainApp::Initalize( )
{
	printf( "//-----------------------------------\n" ) ;
	printf( "Initialize �����s����܂���\n" );

	// �`��ꏊ�̊m��
	Renderer::GetInstance()->Initialize( ) ;
	Renderer::GetInstance()->setHDC( GetHWindow( ) , GetHDCBack( ) , GetHDCWork() ) ;

	// Key ���̎擾 ������
	KeyManager::GetInstance()->Initialize( ) ;

	// �摜�f�[�^�ɂ̏�����
	BitmapData::GetInstance()->Initialize( ) ;
	BackGround::GetInstance()->Initialize( ) ;
	Chip::GetInstance()->Initialize( ) ;
	Sprite::GetInstance()->Initialize( ) ;

	// �摜�̓ǂݍ���
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerR.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/all_grass.bmp") , 640 , 500 ) ;
	BitmapData::GetInstance()->loadData( 3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 128 , 128 ) ;
	BitmapData::GetInstance()->loadData( 4 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 5 , TEXT("data/image/sprites/gimic/movefloor.bmp") , 256 , 64 ) ;
	BitmapData::GetInstance()->loadData( 6 , TEXT("data/image/bgs/bg02.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 7 , TEXT("data/image/sprites/gimic/huriko.bmp") , 128 , 128 ) ;
	BitmapData::GetInstance()->loadData( 8 , TEXT("data/image/sprites/gimic/rope.bmp") , 512 , 512 ) ;
	BitmapData::GetInstance()->loadData( 9 , TEXT("data/image/sprites/gimic/shock.bmp") , 128 , 64 ) ;
	BitmapData::GetInstance()->loadData( 10 , TEXT("data/image/sprites/gimic/speedup.bmp") , 128 , 64 ) ;
	BitmapData::GetInstance()->loadData( 11 , TEXT("data/image/sprites/PlayerDeth.bmp") , 200 , 178 ) ;
	BitmapData::GetInstance()->loadData( 12 , TEXT("data/image/sprites/hp.bmp") , 200 , 178 ) ;
	BitmapData::GetInstance()->loadData( 13 , TEXT("data/image/sprites/gimic/cloud.bmp") , 128 , 64 ) ;
	
	// �w�i�ǂݍ���
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;
	BackGround::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 6 ) ) ;

	// �`�b�v�ǂݍ���
	Chip::GetInstance()->setMapSize( CHIP_MAP_SIZE_X , CHIP_MAP_SIZE_Y ) ;
	Chip::GetInstance()->RenderMapSize( 12 + 10 , 10 + 4 ) ;
	Chip::GetInstance()->loadBmpDataAll( BitmapData::GetInstance()->getBmpData( 2 ) ) ;

	// Sprite �̓ǂݍ���
	Sprite::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 4 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 1 ) ) ;
	Sprite::GetInstance()->loadBmpData( 3 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 4 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 8 , BitmapData::GetInstance()->getBmpData( 12 ) ) ;
	Sprite::GetInstance()->loadBmpDataFor( 10 , BitmapData::GetInstance()->getBmpData( 3 ) , 40 ) ;		// 10 ~ 49 �܂Ł@�܂�̂�
	Sprite::GetInstance()->loadBmpDataFor( 50 , BitmapData::GetInstance()->getBmpData( 5 ) , 40 ) ;		// 50 ~ 89 �܂Ł@������
	Sprite::GetInstance()->loadBmpDataFor( 90 , BitmapData::GetInstance()->getBmpData( 8 ) , 10 ) ;		// 90 ~ 99 �܂Ł@�U��q�̂�����
	Sprite::GetInstance()->loadBmpDataFor( 100 , BitmapData::GetInstance()->getBmpData( 7 ) , 10 ) ;	// 100 ~ 109 �܂Ł@�U��q
	Sprite::GetInstance()->loadBmpDataFor( 400 , BitmapData::GetInstance()->getBmpData( 9 ) , 50 ) ;	// 400 ~ 449 �܂Ł@�d�C
	Sprite::GetInstance()->loadBmpDataFor( 450 , BitmapData::GetInstance()->getBmpData( 10 ) , 10 ) ;	// 450 ~ 459 �܂Ł@SpeedUp
	Sprite::GetInstance()->loadBmpDataFor( 150 , BitmapData::GetInstance()->getBmpData( 13 ) , 20 ) ;	// 150 ~ 199 �܂Ł@�_

	// �V�[��
	SceneManager::GetInstance()->Initialize() ;
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
	printf( "//-----------------------------------\n" ) ;
	printf( "���C�����[�v : Update�C�x���g�����s����܂���\n" );
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
	SceneManager::GetInstance()->Update( g_state ) ;			// -------------------------------------- Gvl

}

/*/
/*	�`��
/*/
void MainApp::Render_( )
{
	printf( "Main::Render_ �����s����܂���\n" ) ;

	// �V�[���`��̔z�u
//	SceneManager::GetInstance()->Render( ) ;

	// �f�o�b�O�̕\��


}



