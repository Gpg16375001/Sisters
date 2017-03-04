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

#define	PLAYER	0

/*/
/*	�R���X�g���N�^
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

	printf( "Player : Xpos = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd = %8.4f \n" , Player_yspd_ ) ;

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
/*	�~�܂莞
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
/*	���E����
/*/
void Player::Pwalk( )
{

	if ( FootCheck() )
	{

	} else {
		Pmode_ = P_jinit ;
	}

	// ���E�`�F�b�N
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
/*	�W�����v������
/*/
void Player::Pjinit( )
{

	Pmode_ = P_jump ;
}

/*/
/*	�W�����v�Ɨ���
/*/
void Player::Pjump( )
{
	Player_yspd_ = 0.0f ;
	/*/
	/*	___/ �v���C���[ /___________________
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
/*	�����`�F�b�N
/*/
bool Player::FootCheck( )
{
	bool iRet = false ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	arrayX_ = ( int )( Player_xpos_ / CHIP_W + 1 ) ;	// �z����W�����߂� x
	arrayY_ = ( int )( Player_ypos_ / CHIP_H + 1 ) ;	// �z����W�����߂� y

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;			// �����̍��W�ʒu
	printf( "chipTable = %d \n" ,												// �����̍��W�ʒu�̔ԍ�
			chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ]
		) ;

	// �v���C���[�̑����̔z����W
	if ( chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] != NULL )
	{
		iRet = true ;
		printf( "foot check was true! \n" ) ;
	}

	return( iRet ) ;
}

/*/
/*	�����蔻��
/*/
bool Player::Collision( )
{
	bool iRet = false ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	arrayX_ = ( int )( Player_xpos_ / CHIP_W + 1 ) ;	// �z����W�����߂� x
	arrayY_ = ( int )( Player_ypos_ / CHIP_H + 1 ) ;	// �z����W�����߂� y

	// �v���C���[�̔z����W
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
/*	 �X�V
/*/
void Player::Update( )
{
	printf( "Player : Action = %d\n" , Pmode_ ) ;
	PlayerAction( ) ;
}



