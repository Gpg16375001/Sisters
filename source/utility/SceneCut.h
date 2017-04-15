/*
______________________________________________________________________________________________

	FILE : SceneCut.h

	________/ Explanation of file /___________________________________________________________

		背景の描画に必要なデータを保持するするするクラス
		
			--- 主な使い方 ---
			1つのインスタンスで4枚の背景を保持することができる。
			つまり、画像の情報を補完するクラスなのでほしい画像の番号から呼び出すことになる。
			かならず一度だけ最初に SceneCut::GetInstance( )->Initialize( ) で初期化する。

			例1. 画像の読み込み方法
			SceneCut::GetInstance( )->loadBmpData( bmpNo , hBITMAP ) ;

			例2. 画像をセット
			SceneCut::GetInstance()->setBmpData(
					bmpNo ,
					anchor ,
					x , y ,
					u , v ,
					width , height ,
					scaleX , scaleY
				) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// クラスの宣言
class SceneCut
{
	static const int MAX_BMP = 4 ;

	public :
		struct BmpData {
			HBITMAP _hBmp ;
			bool	_useFlg ;				// 描画するかどうかのフラグ
			float	_x , _y ;				// 座標
			float	_w , _h ;				// 幅高さ
			bool	_useAlpha  ;			// 透明処理を行うかどうかのフラグ
			int		_alpha ;				// 透明度
		} ;

		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~SceneCut( ) ;

		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;
		int clearData( int arg_bmpNo ) ;
		int fadeIn( ) ;
		int fadeOut( ) ;
		int BlackOut( ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// 描画するかどうかのフラグをセット
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;			// 透明処理をするかどうかのフラグをセット
		int setBmpXY( int arg_bmpNo , float arg_x , float arg_y ) ;	// ポジションのセット
		int setBmpWH( int arg_bmpNo , float arg_w , float arg_h ) ;	// 幅、高さのセット
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;				// 透明度のセット
		int setBmpData(													// すべてのセット
				int arg_bmpNo ,
				float arg_x , float arg_y ,
				float arg_w , float arg_h ,
				int arg_alpha = 255
			) ;

		/*/
		/*	最大描画数の取得
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP ) ;
		}
		/*/
		/*	描画するかの取得
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	透明処理するかの取得
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpTable_[ arg_bmpNo ]._useAlpha ) ;
		}

		/*/
		/*	ビットマップのハンドルのアクセッサ
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	X軸の取得
		/*/
		float getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y軸の取得
		/*/
		float getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	幅の取得
		/*/
		float getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	高さの取得
		/*/
		float getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	透明度の取得
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpTable_[ arg_bmpNo ]._alpha ) ;
		}


		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static SceneCut* GetInstance( )
		{
			static SceneCut v ;
			return &v ;
		}

	private :
		/*/
		/*	コンストラクタ
		/*/
		SceneCut( ) {
			alphaCnt_ = 0 ;
		} ;

		BmpData bmpTable_[ MAX_BMP ] ;			// 画像データ
		int		alphaCnt_ ;

} ;


