/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		ビットマップの描画を行うクラス
		
			--- 主な使い方 ---
			インスタンス1つで1枚のビットマップを描画する。
			必ずプログラムの最初に setHDC をしなければならない。
			selectBmp に背景用ビットマップテーブル内の描画したいビットマップのデータと
			大きさを渡すことで、描画するビットマップの変更が行える。
			select -> set -> render が一つのオブジェクトに対しての処理となる。
			つまり一度に二つの描画を行うときは、
				Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;
				Renderer::GetInstance()->setPos( x , y ) ;
				Renderer::GetInstance()->Render( ) ;

				Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;
				Renderer::GetInstance()->setPos( x , y ) ;
				Renderer::GetInstance()->Render( ) ;
			となる。

			例1. setHDC() の方法
			Renderer::GetInstance()->setHDC( hDCBackBuf , hDCWorkBuf ) ;

			例2. 画像をセレクトする方法
			Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>

/*/
/*	クラスの宣言
/*/
class Renderer
{
	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;

		int setHDC( HDC arg_hDCBack , HDC arg_hDCWork ) ;	// 裏画面の描画に必要なものをもらう
		int selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height ) ;
		int Render( ) ;

		int setPos( int arg_x , int arg_y ) ;

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static Renderer* GetInstance( )
		{
			static Renderer v ;
			return &v ;
		}

	private :	
		/*/
		/*	コンストラクタ
		/*/
		Renderer( ) {	}

		HGDIOBJ bmpData_ ;
		int x_ ;
		int y_ ;
		int width_ ;
		int height_ ;
		HDC hDCBack_ ;			// 裏画面
		HDC hDCWork_ ;			// 作業用画面

} ;


