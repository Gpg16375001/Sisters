
#include "WinMain.h"

class MainApp : public WinMain
{
	public :
		MainApp( TCHAR* szClassName , TCHAR* szTitleName ) ;
		~MainApp( ) ;

		/*/
		/*	<-�p��-> �E�C���h�v���V�[�W��
		/*/
		virtual LRESULT WndProc( HWND hWnd , UINT msg , UINT wParam , LONG lParam ) ;

		/*/
		/*	<-�p��-> ������
		/*/
		virtual void Initalize( ) ;

		/*/
		/*	<-�p��-> �I����
		/*/
		virtual void Finalize( ) ;

		/*/
		/*	<-�p��-> ���C�����[�v
		/*/
		virtual void Update( ) ;

	private :
		void Update_( ) ;
		void Render_( ) ;
		void RenderDebug_( ) ;

		bool is_debug_render_ ;

} ;


