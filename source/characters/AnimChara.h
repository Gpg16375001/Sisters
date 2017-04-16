/*
______________________________________________________________________________________________

	FILE	: AnimChara.cpp

	________/ Explanation of file /___________________________________________________________
       
    AnimChara�N���X

	AnimChara�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "Common.h"
#include <stdio.h>

#define		DECELERATION_RATE	0.995f		// ������

class AnimChara
{
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		AnimChara( ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		~AnimChara( ) ;

		/*/
		/*	 ������
		/*/
		void Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		void Finalize( ) ;

		void PlayerAction( ) ;

		void Pinit( ) ;			// ����
		void Psinit( ) ;		// �~�܂莞 �����Z�b�g
		void Pstop( ) ;			// �~�܂莞
		void Pwalk( ) ;			// ���E����
		void Pjinit( ) ;		// �W�����v������
		void Pjump( ) ;			// �W�����v
		void Pdainit( ) ;		// �_���[�W������
		void Pdamage( ) ;		// �_���[�W

		float FootCheck( ) ;	// �����`�F�b�N ( �����̍��W��Ԃ� )

		/*/
		/*	 �X�V
		/*/
		void Update( ) ;

	private :
		enum PlayerMode {
			P_init = -1 ,
			P_sinit = 0 ,
			P_stop ,
			P_walk ,
			P_jinit ,
			P_jump ,
			P_drop ,
			P_dainit ,
			P_damage ,
			P_deinit ,
			P_deth ,
		} ;
		PlayerMode Pmode_ ;

		// �v���C���[�̃f�[�^
		int				Player_hp_	;	// �v���C���[�̗̑�
		Vector2D_polar	Player_vec_ ;	// �����Ƒ傫����������
		Vector2D_compo	Player_spd_ ;	// �����ɂ����f�[�^
		float			Player_xpos_ ;
		float			Player_ypos_ ;
		float			nowPos[ 2 ] ;
		float			oldPos[ 2 ] ;
		int				arrayX_ ;
		int				arrayY_ ;
		bool			lrflg_ ;
		bool			scrollflg[ 2 ] ;
		int				scrollx ;
		bool			flipMag_ ;		// ���E���]�̃t���O
		bool			cycleFlg_ ;		// ����ɏ�邩�Â��̃t���O

		// �v���C���[�̕����I�Ȃ���
		Physics			Player_ ;
		float			Player_acceration_ ;
		Vector2D_compo	Player_mag_ ;

		// �A�j���[�V����
		Animation		PlayerAnim_ ;
		AnimationData	Panim_stop_[ 4 ] ;
		AnimationData	Panim_walk_[ 4 ] ;
		AnimationData	Panim_jump_[ 1 ] ;
		AnimationData	Panim_drop_[ 1 ] ;
		AnimationData	Panim_deth_[ 1 ] ;
		Animation		ballAnim_ ;
		AnimationData	Panim_ball_[ 4 ] ;

} ;


