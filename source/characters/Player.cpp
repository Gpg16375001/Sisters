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
#include "Physics.h"

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
	, arrayX_( 0 )
	, arrayY_( 0 )
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
	Physics::GetInstance()->Initialize( ) ;

}

/*/
/*	プレイヤーのアクション
/*/
void Player::PlayerAction( )
{

	printf( "Player : Xpos = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd = %8.4f \n" , Player_yspd_ ) ;

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
/*	初期
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
/*	止まり時
/*/
void Player::Pstop( )
{
	Player_yspd_ = 0.0f ;

	if ( FootCheck() )
	{

	} else {
		Pmode_ = P_jinit ;
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		Pmode_ = P_walk ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		Pmode_ = P_walk ;
	}

	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ ,
			Player_ypos_ ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

}

/*/
/*	左右歩き
/*/
void Player::Pwalk( )
{

	if ( FootCheck() )
	{

	} else {
		Pmode_ = P_jinit ;
	}

	// 左右チェック
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Collision() )
		{
			Player_xspd_ = -0.0f ;
			if ( Chip::GetInstance()->getScrollX() < 32 )
			{
				Player_xpos_ += 2 ;
				Chip::GetInstance()->setScrollSize( 2 , 0 ) ;
			}
		}
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
	{
		if ( Collision() )
		{
			Player_xspd_ = 0.0f ;
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_xpos_ += -2 ;
				Chip::GetInstance()->setScrollSize( -2 , 0 ) ;
			}
		}
	}

	Player_xpos_ += Player_xspd_ ;
	Player_ypos_ += Player_yspd_ ;
	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ ,
			Player_ypos_ ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;
	Pmode_ = P_stop ;		

}

/*/
/*	ジャンプ初期化
/*/
void Player::Pjinit( )
{

	Pmode_ = P_jump ;
}

/*/
/*	ジャンプと落下
/*/
void Player::Pjump( )
{
	Player_yspd_ = 0.0f ;
	/*/
	/*	___/ プレイヤー /___________________
	/*/
	Player_yspd_ += Physics::GetInstance()->getGravity( ) ;
	Player_xpos_ += Player_xspd_ ;
	Player_ypos_ += Player_yspd_ ;
	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ ,
			Player_ypos_ ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	if ( FootCheck() )
	{
		Pmode_ = P_stop ;
	}

}

/*/
/*	足元チェック
/*/
bool Player::FootCheck( )
{
	bool iRet = false ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	arrayX_ = ( int )( Player_xpos_ / CHIP_W + 1 ) ;	// 配列座標を求める x
	arrayY_ = ( int )( Player_ypos_ / CHIP_H + 1 ) ;	// 配列座標を求める y

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;			// 自分の座標位置
	printf( "chipTable = %d \n" ,												// 自分の座標位置の番号
			chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ]
		) ;

	// プレイヤーの足元の配列座標
	if ( chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] != NULL )
	{
		iRet = true ;
		printf( "foot check was true! \n" ) ;
	}

	return( iRet ) ;
}

/*/
/*	あたり判定
/*/
bool Player::Collision( )
{
	bool iRet = false ;

	// あたり判定をとるためのチップデータ
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	arrayX_ = ( int )( Player_xpos_ / CHIP_W + 1 ) ;	// 配列座標を求める x
	arrayY_ = ( int )( Player_ypos_ / CHIP_H + 1 ) ;	// 配列座標を求める y

	// プレイヤーの配列座標
	if (	(chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ - 1) ] != 1)
		||	(chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ - 1) ] != 2) )
	{
		iRet = true ;
		printf( "fCollision check was true! \n" ) ;
	} else if ( (chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 1) ] != 1)
			||	(chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 1) ] != 2) )
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
	PlayerAction( ) ;
}



