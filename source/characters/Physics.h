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
/*	�x�N�g���F���� component
/*/
struct Vector2D_compo {
	float x , y ;
} ;
/*/
/*	�x�N�g���F�傫���ƌ��� polar
/*/
struct Vector2D_polar {
	// magnitude , degree
	float mag , deg ;
} ;

/*/
/*	�N���X�̐錾
/*/
class Physics
{
	// ���J�ϐ��ƃ����o�֐�
	public:
		/*/
		/*	�R���X�g���N�^
		/*/
		Physics( )
			: Pi		( 3.141592654f )
			, RadToDeg	( 57.29577951f )
			, DegToRad	( 0.017453293f )
			, gravity_	( 9.81f )
			, mass_		( 1.0f )
		{
			
		} ;

		~Physics( ) ;							// �f�X�g���N�^
		void update( ) ;						// ���̍X�V

		/*/
		/*	������
		/*/
		void Initialize( ) ;

		/*/
		/*	�I����
		/*/
		void Finalize( ) ;

		/*/
		/*	�g�����F2�_�Ԃ��Ȃ����������߂�
		/*	�����@�F���W������킷float�z��Q��
		/*	�Ԃ�l�F�����̌X��
		/*/
		float slopePoint( float *arg_point1 , float *arg_point2  ) ;
		/*/
		/*	�g�����F�x�N�g���� polar ���� component �ɕϊ�
		/*	�����@�Fpolar �\���̃x�N�g��
		/*	�Ԃ�l�Fcomponent �\���̃x�N�g��
		/*/
		Vector2D_compo PolarToCompo( Vector2D_polar arg_vector2d ) ;
		/*/
		/*	�g�����F�x�N�g���� component ���� polar �ɕϊ�
		/*	�����@�Fcomponent �\���̃x�N�g��
		/*	�Ԃ�l�Fpolar �\���̃x�N�g��
		/*/
		Vector2D_polar CompoToPolar( Vector2D_compo arg_vector2d ) ;

		/*/
		/*	�g�����F�d�� �̃x�N�g���ɕϊ�
		/*	�����@�F���� �� �����x
		/*	�Ԃ�l�F���̕��̂ɓ��� �d�� �̃x�N�g��
		/*/
		Vector2D_compo Weight2D( float arg_mass = 1.0f , float arg_grav = 0.0f ) ;

		/*/
		/*	���ʂ̑��
		/*/
		int setMass( float arg_mass ) ;

	private :
		float Pi ;
		float RadToDeg ;
		float DegToRad ;

		float gravity_ ;	// �d�͉����x
		float mass_ ;		// ����

		Vector2D_compo weight_ ;

};


