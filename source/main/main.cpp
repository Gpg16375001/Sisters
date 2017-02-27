
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
	BackGround::GetInstance()->Initialize( ) ;
	Chip::GetInstance()->Initialize( ) ;
	Sprite::GetInstance()->Initialize( ) ;

	// �摜�̓ǂݍ���
	BitmapData::GetInstance()->loadData( 0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;
	BitmapData::GetInstance()->loadData( 1 , TEXT("data/image/sprites/PlayerL.bmp") , 2000 , 178 ) ;
	BitmapData::GetInstance()->loadData( 2 , TEXT("data/image/chips/all_grass.bmp") , 640 , 500 ) ;
	BitmapData::GetInstance()->loadData( 3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 256 , 256 ) ;

	// �w�i�ǂݍ���
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;

	// �`�b�v�ǂݍ���
	Chip::GetInstance()->setMapSize( 30 , 30 ) ;
	Chip::GetInstance()->RenderMapSize( 16 , 10 ) ;
	Chip::GetInstance()->loadBmpDataAll( BitmapData::GetInstance()->getBmpData( 2 ) ) ;


	// Sprite �̓ǂݍ���
	Sprite::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 3 ) ) ;

	// �V�[��

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
	BackGround::GetInstance()->setBmpData(
			0 ,
			0 ,
			-200 , -200 ,
			0 , 0 ,
			2000 , 1000 ,
			1.0f , 1.0f
		) ;

	Chip::GetInstance()->Update( ) ;

	Sprite::GetInstance()->setBmpData(
			0 ,
			0 ,
			200 , 200 ,
			0 , 0 ,
			256 , 256 ,
			1.0f , 1.0f
		) ;

}

/*/
/*	�`��
/*/
void MainApp::Render_( )
{
	printf( "���C���`��\n" ) ;

	// �V�[���`��̔z�u

	/*/
	/*	�w�i�`��
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BackGround::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , BackGround::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , BackGround::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , BackGround::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4.0f \n" , BackGround::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					BackGround::GetInstance()->getBmpData( i ) ,
					BackGround::GetInstance()->getBmpAnchor( i ) ,
					BackGround::GetInstance()->getBmpXPos( i ) ,
					BackGround::GetInstance()->getBmpYPos( i ) ,
					BackGround::GetInstance()->getBmpUPos( i ) ,
					BackGround::GetInstance()->getBmpVPos( i ) ,
					BackGround::GetInstance()->getBmpWidth( i ) ,
					BackGround::GetInstance()->getBmpHeight( i ) ,
					BackGround::GetInstance()->getBmpScaleX( i ) ,
					BackGround::GetInstance()->getBmpScaleY( i ) ,
					BackGround::GetInstance()->getBmpAlpha( i ) ,
					BackGround::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	/*/
	/*	�`�b�v�w�i�`��
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Chip::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , Chip::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , Chip::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , Chip::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4.0f \n" , Chip::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					Chip::GetInstance()->getBmpData( i ) ,
					Chip::GetInstance()->getBmpAnchor( i ) ,
					Chip::GetInstance()->getBmpXPos( i ) ,
					Chip::GetInstance()->getBmpYPos( i ) ,
					Chip::GetInstance()->getBmpUPos( i ) ,
					Chip::GetInstance()->getBmpVPos( i ) ,
					Chip::GetInstance()->getBmpWidth( i ) ,
					Chip::GetInstance()->getBmpHeight( i ) ,
					Chip::GetInstance()->getBmpScaleX( i ) ,
					Chip::GetInstance()->getBmpScaleY( i ) ,
					Chip::GetInstance()->getBmpAlpha( i ) ,
					Chip::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}


	/*/
	/*	Sprite �`��
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( Sprite::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , Sprite::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , Sprite::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , Sprite::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4.0f \n" , Sprite::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					Sprite::GetInstance()->getBmpData( i ) ,
					Sprite::GetInstance()->getBmpAnchor( i ) ,
					Sprite::GetInstance()->getBmpXPos( i ) ,
					Sprite::GetInstance()->getBmpYPos( i ) ,
					Sprite::GetInstance()->getBmpUPos( i ) ,
					Sprite::GetInstance()->getBmpVPos( i ) ,
					Sprite::GetInstance()->getBmpWidth( i ) ,
					Sprite::GetInstance()->getBmpHeight( i ) ,
					Sprite::GetInstance()->getBmpScaleX( i ) ,
					Sprite::GetInstance()->getBmpScaleY( i ) ,
					Sprite::GetInstance()->getBmpAlpha( i ) ,
					Sprite::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	// ��ʂ̃N���A
	/*/
	/*	�w�i�̃N���A
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		BackGround::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	�`�b�v�̃N���A
	/*/
	for ( int i = 0 ; i < Chip::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Chip::GetInstance()->clearData( i ) ;
	}

	/*/
	/*	Sprite �̃N���A
	/*/
	for ( int i = 0 ; i < Sprite::GetInstance()->getMaxBmp( ) ; ++i )
	{
		Sprite::GetInstance()->clearData( i ) ;
	}

	// �f�o�b�O�̕\��


}



