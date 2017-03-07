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
	, Player_jspd_( 0.0f )
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( true )
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
	Player_.Initialize( ) ;

	Player_.setMass( 0.08f ) ;

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
/*	-1 : ����
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
/*	0 : �~�܂莞
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
/*	1 : ���E����
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

	// ���E�`�F�b�N
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
/*	2 : �W�����v������
/*/
void Player::Pjinit( )
{
	Player_jspd_ = -18 ;
	Pmode_ = P_jump ;
}

/*/
/*	3 : �W�����v
/*	4 : ����
/*/
void Player::Pjump( )
{
	Player_yspd_ += Player_jspd_ ;
	Player_jspd_ += Player_.Weight2D().y ;

	if ( Pmode_ == P_jump )
	{
		// ���E�`�F�b�N
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
		// ���E�`�F�b�N
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
/*	�����`�F�b�N
/*	�����̍��W��Ԃ�
/*/
float Player::FootCheck( )
{
	float footY = 0.0f ;

	g_bx1 = g_bx2 = g_bx3 = g_bx4 = g_bx5 = g_bx6 = g_bx7 = g_bx8 = g_bx9 = 0 ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// ���̃t���[���̎����̍��W�ʒu
	printf( "chipTable = %d \n" ,										// �����̍��W�ʒu�̔ԍ�
			chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ]
		) ;

	// �v���C���[�̑����̔z����W
	if ( (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 0) ] != 0) )
	{
		// �ʏ�̓y
		if ( (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 1)
			|| (chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 5) )
		{
			// �� ���ʏ�u���b�N��������
			if ( chipTable[ (CHIP_X * (arrayY_ + 1)) - (Chip::GetInstance()->getScrollX() / CHIP_W) + arrayX_ ] == 1 )
			{
				g_bx1 = ( arrayX_ * CHIP_W + 0 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by1 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				g_bx2 = ( arrayX_ * CHIP_W + 32 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by2 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				g_bx3 = ( arrayX_ * CHIP_W + 64 ) + Chip::GetInstance()->getScrollX() - ( (Chip::GetInstance()->getScrollX() - 32) / CHIP_W * CHIP_W ) ;			
				g_by3 = ( (arrayY_ + 1) * CHIP_H - 128) + Chip::GetInstance()->getScrollY() ;

				printf( "bX = %d  bY = %d \n" , g_bx1 , g_by1 ) ;	// block�̍��W�ʒu
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
			printf( "footY = %8.4f \n" , footY ) ;	// block�̍��W�ʒu
		}


		// �v���C���[�� �� �̔z����W
		if ( (chipTable[ (CHIP_X * arrayY_ + 1) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 0) ] != 0) )
		{
			POINT sropeTable[64] ;
			for ( int i = 0 ; i < 64 ; ++i )
			{
				sropeTable[ i ].x = i ;
				sropeTable[ i ].y = i ;
			}

			// �v���C���[�� �� �̔z����W
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
//				printf( "bX = %d \n" , stno ) ;	// block�̍��W�ʒu
			}

		}

		Player_yspd_ = 0 ;

	}

	return( footY ) ;
}

/*/
/*	�����蔻��
/*/
float Player::Collision( )
{
	bool iRet = false ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	// �v���C���[�̔z����W
	if ( chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ - 1) ] == 0 )
	{
		iRet = true ;
		printf( "fCollision check was true! \n" ) ;
	}

	// �v���C���[�̔z����W
	if ( chipTable[ (CHIP_X * arrayY_) - (Chip::GetInstance()->getScrollX() / CHIP_W) + (arrayX_ + 1) ] == 0 )
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

	/*/
	/*	___/ �v���C���[ /___________________
	/*/
	PlayerAction( ) ;

	Player_xpos_ += Player_xspd_ ;
	Player_ypos_ += Player_yspd_ ;
	if ( Player_ypos_ <= -100 )
	{
		Player_ypos_ = 0 ;
	}
	arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// �z����W�����߂� x
	arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// �z����W�����߂� y

	Sprite::GetInstance()->setBmpData(
			PLAYER ,
			7 ,
			Player_xpos_ + 4 ,		// ���S�ʒu�𒲐�
			Player_ypos_ - 54 ,		// ���S�ʒu�𒲐�
			0 , 0 ,
			200 , 178 ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	// �N���A
	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;

	// �f�o�b�O�p
	printf( "Player : Xpos = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd = %8.4f \n" , Player_yspd_ ) ;
	g_px = Player_xpos_ ;
	g_py = Player_ypos_ - 54 - 8 ;

}



