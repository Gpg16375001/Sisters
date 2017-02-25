/*
______________________________________________________________________________________________

	FILE : BitmapData.h

	________/ Explanation of file /___________________________________________________________

		�r�b�g�}�b�v��ǂݍ��݃f�[�^��ێ�����N���X
		
			--- ��Ȏg���� ---
			1�̃C���X�^���X��1024���̃r�b�g�}�b�v�f�[�^��ێ����邱�Ƃ��ł���B
			�܂�A�摜�̏���⊮����N���X�Ȃ̂łق����摜�̔ԍ�����Ăяo�����ƂɂȂ�B
			���Ȃ炸��x�����ŏ��� BitmapData::GetInstance( )->Initialize( ) �ŏ���������B

			��1. �摜�̓ǂݍ��ݕ��@
			BitmapData::GetInstance( )->loadData( bmpNo , file_path , width , height ) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

struct BmpData {
	HBITMAP _hBmp ;
	bool _useFlg ;				// �`�悷�邩�ǂ����̃t���O
	int _anchor ;				// �A���J�[�̈ʒu
	int _x , _y ;
	int _u , _v ;
	int _w , _h ;
	float _scaleX , _scaleY ;	// �g�嗦
} ;

// �N���X�̐錾
class BitmapData
{
	static const int MAX_BMP_IMAGES = 1024 ;

	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~BitmapData( ) ;

		int loadData( int arg_bmpNo_ , LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( int arg_bmpNo ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// �`�悷�邩�ǂ����̃t���O���Z�b�g
		int setBmpXY( int arg_bmpNo , int arg_x , int arg_y ) ;			// �|�W�V�����̃Z�b�g
		int setBmpUV( int arg_bmpNo , int arg_u , int arg_v ) ;			// �؂���ʒu�̃Z�b�g
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;			// ���A�����̃Z�b�g
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;	// �g�嗦�̃Z�b�g
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;				// �A���J�[�̃Z�b�g
		int setBmpData(													// ���ׂẴZ�b�g
				int arg_bmpNo ,
				int arg_anchor ,
				int arg_x , int arg_y ,
				int arg_u , int arg_v ,
				int arg_w , int arg_h ,
				float arg_scaleX , float arg_scaleY
			) ;

		/*/
		/*	�ő�`�搔�̎擾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_IMAGES ) ;
		}
		/*/
		/*	�`�悷�邩�̎擾
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpDataTable_[ arg_bmpNo ]._useFlg ) ;
		}

		/*/
		/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	�A���J�[���擾
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	X���̎擾
		/*/
		int getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y���̎擾
		/*/
		int getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	X���̐؂���ʒu�̎擾
		/*/
		int getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y���̐؂���ʒu�̎擾
		/*/
		int getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	���̎擾
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	�����̎擾
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	���̊g�嗦�̎擾
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	�����̊g�嗦�̎擾
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._scaleY ) ;
		}


		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static BitmapData* GetInstance( )
		{
			static BitmapData v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		BitmapData( ) {	} ;

		BmpData bmpDataTable_[ MAX_BMP_IMAGES ] ;			// �摜�f�[�^


} ;


