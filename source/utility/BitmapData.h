/*
______________________________________________________________________________________________

	FILE : BitmapData.h

	________/ Explanation of file /___________________________________________________________

		ビットマップを読み込みデータを保持するクラス
		
			--- 主な使い方 ---
			1つのインスタンスで1024枚のビットマップデータを保持することができる。
			つまり、画像を補完するクラスなのでほしい画像の番号から呼び出すことになる。
			かならず一度だけ最初に BitmapData::GetInstance( )->Initialize( ) で初期化する。

			例1. 画像の読み込み方法
			BitmapData::GetInstance( )->loadData( bmpNo , file_path , width , height ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

struct BmpData {
	HBITMAP _hBmp ;
	int _width ;
	int _height ;
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
		
		HBITMAP getBmpData( int arg_bmpNo ) ;
		int getBmpWidth( int arg_bmpNo ) ;
		int getBmpHeight( int arg_bmpNo ) ;

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


