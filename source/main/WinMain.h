
#include <windows.h>
#include <DxLib.h>

class WinMain {
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		WinMain( TCHAR* arg_szClassName , TCHAR* arg_szTitleName ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		virtual ~WinMain( ) ;

		/*/
		/*	�E�B���h�E�̍��W�ύX
		/*/
		void SetWindowPos( int arg_x , int arg_y ) ;

		/*/
		/*	�E�B���h�E�̃T�C�Y�ύX
		/*/
		void SetWindowSize( int arg_w , int arg_h ) ;

		/*/
		/*	�E�B���h�E�� X���W �̎擾
		/*/
		int GetPostionX( ) const {
			return( wPos_x_ ) ;
		} ;

		/*/
		/*	�E�B���h�E�� Y���W �̎擾
		/*/
		int GetPostionY( ) const {
			return( wPos_y_ ) ;
		} ;

		/*/
		/*	�E�B���h�E�� �� �̎擾
		/*/
		int GetWidth( ) const {
			return( wSize_w_ ) ;
		} ;

		/*/
		/*	�E�B���h�E�� ���� �̎擾
		/*/
		int GetHeight( ) const {
			return( wSize_h_ ) ;
		} ;

		/*/
		/*	�E�B���h�E�� �n���h�� �̎擾
		/*/
		HWND GetHWindow( ) const {
			return( hWnd_ ) ;
		} ;

		/*/
		/*	����ʂ�HDC �̎擾
		/*/
		HDC GetHDCBack( ) const {
			return( hDCBack_ ) ;
		} ;

		/*/
		/*	��Ɨp��HDC �̎擾
		/*/
		HDC GetHDCWork( ) const {
			return( hDCWork_ ) ;
		} ;

		/*/
		/*	�J�n
		/*/
		bool Start( ) ;

	private :
		static LRESULT CALLBACK WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lPram ) ;

		/*/
		/*	�^�C���v���V�[�W��
		/*/
		static void CALLBACK TimerProc( UINT arg_ID , UINT arg_Msg , DWORD arg_User , DWORD arg_dw1 , DWORD arg_dw2 ) ;

		/*/
		/*	�\�����\���ǂ������Z�b�g
		/*/
		static void SetFpsFlg( bool arg_fpsFlg ) ;

		/*/
		/*	�N���C�A���g�T�C�Y�̎擾 ( SIZE�^�ŕԂ� )
		/*/
		SIZE GetClientSize_( int arg_w , int arg_h ) ;

	/*/
	/*	--+ VIRTUAL +-- 
	/*/
	public :

		/*/
		/*	�E�B���h�E�v���V�[�W��
		/*/
		virtual LRESULT WndProc( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lParam ) = 0 ;

		/*/
		/*	UPDATE
		/*/
		virtual void Update( ) = 0 ;

		/*/
		/*	INITALIZE
		/*/
		virtual void Initalize( ) = 0 ;

		/*/
		/*	FINALIZE
		/*/
		virtual void Finalize( ) = 0 ;

	private :		
		/*/
		/*	�`��̏���
		/*/
		void Draw_( ) ;

		TCHAR		szClassName_[256] ;
		TCHAR		szTitleName_[256] ;
		int			wPos_x_ , wPos_y_ ;
		int			wSize_w_ , wSize_h_ ;
		HWND		hWnd_ ;
		WNDCLASSEX	wc_ ;												// �E�B���h�E�N���X�\����
		HINSTANCE	hInst_ ;
		DWORD		start_time_ , old_time_ ;
		static bool	*fpsp_ ;
		bool		fps_ ;												// �`��\flag
		int			timerID_ ;											// �^�C���v���V�[�W����ID

		HBITMAP		hDCBackBmp_ ;
		HDC			hDCBack_ ;
		HDC			hDCWork_ ;

} ;


