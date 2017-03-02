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

/*/
/*	コンストラクタ
/*/
Player::Player( )
	: Pmode_( P_init )
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
			0 ,
			0 ,
			200 , 200 ,
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
	/*/
	/*	___/ プレイヤー /___________________
	/*/
	static float pYPos = 0.0f ;
	pYPos += Physics::GetInstance()->getGravity( ) ;
	Sprite::GetInstance()->setBmpData(
			0 ,
			0 ,
			Sprite::GetInstance()->getBmpXPos( 0 ) ,
			pYPos ,
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;
	printf( "Y Position = %d\n" , Sprite::GetInstance()->getBmpYPos( 0 ) ) ;

	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		Chip::GetInstance()->setScrollSize( 2 , 0 ) ;

	if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		Chip::GetInstance()->setScrollSize( -2 , 0 ) ;

}

/*/
/*	左右歩き
/*/
void Player::Pwalk( )
{

}

/*/
/*	ジャンプ初期化
/*/
void Player::Pjinit( )
{

}

/*/
/*	ジャンプと落下
/*/
void Player::Pjump( )
{

}

/*/
/*	 更新
/*/
void Player::Update( )
{
	PlayerAction( ) ;
}



