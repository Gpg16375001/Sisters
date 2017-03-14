/*
______________________________________________________________________________________________

	FILE : Sprite.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		スプライトを描画するクラス
		
			--- 主な使い方 ---
			インスタンス 1つ で 1枚 のスプライトを描画する
			基本的な流れとしては 【 setSprite -> draw -> clearSprite -> Next_Frame 】 となる。
			個別にセットしたい場合は各メンバの対応メソッドを使用する。

			例1. スプライトクラスの基本的な流れ
			インスタンス.setSprite( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;
			インスタンス.draw( ) ;
			インスタンス.clearSprite( ) ;

			例2. 2倍での表示を行いたい場合
			インスタンス.setScaleXY( 2.0 , 2.0 ) ;

			例3. アルファ50% で表示を行いたい場合
			インスタンス.setAlpha( 0.5 ) ;

			例4. 45度回転処理を行いたい場合
			インスタンス.setRotate( 45.0f ) ;

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// クラスの宣言
class Sprite
{
	public :
		Sprite( ) ;														// コンストラクタ
		~Sprite( ) ;													// デストラクタ

		int setSprite(													// スプライトのセット
				int arg_bmpNo ,											 // . スプライトの番号
				int arg_x , int arg_y ,									 // . 左上の座標
				int arg_u , int arg_v ,									 // . 切り出し座標
				int arg_w , int arg_h									 // . 幅と高さ
			) ;
		int clearSprite( ) ;											// スプライトのクリア
		int setFlg( int arg_flg ) ;										// フラグのセット
		int selectBmp( int arg_bmpNo ) ;								// スプライトのセット
		int setPos( int arg_x , int arg_y ) ;							// 座標のセット
		int setUV( int arg_u , int arg_v ) ;							// 切り出し座標のセット
		int setWH( int arg_w , int arg_h ) ;							// 切り出し幅高さのセット
		int draw( ) ;													// スプライトの描画
		int setScaleFlg( int arg_scaleFlg ) ;							// スケール使用フラグのセット
		int setScaleXY( float arg_scaleX , float arg_scaleY ) ;			// スケール倍率のセット
		int setAlphaFlg( int arg_alphaFlg ) ;							// アルファ処理フラグのセット
		int setAlpha( float arg_alpha ) ;									// アルファ処理のセット
		int setRotateFlg( int arg_rotateFlg ) ;							// 回転処理フラグのセット
		int setRotate( float arg_degree ) ;								// 回転処理のセット

	private :
		int m_useFlg ;													// 使用フラグ
		int	m_bmpNo ;													// テーブル番号
		int	m_x , m_y ;													// 描画座標
		int	m_u , m_v ;													// 切り出し座標
		int	m_w , m_h ;													// 切り出し幅高さ
		int m_scaleFlg ;												// スケール使用フラグ
		float m_scaleX , m_scaleY ;										// 倍率
		int m_alphaFlg ;												// 半透明使用フラグ
		int m_alpha ;													// 半透明の値
		int m_rotateFlg ;												// 回転使用フラグ
		float m_degree ;												// 回転の角度(度数法)

} ;


