
/*
______________________________________________________________________________________________

	FILE	: ConsoleWindow.cpp

	________/ Explanation of file /___________________________________________________________
       
    �R���\�[���E�B���h�E�̐����Ɣj����S������N���X

	--- ��Ȏg���� ---
	�v���O�������s���ɂP�C���X�^���X�����Ďg�p����B�i��������Ă����܂�Ӗ����Ȃ��j
	�K����x�����ŏ��� ConsoleWindow::GetInstance()->Initialize() �ŏ���������B
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
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~ConsoleWindow( ) ;	// --- �f�X�g���N�^

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static ConsoleWindow* GetInstance( )
		{
			static ConsoleWindow v ;
			return &v ;
		}

	private:
		/*/
		/*	�R���X�g���N�^
		/*/
		ConsoleWindow( ) {
		}

	private :
		FILE *m_fIn ;
		FILE *m_fOut ;
};

