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
			全体の流れとしては、clearRender -> select -> set -> Render  -> draw となる。

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
		int selectBmp( HGDIOBJ arg_bmpData ,				// 画像データの取得
				int arg_anchor ,							 // . アンカー
				int arg_x , int arg_y ,						 // . 配置座標
				int arg_u , int arg_v ,						 // . 切り取り位置
				int arg_w , int arg_h ,						 // . 幅高さ
				float arg_scaleX , float arg_scaleY			 // . 拡大率
			) ;
		int Render( ) ;									// バックバッファへの出力

		int setPos( int arg_x , int arg_y ) ;			// 座標のセット
		int setUV( int arg_u , int arg_v ) ;			// 切り出し座標のセット
		int setWH( int arg_w , int arg_h ) ;			// 切り出し幅高さのセット
		int setScale( float arg_w , float arg_h ) ;		// 拡大率のセット
		int setAnchor( int arg_anchor ) ;				// アンカーのセット

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

	private :
		HGDIOBJ bmpData_ ;
		HDC hDCBack_ ;				// 裏画面
		HDC hDCWork_ ;				// 作業用画面

		int x_ , y_ ;				// 描画座標
		int u_ , v_ ;				// 切り取り座標
		int w_ , h_ ;				// 幅高さ
		int anchorX_ , anchorY_ ;
		float scaleX_ , scaleY_ ;	// 拡大率

} ;


