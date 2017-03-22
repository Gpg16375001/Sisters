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

/* Pos To Cell */
#define		PTC( arg_cell )	( (arg_cell * 64) )

struct GimmickData {
	int		_bmpNo ;				// �����̗v�f�ԍ� ( _hBmp �Ɗ֘A�t���邽�� )
	bool	_useFlg ;				// �`�悷�邩�ǂ����̃t���O
	int		_anchor ;				// �A���J�[�̈ʒu
	float	_x , _y ;				// �O���[�o�����W
	int		_u , _v ;				// �؂�����W
	float	_w , _h ;				// ������
	int		_arrayX , _arrayY ;		// �z����W
	float	_delay ;				// �x��
	float	_spd ;					// ����
	int		_Gimmick ;				// �M�~�b�N�̎��
	int		_mode ;					// �M�~�b�N�̃��[�h
	float	_off[ 4 ] ;				// �I�t�Z�b�g
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

		/*/
		/*	�������̃f�[�^���Z�b�g
		/*/
		int setMoveBlocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode ) ;
		/*/
		/*	�������F����1
		/*/
		void moveFloor01( int arg_g ) ;
		/*/
		/*	�������F����2
		/*/
		void moveFloor02( int arg_g ) ;
		/*/
		/*	�������F����3
		/*/
		void moveFloor03( int arg_g ) ;
		/*/
		/*	�������F����4
		/*/
		void moveFloor04( int arg_g ) ;


		/*/
		/*	�܂�̂��̃f�[�^���Z�b�g
		/*/
		int setCircularSaws( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

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
		/*	���ꂼ��̃A�b�v�f�[�g������
		/*/
		void MoveFloor( ) ;
		void CircularSaws( ) ;
		void Pendulums( ) ;
		void Shockers( ) ;
		void SpeedUp( ) ;
		void Clouds( ) ;

		/*/
		/*	�M�~�b�N�̃f�[�^���Q�b�g
		/*/
		GimmickData getGimmickData( int arg_GimmickNo ) {
			return( GimmickData_[ arg_GimmickNo ] ) ;
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

		int			GimmickNo_ ;
		GimmickData	GimmickData_[ MAX_GIMMICK_NO ] ;							// �f�[�^

} ;


