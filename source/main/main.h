
#include "WinMain.h"

class MainApp : public WinMain
{
	public :
		MainApp( TCHAR* szClassName , TCHAR* szTitleName ) ;
		~MainApp( ) ;

		/*/
		/*	<-継承-> ウインドプロシージャ
		/*/
		virtual LRESULT WndProc( HWND hWnd , UINT msg , UINT wParam , LONG lParam ) ;

		/*/
		/*	<-継承-> 初期化
		/*/
		virtual void Initalize( ) ;

		/*/
		/*	<-継承-> 終了化
		/*/
		virtual void Finalize( ) ;

		/*/
		/*	<-継承-> メインループ
		/*/
		virtual void Update( ) ;

	private :
		void Update_( ) ;
		void Render_( ) ;
		void RenderDebug_( ) ;

		bool is_debug_render_ ;

} ;


