
/*
______________________________________________________________________________________________

	FILE	: ConsoleWindow.cpp
	NAME	: Teacher.K

	________/ Explanation of file /___________________________________________________________
       
    �R���\�[���E�B���h�E�̐����Ɣj����S������N���X

	--- ��Ȏg���� ---
	�v���O�������s���ɂP�C���X�^���X�����Ďg�p����B�i��������Ă����܂�Ӗ����Ȃ��j
	��{�I�ɂ�printf���g�����f�o�b�O���\�ɂ��邽�߂Ɏg�p����B

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

// --- �N���X�̐錾
class ConsoleWindow
{
	// --- ���J�ϐ��ƃ����o�֐�
	public:
		ConsoleWindow( ) ;	// --- �R���X�g���N�^
		~ConsoleWindow( ) ;	// --- �f�X�g���N�^

	private:
		FILE *m_fIn ;
		FILE *m_fOut ;
};

