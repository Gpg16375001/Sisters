/*
______________________________________________________________________________________________

	FILE : BitmapData.h

	________/ Explanation of file /___________________________________________________________

		ビットマップを読み込みデータを保持するクラス
		
			--- 主な使い方 ---
			1つのインスタンスで1024枚のビットマップデータを保持することができる。
			つまり、画像の情報を補完するクラスなのでほしい画像の番号から呼び出すことになる。
			かならず一度だけ最初に BitmapData::GetInstance( )->Initialize( ) で初期化する。

			例1. 画像の読み込み方法
			BitmapData::GetInstance( )->loadData( bmpNo , file_path , width , height ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

struct BmpData {
	HBITMAP _hBmp ;
	bool _useFlg ;				// 描画するかどうかのフラグ
	int _anchor ;				// アンカーの位置
	int _x , _y ;
	int _u , _v ;
	int _w , _h ;
	float _scaleX , _scaleY ;	// 拡大率
} ;

// クラスの宣言
class BitmapData
{
	static const int MAX_BMP_IMAGES = 1024 ;

	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~BitmapData( ) ;

		int loadData( int arg_bmpNo_ , LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( int arg_bmpNo ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// 描画するかどうかのフラグをセット
		int setBmpXY( int arg_bmpNo , int arg_x , int arg_y ) ;			// ポジションのセット
		int setBmpUV( int arg_bmpNo , int arg_u , int arg_v ) ;			// 切り取り位置のセット
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;			// 幅、高さのセット
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;	// 拡大率のセット
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;				// アンカーのセット
		int setBmpData(													// すべてのセット
				int arg_bmpNo ,
				int arg_anchor ,
				int arg_x , int arg_y ,
				int arg_u , int arg_v ,
				int arg_w , int arg_h ,
				float arg_scaleX , float arg_scaleY
			) ;

		/*/
		/*	最大描画数の取得
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_IMAGES ) ;
		}
		/*/
		/*	描画するかの取得
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpDataTable_[ arg_bmpNo ]._useFlg ) ;
		}

		/*/
		/*	ビットマップのハンドルのアクセッサ
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	アンカーを取得
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	X軸の取得
		/*/
		int getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y軸の取得
		/*/
		int getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	X軸の切り取り位置の取得
		/*/
		int getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y軸の切り取り位置の取得
		/*/
		int getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	幅の取得
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	高さの取得
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	幅の拡大率の取得
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	高さの拡大率の取得
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._scaleY ) ;
		}


		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static BitmapData* GetInstance( )
		{
			static BitmapData v ;
			return &v ;
		}

	private :
		/*/
		/*	コンストラクタ
		/*/
		BitmapData( ) {	} ;

		BmpData bmpDataTable_[ MAX_BMP_IMAGES ] ;			// 画像データ


} ;


