/*
______________________________________________________________________________________________

	FILE : Player.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		プレイヤーのクラス宣言部
		
			ゲームのキャラクター同士( プレイヤーやエネミー、アイテム等 )
			は相互関係性が強いので柔軟性を出すためにすべてを公開メンバとした。
			本来はオブジェクト同士のメソッドで相互関係を気付いていくことが理想的だが、
			ゲームのように相手の情報に多々アクセスするような場合は開発初期はパブリックな
			アクセスを許可した方が開発がスムーズであることが多い。
			もちろんアクセッサを介さない場合の危険性は十分に考慮する必要がある。
			授業ではできる限りメソッドでの相互関係を目指す処理が無駄に複雑化する場合は
			多少のパブリックアクセスを許容していく。


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

// enum
enum PlayerActionName
{
	ePlayerBlank = -1,
	ePlayerStandby,
	ePlayerMoveLeft,
	ePlayerMoveRight,
	ePlayerMoveUp,
	ePlayerMoveDown,
} ;

// クラスの宣言
class Player
{
	public :
		Player( ) ;														// コンストラクタ
		~Player( ) ;													// デストラクタ

		int action( ) ;													// アクション
		int setGPoint( int arg_gX , int arg_gY ) ;						// グローバル座標のセット
		int setAPoint( int arg_aX , int arg_aY ) ;						// 配列座標のセット

	public :
		int m_actionNo ;												// アクション番号
		POINT m_gPoint ;												// プレイヤーのグローバル座標
		POINT m_aPoint ;												// プレイヤーの配列座標

} ;


