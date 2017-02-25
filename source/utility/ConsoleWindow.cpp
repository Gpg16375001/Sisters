/*
______________________________________________________________________________________________

	FILE	: ConsoleWindow.cpp

	________/ Explanation of file /___________________________________________________________
       
    ConsoleWindow�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "ConsoleWindow.h"

// --- �R���X�g���N�^
void ConsoleWindow::Initialize( )
{
	// --- �ȈՃf�o�b�O�p��printf���g����悤�ɂ���
	AllocConsole( ) ;
	
	freopen_s( &m_fIn,  "CON", "r", stdin ) ;     // --- �W�����͂̊��蓖��
	freopen_s( &m_fOut, "CON", "w", stdout ) ;    // --- �W���o�͂̊��蓖��


	// �J�n���o��
	printf( "It succeeded in starting of a console screen.\nA standard input/output can be used.\n\n" ) ;
}

// --- �f�X�g���N�^
ConsoleWindow::~ConsoleWindow( )
{
	// --- �R���\�[���̍폜
	fclose( m_fIn ) ;
	fclose( m_fIn ) ;
	FreeConsole( ) ;    

}
		
