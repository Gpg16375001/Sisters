
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
	BitmapData::GetInstance()->loadData(  0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;					// �w�i01
	BitmapData::GetInstance()->loadData(  2 , TEXT("data/image/chips/all_grass.bmp") , 1024 , 512 ) ;			// �n�� ( �`�b�v )
	BitmapData::GetInstance()->loadData(  3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 128 , 128 ) ;		// �ۋ�
	BitmapData::GetInstance()->loadData(  5 , TEXT("data/image/sprites/gimic/movefloor.bmp") , 256 , 64 ) ;		// ������
	BitmapData::GetInstance()->loadData(  6 , TEXT("data/image/bgs/bg02.bmp") , 2000 , 1000 ) ;					// �w�i02
	BitmapData::GetInstance()->loadData(  7 , TEXT("data/image/sprites/gimic/huriko.bmp") , 128 , 128 ) ;		// �U��q ( �{�� )
	BitmapData::GetInstance()->loadData(  8 , TEXT("data/image/sprites/gimic/rope.bmp") , 320 , 320 ) ;			// �U��q ( �� )
	BitmapData::GetInstance()->loadData(  9 , TEXT("data/image/sprites/gimic/shock.bmp") , 128 , 64 ) ;			// �d�C
	BitmapData::GetInstance()->loadData( 10 , TEXT("data/image/sprites/gimic/speedup.bmp") , 128 , 64 ) ;		// �X�s�[�h�A�b�v
	BitmapData::GetInstance()->loadData( 11 , TEXT("data/image/sprites/PlayerDeth.bmp") , 200 , 178 ) ;			// �v���C���[�̎��ɊG
	BitmapData::GetInstance()->loadData( 12 , TEXT("data/image/sprites/hp.bmp") , 200 , 178 ) ;					// �n�[�g
	BitmapData::GetInstance()->loadData( 13 , TEXT("data/image/sprites/gimic/cloud.bmp") , 128 , 64 ) ;			// �_
	BitmapData::GetInstance()->loadData( 14 , TEXT("data/image/sprites/vball.bmp") , 200 , 178 ) ;				// �o���A
	BitmapData::GetInstance()->loadData( 15 , TEXT("data/image/sprites/gimic/ammo.bmp") , 64 , 64 ) ;			// �e
	BitmapData::GetInstance()->loadData( 16 , TEXT("data/image/sprites/gimic/enemy_pod.bmp") , 256 , 64 ) ;		// �GPod
	BitmapData::GetInstance()->loadData( 17 , TEXT("data/image/bgs/bg03.bmp") , 1000 , 800 ) ;					// �w�i03 ( �^���� )
	BitmapData::GetInstance()->loadData( 18 , TEXT("data/image/sprites/object/grass.bmp") , 200 , 64 ) ;		// ����

	BitmapData::GetInstance()->loadData( 20 , TEXT("data/image/sprites/player/PlayerR01.bmp") , 200 , 178 ) ;	// �v���C���[�E���� �Î~01
	BitmapData::GetInstance()->loadData( 21 , TEXT("data/image/sprites/player/PlayerR02.bmp") , 200 , 178 ) ;	// �v���C���[�E���� �Î~02
	BitmapData::GetInstance()->loadData( 22 , TEXT("data/image/sprites/player/PlayerR03.bmp") , 200 , 178 ) ;	// �v���C���[�E���� �Î~03
	BitmapData::GetInstance()->loadData( 23 , TEXT("data/image/sprites/player/PlayerR04.bmp") , 200 , 178 ) ;	// �v���C���[�E���� �Î~04
	BitmapData::GetInstance()->loadData( 24 , TEXT("data/image/sprites/player/PlayerR05.bmp") , 200 , 178 ) ;	// �v���C���[�E���� ����01
	BitmapData::GetInstance()->loadData( 25 , TEXT("data/image/sprites/player/PlayerR06.bmp") , 200 , 178 ) ;	// �v���C���[�E���� ����02
	BitmapData::GetInstance()->loadData( 26 , TEXT("data/image/sprites/player/PlayerR07.bmp") , 200 , 178 ) ;	// �v���C���[�E���� ����03
	BitmapData::GetInstance()->loadData( 27 , TEXT("data/image/sprites/player/PlayerR08.bmp") , 200 , 178 ) ;	// �v���C���[�E���� ����04
	BitmapData::GetInstance()->loadData( 28 , TEXT("data/image/sprites/player/PlayerR09.bmp") , 200 , 178 ) ;	// �v���C���[�E���� �W�����v
	BitmapData::GetInstance()->loadData( 29 , TEXT("data/image/sprites/player/PlayerR10.bmp") , 200 , 178 ) ;	// �v���C���[�E���� ����
	BitmapData::GetInstance()->loadData( 30 , TEXT("data/image/sprites/player/PlayerL01.bmp") , 200 , 178 ) ;	// �v���C���[������ �Î~01
	BitmapData::GetInstance()->loadData( 31 , TEXT("data/image/sprites/player/PlayerL02.bmp") , 200 , 178 ) ;	// �v���C���[������ �Î~02
	BitmapData::GetInstance()->loadData( 32 , TEXT("data/image/sprites/player/PlayerL03.bmp") , 200 , 178 ) ;	// �v���C���[������ �Î~03
	BitmapData::GetInstance()->loadData( 33 , TEXT("data/image/sprites/player/PlayerL04.bmp") , 200 , 178 ) ;	// �v���C���[������ �Î~04
	BitmapData::GetInstance()->loadData( 34 , TEXT("data/image/sprites/player/PlayerL05.bmp") , 200 , 178 ) ;	// �v���C���[������ ����01
	BitmapData::GetInstance()->loadData( 35 , TEXT("data/image/sprites/player/PlayerL06.bmp") , 200 , 178 ) ;	// �v���C���[������ ����02
	BitmapData::GetInstance()->loadData( 36 , TEXT("data/image/sprites/player/PlayerL07.bmp") , 200 , 178 ) ;	// �v���C���[������ ����03
	BitmapData::GetInstance()->loadData( 37 , TEXT("data/image/sprites/player/PlayerL08.bmp") , 200 , 178 ) ;	// �v���C���[������ ����04
	BitmapData::GetInstance()->loadData( 38 , TEXT("data/image/sprites/player/PlayerL09.bmp") , 200 , 178 ) ;	// �v���C���[������ �W�����v
	BitmapData::GetInstance()->loadData( 39 , TEXT("data/image/sprites/player/PlayerL10.bmp") , 200 , 178 ) ;	// �v���C���[������ ����

	BitmapData::GetInstance()->loadData( 60 , TEXT("data/image/sprites/start2.bmp") , 256 , 40 ) ;				// �X�^�[�g
	BitmapData::GetInstance()->loadData( 61 , TEXT("data/image/sprites/object/hunsui.bmp") , 800 , 178 ) ;		// ����
	BitmapData::GetInstance()->loadData( 62 , TEXT("data/image/sprites/object/kanban.bmp") , 200 , 178 ) ;		// �Ŕ�
	BitmapData::GetInstance()->loadData( 63 , TEXT("data/image/sprites/waiwai.bmp") , 400 , 178 ) ;				// ���A�N�V�����i�킢�킢�j

	// �w�i�ǂݍ���
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;
	BackGround::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 6 ) ) ;

	SceneCut::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 17 ) ) ;

	// �`�b�v�ǂݍ���
	Chip::GetInstance()->setMapSize( CHIP_MAP_SIZE_X , CHIP_MAP_SIZE_Y ) ;
	Chip::GetInstance()->RenderMapSize( 12 + 10 , 10 + 4 ) ;
	Chip::GetInstance()->loadBmpDataAll( BitmapData::GetInstance()->getBmpData( 2 ) ) ;

	// Sprite �̓ǂݍ���
//	Sprite::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 4 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 60 ) ) ;	// �X�^�[�g
	Sprite::GetInstance()->loadBmpData( 3 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 4 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 5 , BitmapData::GetInstance()->getBmpData( 14 ) ) ;
	Sprite::GetInstance()->loadBmpData( 8 , BitmapData::GetInstance()->getBmpData( 12 ) ) ;
	Sprite::GetInstance()->loadBmpDataFor( 10 , BitmapData::GetInstance()->getBmpData( 3 ) , 40 ) ;		// 10 ~ 49 �܂Ł@�܂�̂�
	Sprite::GetInstance()->loadBmpDataFor( 50 , BitmapData::GetInstance()->getBmpData( 5 ) , 40 ) ;		// 50 ~ 89 �܂Ł@������
	Sprite::GetInstance()->loadBmpDataFor( 90 , BitmapData::GetInstance()->getBmpData( 8 ) , 10 ) ;		// 90 ~ 99 �܂Ł@�U��q�̂�����
	Sprite::GetInstance()->loadBmpDataFor( 100 , BitmapData::GetInstance()->getBmpData( 7 ) , 10 ) ;	// 100 ~ 109 �܂Ł@�U��q
	Sprite::GetInstance()->loadBmpDataFor( 150 , BitmapData::GetInstance()->getBmpData( 13 ) , 20 ) ;	// 150 ~ 199 �܂Ł@�_
	Sprite::GetInstance()->loadBmpDataFor( 200 , BitmapData::GetInstance()->getBmpData( 16 ) , 20 ) ;	// 200 ~ 219 �܂Ł@�G�|�b�h

	Sprite::GetInstance()->loadBmpDataFor( 250 , BitmapData::GetInstance()->getBmpData( 18 ) , 50 ) ;	// 250 ~ 299 �܂Ł@��
	Sprite::GetInstance()->loadBmpDataFor( 300 , BitmapData::GetInstance()->getBmpData( 61 ) , 10 ) ;	// 300 ~ 309 �܂Ł@����
	Sprite::GetInstance()->loadBmpDataFor( 310 , BitmapData::GetInstance()->getBmpData( 62 ) , 10 ) ;	// 309 ~ 319 �܂Ł@�Ŕ�
	Sprite::GetInstance()->loadBmpDataFor( 320 , BitmapData::GetInstance()->getBmpData( 63 ) , 10 ) ;	// 319 ~ 329 �܂Ł@�킢�킢

	Sprite::GetInstance()->loadBmpDataFor( 400 , BitmapData::GetInstance()->getBmpData( 9 ) , 50 ) ;	// 400 ~ 449 �܂Ł@�d�C
	Sprite::GetInstance()->loadBmpDataFor( 450 , BitmapData::GetInstance()->getBmpData( 10 ) , 10 ) ;	// 450 ~ 459 �܂Ł@SpeedUp
	Sprite::GetInstance()->loadBmpDataFor( 500 , BitmapData::GetInstance()->getBmpData( 15 ) , 500 ) ;	// 500 ~ 999 �܂Ł@�e

	Sprite::GetInstance()->loadBmpData( 1000 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1001 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1002 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1003 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1004 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1005 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1006 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1007 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1008 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1009 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1010 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1011 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1012 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1013 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1014 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1015 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1016 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1017 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1018 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1019 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;

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



