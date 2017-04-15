/*
______________________________________________________________________________________________

	FILE : SceneCut.h

	________/ Explanation of file /___________________________________________________________

		�w�i�̕`��ɕK�v�ȃf�[�^��ێ����邷�邷��N���X
		
			--- ��Ȏg���� ---
			1�̃C���X�^���X��4���̔w�i��ێ����邱�Ƃ��ł���B
			�܂�A�摜�̏���⊮����N���X�Ȃ̂łق����摜�̔ԍ�����Ăяo�����ƂɂȂ�B
			���Ȃ炸��x�����ŏ��� SceneCut::GetInstance( )->Initialize( ) �ŏ���������B

			��1. �摜�̓ǂݍ��ݕ��@
			SceneCut::GetInstance( )->loadBmpData( bmpNo , hBITMAP ) ;

			��2. �摜���Z�b�g
			SceneCut::GetInstance()->setBmpData(
					bmpNo ,
					anchor ,
					x , y ,
					u , v ,
					width , height ,
					scaleX , scaleY
				) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class SceneCut
{
	static const int MAX_BMP = 4 ;

	public :
		struct BmpData {
			HBITMAP _hBmp ;
			bool	_useFlg ;				// �`�悷�邩�ǂ����̃t���O
			float	_x , _y ;				// ���W
			float	_w , _h ;				// ������
			bool	_useAlpha  ;			// �����������s�����ǂ����̃t���O
			int		_alpha ;				// �����x
		} ;

		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~SceneCut( ) ;

		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;
		int clearData( int arg_bmpNo ) ;
		int fadeIn( ) ;
		int fadeOut( ) ;
		int BlackOut( ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// �`�悷�邩�ǂ����̃t���O���Z�b�g
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;			// �������������邩�ǂ����̃t���O���Z�b�g
		int setBmpXY( int arg_bmpNo , float arg_x , float arg_y ) ;	// �|�W�V�����̃Z�b�g
		int setBmpWH( int arg_bmpNo , float arg_w , float arg_h ) ;	// ���A�����̃Z�b�g
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;				// �����x�̃Z�b�g
		int setBmpData(													// ���ׂẴZ�b�g
				int arg_bmpNo ,
				float arg_x , float arg_y ,
				float arg_w , float arg_h ,
				int arg_alpha = 255
			) ;

		/*/
		/*	�ő�`�搔�̎擾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP ) ;
		}
		/*/
		/*	�`�悷�邩�̎擾
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	�����������邩�̎擾
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpTable_[ arg_bmpNo ]._useAlpha ) ;
		}

		/*/
		/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	X���̎擾
		/*/
		float getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y���̎擾
		/*/
		float getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	���̎擾
		/*/
		float getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	�����̎擾
		/*/
		float getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	�����x�̎擾
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._alpha ) ;
		}


		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static SceneCut* GetInstance( )
		{
			static SceneCut v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		SceneCut( ) {
			alphaCnt_ = 0 ;
		} ;

		BmpData bmpTable_[ MAX_BMP ] ;			// �摜�f�[�^
		int		alphaCnt_ ;

} ;


