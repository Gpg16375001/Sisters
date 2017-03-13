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
	, Player_xspd_( 0.0f )				// X方向のスピード
	, Player_yspd_( 0.0f )				// Y方向のスピード
	, Player_jspd_( 0.0f )				// ジャンプの初速
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( false )					// false : 左	true : 右
	, Player_acceration_( 0.0f )			// プレイヤーの加速度
	, Player_mag_( 0.0f )				// プレイヤーの移動量
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
	Player_ypos_		= 200.0f ;		// 描画する Y ポジション
	Player_xspd_		= 0.0f ;		// X方向のスピード
	Player_yspd_		= 0.0f ;		// Y方向のスピード
	Player_jspd_		= 0.0f ;		// ジャンプの初速
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= true ;		// false : 左	true : 右
	Player_acceration_	= 0.098f ;		// プレイヤーの加速度
	Player_mag_			= 0.0f ;

	Player_.Finalize( ) ;
	Player_.Initialize( ) ;

	Chip::GetInstance()->Finalize( ) ;

	Player_.setMass( 4.5f ) ;

	/*/
	/*	アニメーションセット
	/*	RECT ( left , top , right , bottom )
	/*/
	AnimationData P_stop[ ] = {
		{ 0 , 8 , {200 * 0 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 1 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 2 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 3 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_walk[ ] = {
		{ 0 , 8 , {200 * 4 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 5 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 6 , 0 , 200 , 178} , ANIM_MODE_NEXT } ,
		{ 0 , 8 , {200 * 7 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_jump[ ] = {
		{ 0 , 4 , {200 * 8 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;
	AnimationData P_drop[ ] = {
		{ 0 , 4 , {200 * 9 , 0 , 200 , 178} , ANIM_MODE_LOOP } ,
	} ;

	memcpy( &Panim_stop_ , P_stop , 4 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_walk_ , P_walk , 4 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_jump_ , P_jump , 1 * sizeof( AnimationData ) ) ;
	memcpy( &Panim_drop_ , P_drop , 1 * sizeof( AnimationData ) ) ;

}

/*/
/*	 終了化
/*/
void Player::Finalize( )
{
	Player_.Finalize( ) ;

	Player_xpos_		= 0.0f ;
	Player_ypos_		= 0.0f ;
	Player_xspd_		= 0.0f ;
	Player_yspd_		= 0.0f ;
	Player_jspd_		= 0.0f ;
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= false ;
	Pmode_				= P_init ;
	Player_acceration_	= 0.0f ;
	Player_mag_			= 0.0f ;

	// アニメーション
	memset( &Panim_stop_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_walk_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_jump_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_drop_ , 0 , 1 * sizeof( AnimationData ) ) ;

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

	PlayerAnim_.setAnimData( Panim_stop_ ) ;

	Pmode_ = P_sinit ;

}

/*/
/*	0 : 止まり時 初期セット
/*/
void Player::Psinit( )
{
	PlayerAnim_.setAnimData( Panim_stop_ ) ;

	Pmode_ = P_stop ;

}

/*/
/*	1 : 止まり時
/*/
void Player::Pstop( )
{
	Player_mag_ *= 0.98f ;
	PlayerAnim_.setAnimData( Panim_stop_ ) ;
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
		Pmode_ = P_drop ;
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
		if ( Collision() )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_mag_ += -Player_acceration_ ;
				// もし右に動いていたら
				if ( Player_xspd_ > 0 )
				{
					Player_mag_ *= 0.98f ;
				}
				// 左右チェック
				lrflg_ = false ;
				Pmode_ = P_walk ;
			}
		}
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		if ( Collision() )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_mag_ += Player_acceration_ ;
				// もし左に動いていたら
				if ( Player_xspd_ < 0 )
				{
					Player_mag_ *= 0.98f ;
				}
				// 左右チェック
				lrflg_ = true ;
				Pmode_ = P_walk ;		
			}
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
		PlayerAnim_.setAnimData( Panim_drop_ ) ;
		Pmode_ = P_drop ;
	}

}

/*/
/*	3 : ジャンプ初期化
/*/
void Player::Pjinit( )
{
	Player_jspd_ = -18 ;
	PlayerAnim_.setAnimData( Panim_jump_ ) ;
	Pmode_ = P_jump ;

}

/*/
/*	4 : ジャンプ
/*	5 : 落下
/*/
void Player::Pjump( )
{
	Player_yspd_ += Player_jspd_ ;
	Player_jspd_ += Player_.Weight2D().y / 60 ;

	if ( Pmode_ == P_jump )
	{
		// 左右チェック
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					// 左右チェック
					lrflg_ = false ;

					Player_mag_ += -Player_acceration_ ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					// 左右チェック
					lrflg_ = true ;
					Player_mag_ += Player_acceration_ ;
				}
			}
		}

		float hcheck = HeadCheck() ;
		if ( hcheck != 0 )
		{
			Player_jspd_ = 0.0f ;
			Player_yspd_ = 0.0f ;
			Player_ypos_ = hcheck ;
		}

		if ( Player_yspd_ >= 0 )
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
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_mag_ += -Player_acceration_ ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_mag_ += Player_acceration_ ;
				}
			}
		}

		float fcheck = FootCheck() ;
		if ( fcheck != 0 )
		{
			Player_jspd_ = 0.0f ;
			Player_yspd_ = 0.0f ;
			Player_ypos_ = fcheck ;
			Pmode_ = P_sinit ;
		}
	}

}

/*/
/*	足元チェック
/*	足元の座標を返す
/*/
float Player::FootCheck( )
{
	float footY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// 次のフレームの自分の座標位置

	/*/
	/*	player 判定位置の調整
	/*/
	if ( lrflg_ )
	{
		//  true : 右向き
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() ;
	}
	else
	{
		//  false : 左向き
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() ;
	}
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// ジャンプ中
	if ( Player_yspd_ < 0.0f )
	{
		return( 0 ) ;
	}

	// 判定をとる範囲　今は全体
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// 何か情報が入っているとき
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) ;

			switch ( chipTable[ i ] )
			{

				// 通常ブロックの場合
				case 1 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							footY = bt ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 5 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl+12 <= px) && (px <= br) )
						{
							footY = bt - 8 ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 7 :
					float radY ;			// 坂の右下からの高さ( Y軸 )
					Vector2D_compo P1 , P3 ;
					Vector2D_compo P2 ;		// 基準点 (br,bb)
					Vector2D_compo P4 ;		// プレイヤーの座標
					float s1 , s2 ;			// 面積
					float cross[ 2 ] ;		// 交点
					float ax , ay ;
					float P2a ;				// 交点までの距離
					float P2p ;				// プレイヤーまでの距離

					// それぞれに代入
					P1.x = bl - 4 ;
					P1.y = bb ;
					P2.x = br - 4 ;
					P2.y = bb ;
					P3.x = br - 4 ;
					P3.y = bt ;
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

					if ( (P2p <= P2a) && (bl - 8 <= px) && (px <= br) && (bt-14 <= py) )
					{
						footY = cross[ 1 ] ;

						if ( Player_.checkMotion( 45.0f , Player_.Weight2D().y , 0.55f ) )
						{
							Player_mag_ -= Player_.calcAccel( 45.0f , Player_.Weight2D().y / 60 , 0.36f , Player_.getMass() ) ;
							printf( "Motion was true. \n" ) ;
						}
					}
					break  ;

				case 6 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br-12) )
						{
							footY = bt - 8 ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 8 :
					// それぞれに代入
					P1.x = br - 4 ;
					P1.y = bb ;
					P2.x = bl - 4 ;
					P2.y = bb ;
					P3.x = bl - 4 ;
					P3.y = bt ;
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

					if ( (P2p <= P2a) && (bl - 4 <= px) && (px <= br) && (bt-14 <= py) )
					{
						footY = cross[ 1 ] ;
					}
					break ;

				case 50 :
					float brad ;	// 丸鋸の半径
					float x ;
					float y ;
					float c2 ;
					float c ;		// プレイヤーと丸鋸の距離
					float rad ;		// 丸鋸の中心からの高さ( Y軸 )

					brad = br - bl ;			// 丸鋸の半径を求める
					x = br - (br - bl) - px ;	// 丸鋸の中心点からプレイヤーまでの X軸 の距離
					y = bb - (bb - bt) - py ;	// 丸鋸の中心点からプレイヤーまでの Y軸 の距離
					c2 = x * x + y * y ;		// ピタゴラスの定理より斜辺の長さ(プレイヤーまでの距離)を求める
					c = sqrt( c2 ) ;			// 二乗の値なので通常の値に戻す

					// 半径よりもプレイヤーまでの距離が短い場合
					if ( brad >= c )
					{
						rad = sqrt( (c2 - x * x) ) ;	// 当たった位置の高さを求める
						footY = bt + c - rad - 60 ;
						printf( "px  : %f \n" , px ) ;
						printf( "rad : %f \n" , rad ) ;
						printf( "On Hit !! \n" ) ;
					}
					break ;

				default :
					break ;

			}
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
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() - 64 ;
	}
	else
	{
		//  false : 左向き
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() - 64 ;
	}
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// ジャンプ中
	if ( Player_yspd_ > 0.0f )
	{
		return( 0 ) ;
	}

	// 判定をとる範囲　今は全体
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// 何か情報が入っているとき
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) ;

			switch ( chipTable[ i ] )
			{

				// 通常ブロックの場合
				case 1 :
				case 2 :
				case 5 :
				case 6 :
				case 7 :
				case 8 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							headY = bb + 64 ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							printf( "footY = %8.4f \n" , headY ) ;		// blockの座標位置

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
						printf( "px  : %f \n" , px ) ;
						printf( "rad : %f \n" , rad ) ;
						printf( "On Hit !! \n" ) ;
					}
					break ;

				default :
					break ;

			}
		}
	}

	return( headY ) ;
}

/*/
/*	あたり判定
/*/
float Player::Collision( )
{
	bool iRet = false ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	// プレイヤーの配列座標
	if ( chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ - 1) ] == 0 )
	{
		iRet = true ;
		printf( "fCollision check was true! \n" ) ;
	}

	// プレイヤーの配列座標
	if ( chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 1) ] == 0 )
	{
		iRet = true ;
		printf( "fCollision check was true! \n" ) ;
	}
	
	return( iRet ) ;

}

/*/
/*	 更新
/*/
void Player::Update( )
{
	printf( "Player : Action = %d\n" , Pmode_ ) ;

	/*/
	/*	___/ プレイヤー 描画 /___________________
	/*/
	PlayerAction( ) ;

	// プレイヤー位置調整
	if ( (-128 < Player_ypos_) && (Player_ypos_ < 800))
	{
		Player_ypos_ += Player_yspd_ ;
		if ( Player_ypos_ <= -64 )
		{
			Player_ypos_ = 0 ;
		}

		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// 配列座標を求める x
		arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// 配列座標を求める y
	}
	Player_xspd_ = Player_mag_ ;
	Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
	Player_mag_ *= 0.995f ;

	// プレイヤー描画	アニメーション
	PlayerAnim_.playAnim( ) ;
	AnimationData *nowAnim = PlayerAnim_.getNowAnim( ) ;
	Sprite::GetInstance()->setBmpData(
			nowAnim->bmpNo + lrflg_ ,
			7 ,
			Player_xpos_ + 4 ,		// 中心位置を調整
			Player_ypos_ - 54 ,		// 中心位置を調整
			nowAnim->cutRect.left ,
			nowAnim->cutRect.top  ,
			nowAnim->cutRect.right ,
			nowAnim->cutRect.bottom ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	// デバッグ用
	printf( "Player : left   = %d \n" , nowAnim->cutRect.left ) ;
	printf( "Player : top    = %d \n" , nowAnim->cutRect.top ) ;
	printf( "Player : right  = %d \n" , nowAnim->cutRect.right ) ;
	printf( "Player : bottom = %d \n" , nowAnim->cutRect.bottom ) ;
	printf( "Player : Xpos   = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos   = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd   = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd   = %8.4f \n" , Player_yspd_ ) ;
	printf( "Player : mag    = %8.4f \n" , Player_mag_ ) ;

	// クリア
//	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;

}



