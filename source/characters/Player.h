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
		void Pdainit( ) ;		// ダメージ初期化
		void Pdamage( ) ;		// ダメージ
		void Pdeinit( ) ;		// 死に初期化
		void Pdeth( ) ;			// 死に

		float FootCheck( ) ;	// 足元チェック ( 足元の座標を返す )
		float HeadCheck( ) ;	// 頭の値判定 ( 頭の座標を返す )
		float Collision( ) ;	// あたり判定

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
			P_dainit ,
			P_damage ,
			P_deinit ,
			P_deth ,
		} ;
		PlayerMode Pmode_ ;

		// プレイヤーのデータ
		int				Player_hp_	;	// プレイヤーの体力
		Vector2D_polar	Player_vec_ ;	// 向きと大きさを持った
		Vector2D_compo	Player_spd_ ;	// 成分にしたデータ
		float			Player_xpos_ ;
		float			Player_ypos_ ;
		float			nowPos[ 2 ] ;
		float			oldPos[ 2 ] ;
		int				arrayX_ ;
		int				arrayY_ ;
		bool			lrflg_ ;
		bool			scrollflg[ 2 ] ;
		int				scrollx ;
		bool			flipMag_ ;		// 左右反転のフラグ

		// プレイヤーの物理的なもの
		Physics			Player_ ;
		float			Player_acceration_ ;
		Vector2D_compo	Player_mag_ ;

		// アニメーション
		Animation		PlayerAnim_ ;
		AnimationData	Panim_stop_[ 4 ] ;
		AnimationData	Panim_walk_[ 4 ] ;
		AnimationData	Panim_jump_[ 1 ] ;
		AnimationData	Panim_drop_[ 1 ] ;
		AnimationData	Panim_deth_[ 1 ] ;
		Animation		ballAnim_ ;
		AnimationData	Panim_ball_[ 4 ] ;

} ;


