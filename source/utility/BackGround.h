/*
______________________________________________________________________________________________

	FILE : BackGround.h

	________/ Explanation of file /___________________________________________________________

		�w�i�̕`��ɕK�v�ȃf�[�^��ێ����邷�邷��N���X
		
			--- ��Ȏg���� ---
			1�̃C���X�^���X��4���̔w�i��ێ����邱�Ƃ��ł���B
			�܂�A�摜�̏���⊮����N���X�Ȃ̂łق����摜�̔ԍ�����Ăяo�����ƂɂȂ�B
			���Ȃ炸��x�����ŏ��� BackGround::GetInstance( )->Initialize( ) �ŏ���������B

			��1. �摜�̓ǂݍ��ݕ��@
			BackGround::GetInstance( )->loadBmpData( bmpNo , hBITMAP ) ;

			��2. �摜���Z�b�g
			BackGround::GetInstance()->setBmpData(
					bmpNo ,
					anchor ,
					x , y ,
					u , v ,
					width , height ,
					scaleX , scaleY
				) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

struct BGData {
	HBITMAP _hBmp ;
	bool	_useFlg ;				// �`�悷�邩�ǂ����̃t���O
	int		_anchor ;				// �A���J�[�̈ʒu
	int		_x , _y ;				// ���W
	int		_u , _v ;				// �؂�����W
	int		_w , _h ;				// ������
	float	_scaleX , _scaleY ;		// �g�嗦
	bool	_useAlpha  ;			// �����������s�����ǂ����̃t���O
	int		_alpha ;				// �����x
	bool	_useRotate ;			// ��]�������s�����ǂ����̃t���O
	float	_degree ;				// �p�x
} ;

// �N���X�̐錾
class BackGround
{
	static const int MAX_BMP_BG = 4 ;

	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~BackGround( ) ;

		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;
		int clearData( int arg_bmpNo ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// �`�悷�邩�ǂ����̃t���O���Z�b�g
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;			// �������������邩�ǂ����̃t���O���Z�b�g
		int setUseRotate( int arg_bmpNo , bool arg_useRotate ) ;		// ��]�������邩�ǂ����̃t���O���Z�b�g
		int setBmpXY( int arg_bmpNo , int arg_x , int arg_y ) ;			// �|�W�V�����̃Z�b�g
		int setBmpUV( int arg_bmpNo , int arg_u , int arg_v ) ;			// �؂���ʒu�̃Z�b�g
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;			// ���A�����̃Z�b�g
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;	// �g�嗦�̃Z�b�g
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;				// �A���J�[�̃Z�b�g
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;					// �����x�̃Z�b�g
		int setAngle( int arg_bmpNo , float arg_angle ) ;				// �p�x�̃Z�b�g
		int setBmpData(													// ���ׂẴZ�b�g
				int arg_bmpNo ,
				int arg_anchor ,
				int arg_x , int arg_y ,
				int arg_u , int arg_v ,
				int arg_w , int arg_h ,
				float arg_scaleX , float arg_scaleY ,
				int arg_alpha = 255 ,
				float arg_degree = 0
			) ;

		/*/
		/*	�ő�`�搔�̎擾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_BG ) ;
		}
		/*/
		/*	�`�悷�邩�̎擾
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	�����������邩�̎擾
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useAlpha ) ;
		}
		/*/
		/*	��]�������邩�̎擾
		/*/
		int getUseRotate( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useRotate ) ;
		}

		/*/
		/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	�A���J�[���擾
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	X���̎擾
		/*/
		int getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y���̎擾
		/*/
		int getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	X���̐؂���ʒu�̎擾
		/*/
		int getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y���̐؂���ʒu�̎擾
		/*/
		int getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	���̎擾
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	�����̎擾
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	���̊g�嗦�̎擾
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	�����̊g�嗦�̎擾
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._scaleY ) ;
		}
		/*/
		/*	�����x�̎擾
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._alpha ) ;
		}
		/*/
		/*	��]�p�x�̎擾
		/*/
		float getBmpAngle( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._degree ) ;
		}


		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static BackGround* GetInstance( )
		{
			static BackGround v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		BackGround( ) {	} ;

		BGData bmpBGTable_[ MAX_BMP_BG ] ;			// �摜�f�[�^


} ;


