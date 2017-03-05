/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    Playerクラス

	Playerクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

class Player
{
	public :
		/*/
		/*	コンストラクタ
		/*/
		Player( ) ;

		/*/
		/*	デストラクタ
		/*/
		~Player( ) ;

		/*/
		/*	 初期化
		/*/
		void Initialize( ) ;

		/*/
		/*	 終了化
		/*/
		void Finalize( ) ;

		void PlayerAction( ) ;

		void Pinit( ) ;		// 初期
		void Pstop( ) ;		// 止まり時
		void Pwalk( ) ;		// 左右歩き
		void Pjinit( ) ;	// ジャンプ初期化
		void Pjump( ) ;		// ジャンプと落下

		bool FootCheck( ) ;	// 足元チェック
		bool Collision( ) ;	// あたり判定

		/*/
		/*	 更新
		/*/
		void Update( ) ;

	private :
		enum PlayerMode {
			P_init = -1 ,
			P_stop = 0 ,
			P_walk ,
			P_jinit ,
			P_jump ,
			P_drop ,
		} ;
		PlayerMode Pmode_ ;

		float	Player_xpos_ ;
		float	Player_ypos_ ;
		float	Player_xspd_ ;
		float	Player_yspd_ ;
		int		arrayX_ ;
		int		arrayY_ ;
		bool	flyCheck_ ;		// 空中かどうかのチェック

} ;


