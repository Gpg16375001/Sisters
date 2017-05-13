
#include <windows.h>
#include <DxLib.h>

class WinMain {
	public :
		/*/
		/*	コンストラクタ
		/*/
		WinMain( TCHAR* arg_szClassName , TCHAR* arg_szTitleName ) ;

		/*/
		/*	デストラクタ
		/*/
		virtual ~WinMain( ) ;

		/*/
		/*	ウィンドウの座標変更
		/*/
		void SetWindowPos( int arg_x , int arg_y ) ;

		/*/
		/*	ウィンドウのサイズ変更
		/*/
		void SetWindowSize( int arg_w , int arg_h ) ;

		/*/
		/*	ウィンドウの X座標 の取得
		/*/
		int GetPostionX( ) const {
			return( wPos_x_ ) ;
		} ;

		/*/
		/*	ウィンドウの Y座標 の取得
		/*/
		int GetPostionY( ) const {
			return( wPos_y_ ) ;
		} ;

		/*/
		/*	ウィンドウの 幅 の取得
		/*/
		int GetWidth( ) const {
			return( wSize_w_ ) ;
		} ;

		/*/
		/*	ウィンドウの 高さ の取得
		/*/
		int GetHeight( ) const {
			return( wSize_h_ ) ;
		} ;

		/*/
		/*	ウィンドウの ハンドル の取得
		/*/
		HWND GetHWindow( ) const {
			return( hWnd_ ) ;
		} ;

		/*/
		/*	裏画面のHDC の取得
		/*/
		HDC GetHDCBack( ) const {
			return( hDCBack_ ) ;
		} ;

		/*/
		/*	作業用のHDC の取得
		/*/
		HDC GetHDCWork( ) const {
			return( hDCWork_ ) ;
		} ;

		/*/
		/*	開始
		/*/
		bool Start( ) ;

	private :
		static LRESULT CALLBACK WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lPram ) ;

		/*/
		/*	タイムプロシージャ
		/*/
		static void CALLBACK TimerProc( UINT arg_ID , UINT arg_Msg , DWORD arg_User , DWORD arg_dw1 , DWORD arg_dw2 ) ;

		/*/
		/*	表示が可能かどうかをセット
		/*/
		static void SetFpsFlg( bool arg_fpsFlg ) ;

		/*/
		/*	クライアントサイズの取得 ( SIZE型で返す )
		/*/
		SIZE GetClientSize_( int arg_w , int arg_h ) ;

	/*/
	/*	--+ VIRTUAL +-- 
	/*/
	public :

		/*/
		/*	ウィンドウプロシージャ
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
		/*	描画の処理
		/*/
		void Draw_( ) ;

		TCHAR		szClassName_[256] ;
		TCHAR		szTitleName_[256] ;
		int			wPos_x_ , wPos_y_ ;
		int			wSize_w_ , wSize_h_ ;
		HWND		hWnd_ ;
		WNDCLASSEX	wc_ ;												// ウィンドウクラス構造体
		HINSTANCE	hInst_ ;
		DWORD		start_time_ , old_time_ ;
		static bool	*fpsp_ ;
		bool		fps_ ;												// 描画可能flag
		int			timerID_ ;											// タイムプロシージャのID

		HBITMAP		hDCBackBmp_ ;
		HDC			hDCBack_ ;
		HDC			hDCWork_ ;

} ;


