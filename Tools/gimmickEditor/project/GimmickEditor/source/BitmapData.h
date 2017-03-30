/*
______________________________________________________________________________________________

	FILE : BitmapData.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		ビットマップを読み込みデータを保持するクラス
		
			--- 主な使い方 ---
			1つのインスタンスで1枚のビットマップデータを保持することができる。
			つまり16枚のビットマップデータを読み込みたいときはインスタンスが16個必要である。
			また使いまわしを考え、明示的な開放と多重読み込みの時の暗黙の解放をサポートしている。

			例1.コンストラクタでビットマップを読み込む
			BitmapData bmp( file_path , width , height ) ;

			例2.コンストラクタを使わない場合
			BitmapData bmp1 ;
			bmp1.loadData bmp( file_path , width , height ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// クラスの宣言
class BitmapData
{
	public :
		BitmapData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		BitmapData( ) ;
		~BitmapData( ) ;

		int loadData( LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( ) ;
		
		HBITMAP getBmpData( ) ;
		int getBmpWidth( ) ;
		int getBmpHeight( ) ;

	private :
		HBITMAP m_hBmp ;
		int m_width ;
		int m_height ;

} ;


