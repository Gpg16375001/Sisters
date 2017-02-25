/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		�r�b�g�}�b�v�̕`����s���N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1��1���̃r�b�g�}�b�v��`�悷��B
			selectBmp �ɔw�i�p�r�b�g�}�b�v�e�[�u�����̕`�悵�����r�b�g�}�b�v�̃f�[�^��
			�傫����n�����ƂŁA�`�悷��r�b�g�}�b�v�̕ύX���s����B
			�`��ɂ� Draw ���\�b�h���t���[�����ɌĂяo�����ƁB

			��1. �摜���Z���N�g������@
			Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>

/*/
/*	�N���X�̐錾
/*/
class Renderer
{
	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;

		int selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height ) ;
		int Render( ) ;

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static Renderer* GetInstance( )
		{
			static Renderer v ;
			return &v ;
		}

	private :	
		/*/
		/*	�R���X�g���N�^
		/*/
		Renderer( ) {	}

		HGDIOBJ bmpData_ ;
		int width_ ;
		int height_ ;

} ;


