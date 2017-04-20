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

/*/
/*	コンストラクタ
/*/
Player::Player( )
	: Pmode_( P_init )					// 初期アクションモード
	, Player_xpos_( 0.0f )				// 描画する X ポジション
	, Player_ypos_( 0.0f )				// 描画する Y ポジション
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( false )					// false : 左	true : 右
	, Player_acceration_( 0.0f )		// プレイヤーの加速度
	, scrollx( 0 )
	, flipMag_( false )					// false : 通常 true : 反転
	, barrierFlg_( false )				// false : 通常	true : バリア展開中
	, cycleFlg_( false )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	デストラクタ
/*/
Player::~Player( )
{
	Finalize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 初期化
/*/
void Player::Initialize( )
{
	Finalize( ) ;
	printf( "Player -> " ) ;

	/*/
	/*	プレイヤー 初期セット
	/*/
	Pmode_				= P_init ;		// 初期アクションモード
	Player_xpos_		= 200.0f ;		// 描画する X ポジション
	Player_ypos_		= 0.0f ;		// 描画する Y ポジション
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= true ;		// false : 左	true : 右
	Player_acceration_	= 0.098f ;		// プレイヤーの加速度
	Player_mag_.x		= 0.0f ;		// プレイヤーの移動量 x
	Player_mag_.y		= 0.0f ;		// プレイヤーの移動量 y
	Player_spd_.x		= 0.0f ;
	Player_spd_.y		= 0.0f ;
	Player_vec_.deg		= 0.0f ;
	Player_vec_.mag		= 0.0f ;
	nowPos[ 0 ]			= 0.0f ;
	nowPos[ 1 ]			= 0.0f ;
	oldPos[ 0 ]			= 0.0f ;
	oldPos[ 1 ]			= 0.0f ;
	scrollflg[ 0 ]		= false ;
	scrollflg[ 1 ]		= false ;
	scrollx				= 0 ;
	flipMag_			= false ;		// false : 通常 true : 反転
	barrierFlg_			= false ;		// false : 通常	true : バリア展開中
	cycleFlg_			= true ;		// false : さかのぼれない	true : さかのぼれる

	Player_hp_			= 3 ;

	Player_.Finalize( ) ;
	Player_.Initialize( ) ;

	Chip::GetInstance()->Finalize( ) ;

	Player_.setMass( 4.5f ) ;

	// 開始地点の設定
	Chip::GetInstance()->setScrollSize( -600 + RenderScale , 0 ) ;

	/*/
	/*	アニメーションセット
	/*	RECT ( left , top , right , bottom )
	/*/
	AnimationData P_stop[ ] = {
		{ 1000 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1001 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1002 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1003 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_walk[ ] = {
		{ 1004 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1005 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1006 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 1007 , 8 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_jump[ ] = {
		{ 1008 , 4 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_drop[ ] = {
		{ 1009 , 4 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_damg[ ] = {
		{ 1010 , 4 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_deth[ ] = {
		{ 3 , 4 , {0 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_ball[ ] = {
		{ 5 , 8 , {200 * 0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 5 , 8 , {200 * 1 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 5 , 4 , {200 * 2 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 5 , 4 , {200 * 2 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;

	memcpy( &Panim_stop_ , P_stop , 4 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_walk_ , P_walk , 4 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_jump_ , P_jump , 1 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_drop_ , P_drop , 1 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_deth_ , P_deth , 1 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_damg_ , P_damg , 1 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_ball_ , P_ball , 4 * sizeof( AnimationData ) ) ;

}

/*/
/*	 終了化
/*/
void Player::Finalize( )
{
	Player_.Finalize( ) ;

	Player_xpos_		= 0.0f ;
	Player_ypos_		= 0.0f ;
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= false ;
	Pmode_				= P_init ;
	Player_acceration_	= 0.0f ;
	Player_mag_.x		= 0.0f ;		// プレイヤーの移動量 x
	Player_mag_.y		= 0.0f ;		// プレイヤーの移動量 y
	Player_spd_.x		= 0.0f ;
	Player_spd_.y		= 0.0f ;
	Player_vec_.deg		= 0.0f ;
	Player_vec_.mag		= 0.0f ;
	nowPos[ 0 ]			= 0.0f ;
	nowPos[ 1 ]			= 0.0f ;
	oldPos[ 0 ]			= 0.0f ;
	oldPos[ 1 ]			= 0.0f ;
	scrollflg[ 0 ]		= false ;
	scrollflg[ 1 ]		= false ;
	scrollx				= 0 ;
	flipMag_			= false ;		// false : 通常 true : 反転
	barrierFlg_			= false ;		// false : 通常	true : バリア展開中
	cycleFlg_			= false ;		// false : さかのぼれない	true : さかのぼれる

	Player_hp_			= 0 ;

	// アニメーション
	memset( &Panim_stop_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_walk_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_jump_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_drop_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_deth_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_damg_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_ball_ , 0 , 1 * sizeof( AnimationData ) ) ;

}

/*/
/*	プレイヤーのアクション
/*/
void Player::PlayerAction( )
{

	// 各アクションへ
	switch( Pmode_ )
	{

		// 初期セット
		case P_init :
			Pinit( ) ;
			break ;

		// 静止アクション 初期セット
		case P_sinit :
			Psinit( ) ;
			break ;

		// 静止アクション
		case P_stop :
			Pstop( ) ;
			break ;

		// 歩きアクション
		case P_walk :
			Pwalk( ) ;
			break ;

		// ジャンプ初期セット
		case P_jinit :
			Pjinit( ) ;
			break ;

		// ジャンプアクション
		case P_jump :
			Pjump( ) ;
			break ;

		// 落下アクション
		case P_drop :
			Pjump( ) ;
			break ;

		// ダメージ初期化
		case P_dainit :
			Pdainit( ) ;
			break ;

		// ダメージ
		case P_damage :
			Pdamage( ) ;
			break ;

		// 死に初期化
		case P_deinit :
			Pdeinit( ) ;
			break ;

		// 死に
		case P_deth :
			Pdeth( ) ;
			break ;

	}


	if ( g_dethflg )
	{
		
	} else {

		// コリジョンチェック
		float collisionCheck ;
		collisionCheck = Collision( ) ;
		if ( collisionCheck != 0 )
		{
			Player_mag_.x = 0.0f ;
			Player_xpos_ = collisionCheck ;
		}
	}
}

/*/
/*	-1 : 初期
/*/
void Player::Pinit( )
{
	/*/
	/*	___/ キャラクター 初期セット /___________________
	/*/
	Sprite::GetInstance()->setBmpData(
			0 ,
			7 ,
			Player_xpos_ , Player_ypos_ ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	ballAnim_.setAnimData( Panim_ball_ ) ;
	PlayerAnim_.setAnimData( Panim_stop_ ) ;

	Pmode_ = P_sinit ;

}

/*/
/*	0 : 止まり時 初期セット
/*/
void Player::Psinit( )
{
	Pmode_ = P_stop ;

}

/*/
/*	1 : 止まり時
/*/
void Player::Pstop( )
{
	if ( (Player_spd_.x < 1.0f) || (Player_spd_.x > -1.0f) )
	{
		PlayerAnim_.setAnimData( Panim_stop_ ) ;
	}

	Player_mag_.x *= 0.98f ;
	Player_spd_.x *= 0.98f ;
	float fcheck = FootCheck() ;
	if ( fcheck != 0 )
	{
		Player_ypos_ = fcheck ;

		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			PlayerAnim_.setAnimData( Panim_walk_ ) ;
			Pmode_ = P_walk ;
		}
		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			PlayerAnim_.setAnimData( Panim_walk_ ) ;
			Pmode_ = P_walk ;
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_SPACE ) )
		{
			Pmode_ = P_jinit ;
		}

	} else {
		PlayerAnim_.setAnimData( Panim_drop_ ) ;
		if ( Pmode_ != P_damage )
		{
			Pmode_ = P_drop ;
		}
	}

}

/*/
/*	2 : 左右歩き
/*/
void Player::Pwalk( )
{
	Pmode_ = P_sinit ;

	// 左右チェック
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
		{
			if ( flipMag_ )
			{
				// 左右反転の場合
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			} else {
				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			}
			// もし右に動いていたら
			if ( Player_mag_.x > 0 )
			{
				Player_mag_.x *= 0.98f ;
				Player_spd_.x *= 0.98f ;
			}
			// 左右チェック
			lrflg_ = false ;
			Pmode_ = P_walk ;
		}
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
		{
			if ( flipMag_ )
			{
				// 左右反転の場合
				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			} else {
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			}
			// もし左に動いていたら
			if ( Player_mag_.x < 0 )
			{
				Player_mag_.x *= 0.98f ;
				Player_spd_.x *= 0.98f ;
			}
			// 左右チェック
			lrflg_ = true ;
			Pmode_ = P_walk ;		
		}
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_SPACE ) )
	{
		Pmode_ = P_jinit ;
	}

	float fcheck = FootCheck() ;
	if ( fcheck != 0 )
	{
		Player_ypos_ = fcheck ;
	} else {
		if ( (Player_spd_.x <= 5.0f) && (Player_spd_.x >= -5.0f) )
		{
			PlayerAnim_.setAnimData( Panim_drop_ ) ;
		}
		if ( Pmode_ != P_damage )
		{
			Pmode_ = P_drop ;
		}
	}

}

/*/
/*	3 : ジャンプ初期化
/*/
void Player::Pjinit( )
{
	PlayerAnim_.setAnimData( Panim_jump_ ) ;
	if ( flipMag_ )
	{
		Pmode_ = P_sinit ;
	} else {
		Player_mag_.y = -18 ;
		Pmode_ = P_jump ;
	}

}

/*/
/*	4 : ジャンプ
/*	5 : 落下
/*/
void Player::Pjump( )
{
	flipMag_ = false ;
	Player_mag_.y += Player_.Weight2D().y / 60 ;

	if ( Pmode_ == P_jump )
	{
		// 左右チェック
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				// 左右チェック
				lrflg_ = false ;

				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				// 左右チェック
				lrflg_ = true ;
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			}
		}

		float hcheck = HeadCheck() ;
		if ( hcheck != 0 )
		{
			Player_mag_.y = 0.0f ;
			Player_spd_.y = 0.0f ;
			Player_ypos_ = hcheck ;
		}

		if ( Player_mag_.y >= 0 )
		{
			PlayerAnim_.setAnimData( Panim_drop_ ) ;
			Pmode_ = P_drop ;
		}
	}

	if ( Pmode_ == P_drop )
	{
		// 左右チェック
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			}
		}

		float fcheck = FootCheck() ;
		if ( fcheck != 0 )
		{
			Player_mag_.y = 0.0f ;
			Player_spd_.y = 0.0f ;
			Player_ypos_ = fcheck ;
			PlayerAnim_.setAnimData( Panim_walk_ ) ;
			Pmode_ = P_sinit ;
		}
	}

}

/*/
/*	6 : ダメージ 初期セット
/*/
void Player::Pdainit( )
{
	Pmode_ = P_damage ;

	if ( g_dethflg )
	{
		Pmode_ = P_deth ;
	} else {
		if ( lrflg_ )
		{
			//  true : 右向き
			Player_mag_.x = -4.0f ;
			Player_spd_.x = -4.0f ;
		}
		else
		{
			//  false : 左向き
			Player_mag_.x = 4.0f ;
			Player_spd_.x = 4.0f ;
		}
		Player_mag_.y = -16 ;
		PlayerAnim_.setAnimData( Panim_damg_ ) ;
	}

}

/*/
/*	7 : ダメージ
/*/
void Player::Pdamage( )
{
	Player_mag_.y += Player_.Weight2D().y / 60 ;

	// 左右チェック
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
		{
			Player_mag_.x += -Player_acceration_ ;
		}
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
		{
			Player_mag_.x += Player_acceration_ ;
		}
	}

	if ( Player_mag_.y > 0 )
	{
		float fcheck = FootCheck() ;
		if ( fcheck != 0 )
		{
			Player_mag_.y = 0.0f ;
			Player_spd_.y = 0.0f ;
			Player_ypos_ = fcheck ;
			PlayerAnim_.setAnimData( Panim_walk_ ) ;
			Pmode_ = P_sinit ;
		}
	}

}

/*/
/*	8 : 死	初期セット
/*/
void Player::Pdeinit( )
{
	if ( g_dethflg )
	{
		Pmode_ = P_deth ;
	} else {
		Player_mag_.y = -18 ;
		PlayerAnim_.setAnimData( Panim_deth_ ) ;
		Pmode_ = P_deth ;
	}
}

/*/
/*	9 : 死
/*/
void Player::Pdeth( )
{
	if ( g_dethflg )
	{

	} else {
		Player_mag_.y += Player_.Weight2D().y / 60 ;

		if ( Player_ypos_ >= 900 )
		{
			Finalize( ) ;
			Initialize( ) ;
			Gimmick::GetInstance()->Finalize( ) ;
			Gimmick::GetInstance()->Initialize( ) ;
			g_state-- ;
		}
	}
}

/*/
/*	足元チェック
/*	足元の座標を返す
/*/
float Player::FootCheck( )
{
	if ( Pmode_ == P_deth )
	{
		return 0 ;
	}

	// ジャンプ中
	if ( Player_spd_.y < 0.0f )
	{
		return( 0 ) ;
	}

	float footY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	//printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// 次のフレームの自分の座標位置

	/*/
	/*	player 判定位置の調整
	/*/
	if ( lrflg_ )
	{
		//  true : 右向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y ;
	}
	else
	{
		//  false : 左向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y ;
	}

	// ---+ デバッグ +----------------------------------------------------------------------------------------------- debug
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// 判定をとる範囲　今は全体
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// 何か情報が入っているとき
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) + Chip::GetInstance()->getScrollY( ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) + Chip::GetInstance()->getScrollY( ) ;

			switch ( chipTable[ i ] )
			{
				// テレポート
				case -1 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							Chip::GetInstance()->setScrollSize( -896 , 0 ) ;
							footY = 1 ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							//printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				// 通常ブロックの場合
				case 1 :
				case 9 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							footY = bt ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							//printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 3 :
				case 5 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bt-1 ;

							if (cycleFlg_)
							{

							} else {
								footY = bt ;
							}

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							//printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 7 :
				case 10 :
					Vector2D_compo P1 , P3 ;
					Vector2D_compo P2 ;		// 基準点 (br,bb)
					Vector2D_compo P4 ;		// プレイヤーの座標
					float s1 , s2 ;			// 面積
					float cross[ 2 ] ;		// 交点
					float ax , ay ;
					float P2a ;				// 交点までの距離
					float P2p ;				// プレイヤーまでの距離

					// それぞれに代入
					P1.x = bl - 64 ;
					P1.y = bb + 64 ;
					P2.x = br + 64 ;
					P2.y = bb + 64 ;
					P3.x = br + 64 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// それぞれの面積を求める
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// 比率から交点を求める
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// 基準点から交点までの距離
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// 基準点からプレイヤーまでの距離
					ax = P2.x - P4.x ;
					ay = P2.y - P4.y ;
					P2p = ax * ax + ay * ay ;
					P2p = sqrt( P2a ) ;

					if ( (P2p <= P2a) && (bl - 32 <= px) && (px <= br+12) && (bt-14+Player_mag_.x <= py) )
					{
						footY = cross[ 1 ] ;

						if ( Player_.checkMotion( 45.0f , Player_.Weight2D().y , 0.95f ) )
						{
							Player_vec_.deg = -45.0f ;
							Player_mag_.x -= Player_.calcAccel( 45.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
							Player_spd_.x -= Player_.calcAccel( 45.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
							//printf( "Motion was true. \n" ) ;
						}
					}
					break  ;

				case 4 :
				case 6 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bt - 1 ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							//printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 8 :
				case 11 :
					// それぞれに代入
					P1.x = br + 64 ;
					P1.y = bb + 64 ;
					P2.x = bl - 64 ;
					P2.y = bb + 64 ;
					P3.x = bl - 64 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// それぞれの面積を求める
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// 交点を求める
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// 基準点から交点までの距離
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// 基準点からプレイヤーまでの距離
					ax = P2.x - P4.x ;
					ay = P2.y - P4.y ;
					P2p = ax * ax + ay * ay ;
					P2p = sqrt( P2a ) ;

					if ( (P2p <= P2a) && (bl - 4 <= px) && (px <= br+32) && (bt-14-Player_mag_.x <= py) )
					{
						Player_vec_.deg = 45.0f ;
						footY = cross[ 1 ] ;

						if ( Player_.checkMotion( 45.0f , Player_.Weight2D().y , 0.95f ) )
						{
							Player_mag_.x += Player_.calcAccel( 45.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
							Player_spd_.x += Player_.calcAccel( 45.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
							//printf( "Motion was true. \n" ) ;
						}
					}
					break ;

				case 12 :
					// それぞれに代入
					P1.x = bl - 64 ;
					P1.y = bb + 32 ;
					P2.x = br + 192 + 4 ;
					P2.y = bb + 32 ;
					P3.x = br + 192 + 4 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// それぞれの面積を求める
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// 比率から交点を求める
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// 基準点から交点までの距離
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// 基準点からプレイヤーまでの距離
					ax = P2.x - P4.x ;
					ay = P2.y - P4.y ;
					P2p = ax * ax + ay * ay ;
					P2p = sqrt( P2a ) ;

					if ( (P2p <= P2a) && (bl - 64 <= px) && (px <= br + 196) && (bt-64 <= py) )
					{
						footY = cross[ 1 ] ;

						if ( Player_.checkMotion( 30.0f , Player_.Weight2D().y , 0.55f ) )
						{
							Player_vec_.deg = -30.0f ;
							Player_mag_.x -= Player_.calcAccel( 30.0f , Player_.Weight2D().y / 60 , 0.60f , Player_.getMass() ) ;
							Player_spd_.x -= Player_.calcAccel( 30.0f , Player_.Weight2D().y / 60 , 0.60f , Player_.getMass() ) ;
							//printf( "Motion was true. \n" ) ;
						}
					}
					break  ;

				case 13 :
					// それぞれに代入
					P1.x = bl + 192 + 96 ;
					P1.y = bb + 16 ;
					P2.x = br + 32 ;
					P2.y = bb + 16 ;
					P3.x = br + 32 ;
					P3.y = bt - 16 ;
					P4.x = px ;
					P4.y = py ;

					// それぞれの面積を求める
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// 比率から交点を求める
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// 基準点から交点までの距離
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// 基準点からプレイヤーまでの距離
					ax = P2.x - P4.x ;
					ay = P2.y - P4.y ;
					P2p = ax * ax + ay * ay ;
					P2p = sqrt( P2a ) ;

					if ( (P2p <= P2a) && (bl - 0 <= px) && (px <= br + 260) && (bt-64 <= py) )
					{
						footY = cross[ 1 ] ;

						if ( Player_.checkMotion( 30.0f , Player_.Weight2D().y , 0.55f ) )
						{
							Player_vec_.deg = -90.0f ;
							Player_mag_.x += Player_.calcAccel( 30.0f , Player_.Weight2D().y / 60 , 0.60f , Player_.getMass() ) ;
							Player_spd_.x += Player_.calcAccel( 30.0f , Player_.Weight2D().y / 60 , 0.60f , Player_.getMass() ) ;
							//printf( "Motion was true. \n" ) ;
						}
					}
					break  ;

				// 右下
				case 14 :
					float brad ;	// 丸鋸の半径
					float x ;
					float y ;
					float c2 ;
					float c ;		// プレイヤーと丸鋸の距離
					float rad ;		// 丸鋸の中心からの高さ( Y軸 )

					if (cycleFlg_)
					{
					} else {
						break ;
					}

					bl -= 256 + 64 ;
					bt -= 384 + 64 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;	// 丸鋸の半径を求める
					x = br - brad - px ;		// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - brad - py ;		// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( (bl+brad < px) && (px < br + 64) && (bt + 256 + 32 < py) )
					{
						if ( brad <= c )
						{
							if ( flipMag_ != true )
							{
								Player_vec_.deg = -90.0f ;

								rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める
								footY = bb - c + rad + 8 ;

								if ( rad < 30 )
								{
									Player_mag_.x *= -1 ;
								}

								if ( (rad < 40) && (!barrierFlg_) )
								{
									Player_mag_.x *= -1 ;
									Player_mag_.x -= 0.78f ;

								}

								if ( (rad < 120) && (Pmode_ != P_jump) && (Pmode_ != P_drop) )
								{
									Player_mag_.x -= Player_.calcAccel( 70.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
									Player_spd_.x -= Player_.calcAccel( 70.0f , Player_.Weight2D().y / 60 , 0.66f , Player_.getMass() ) ;
								}

								//printf( " c  : %f \n" , c ) ;
								//printf( "rad : %f \n" , rad ) ;
								//printf( "brad : %f \n" , brad ) ;
								//printf( "On Hit !! \n" ) ;
							}

						}
					}
					break ;

				// 左下
				case 15 :
					bl += 0 - 44 ;
					bt -= 384 + 64 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					if ( !barrierFlg_ )
					{
						break ;
					}

					if ( (Pmode_ == P_jump) || (Pmode_ == P_drop) )
					{
						break  ;
					}

					brad = (br - bl) / 2 - 50 ;	// 丸鋸の半径を求める
					x = br - brad - px ;		// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - brad - py ;		// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( (bl+40 < px) && (px < br-brad) && (bt + 256 - 16 < py) )
					{
						if ( brad <= c + 20 )
						{
							Player_vec_.deg = -90.0f ;
							if ( flipMag_ )
							{
								if ( Player_mag_.x < 0 )
								{
									Player_mag_.x *= -1.0f ;
								}
								flipMag_ = false ;
							}

							rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める

							footY = bb - c + rad + 8 ;

							if ( (!flipMag_) && (bb > py) )
							{
								Player_mag_.x += 0.2f ;
							}

							//printf( " c  : %f \n" , c ) ;
							//printf( "rad : %f \n" , rad ) ;
							//printf( "brad : %f \n" , brad ) ;
							//printf( "On Hit !! \n" ) ;

						}
					}
					break ;

				// 右上
				case 16 :
					bl -= 256 + 64 + 32 ;
					bt -= 384 + 32 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;		// 丸鋸の半径を求める
					x = br - brad - px ;		// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - py ;				// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( (bl+brad+128 < px) && (px < br + 32 + 32) && (bt + 256 - 16 < py) && (py < bt + 256 + brad + 16) )
					{
						if ( brad < c+20 )
						{
							// スピードが足りてないとき
							if ( !barrierFlg_ )
							{
								Player_mag_.y += 9.81f / 60 ;
								if ( (-1.0f >= Player_mag_.x) && (Player_mag_.x >= 1.0f) )
								{
									Player_mag_.x = 1.0f ;
								}
								break ;
							}

							flipMag_ = true ;
							Player_mag_.x += -0.2f ;

							rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める

							footY = bt + c - rad - 8 + 256 ;
							//printf( " c  : %f \n" , c ) ;
							//printf( "rad : %f \n" , rad ) ;
							//printf( "brad : %f \n" , brad ) ;
							//printf( "On Hit !! \n" ) ;

						}
					}
					break ;

				// 左上
				case 17 :
					bl += 0 ;
					bt -= 384 + 40 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;		// 丸鋸の半径を求める
					x = br - brad - px ;			// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - py ;					// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;			// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;				// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( (bl-128 < px) && (px < br-brad) && (bt + 256 - 16 < py) && (py < bt + 256 + brad) )
					{
						if ( brad <= c )
						{
							if ( flipMag_ != false )
							{
								cycleFlg_ = false ;

								rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める

								// さかさまの時スピード足らないとき
								if ( Player_spd_.x >= -6.0f )
								{
									Pmode_ = P_drop ;
									Player_mag_.y += 6.41f ;
								}

								footY = bt + c - rad - 8 + 256 ;

								//printf( " c  : %f \n" , c ) ;
								//printf( "rad : %f \n" , rad ) ;
								//printf( "brad : %f \n" , brad ) ;
								//printf( "On Hit !! \n" ) ;
							}


						}
					}
					break ;

				// 針ブロックの場合
				case 27 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							footY = bt ;
							Pmode_ = P_dainit ;	// ------------ 変更予定 ( 死に )
						}
					}
					break ;

				case 90 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{


						}
					}
					break ;

				case 91 :

					break ;

				default :
					break ;

			}
		}
	}

	float brad ;	// 丸鋸の半径
	float x ;
	float y ;
	float c2 ;
	float c ;		// プレイヤーと丸鋸の距離
	float rad ;		// 丸鋸の中心からの高さ( Y軸 )

	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	ぎっみっくの種類分け
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ まるのこ /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

				brad = br - bl ;			// 丸鋸の半径を求める
				x = br - (br - bl) - px ;	// 丸鋸の中心点からプレイヤーまでの X軸 の距離
				y = bb - (bb - bt) - py ;	// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
				c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
				c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

				// 半径よりもプレイヤーまでの距離が短い場合
				if ( brad >= c )
				{
					rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める
//					footY = bt + c - rad - 60 ;

					//printf( "px  : %f \n" , px ) ;
					//printf( "rad : %f \n" , rad ) ;
					//printf( "On Hit !! \n" ) ;
				}
				break ;

			/*/
			/*	___/ 動く床 /___________________
			/*/
			case GIMMICK_NAME_MOVEFLOOR :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 128 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 96 + Chip::GetInstance()->getScrollY( ) ;

				if ( (bt-8 <= py) && (py < bb) )
				{
					if ( (bl-2 <= pr) && (pl <= br+2) )
					{
						Player_vec_.deg = 0.0f ;
						if ( (Gimmick::GetInstance()->getGimmickData( g )._off[ 3 ] == 0) && (bl+32 <= pr) && (pl <= br-32) )
						{
							Gimmick::GetInstance()->setOff_3( g , 1 ) ;
						}
						footY = bt-2 ;

					}
				}
				break ;

			/*/
			/*	___/ 振り子 /___________________
			/*/
			case GIMMICK_NAME_PENDULUM :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

				brad = br - bl ;			// 丸鋸の半径を求める
				x = br - (br - bl) - px ;	// 丸鋸の中心点からプレイヤーまでの X軸 の距離
				y = bb - (bb - bt) - py ;	// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
				c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
				c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

				// 半径よりもプレイヤーまでの距離が短い場合
				if ( brad+8 >= c )
				{
					rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める
					footY = bt + c - rad - 66 ;

					//printf( "px  : %f \n" , px ) ;
					//printf( "rad : %f \n" , rad ) ;
					//printf( "On Hit !! \n" ) ;
				}
				break ;

			/*/
			/*	___/ くも /___________________
			/*/
			case GIMMICK_NAME_CLOUD :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 10 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 118 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 70 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 96 + Chip::GetInstance()->getScrollY( ) ;

				if ( (bt-4 <= py) && (py < bb) )
				{
					if ( (bl-2 <= pr) && (pl <= br+2) )
					{
						Player_vec_.deg = 0.0f ;
						Player_mag_.x *= 0.965f ;			// 減速率
						Player_spd_.x *= 0.965f ;			// 減速率
						if ( Gimmick::GetInstance()->getGimmickData( g )._off[ 3 ] == 0 )
						{
							Gimmick::GetInstance()->getGimmickData( g )._off[ 3 ] = 1 ;
						}
						footY = bt ;

					}
				}
				break ;

			/*/
			/*	___/ てき POD /___________________
			/*/
			case GIMMICK_NAME_SHOOTER :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 66 + Chip::GetInstance()->getScrollY( ) ;
				bb = bt + 64 ;

				if ( (bt <= py) && (py < bb) )
				{
					if ( (bl <= pr) && (pl <= br) )
					{
						Player_vec_.deg = 0.0f ;
						footY = bt ;
					}
				}
				break ;


		}
	}
	return( footY ) ;

}

/*/
/*	頭のあたり判定
/*	頭の座標を返す
/*/
float Player::HeadCheck( )
{
	if ( Pmode_ == P_deth )
	{
		return 0 ;
	}

	float headY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	/*/
	/*	player 判定位置の調整
	/*/
	if ( lrflg_ )
	{
		//  true : 右向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 64 ;
	}
	else
	{
		//  false : 左向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 64 ;
	}

	// ジャンプ中
	if ( Player_spd_.y > 0.0f )
	{
		return( 0 ) ;
	}

	// 判定をとる範囲　今は全体
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// 何か情報が入っているとき
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 + Chip::GetInstance()->getScrollY( ) ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H + Chip::GetInstance()->getScrollY( ) ) ;

			switch ( chipTable[ i ] )
			{
				// 通常ブロックの場合
				case 1 :
				case 2 :
				case 3 :
				case 4 :
				case 5 :
				case 6 :
				case 7 :
				case 8 :
				case 9 :
				case 10 :
				case 11 :
					if ( (bt-32 <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							headY = bb + 64 ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							//printf( "footY = %8.4f \n" , headY ) ;		// blockの座標位置

						}
					}
					break ;

				case 50 :
					float brad ;
					float x ;
					float y ;
					float c2 ;
					float c ;
					float rad ;

					brad = br - bl ;
					x = br - (br - bl) - px ;
					y = bb - (bb - bt) - py ;
					c2 = x * x + y * y ;
					c = sqrt( c2 ) ;

					if ( brad >= c )
					{
						rad = sqrt( (c2 - x * x) ) ;
						headY = bt + c + rad ;

						//printf( "px  : %f \n" , px ) ;
						//printf( "rad : %f \n" , rad ) ;
						//printf( "On Hit !! \n" ) ;
					}
					break ;

				default :
					break ;

			}
		}
	}

	float brad ;	// 丸鋸の半径
	float x ;
	float y ;
	float c2 ;
	float c ;		// プレイヤーと丸鋸の距離
	float rad ;		// 丸鋸の中心からの高さ( Y軸 )

	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	ぎっみっくの種類分け
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ 振り子 /___________________
			/*/
			case GIMMICK_NAME_PENDULUM :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

					brad = br - bl ;
					x = br - (br - bl) - px ;
					y = bb - (bb - bt) - py ;
					c2 = x * x + y * y ;
					c = sqrt( c2 ) ;

					if ( brad >= c )
					{
						rad = sqrt( (c2 - x * x) ) ;
						headY = bt + c + rad ;
					}
				break ;

			/*/
			/*	___/ てき POD /___________________
			/*/
			case GIMMICK_NAME_SHOOTER :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 66 + Chip::GetInstance()->getScrollY( ) ;
				bb = bt + 64 ;

					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							headY = bb + 64 ;
						}
					}
				break ;


		}
	}

	return( headY ) ;
}

/*/
/*	あたり判定
/*/
float Player::Collision( )
{
	if ( Pmode_ == P_deth )
	{
		return 0 ;
	}

	float collisionX = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	/*/
	/*	player 判定位置の調整
	/*/
	if ( lrflg_ )
	{
		//  true : 右向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 20 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 22 ;
		py = Player_ypos_ + Player_mag_.y - 48 ;
	}
	else
	{
		//  false : 左向き
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 20 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 48 ;
	}

	// 判定をとる範囲　今は全体
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// 何か情報が入っているとき
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 + Chip::GetInstance()->getScrollY( ) ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H + Chip::GetInstance()->getScrollY( ) ) ;
			float center = bl + (br - bl) / 2 ;

			switch ( chipTable[ i ] )
			{

				// 通常ブロックの場合
				case 1 :
				case 2 :
				case 9 :
				case 27 :
					if ( (bl <= pr) && (pl <= br) )
					{
						if ( (bt <= py) && (py < bb) )
						{
							if ( Player_vec_.deg > -90 )
							{
								if ( center < px )
								{
									collisionX = br + Chip::GetInstance()->getScrollX() + 20 ;
								} else if ( px < center ) {
									collisionX = bl + Chip::GetInstance()->getScrollX() - 24 ;
								}
								Player_spd_.x = 0 ;
								
							} else {
								Player_mag_.y = -Player_mag_.x ;
								Player_mag_.x = 0 ;
								Player_spd_.x = 0 ;
							}
						}
					}
					break ;

				case 90 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							if ( center < px )
							{
								collisionX = br + Chip::GetInstance()->getScrollX() ;
							} else if ( px < center ) {
								collisionX = bl + Chip::GetInstance()->getScrollX() ;
							}

						}
					}
					break ;

				case 91 :
					break ;

				case 93 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							cycleFlg_ = true ;

						}
					}
					break ;

				// Next Stage
				case 99 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							g_state++ ;

						}
					}
					break ;

				default :
					break ;

			}
		}
	}

	float brad ;	// 丸鋸の半径
	float x ;
	float y ;
	float c2 ;
	float c ;		// プレイヤーと丸鋸の距離
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	ぎっみっくの種類分け
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ まるのこ /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :

				if ( Pmode_ != P_damage )
				{
					bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
					br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
					bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
					bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

					brad = br - bl ;			// 丸鋸の半径を求める
					x = br - (br - bl) - px ;	// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - (bb - bt) - py ;	// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( brad >= c )
					{
						// 衝突
						Pmode_ = P_dainit ;
					}
				}
				break ;

			/*/
			/*	___/ 電気 /___________________
			/*/
			case GIMMICK_NAME_SHOCKER :
				
				if ( Pmode_ != P_damage )
				{
					bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 8 ;
					br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
					bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 64 + Chip::GetInstance()->getScrollY( ) ;
					bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 128 + Chip::GetInstance()->getScrollY( ) ;

					if ( (bt-8 <= py) && (py < bb) )
					{
						if ( (bl+2 <= pr) && (pl <= br+2) )
						{
							// 衝突
							Pmode_ = P_dainit ;
						}
					}
				}
				break ;

			/*/
			/*	___/ SPEED UP /___________________
			/*/
			case GIMMICK_NAME_SPEEDUP :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 128  ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 96 + Chip::GetInstance()->getScrollY( ) ;

				if ( Player_mag_.x > 0 )
				{
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl-2 <= pr) && (pl <= br+2) )
						{
							Player_vec_.deg = 0.0f ;

							Player_mag_.x = 15.0f ;
							//printf( "Speed UP !!! \n" ) ;

						}
					}
				}
				break ;

			/*/
			/*	___/ POD /___________________
			/*/
			case GIMMICK_NAME_SHOOTER :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64  ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 64 + Chip::GetInstance()->getScrollY( ) ;
				float center = bl + (br - bl) / 2 ;

					if ( (bl <= pr) && (pl <= br) )
					{
						if ( (bt <= py) && (py < bb) )
						{
							if ( Player_vec_.deg > -90 )
							{
								if ( center < px )
								{
									//collisionX = br + Chip::GetInstance()->getScrollX() + 20 ;
								} else if ( px < center ) {
									//collisionX = bl + Chip::GetInstance()->getScrollX() - 24 ;
								}
							} else {
								//Player_mag_.y = -Player_mag_.x ;
								//Player_mag_.x = 0 ;
							}
						}
					}
				break ;

		}
	}

	if ( Pmode_ != P_damage )
	{
		// 弾だけのあたり判定
		for ( int g = 500 ; g < 1000 ; ++g )
		{
			bl = Sprite::GetInstance()->getBmpXPos( g ) - Chip::GetInstance()->getScrollX( ) ;
			br = Sprite::GetInstance()->getBmpXPos( g ) - Chip::GetInstance()->getScrollX( ) + 45 ;
			bt = Sprite::GetInstance()->getBmpYPos( g ) + Chip::GetInstance()->getScrollY( ) ;
			bb = Sprite::GetInstance()->getBmpYPos( g ) + 45 + Chip::GetInstance()->getScrollY( ) ;

			brad = br - bl ;					// 丸鋸の半径を求める
			x = br - (br - bl) - (px - 32) ;	// 丸鋸の中心点からプレイヤーまでの X軸 の距離
			y = bb - (bb - bt) - (py - 96) ;	// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
			c2 = x * x + y * y ;				// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
			c = sqrt( c2 ) ;					// 二乗の値なので通常の値に戻す

			// 半径よりもプレイヤーまでの距離が短い場合
			if ( brad >= c )
			{
				// 衝突
				Gimmick::GetInstance()->deleteBullet( (g - 500) ) ;

				if ( barrierFlg_ )
				{

				} else {
					Pmode_ = P_dainit ;
				}

			}

		}
	}

	return( collisionX ) ;

}

/*/
/*	 更新
/*/
void Player::Update( )
{
	//printf( "Player : Action = %d\n" , Pmode_ ) ;

	
	if ( KeyManager::GetInstance()->getKeyState( VK_F7 ) )
	{
		Player_ypos_ = 0.0f ;
		Player_mag_.y = 0.0f ;
		Player_spd_.y = 0.0f ;
	}


	/*/
	/*	___/ プレイヤー 描画 /___________________
	/*/
	PlayerAction( ) ;

	// プレイヤー位置調整
	Player_spd_.y += Player_mag_.y ;
	Player_ypos_ += Player_spd_.y ;
	if ( -128 < Player_ypos_ )
	{
		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// 配列座標を求める x
		arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// 配列座標を求める y

	} else {
		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// 配列座標を求める x
		arrayY_ = 0 ;										// 配列座標を求める y
	}

	// 速度調整
	float camera_y = 0.0f ;
	if ( KeyManager::GetInstance()->getKeyState( VK_UP ) )
	{
//		camera_y++ ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_DOWN ) )
	{
//		camera_y-- ;

		/*/
		/*	縦に動いた時のギミックの
		/*	あたり判定が終わっていない
		/*/
	}
	Player_spd_.x = Player_mag_.x ;
	Chip::GetInstance()->setScrollSize( ( int )-Player_mag_.x , (int)-camera_y ) ;
	Player_mag_.x *= DECELERATION_RATE ;			// 減速率

	// カメラの位置調整
	if ( lrflg_ )
	{
		// 右向き
		scrollflg[ 1 ] = true ;
		if ( scrollflg[ 0 ] )
		{
			if ( scrollx > 0 )
			{
				scrollx = 0 ;
			}

			scrollx-- ;
			Chip::GetInstance()->setScrollSize( scrollx , 0 ) ;
			Player_xpos_ += scrollx ;
			if ( Player_xpos_ <= 200 )
			{
				Player_xpos_ = 200 ;
				scrollflg[ 0 ] = false ;
			}
		} else {
			scrollx = 0 ;
		}

	} else {
		//左向き
		scrollflg[ 0 ] = true ;
		if ( scrollflg[ 1 ] )
		{
			if ( scrollx < 0 )
			{
				scrollx = 0 ;
			}

			scrollx++ ;
			if ( Chip::GetInstance()->getScrollX() > (-600 - RenderScale) )
			{
				scrollflg[ 0 ] = false ;
			}
			Chip::GetInstance()->setScrollSize( scrollx , 0 ) ;
			Player_xpos_ += scrollx ;
			if ( Player_xpos_ >= 600 )
			{
				Player_xpos_ = 600 ;
				scrollflg[ 1 ] = false ;
			}

		} else {
			scrollx = 0 ;
		}

		if ( Chip::GetInstance()->getScrollX() >= RenderScale )
		{
			Player_mag_.x = 0 ;
		}

	}


	// 傾き調整
	nowPos[ 0 ] = Player_xpos_ ;
	nowPos[ 1 ] = Player_ypos_ ;
	Player_vec_.deg = Player_.slopeDeg( oldPos , nowPos ) ;
	if ( Player_vec_.deg == 90 )
	{
		Player_vec_.deg -= 90 ;
	}
	if ( Player_vec_.deg >= 360 )
	{
		Player_vec_.deg = 0 ;
	}
	oldPos[ 0 ] = nowPos[ 0 ] ;
	oldPos[ 1 ] = nowPos[ 1 ] ;
	if ( flipMag_ )
	{
		Player_vec_.deg = 180 ;
	}

	// ゲームオーバー判定
	if ( Player_ypos_ >= 1000 )
	{
		Pmode_ = P_deth ;
	}

	// プレイヤー描画	アニメーション
	PlayerAnim_.playAnim( ) ;
	AnimationData *nowAnim = PlayerAnim_.getNowAnim( ) ;
	Sprite::GetInstance()->setBmpData(
			nowAnim->bmpNo + (lrflg_ * 11) ,
			7 ,
			Player_xpos_ + 4 ,							// 中心位置を調整
			Player_ypos_ - 54 + (flipMag_ * 72) ,		// 中心位置を調整
			(float)nowAnim->cutRect.left ,
			(float)nowAnim->cutRect.top ,
			(float)nowAnim->cutRect.right ,
			(float)nowAnim->cutRect.bottom ,
			0.5f , 0.5f ,
			255 ,
			flipMag_ * 180//Player_vec_.deg
		) ;

	// バリアの展開するかどうか
	barrierFlg_ = false ;
	if ( (Player_spd_.x >= 8.0f) || ((Player_spd_.x <= -8.0f)) )
	{
		barrierFlg_ = true ;
		ballAnim_.playAnim( );
		AnimationData *nowball = ballAnim_.getNowAnim( ) ;
		Sprite::GetInstance()->setBmpData(
				nowball->bmpNo ,
				7 ,
				Player_xpos_ + 4 ,							// 中心位置を調整
				Player_ypos_ - 54 + (flipMag_ * 72) ,		// 中心位置を調整
				(float)nowball->cutRect.left ,
				(float)nowball->cutRect.top ,
				(float)nowball->cutRect.right ,
				(float)nowball->cutRect.bottom ,
				0.5f , 0.5f ,
				255 ,
				0
			) ;
	}

	// デバッグ用
	//printf( "Player : left   = %d \n" , nowAnim->cutRect.left ) ;
	//printf( "Player : top    = %d \n" , nowAnim->cutRect.top ) ;
	//printf( "Player : right  = %d \n" , nowAnim->cutRect.right ) ;
	//printf( "Player : bottom = %d \n" , nowAnim->cutRect.bottom ) ;
	//printf( "Player : Xpos   = %8.4f \n" , Player_xpos_ ) ;
	//printf( "Player : Ypos   = %8.4f \n" , Player_ypos_ ) ;
	//printf( "Player : Xspd   = %8.4f \n" , Player_spd_.x ) ;
	//printf( "Player : Yspd   = %8.4f \n" , Player_spd_.y ) ;
	//printf( "Player : Xmag   = %8.4f \n" , Player_mag_.x ) ;
	//printf( "Player : Ymag   = %8.4f \n" , Player_mag_.y ) ;
	//printf( "Player : mag    = %8.4f \n" , Player_vec_.mag ) ;
	//printf( "Player : deg    = %8.4f \n" , Player_vec_.deg ) ;

	// クリア
//	Player_spd_.x = 0.0f ;
	Player_spd_.y = 0.0f ;

}



