/*
______________________________________________________________________________________________

	FILE : Gimmick.h

	________/ Explanation of file /___________________________________________________________

		�`�b�v�w�i��`�悷��N���X
		
			--- ��Ȏg���� ---


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "../characters/Animation.h"

#define		MAX_GIMMICK_NO				256

#define		GIMMICK_MODE_STAY			1
#define		GIMMICK_MODE_UPDOWN			2
#define		GIMMICK_MODE_LEFTRIGHT		3
#define		GIMMICK_MODE_CYCLE			4
#define		GIMMICK_MODE_WAVE			5
#define		GIMMICK_MODE_DROP			6
#define		GIMMICK_MODE_UPPER			7

#define		GIMMICK_NAME_CIRCULARSAWS	1
#define		GIMMICK_NAME_MOVEFLOOR		2
#define		GIMMICK_NAME_PENDULUM		3
#define		GIMMICK_NAME_SHOCKER		4
#define		GIMMICK_NAME_SPEEDUP		5
#define		GIMMICK_NAME_CLOUD			6
#define		GIMMICK_NAME_SHOOTER		7

/* Pos To Cell */
#define		PTC( arg_cell )	( (arg_cell * 64) )

struct GimmickData {
	int				_bmpNo ;				// �����̗v�f�ԍ� ( _hBmp �Ɗ֘A�t���邽�� )
	bool			_useFlg ;				// �`�悷�邩�ǂ����̃t���O
	int				_anchor ;				// �A���J�[�̈ʒu
	float			_x , _y ;				// �O���[�o�����W
	int				_u , _v ;				// �؂�����W
	float			_w , _h ;				// ������
	int				_arrayX , _arrayY ;		// �z����W
	float			_delay ;				// �x��
	float			_spd ;					// ����
	int				_Gimmick ;				// �M�~�b�N�̎��
	int				_mode ;					// �M�~�b�N�̃��[�h
	float			_off[ 8 ] ;				// �I�t�Z�b�g
	Animation		_gAnim ;				// animation
	AnimationData	_gAnim_01[ 4 ] ;		// anim 01
	AnimationData	_gAnim_02[ 4 ] ;		// anim 02
	AnimationData	_gAnim_03[ 4 ] ;		// anim 03
} ;

// �N���X�̐錾
class Gimmick
{
	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 
		/*/
		/*	�I����
		/*/
		void Finalize( ) ; 

		~Gimmick( ) ;
		void Update( ) ;												// �`�b�v�̍X�V
		void clearGimmickData( ) ;
		void clearBulletData( ) ;
		void setBulletData( ) ;

		/*/
		/*	�������̃f�[�^���Z�b�g
		/*/
		int setMoveBlocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode ) ;
		/*/
		/*	�������F����
		/*/
		void moveFloor01( int arg_g ) ;
		void moveFloor02( int arg_g ) ;
		void moveFloor03( int arg_g ) ;
		void moveFloor04( int arg_g ) ;


		/*/
		/*	�܂�̂��̃f�[�^���Z�b�g
		/*/
		int setCircularSaws( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;
		/*/
		/*	�܂�̂��F����
		/*/
		void moveSaws01( int arg_g ) ;
		void moveSaws02( int arg_g ) ;
		void moveSaws03( int arg_g ) ;
		void moveSaws04( int arg_g ) ;

		/*/
		/*	�U��q�̃f�[�^���Z�b�g
		/*/
		int setPendulums( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	�d�C�̃f�[�^���Z�b�g
		/*/
		int setShockers( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	SpeedUp�̃f�[�^���Z�b�g
		/*/
		int setSpeedUp( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	�_�̃f�[�^���Z�b�g
		/*/
		int setClouds( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	�ˌ����̃f�[�^���Z�b�g
		/*/
		int setShooter( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;
		int nullCheck( ) ;
		int useCheck( int arg_used ) ;
		/*/
		/*	�ˌ����F���
		/*/
		void blockShot01( int arg_g ) ;
		void blockShot02( int arg_g ) ;
		void blockShot03( int arg_g ) ;
		void blockShot04( int arg_g ) ;

		/*/
		/*	���ꂼ��̃A�b�v�f�[�g������
		/*/
		void MoveFloor( ) ;
		void CircularSaws( ) ;
		void Pendulums( ) ;
		void Shockers( ) ;
		void SpeedUp( ) ;
		void Clouds( ) ;
		void Shooter( ) ;

		/*/
		/*	�M�~�b�N�̃f�[�^���Q�b�g
		/*/
		GimmickData getGimmickData( int arg_GimmickNo ) {
			return( GimmickData_[ arg_GimmickNo ] ) ;
		}

		/*/
		/*	�o���b�g������
		/*/
		int deleteBullet( int arg_GimmickNo ) {
			BulletData_[ arg_GimmickNo ]._useFlg	= false ;
			BulletData_[ arg_GimmickNo ]._x			= 0.0f ;
			BulletData_[ arg_GimmickNo ]._y			= 0.0f ;
			BulletData_[ arg_GimmickNo ]._off[ 0 ]	= 0.0f ;
			BulletData_[ arg_GimmickNo ]._off[ 1 ]	= 0.0f ;
			BulletData_[ arg_GimmickNo ]._delay		= 0 ;
			return( true ) ;
		}

		/*/
		/*	off[ 3 ]�̃f�[�^�𒼐ڃZ�b�g
		/*/
		int setOff_3( int arg_GimmickNo , float arg_no ) {
			GimmickData_[ arg_GimmickNo ]._off[ 3 ] = arg_no ;
			return( true ) ;
		}

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static Gimmick* GetInstance( )
		{
			static Gimmick v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		Gimmick( ) {
			Initialize( ) ;
		} ;

		int				GimmickNo_ ;
		GimmickData		GimmickData_[ MAX_GIMMICK_NO ] ;					// �f�[�^
		GimmickData		BulletData_[ 500 ] ;								// �e�����̃f�[�^

} ;


