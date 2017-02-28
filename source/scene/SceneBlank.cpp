/*
______________________________________________________________________________________________

	FILE	: SceneBlank.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBlank�N���X

	SceneBlank�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "SceneBlank.h"

/*/
/*	�R���X�g���N�^
/*/
SceneBlank::SceneBlank( )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	�f�X�g���N�^
/*/
SceneBlank::~SceneBlank( )
{
	Initialize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ������
/*/
void SceneBlank::Initialize( )
{
	printf( "SceneBlank -> " ) ;

}

/*/
/*	 �X�V
/*/
void SceneBlank::Update( )
{
	static float spin = 0.0f ;

	// �V�[�����e
	for ( int i = 0 ; i < Chip::GetInstance()->getMapSizeX() * Chip::GetInstance()->getMapSizeY() ; ++i )
	{
		Chip::GetInstance()->setChipMap( 
				(i % Chip::GetInstance()->getMapSizeX()) ,
				(i / Chip::GetInstance()->getMapSizeX()) ,
				g_mapData01[ i ]
			) ;
	}

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
			500 , 300 ,
			0 , 0 ,
			128 , 128 ,
			1.0f , 1.0f ,
			255 ,
			spin += 2.0f
		) ;

	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		Chip::GetInstance()->setScrollSize( -2 , 0 ) ;

	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		Chip::GetInstance()->setScrollSize( 2 , 0 ) ;

}

/*/
/*	 �`��
/*/
void SceneBlank::Render( )
{
	// �V�[�����e

	/*/
	/*	�w�i�`��
	/*/
	for ( int i = 0 ; i < BackGround::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BackGround::GetInstance()->getUseFlg( i ) )
		{
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
			//printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			//printf( "��������  true=1  �F%4d \n" , Sprite::GetInstance()->getUseAlpha( i ) ) ;
			//printf( "�����x    alpha   �F%4d \n" , Sprite::GetInstance()->getBmpAlpha( i ) ) ;
			//printf( "��]����  true=1  �F%4d \n" , Sprite::GetInstance()->getUseRotate( i ) ) ;
			//printf( "��]�p�x  angle   �F%4.0f \n" , Sprite::GetInstance()->getBmpAngle( i ) ) ;
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


}



