/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManager�N���X

	SceneManager�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "SceneBlank.h"
#include "SceneTitle.h"

/*/
/*	 ������
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
}

/*/
/*	 �I����
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	�f�X�g���N�^
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 �X�V
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;
	SceneTitle title ;

	// �V�[�����e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			// �M�~�b�N�̏����Z�b�g
			Gimmick::GetInstance()->Initialize( ) ;
			// �M�~�b�N���Z�b�g
			Gimmick::GetInstance()->setCircularSaws( 10 , 2216 , 300 , 360 , 10 , GIMMICK_MODE_LEFTRIGHT ) ;
			Gimmick::GetInstance()->setCircularSaws( 11 , 2408 , 300 , 360 , 10 , GIMMICK_MODE_CYCLE ) ;
			Gimmick::GetInstance()->setCircularSaws( 12 , 2600 , 200 , 360 , 90 , GIMMICK_MODE_LEFTRIGHT ) ;
			Gimmick::GetInstance()->setCircularSaws( 13 , 2792 , 200 , 360 , 90 , GIMMICK_MODE_CYCLE ) ;
			Gimmick::GetInstance()->setCircularSaws( 14 , 2984 , 300 , 360 , 120 , GIMMICK_MODE_UPDOWN ) ;

			g_state++ ;
			break ;

		case S_PlayTitle :
			title.Update( ) ;
			title.Render( ) ;
			break ;

		case S_InitGame :
			break ;

		case S_PlayGame :
			break ;

	}
}



