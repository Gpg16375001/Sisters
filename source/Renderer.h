/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		�o�b�N�o�b�t�@�ɕ`�������N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X 1�� �� 1�� ��`�悷�� ( �����ɌĂԂ��Ƃ͂Ȃ��悤�ɂ��� ���������ĂׂȂ���.. )
			��{�I�ȗ���Ƃ��Ă� ��
			�y Renderer::GetInstance()->setRender() �� draw ��
				Renderer::GetInstance()->clearRenderer() �� Next_Frame �z �ƂȂ�B

			�ʂɃZ�b�g�������ꍇ�͊e�����o�̑Ή����\�b�h���g�p����B

			��1. ��{�I�ȗ���
			Renderer::GetInstance()->setRenderer( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;

			��2. 2�{�ł̕\�����s�������ꍇ
			Renderer::GetInstance()->setScaleXY( 2.0 , 2.0 ) ;

			��3. �A���t�@50% �ŕ\�����s�������ꍇ
			Renderer::GetInstance()->setAlpha( 0.5 ) ;

			��4. 45�x��]�������s�������ꍇ
			Renderer::GetInstance()->setRotate( 45.0f ) ;

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class Renderer
{
	public :
		/*/
		/*	������
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;													// �f�X�g���N�^

		int setRender(													// �X�v���C�g�̃Z�b�g
				HBITMAP arg_bmp ,										 // . �摜�f�[�^
				int anchor ,											 // . �A���J�[ ( �z�u�ʒu )
				int arg_x , int arg_y ,									 // . ����̍��W
				int arg_u , int arg_v ,									 // . �؂�o�����W
				int arg_w , int arg_h ,									 // . ���ƍ���
				float arg_scaleX = 1.0f , float arg_scaleY = 1.0f ,		 // . �X�P�[���{��
				float arg_degree = 0.0f ,								 // . ��]����p�x
				float arg_alpha = 0.0f									 // . �����x
			) ;
		int clearScreen( ) ;											// �X�v���C�g�̃N���A
		int setFlg( int arg_flg ) ;										// �t���O�̃Z�b�g
		int selectBmp( HBITMAP arg_bmp ) ;								// �X�v���C�g�̃Z�b�g
		int setPos( int arg_x , int arg_y ) ;							// ���W�̃Z�b�g
		int setUV( int arg_u , int arg_v ) ;							// �؂�o�����W�̃Z�b�g
		int setWH( int arg_w , int arg_h ) ;							// �؂�o���������̃Z�b�g
		int draw( ) ;													// �X�v���C�g�̕`��
		int setScaleXY( float arg_scaleX , float arg_scaleY ) ;			// �X�P�[���{���̃Z�b�g
		int setAlphaFlg( int arg_alphaFlg ) ;							// �A���t�@�����t���O�̃Z�b�g
		int setAlpha( float arg_alpha ) ;								// �A���t�@�����̃Z�b�g
		int setRotateFlg( int arg_rotateFlg ) ;							// ��]�����t���O�̃Z�b�g
		int setRotate( float arg_degree ) ;								// ��]�����̃Z�b�g

		int	setHDC( HDC arg_hDCBack ) {									// �]����̃o�b�N�o�b�t�@�����炤
			hDCBack_ = &arg_hDCBack ;
			return( true ) ;
		}
		int setHWindow( HWND arg_hWnd ) {								// �E�B���h�E�n���h���̎擾
			hWnd_ = arg_hWnd ;
			return( true ) ;
		}

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
/*		static Renderer* GetInstance( )
		{
			static Renderer v ;
			return &v ;
		}
*/
//	private :
		Renderer( ) 
			: bmp_( NULL )
			, hDCBack_( NULL )
			, hDCWork_( NULL )
			, hWnd_( 0 )
			, useFlg_( false )
		{													// �R���X�g���N�^
			// �C���X�^���X�����̏�����
			clearScreen( ) ;

		} ;

	private :
		HBITMAP bmp_ ;													// �`�悷��摜
		HDC* hDCBack_ ;													// �]����̃o�b�N�o�b�t�@
		HDC hDCWork_ ;													// ���[�N�o�b�t�@
		HWND hWnd_ ;													// �E�B���h�E�n���h��
		int useFlg_ ;													// �g�p�t���O
		int	x_ , y_ ;													// �`����W
		int	u_ , v_ ;													// �؂�o�����W
		int	w_ , h_ ;													// �؂�o��������
		float scaleX_ , scaleY_ ;										// �{��
		int alphaFlg_ ;													// �������g�p�t���O
		int alpha_ ;													// �������̒l
		int rotateFlg_ ;												// ��]�g�p�t���O
		float degree_ ;													// ��]�̊p�x(�x���@)

} ;


