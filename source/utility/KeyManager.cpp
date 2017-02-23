/*
______________________________________________________________________________________________

	FILE	: KeyManager.cpp
	NAME	: Teacher.K

	________/ Explanation of file /___________________________________________________________
    
		KeyManager�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>

#include "KeyManager.h"


/*/
/*	�f�X�g���N�^
/*/
KeyManager::~KeyManager( )
{
	// �I�����o��
	printf( "Management of a keystroke is ended.\n" ) ;
}

/*/
/*	������
/*/
void KeyManager::Initialize( )
{
	// �Ƃ肠�����f�[�^����Ƃ�
	GetKeyboardState( m_bKeyTbl ) ;

	// �J�n���o��
	printf( "Management of a keystroke is started.\n" ) ;

}

/*/
/*	�L�[���̍X�V
/*/
int KeyManager::update( )
{
	// �Ƃ肠�����f�[�^����Ƃ�
	return( GetKeyboardState( m_bKeyTbl ) ) ;
}

/*/
/*	�L�[���̎擾
/*/
BYTE KeyManager::getKeyState( BYTE arg_keyCode )
{
	// �n���ꂽ�L�[����Ԃ�
	return( m_bKeyTbl[ arg_keyCode ] & 0x80 ) ;
}


		
