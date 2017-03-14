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
	// magnitude , degree �x
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
			, r2_		( 1.414213562f )
			, r3_		( 1.732050807f )
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
		/*	�g�����F�Ζʂ����ׂ邩�ǂ����𒲂ׂ�
		/*	�����@�F�n�ʂ̊p�x , ���̂̏d�� , ���C�W��
		/*	�Ԃ�l�Ftrue or false
		/*/
		bool checkMotion( float arg_angle , float arg_weight , float arg_coeff ) ;
		/*/
		/*	�g�����F�Ζʂ����ׂ�
		/*	�����@�F�n�ʂ̊p�x , ���̂̏d�� , �����C�W�� , ����
		/*	�Ԃ�l�F���̂̉����x
		/*/
		float calcAccel( float arg_angle , float arg_weight , float arg_coeff , float arg_mass ) ;
		/*/
		/*	�g�����F�����x�����߂�
		/*	�����@�F�ω��O�̃X�s�[�h , �ω���̃X�s�[�h , ����(�b)
		/*	�Ԃ�l�F�����x
		/*/
		float AccelerationSeconds( float arg_v1 , float arg_v2 , float arg_time  ) ;
		/*/
		/*	�g�����F�Q�_�Ԃ̌X�������߂�
		/*	�����@�F�_�P �� �_�Q
		/*	�Ԃ�l�F�X��
		/*/
		float slopeTilt( float *arg_p1 , float *arg_p2 ) ;
		/*/
		/*	�g�����F�Q�̒����̌�_�����߂�
		/*	�����@�F�_�P , �_�P�̌X�� �� �_�Q , �_2�̌X��
		/*	�Ԃ�l�F��_
		/*/
		float *linePoint( float *arg_p1 , float arg_a1 , float *arg_p2 , float arg_a2 ) ;
		/*/
		/*	�g�����F�X�����獂�������߂�
		/*	�����@�Fx�����̃x�N�g�� �� �ړ��ړ������̃x�N�g��
		/*	�Ԃ�l�FY���̍���
		/*/
		float slopePoint( Vector2D_compo arg_Xvector , Vector2D_compo arg_Yvector ) ;
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
		/*/
		/*	���ʂ��擾
		/*/
		float getMass( ) const {
			return( mass_ ) ;
		} ;

		/*/
		/*	��2 ���擾
		/*/
		float r2( ) const {
			return( r2_ ) ;
		} ;

		/*/
		/*	��3 ���擾
		/*/
		float r3( ) const {
			return( r3_ ) ;
		} ;

	private :
		float Pi ;
		float RadToDeg ;
		float DegToRad ;

		float r2_ ;
		float r3_ ;

		float gravity_ ;	// �d�͉����x
		float mass_ ;		// ����

		Vector2D_compo weight_ ;

};


