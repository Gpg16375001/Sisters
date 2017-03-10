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
	Pmode_		 = P_init ;
	Player_xpos_ = 200.0f ;
	Player_ypos_ = 200.0f ;
	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;
	Player_jspd_ = 0.0f ;
	arrayX_		 = 0 ;
	arrayY_		 = 0 ;
	lrflg_		 = true ;

	Player_.Finalize( ) ;
	Player_.Initialize( ) ;

	Chip::GetInstance()->Finalize( ) ;

	Player_.setMass( 0.08f ) ;

}

/*/
/*	 終了化
/*/
void Player::Finalize( )
{
	Player_.Finalize( ) ;

	Player_xpos_ = 0.0f ;
	Player_ypos_ = 0.0f ;
	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;
	Player_jspd_ = 0.0f ;
	arrayX_ = 0 ;
	arrayY_ = 0 ;
	lrflg_ = false ;
	Pmode_ = P_init ;

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
	if ( fcheck != 0 )
	{
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

	} else {
		Pmode_ = P_drop ;
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
			Player_jspd_ = 0.0f ;
			Player_yspd_ = 0.0f ;
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
	float px = 0.0f , py = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	g_bx1 = g_bx2 = g_bx3 = g_bx4 = g_bx5 = g_bx6 = g_bx7 = g_bx8 = g_bx9 = 0 ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// 次のフレームの自分の座標位置
/*	printf( "chipTable = %d \n" ,										// 自分の座標位置の番号
			chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ]
		) ;
*/

	px = Player_xpos_ - Chip::GetInstance()->getScrollX() ;
	py = Player_ypos_ - Chip::GetInstance()->getScrollY() ;

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
				case 2 :
				case 5 :
				case 6 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bt ;

							printf( "chipTable = %d _ x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// 自分の座標位置の番号
							printf( "footY = %8.4f \n" , footY ) ;		// blockの座標位置

						}
					}
					break ;

				case 7 :
					if ( (bt <= py) && (py <= bb) )
					{
						if ( (bl <= px) && (px <= br) )
						{
						}
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



