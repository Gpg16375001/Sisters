/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    Playerクラス

	Playerクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include "Common.h"
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

		void Pinit( ) ;			// 初期
		void Psinit( ) ;			// 止まり時 初期セット
		void Pstop( ) ;			// 止まり時
		void Pwalk( ) ;			// 左右歩き
		void Pjinit( ) ;		// ジャンプ初期化
		void Pjump( ) ;			// ジャンプ

		float FootCheck( ) ;	// 足元チェック ( 足元の座標を返す )
		float Collision( ) ;		// あたり判定

		/*/
		/*	 更新
		/*/
		void Update( ) ;

	private :
		enum PlayerMode {
			P_init = -1 ,
			P_sinit = 0 ,
			P_stop ,
			P_walk ,
			P_jinit ,
			P_jump ,
			P_drop ,
		} ;
		PlayerMode Pmode_ ;

		// プレイヤーのデータ
		float	Player_xpos_ ;
		float	Player_ypos_ ;
		float	Player_xspd_ ;
		float	Player_yspd_ ;
		float	Player_jspd_ ;
		int		arrayX_ ;
		int		arrayY_ ;
		bool	lrflg_ ;

		// プレイヤーの物理的なもの
		Physics Player_ ;
		float	Player_acceration ;

		// アニメーション
		Animation		PlayerAnim_ ;
		AnimationData	Panim_stop_[ 4 ] ;
		AnimationData	Panim_walk_[ 4 ] ;
		AnimationData	Panim_jump_[ 1 ] ;
		AnimationData	Panim_drop_[ 1 ] ;

} ;


