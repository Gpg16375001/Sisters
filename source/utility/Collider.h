/*
______________________________________________________________________________________________

	FILE	: Collider.h

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
class Collider
{
	// ���J�ϐ��ƃ����o�֐�
	public:
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~Collider( ) ;							// �f�X�g���N�^
		void update( ) ;						// ���̍X�V

		bool getFootCheck( ) ;

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static Collider* GetInstance( )
		{
			static Collider v ;
			return &v ;
		}

	// ����J�ϐ��ƃ����o�֐�
	private:
		// �R���X�g���N�^
		Collider( )
		{
		} ;

	private :


};

