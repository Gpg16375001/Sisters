/*
______________________________________________________________________________________________

	FILE : ChipBackGround.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		チップ背景を描画するクラス
		
			--- 主な使い方 ---
			インスタンス1つで一枚のチップ背景を描画する。
			selectBmpで選択されたビットマップを 32 * 32 で縦に切り取り、
			チップテーブルの番号に従って描画を行う。
			今回は 32 * 32 のチップテーブルを採用した。
			つまり 32 * 32 は 1024 なので　1024 * 1024 のチップ背景を描画できる。
			また m_x , m_y メンバを使用してのチップ背景スクロールが可能である。
			これをうまく使うことにより無限スクロールや横スクロールアクション等の
			ステージを表現できる。


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#define CHIP_X	32
#define CHIP_Y	32
#define CHIP_W	32
#define CHIP_H	32

// クラスの宣言
class ChipBackGround
{
	public :
		ChipBackGround( ) ;												// コンストラクタ
		~ChipBackGround( ) ;											// デストラクタ

		int selectBmp( int arg_bmpNo ) ;								// 描画したい背景の番号をセット
		int setPos( int arg_x , int arg_y ) ;							// 座標のセット
		int setChip( int arg_x , int arg_y , int arg_chipNo ) ;			// チップのセット
		int setFastChip( int *arg_chipData ) ;							// チップデータの高速コピー
		int clearChip( ) ;												// チップのクリア
		int draw( ) ;													// チップの描画

	private :
		int	m_bmpNo ;													// テーブル番号
		int	m_x , m_y ;													// 描画座標
		int m_chipTable[ CHIP_X * CHIP_Y ] ;

} ;


