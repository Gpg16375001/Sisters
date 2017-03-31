/*
______________________________________________________________________________________________

	FILE : BitmapData.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�r�b�g�}�b�v��ǂݍ��݃f�[�^��ێ�����N���X
		
			--- ��Ȏg���� ---
			1�̃C���X�^���X��1���̃r�b�g�}�b�v�f�[�^��ێ����邱�Ƃ��ł���B
			�܂�16���̃r�b�g�}�b�v�f�[�^��ǂݍ��݂����Ƃ��̓C���X�^���X��16�K�v�ł���B
			�܂��g���܂킵���l���A�����I�ȊJ���Ƒ��d�ǂݍ��݂̎��̈Öق̉�����T�|�[�g���Ă���B

			��1.�R���X�g���N�^�Ńr�b�g�}�b�v��ǂݍ���
			BitmapData bmp( file_path , width , height ) ;

			��2.�R���X�g���N�^���g��Ȃ��ꍇ
			BitmapData bmp1 ;
			bmp1.loadData bmp( file_path , width , height ) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class BitmapData
{
	public :
		BitmapData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		BitmapData( ) ;
		~BitmapData( ) ;

		int loadData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( ) ;
		
		HBITMAP getBmpData( ) ;
		int getBmpWidth( ) ;
		int getBmpHeight( ) ;

	private :
		HBITMAP m_hBmp ;
		int m_width ;
		int m_height ;

} ;


