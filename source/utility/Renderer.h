/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		ビットマップの描画を行うクラス
		
			--- 主な使い方 ---
			インスタンス1つで1枚のビットマップを描画する。
			必ずプログラムの最初に setHDC をしなければならない。
			selectBmp にビットマップテーブル内の描画したいビットマップのデータと
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
#include <math.h>

/*/
/*	クラスの宣言
/*/
class Renderer
{
	public :
		struct POS {
			float x ;
			float y ;
		} ;

		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;

		int setHDC( HWND arg_hWnd , HDC arg_hDCBack , HDC arg_hDCWork ) ;	// 裏画面の描画に必要なものをもらう
		int selectBmp( HGDIOBJ arg_bmpData ,				// 画像データの取得
				int arg_anchor ,							 // . アンカー
				float arg_x , float arg_y ,					 // . 配置座標
				float arg_u , float arg_v ,					 // . 切り取り位置
				float arg_w , float arg_h ,					 // . 幅高さ
				float arg_scaleX , float arg_scaleY ,		 // . 拡大率
				int arg_alpha = 255 ,						 // . 透明度
				float arg_degree = 0						 // . 角度
			) ;
		int DrawAlpha( ) ;
		int DrawRote( ) ;
		int Render( ) ;										// バックバッファへの出力

		int setPos( float arg_x , float arg_y ) ;			// 座標のセット
		int setUV( float arg_u , float arg_v ) ;			// 切り出し座標のセット
		int setWH( float arg_w , float arg_h ) ;			// 切り出し幅高さのセット
		int setScale( float arg_w , float arg_h ) ;			// 拡大率のセット
		int setAnchor( int arg_anchor ) ;					// アンカーのセット
		int setAlpha( int arg_alpha ) ;						// 透明度のセット
		int setAngle( float arg_degree ) ;					// 角度のセット
		int setAlphaFlg( bool arg_alphaFlg ) ;				// 透明度のフラグをセット
		int setRotateFlg( bool arg_rotateFlg ) ;			// 角度のフラグをセット

		HDC getHDCBack( ) const {
			return( hDCBack_ ) ;
		}

		/*/
		/*	sceneCut
		/*/
		int setSceneCut( int arg_no )
		{
			int oldSceneCut = sceneCut ;
			sceneCut = arg_no ;
			return( oldSceneCut ) ;
		}

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static Renderer* GetInstance( )
		{
			static Renderer v ;
			return &v ;
		}

		/*/
		/*	sin の取得
		/*/
		float Mysin( float arg_time , int arg_width )
		{
			int time = ( int )arg_time % 360 ;
			return( (sinTbl[ time ] * arg_width) ) ;
		}
		float Mysin( int arg_time , int arg_width )
		{
			int time = arg_time % 360 ;
			return( (sinTbl[ time ] * arg_width) ) ;
		}
		/*/
		/*	cos の取得
		/*/
		float Mycos( float arg_time , int arg_width )
		{
			int time = ( int )(arg_time + 90) % 360 ;
			return( (sinTbl[ time ] * arg_width) ) ;
		}
		float Mycos( int arg_time , int arg_width )
		{
			int time = (arg_time + 90) % 360 ;
			return( (sinTbl[ time ] * arg_width) ) ;
		}

		HWND getHWnd() const {
			return( hWnd_ ) ;
		} ;

	private :	
		/*/
		/*	コンストラクタ
		/*/
		Renderer( ) {
			for ( int i = 0 ; i < 360 ; ++i )
			{
				sinTbl[ i ] = sin( i * 3.14f / 180.0f ) ;
			}
		} ;

	private :
		HGDIOBJ bmpData_ ;
		HDC		hDCBack_ ;				// 裏画面
		HDC		hDCWork_ ;				// 作業用画面
		HDC		hDCHold_ ;				// 作業用画面2 一度ここに集める
		HWND	hWnd_ ;					// 親のウィンドウハンドル

		float	x_ , y_ ;				// 描画座標
		float	u_ , v_ ;				// 切り取り座標
		float	w_ , h_ ;				// 幅高さ
		int		anchorX_ , anchorY_ ;	// アンカーの位置
		float	scaleX_ , scaleY_ ;		// 拡大率
		int		alpha_ ;				// 透明度
		float	degree_ ;				// 角度
		bool	alphaFlg_ ;				// 透明処理をするかどうかのフラグ
		bool	rotateFlg_ ;			// 回転処理をするかどうかのフラグ
		float	sinTbl[ 360 ] ;
		int		sceneCut ;				// シーン切り替え時の処理

} ;


