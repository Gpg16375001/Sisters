/*
______________________________________________________________________________________________

	FILE : Chip.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�`�b�v�w�i��`�悷��N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1�ňꖇ�̃`�b�v�w�i��`�悷��B
			��������f�[�^���O���b�h����ɔz�u����B
			selectBmp�őI�����ꂽ�r�b�g�}�b�v�� CHIP_X * CHIP_Y �ŏc�ɐ؂���A
			�`�b�v�e�[�u���̔ԍ��ɏ]���ĕ`����s���B
			�܂� m_x , m_y �����o���g�p���Ẵ`�b�v�w�i�X�N���[�����\�ł���B
			��������܂��g�����Ƃɂ�薳���X�N���[���≡�X�N���[���A�N�V��������
			�X�e�[�W��\���ł���B

			���Ȃ炸��x�����ŏ��� Sprite::GetInstance( )->Initialize( ) �ŏ��������A
			setMapSize( ) �� RenderMapSize( ) ���w�肵�Ȃ��Ă͂����Ȃ��B

			setMapSize �̓}�b�v�f�[�^�̔z��̕��ƍ������w�肷��B
			RenderMapSize �͈��ʂɕ`��ł��� �� �� �c �̃O���b�h�����󂯎��B


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>
#include <math.h>

#define CHIP_X	128
#define CHIP_Y	32
#define CHIP_W	64
#define CHIP_H	64

struct ChipData {
	HBITMAP _hBmp ;
	int		_bmpNo ;				// �����̗v�f�ԍ� ( _hBmp �Ɗ֘A�t���邽�� )
	bool	_useFlg ;				// �`�悷�邩�ǂ����̃t���O
	int		_anchor ;				// �A���J�[�̈ʒu
	float	_x , _y ;				// �O���[�o�����W
	int		_u , _v ;				// �؂�����W
	int		_w , _h ;				// ������
	int		_arrayX , _arrayY ;		// �z����W
	float	_scaleX , _scaleY ;		// �g�嗦
	bool	_useAlpha  ;			// �����������s�����ǂ����̃t���O
	int		_alpha ;				// �����x
	bool	_useRotate ;			// ��]�������s�����ǂ����̃t���O
	float	_degree ;				// �p�x
} ;

// �N���X�̐錾
class Chip
{
	static const int MAX_BMP_CBG = 4096 ;

	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 
		/*/
		/*	�I����
		/*/
		void Finalize( ) ; 

		~Chip( ) ;

		int RenderMapSize( int arg_w , int arg_h ) ;
		int setMapSize( int arg_w , int arg_h ) ;
		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;			// bmp�摜�̓ǂݍ���
		int loadBmpDataAll( HBITMAP arg_hbmp ) ;						// �ꊇ�ǂݍ���
		int clearData( int arg_bmpNo ) ;

		int setChipMap( int arg_x , int arg_y , int arg_chipNo ) ;		// �`�b�v�}�b�v���Z�b�g
		int clearChipMap( ) ;											// �`�b�v�}�b�v���N���A

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// �`�悷�邩�ǂ����̃t���O���Z�b�g
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;			// �������������邩�ǂ����̃t���O���Z�b�g
		int setUseRotate( int arg_bmpNo , bool arg_useRotate ) ;		// ��]�������邩�ǂ����̃t���O���Z�b�g
		int setBmpXY( int arg_bmpNo , float arg_x , float arg_y ) ;		// �|�W�V�����̃Z�b�g
		int setBmpUV( int arg_bmpNo , int arg_u , int arg_v ) ;			// �؂���ʒu�̃Z�b�g
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;			// ���A�����̃Z�b�g
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;	// �g�嗦�̃Z�b�g
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;				// �A���J�[�̃Z�b�g
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;					// �����x�̃Z�b�g
		int setAngle( int arg_bmpNo , float arg_angle ) ;				// �p�x�̃Z�b�g
		int setArray( int arg_bmpNo , int arg_ax , int arg_ay  ) ;		// �z����W�̃Z�b�g
		int setChipData(												// ���ׂẴZ�b�g
				int arg_bmpNo ,
				int arg_anchor ,
				int arg_arrayX , int arg_arrauY ,
				float arg_x , float arg_y ,
				int arg_u , int arg_v ,
				int arg_w , int arg_h ,
				float arg_scaleX , float arg_scaleY ,
				int arg_alpha = 255 ,
				float arg_degree = 0
			) ;
		void Update( ) ;												// �`�b�v�̍X�V
		int setScrollSize( int arg_x , int arg_y ) ;					// �X�N���[��

		/*/
		/*	�`�b�v�e�[�u���̎擾
		/*/
		int* getChipTable( )
		{
			return( m_chipTable_ ) ;
		}

		/*/
		/*	�ő�`�搔�̎擾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_CBG ) ;
		}
		/*/
		/*	�`�悷�邩�̎擾
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	�����������邩�̎擾
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useAlpha ) ;
		}
		/*/
		/*	��]�������邩�̎擾
		/*/
		int getUseRotate( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useRotate ) ;
		}

		/*/
		/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	�A���J�[���擾
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	�O���[�o�����W X���̎擾
		/*/
		float getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	�O���[�o�����W Y���̎擾
		/*/
		float getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	�z����W X���̎擾
		/*/
		int getArrayX( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._arrayX ) ;
		}
		/*/
		/*	�z����W Y���̎擾
		/*/
		int getArrayY( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._arrayY ) ;
		}
		/*/
		/*	X���̐؂���ʒu�̎擾
		/*/
		int getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y���̐؂���ʒu�̎擾
		/*/
		int getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	���̎擾
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	�����̎擾
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	���̊g�嗦�̎擾
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	�����̊g�嗦�̎擾
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._scaleY ) ;
		}
		/*/
		/*	�����x�̎擾
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._alpha ) ;
		}
		/*/
		/*	��]�p�x�̎擾
		/*/
		float getBmpAngle( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._degree ) ;
		}
		/*/
		/*	�X�N���[���̎擾
		/*/
		int getScrollX( ) const
		{
			return ( scrollX_ ) ;
		}
		/*/
		/*	�X�N���[���̎擾
		/*/
		int getScrollY( ) const
		{
			return ( scrollY_ ) ;
		}
		/*/
		/*	RENDER MAP SIZE X �̎擾
		/*/
		int getRenderMapSizeX( ) const
		{
			return ( renderMap_w_ ) ;
		}
		/*/
		/*	RENDER MAP SIZE Y �̎擾
		/*/
		int getRenderMapSizeY( ) const
		{
			return ( renderMap_h_ ) ;
		}
		/*/
		/*	MAP SIZE X �̎擾
		/*/
		int getMapSizeX( ) const
		{
			return ( map_w_ ) ;
		}
		/*/
		/*	MAP SIZE Y �̎擾
		/*/
		int getMapSizeY( ) const
		{
			return ( map_h_ ) ;
		}

		/*/
		/*	sin �̎擾
		/*/
		float sinWave( float arg_time , int arg_width , int arg_strength = 180 )
		{
			return( (float)(sin( arg_time * 3.14 / arg_strength ) * arg_width) ) ;
		}
		/*/
		/*	cos �̎擾
		/*/
		float cosWave( float arg_time , int arg_width , int arg_strength = 180 )
		{
			return( (float)(cos( arg_time * 3.14 / arg_strength ) * arg_width) ) ;
		}

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static Chip* GetInstance( )
		{
			static Chip v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		Chip( ) {	} ;

		ChipData bmpCBGTable_[ MAX_BMP_CBG ] ;							// �摜�f�[�^
		int m_chipTable_[ CHIP_X * CHIP_Y ] ;							// ChipBgData���̃}�b�v�f�[�^
		int map_w_ , map_h_ ;											// �}�b�v�̕��ƍ���
		int renderMap_w_ , renderMap_h_ ;								// ���ʏ�̃}�b�v�̕��ƍ���
		int scrollX_ , scrollY_ ;										// �X�N���[�����W


} ;


