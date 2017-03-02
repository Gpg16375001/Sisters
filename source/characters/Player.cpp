/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    Player�N���X

	Player�N���X�̎�����


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "Common.h"
#include "Physics.h"

/*/
/*	�R���X�g���N�^
/*/
Player::Player( )
	: Pmode_( P_init )
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	�f�X�g���N�^
/*/
Player::~Player( )
{
	Initialize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ������
/*/
void Player::Initialize( )
{
	printf( "Player -> " ) ;
	Physics::GetInstance()->Initialize( ) ;

}

/*/
/*	�v���C���[�̃A�N�V����
/*/
void Player::PlayerAction( )
{
	// �e�A�N�V������
	switch( Pmode_ )
	{
		// �����Z�b�g
		case P_init :
			Pinit( ) ;
			break ;

		// �Î~�A�N�V����
		case P_stop :
			Pstop( ) ;
			break ;

		// �����A�N�V����
		case P_walk :
			Pwalk( ) ;
			break ;

		// �W�����v�����Z�b�g
		case P_jinit :
			Pjinit( ) ;
			break ;

		// �W�����v�A�N�V����
		case P_jump :
			Pjump( ) ;
			break ;

		// �����A�N�V����
		case P_drop :
			Pjump( ) ;
			break ;
	}

}

/*/
/*	����
/*/
void Player::Pinit( )
{
	/*/
	/*	___/ �L�����N�^�[ /___________________
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
/*	�~�܂莞
/*/
void Player::Pstop( )
{
	/*/
	/*	___/ �v���C���[ /___________________
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
/*	���E����
/*/
void Player::Pwalk( )
{

}

/*/
/*	�W�����v������
/*/
void Player::Pjinit( )
{

}

/*/
/*	�W�����v�Ɨ���
/*/
void Player::Pjump( )
{

}

/*/
/*	 �X�V
/*/
void Player::Update( )
{
	PlayerAction( ) ;
}



