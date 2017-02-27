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
	int		_w , _h ;				// ������
} ;

// �N���X�̐錾
class BitmapData
{
	static const int MAX_BMP_IMAGES = 256 ;

	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~BitmapData( ) ;

		int loadData( int arg_bmpNo_ , LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( int arg_bmpNo ) ;
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;

		/*/
		/*	�ő�ێ����̎擾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_IMAGES ) ;
		}
		/*/
		/*	�r�b�g�}�b�v�̃n���h���̃A�N�Z�b�T
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
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


