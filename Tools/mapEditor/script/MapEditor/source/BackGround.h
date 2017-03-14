/*
______________________________________________________________________________________________

	FILE : BackGround.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		バックグラウンド面の描画を行うクラス
		
			--- 主な使い方 ---
			インスタンス1つで1枚のビットマップを描画する(仕様上で一枚でよい)
			selectBmp に背景用ビットマップテーブル内の描画したい番号を渡すことで、
			（ 0番目と決めておくとよい ）
			描画する背景ビットマップの変更が行える。
			描画には Draw メソッドをフレーム毎に呼び出すこと。

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// クラスの宣言
class BackGround
{
	public :
		BackGround( ) ;
		~BackGround( ) ;

		int setX( int arg_x ) ;
		int setY( int arg_y ) ;

		int selectBmp( int arg_bmpNo ) ;
		int draw( ) ;

	private :
		int	m_bmpNo ;
		int	m_x, m_y ;

} ;


