/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		�r�b�g�}�b�v�̕`����s���N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1��1���̃r�b�g�}�b�v��`�悷��B
			�K���v���O�����̍ŏ��� setHDC �����Ȃ���΂Ȃ�Ȃ��B
			selectBmp �ɔw�i�p�r�b�g�}�b�v�e�[�u�����̕`�悵�����r�b�g�}�b�v�̃f�[�^��
			�傫����n�����ƂŁA�`�悷��r�b�g�}�b�v�̕ύX���s����B
			select -> set -> render ����̃I�u�W�F�N�g�ɑ΂��Ă̏����ƂȂ�B
			�܂��x�ɓ�̕`����s���Ƃ��́A
				Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;
				Renderer::GetInstance()->setPos( x , y ) ;
				Renderer::GetInstance()->Render( ) ;

				Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;
				Renderer::GetInstance()->setPos( x , y ) ;
				Renderer::GetInstance()->Render( ) ;
			�ƂȂ�B
			�S�̗̂���Ƃ��ẮAclearRender -> select -> set -> Render  -> draw �ƂȂ�B

			��1. setHDC() �̕��@
			Renderer::GetInstance()->setHDC( hDCBackBuf , hDCWorkBuf ) ;

			��2. �摜���Z���N�g������@
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

		int setHDC( HWND arg_hWnd , HDC arg_hDCBack , HDC arg_hDCWork ) ;	// ����ʂ̕`��ɕK�v�Ȃ��̂����炤
		int selectBmp( HGDIOBJ arg_bmpData ,				// �摜�f�[�^�̎擾
				int arg_anchor ,							 // . �A���J�[
				int arg_x , int arg_y ,						 // . �z�u���W
				int arg_u , int arg_v ,						 // . �؂���ʒu
				int arg_w , int arg_h ,						 // . ������
				float arg_scaleX , float arg_scaleY ,		 // . �g�嗦
				int arg_alpha = 255 ,						 // . �����x
				float arg_angle = 0							 // . �p�x
			) ;
		int Render( ) ;										// �o�b�N�o�b�t�@�ւ̏o��

		int setPos( int arg_x , int arg_y ) ;				// ���W�̃Z�b�g
		int setUV( int arg_u , int arg_v ) ;				// �؂�o�����W�̃Z�b�g
		int setWH( int arg_w , int arg_h ) ;				// �؂�o���������̃Z�b�g
		int setScale( float arg_w , float arg_h ) ;			// �g�嗦�̃Z�b�g
		int setAnchor( int arg_anchor ) ;					// �A���J�[�̃Z�b�g
		int setAlpha( int arg_alpha ) ;						// �����x�̃Z�b�g
		int setAngle( float arg_angle ) ;					// �p�x�̃Z�b�g
		int setAlphaFlg( bool arg_alphaFlg ) ;				// �����x�̃t���O���Z�b�g
		int setRotateFlg( bool arg_rotateFlg ) ;			// �p�x�̃t���O���Z�b�g

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

	private :
		HGDIOBJ bmpData_ ;
		HDC		hDCBack_ ;				// �����
		HDC		hDCWork_ ;				// ��Ɨp���
		HWND	hWnd_ ;					// �e�̃E�B���h�E�n���h��

		int		x_ , y_ ;				// �`����W
		int		u_ , v_ ;				// �؂�����W
		int		w_ , h_ ;				// ������
		int		anchorX_ , anchorY_ ;	// �A���J�[�̈ʒu
		float	scaleX_ , scaleY_ ;		// �g�嗦
		int		alpha_ ;				// �����x
		float	angle_ ;				// �p�x
		bool	alphaFlg_ ;				// �������������邩�ǂ����̃t���O
		bool	rotateFlg_ ;			// ��]���������邩�ǂ����̃t���O

} ;


