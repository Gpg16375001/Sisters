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

/*/
/*	 ������
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
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

	// �V�[�����e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			break ;

		case S_PlayTitle :
			break ;

		case S_InitGame :
			break ;

		case S_PlayGame :
			break ;

	}
}



