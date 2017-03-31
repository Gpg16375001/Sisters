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
	int		_w , _h ;				// 幅高さ
} ;

// クラスの宣言
class BitmapData
{
	static const int MAX_BMP_IMAGES = 256 ;

	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~BitmapData( ) ;

		int loadData( int arg_bmpNo_ , LPCTSTR arg_pStr , int arg_width , int arg_height , int arg_cx = 0 , int arg_cy = 0 ) ;
		int clearData( int arg_bmpNo ) ;
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;

		/*/
		/*	最大保持数の取得
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_IMAGES ) ;
		}
		/*/
		/*	ビットマップのハンドルのアクセッサ
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
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


