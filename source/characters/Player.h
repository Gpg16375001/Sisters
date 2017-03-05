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

		bool FootCheck( ) ;	// �����`�F�b�N
		bool Collision( ) ;	// �����蔻��

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

		float	Player_xpos_ ;
		float	Player_ypos_ ;
		float	Player_xspd_ ;
		float	Player_yspd_ ;
		int		arrayX_ ;
		int		arrayY_ ;
		bool	flyCheck_ ;		// �󒆂��ǂ����̃`�F�b�N

} ;


