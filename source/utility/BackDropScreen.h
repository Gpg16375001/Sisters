/*
______________________________________________________________________________________________

	FILE : BackDropScreen.h

	________/ Explanation of file /___________________________________________________________

		バックドロップ面の描画を行うクラス
		
			--- 主な使い方 ---
			インスタンス1つで1枚のビットマップを描画する(仕様上で一枚でよい)
			selectBmp に背景用ビットマップテーブル内の描画したい番号を渡すことで、
			（ 0番目と決めておくとよい ）
			描画する背景ビットマップの変更が行える。
			描画には Draw メソッドをフレーム毎に呼び出すこと。

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>

// クラスの宣言
class BackDropScreen
{
	public :
		BackDropScreen( ) ;
		~BackDropScreen( ) ;

		int selectBmp( int arg_bmpNo ) ;
		int draw( ) ;

//	private :
		int bmpNo_ ;
		BitmapData bDataBGTable_[ 4 ] ;

} ;


