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

#define		MAX_GIMMICK_NO			256

#define		GIMMICK_MODE_STAY		1
#define		GIMMICK_MODE_UPDOWN		2
#define		GIMMICK_MODE_LEFTRIGHT	3
#define		GIMMICK_MODE_CYCLE		4
#define		GIMMICK_MODE_WAVE		5

#define		GIMMICK_NAME_MARU		1
#define		GIMMICK_NAME_MOVEFLOOR	2

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
	float	_off[ 2 ] ;				// �I�t�Z�b�g
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

		void setGimmicks( ) ;

		/*/
		/*	�M�~�b�N�̃f�[�^���Z�b�g
		/*/
		int setMoveBlock( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_Delay , int _mode ) ;

		/*/
		/*	�M�~�b�N�̃f�[�^���Q�b�g
		/*/
		GimmickData getMoveBlock( int arg_GimmickNo ) {
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


