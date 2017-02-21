
#include <windows.h>

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
			return wPos_x_ ;
		} ;

		/*/
		/*	ウィンドウの Y座標 の取得
		/*/
		int GetPostionY( ) const {
			return wPos_y_ ;
		} ;

		/*/
		/*	ウィンドウの 幅 の取得
		/*/
		int GetWidth( ) const {
			return wSize_w_ ;
		} ;

		/*/
		/*	ウィンドウの 高さ の取得
		/*/
		int GetHeight( ) const {
			return wSize_h_ ;
		} ;

		/*/
		/*	ウィンドウの ハンドル の取得
		/*/
		HWND GetHWindow( ) const {
			return hWnd_ ;
		} ;

		/*/
		/*	裏画面のHDC の取得
		/*/
		HDC GetBackHDC( ) const {
			return hDCBack_ ;
		} ;

		/*/
		/*	開始
		/*/
		bool Start( ) ;

	private :
		static LRESULT CALLBACK WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lPram ) ;

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

//	private :
		
		/*/
		/*	描画の処理
		/*/
		void Render_( ) ;

		TCHAR		szClassName_[256] ;
		TCHAR		szTitleName_[256] ;
		int			wPos_x_ , wPos_y_ ;
		int			wSize_w_ , wSize_h_ ;
		HWND		hWnd_ ;
		WNDCLASSEX	wc_ ;												// ウィンドウクラス構造体
		HINSTANCE	hInst_ ;

		HBITMAP		bitmap_ ;
		HDC			hDCBack_ ;

} ;


