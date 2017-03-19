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
//			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �ۋ�

//			Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;		// ������

			Gimmick::GetInstance()->setPendulums( 100 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;		// �U��q
			Gimmick::GetInstance()->setPendulums( 101 , PTC(76) , PTC(3) , 360 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;
			Gimmick::GetInstance()->setPendulums( 102 , PTC(82) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;

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



