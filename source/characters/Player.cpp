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

#define	PLAYER	0

/*/
/*	コンストラクタ
/*/
Player::Player( )
	: Pmode_( P_init )
	, Player_xpos_( 200.0f )
	, Player_ypos_( 200.0f )
	, Player_xspd_( 0.0f )
	, Player_yspd_( 0.0f )
	, Player_jspd_( 0.0f )
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( true )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	デストラクタ
/*/
Player::~Player( )
{
	Initialize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 初期化
/*/
void Player::Initialize( )
{
	printf( "Player -> " ) ;
	Player_.Initialize( ) ;

	Player_.setMass( 0.08f ) ;

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
	/*	___/ キャラクター /___________________
	/*/
	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ , Player_ypos_ ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	Pmode_ = P_stop ;

}

/*/
/*	0 : 止まり時
/*/
void Player::Pstop( )
{
	float fcheck = FootCheck() ;
	if ( fcheck == 0 )
	{
		Pmode_ = P_drop ;
	} else {

		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			Pmode_ = P_walk ;
		}
		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			Pmode_ = P_walk ;
		}
		if ( KeyManager::GetInstance()->getKeyState( VK_SPACE ) )
		{
			Pmode_ = P_jinit ;
		}
	}

}

/*/
/*	1 : 左右歩き
/*/
void Player::Pwalk( )
{
	float fcheck = FootCheck() ;
	if ( fcheck != 0 )
	{
		Player_ypos_ = fcheck ;
	} else {
		Pmode_ = P_drop ;
	}

	// 左右チェック
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Collision() )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_xspd_ = -8.0f ;
				Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
				Player_xspd_ = 0.0f ;
			}
		}
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		if ( Collision() )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_xspd_ = 8.0f ;
				Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
				Player_xspd_ = 0.0f ;
			}
		}
	}

	Pmode_ = P_stop ;		

}

/*/
/*	2 : ジャンプ初期化
/*/
void Player::Pjinit( )
{
	Player_jspd_ = -18 ;
	Pmode_ = P_jump ;
}

/*/
/*	3 : ジャンプ
/*	4 : 落下
/*/
void Player::Pjump( )
{
	Player_yspd_ += Player_jspd_ ;
	Player_jspd_ += Player_.Weight2D().y ;

	if ( Pmode_ == P_jump )
	{
		// 左右チェック
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = -4.0f ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
					Player_xspd_ = 0.0f ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = 4.0f ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
					Player_xspd_ = 0.0f ;
				}
			}
		}

		if ( Player_yspd_ >= 0 )
		{
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
					Player_xspd_ = -4.0f ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
					Player_xspd_ = 0.0f ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = 4.0f ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
					Player_xspd_ = 0.0f ;
				}
			}
		}

		float fcheck = FootCheck() ;
		if ( fcheck != 0 )
		{
			Player_jspd_ = 0 ;
			Player_ypos_ = fcheck ;
			Pmode_ = P_stop ;
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

	g_bx1 = g_bx2 = g_bx3 = g_bx4 = g_bx5 = g_bx6 = g_bx7 = g_bx8 = g_bx9 = 0 ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// 次のフレームの自分の座標位置
	printf( "chipTable = %d \n" ,										// 自分の座標位置の番号
			chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ]
		) ;

	// プレイヤーの足元の配列座標
	if ( (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 0) ] != 0) )
	{
		// 通常の土
		if ( (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 1)
			|| (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 5) )
		{
			// ↓ が通常ブロックだったら
			if ( chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 1 )
			{
				g_bx1 = ( arrayX_ * CHIP_W + 0 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by1 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				g_bx2 = ( arrayX_ * CHIP_W + 32 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by2 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				g_bx3 = ( arrayX_ * CHIP_W + 64 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by3 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				printf( "bX = %d  bY = %d \n" , g_bx1 , g_by1 ) ;	// blockの座標位置
			}

			float blockL[ ] = {
				( float )( (arrayX_ * CHIP_W + 0) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ) ,
				( float )( (arrayY_ * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ) ,
			} ;
			float blockR[ ] = {
				( float )( (arrayX_ * CHIP_W + 64) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ) ,
				( float )( (arrayY_ * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ) ,
			} ;
			
			float py ;
			py = Player_.slopePoint( blockL , blockR ) ;
			py = blockL[ 1 ] - py * (Player_xpos_ - blockL[ 0 ]) ;
			footY = py + 128 ;
			printf( "footY = %8.4f \n" , footY ) ;	// blockの座標位置
		}


		// プレイヤーの ↓ の配列座標
		if ( (chipTable[ (CHIP_X * arrayY_ + 1) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 0) ] != 0) )
		{
			POINT sropeTable[64] ;
			for ( int i = 0 ; i < 64 ; ++i )
			{
				sropeTable[ i ].x = i ;
				sropeTable[ i ].y = i ;
			}

			// プレイヤーの ↓ の配列座標
			if ( (chipTable[ (CHIP_X * arrayY_ - 0) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 0) ] == 7) )
			{
				g_bx1 = (arrayX_ * CHIP_W + 0) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ;			
				g_by1 = ((arrayY_) * CHIP_H - 64 - 0) + Chip::GetInstance()->getScrollY() ;
						 
				g_bx2 = (arrayX_ * CHIP_W + 32) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ;			
				g_by2 = ((arrayY_) * CHIP_H - 64 - 32) + Chip::GetInstance()->getScrollY() ;
						 
				g_bx3 = (arrayX_ * CHIP_W + 64) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ;			
				g_by3 = ((arrayY_) * CHIP_H - 64 - 64) + Chip::GetInstance()->getScrollY() ;

				float blockL[ ] = {
					( float )( (arrayX_ * CHIP_W + 0) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ) ,
					( float )( (arrayY_ * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ) ,
				} ;
				float blockR[ ] = {
					( float )( (arrayX_ * CHIP_W + 64) + Chip::GetInstance()->getScrollX() - ((Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W) ) ,
					( float )( (arrayY_ * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ) ,
				} ;

				float py ;
				py = Player_.slopePoint( blockL , blockR ) ;
				py = blockL[ 1 ] - py * (Player_xpos_ - blockL[ 0 ]) ;
				if ( (blockL[ 1 ] + 64) > py )
				{
					footY = py + 64 ;
				}
//				printf( "bX = %d \n" , stno ) ;	// blockの座標位置
			}

		}

		Player_yspd_ = 0 ;

	}

	return( footY ) ;
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
	/*	___/ プレイヤー /___________________
	/*/
	PlayerAction( ) ;

	Player_xpos_ += Player_xspd_ ;
	Player_ypos_ += Player_yspd_ ;
	if ( Player_ypos_ <= -100 )
	{
		Player_ypos_ = 0 ;
	}
	arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// 配列座標を求める x
	arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// 配列座標を求める y

	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ + 4 ,		// 中心位置を調整
			Player_ypos_ - 54 ,		// 中心位置を調整
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	// クリア
	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;

	// デバッグ用
	printf( "Player : Xpos = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd = %8.4f \n" , Player_yspd_ ) ;
	g_px = Player_xpos_ ;
	g_py = Player_ypos_ - 54 - 8 ;

}



