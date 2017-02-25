/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		バックバッファに描画をするクラス
		
			--- 主な使い方 ---
			インスタンス 1つ で 1枚 を描画する ( 同時に呼ぶことはないようにする そもそも呼べないが.. )
			基本的な流れとしては ↓
			【 Renderer::GetInstance()->setRender() → draw →
				Renderer::GetInstance()->clearRenderer() → Next_Frame 】 となる。

			個別にセットしたい場合は各メンバの対応メソッドを使用する。

			例1. 基本的な流れ
			Renderer::GetInstance()->setRenderer( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;

			例2. 2倍での表示を行いたい場合
			Renderer::GetInstance()->setScaleXY( 2.0 , 2.0 ) ;

			例3. アルファ50% で表示を行いたい場合
			Renderer::GetInstance()->setAlpha( 0.5 ) ;

			例4. 45度回転処理を行いたい場合
			Renderer::GetInstance()->setRotate( 45.0f ) ;

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// クラスの宣言
class Renderer
{
	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;													// デストラクタ

		int setRender(													// スプライトのセット
				HBITMAP arg_bmp ,										 // . 画像データ
				int anchor ,											 // . アンカー ( 配置位置 )
				int arg_x , int arg_y ,									 // . 左上の座標
				int arg_u , int arg_v ,									 // . 切り出し座標
				int arg_w , int arg_h ,									 // . 幅と高さ
				float arg_scaleX = 1.0f , float arg_scaleY = 1.0f ,		 // . スケール倍率
				float arg_degree = 0.0f ,								 // . 回転する角度
				float arg_alpha = 0.0f									 // . 透明度
			) ;
		int clearScreen( ) ;											// スプライトのクリア
		int setFlg( int arg_flg ) ;										// フラグのセット
		int selectBmp( HBITMAP arg_bmp ) ;								// スプライトのセット
		int setPos( int arg_x , int arg_y ) ;							// 座標のセット
		int setUV( int arg_u , int arg_v ) ;							// 切り出し座標のセット
		int setWH( int arg_w , int arg_h ) ;							// 切り出し幅高さのセット
		int draw( ) ;													// スプライトの描画
		int setScaleXY( float arg_scaleX , float arg_scaleY ) ;			// スケール倍率のセット
		int setAlphaFlg( int arg_alphaFlg ) ;							// アルファ処理フラグのセット
		int setAlpha( float arg_alpha ) ;								// アルファ処理のセット
		int setRotateFlg( int arg_rotateFlg ) ;							// 回転処理フラグのセット
		int setRotate( float arg_degree ) ;								// 回転処理のセット

		int	setHDC( HDC arg_hDCBack ) {									// 転送先のバックバッファをもらう
			hDCBack_ = &arg_hDCBack ;
			return( true ) ;
		}
		int setHWindow( HWND arg_hWnd ) {								// ウィンドウハンドルの取得
			hWnd_ = arg_hWnd ;
			return( true ) ;
		}

		/*/
		/*	Shingleton -> インスタンスの取得
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
		{													// コンストラクタ
			// インスタンス化時の初期化
			clearScreen( ) ;

		} ;

	private :
		HBITMAP bmp_ ;													// 描画する画像
		HDC* hDCBack_ ;													// 転送先のバックバッファ
		HDC hDCWork_ ;													// ワークバッファ
		HWND hWnd_ ;													// ウィンドウハンドル
		int useFlg_ ;													// 使用フラグ
		int	x_ , y_ ;													// 描画座標
		int	u_ , v_ ;													// 切り出し座標
		int	w_ , h_ ;													// 切り出し幅高さ
		float scaleX_ , scaleY_ ;										// 倍率
		int alphaFlg_ ;													// 半透明使用フラグ
		int alpha_ ;													// 半透明の値
		int rotateFlg_ ;												// 回転使用フラグ
		float degree_ ;													// 回転の角度(度数法)

} ;


