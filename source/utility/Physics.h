/*
______________________________________________________________________________________________

	FILE	: Physics.h

	________/ Explanation of file /___________________________________________________________
 
		�����I�Ȃ��Ƃ��s���N���X

			--- ��Ȏg���� ---


			��E


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>

/*/
/*	�N���X�̐錾
/*/
class Physics
{
	// ���J�ϐ��ƃ����o�֐�
	public:
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~Physics( ) ;							// �f�X�g���N�^
		void update( ) ;						// ���̍X�V

		float getGravity( )
		{
			return( gravity_ ) ;
		}

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static Physics* GetInstance( )
		{
			static Physics v ;
			return &v ;
		}

	// ����J�ϐ��ƃ����o�֐�
	private:
		// �R���X�g���N�^
		Physics( )
			: gravity_( 9.81f )
		{
		} ;

	private :
		float gravity_ ;

};

