/*
______________________________________________________________________________________________

	FILE	: KeyManager.h

	________/ Explanation of file /___________________________________________________________
 
		�L�[���͂̊Ǘ����s���N���X

			--- ��Ȏg���� ---
			�v���O�������s���ɂP�C���X�^���X�������B�i �����ō���� �j
			���Ȃ炸��x�����ŏ��� KeyManager::GetInstance( )->Initialize( ) �ŏ���������B
			�t���[���̔����^�C�~���O�ň�xupdate���Ăяo���L�[���̍X�V���s���B
			�L�[���̎擾�ɂ� getKeyState( ) �ɉ��z�L�[�R�[�h�܂��͕����R�[�h�i�p���j��n���A
			�߂�l���󂯎�鎖�邱�ƂŎ����ł���B
			��{�I�Ȏg�����Ƃ��Ă͕K�v�ȃ^�C�~���O�� getKeyState( ) ���Ăяo���A
			�߂�l��^�U���肷�邱�ƂŃL�[���ł̕��򏈗����\�ł���B

			��EA��������Ă���ꍇ�R���\�[����ʂɏo�͂��s��

			if( KeyManager::GetInstance( )->getKeyState( 'A' ) != 0 )
			{
				printf( "A��������Ă��܂�" );
			}

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>

/*/
/*	�N���X�̐錾
/*/
class KeyManager
{
	// ���J�ϐ��ƃ����o�֐�
	public:
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~KeyManager( ) ;						// --- �f�X�g���N�^
		int update( ) ;							// --- �L�[���̍X�V
		BYTE getKeyState( BYTE arg_keyCode ) ;	// --- �L�[���̎擾

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static KeyManager* GetInstance( )
		{
			static KeyManager v ;
			return &v ;
		}

	// ����J�ϐ��ƃ����o�֐�
	private:
		// �R���X�g���N�^
		KeyManager( ) {
		} ;

		BYTE m_bKeyTbl[ 256 ] ;					// --- �L�[�e�[�u��
};

