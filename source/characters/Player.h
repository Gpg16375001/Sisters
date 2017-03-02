/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    Player�N���X

	Player�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>

class Player
{
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		Player( ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		~Player( ) ;

		/*/
		/*	 ������
		/*/
		void Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		void Finalize( ) ;

		void PlayerAction( ) ;

		void Pinit( ) ;		// ����
		void Pstop( ) ;		// �~�܂莞
		void Pwalk( ) ;		// ���E����
		void Pjinit( ) ;	// �W�����v������
		void Pjump( ) ;		// �W�����v�Ɨ���

		/*/
		/*	 �X�V
		/*/
		void Update( ) ;

	private :
		enum PlayerMode {
			P_init = -1 ,
			P_stop = 0 ,
			P_walk ,
			P_jinit ,
			P_jump ,
			P_drop ,
		} ;
		PlayerMode Pmode_ ;

} ;


