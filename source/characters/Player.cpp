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

/*/
/*	�R���X�g���N�^
/*/
Player::Player( )
	: Pmode_( P_init )					// �����A�N�V�������[�h
	, Player_xpos_( 0.0f )				// �`�悷�� X �|�W�V����
	, Player_ypos_( 0.0f )				// �`�悷�� Y �|�W�V����
	, Player_xspd_( 0.0f )				// X�����̃X�s�[�h
	, Player_yspd_( 0.0f )				// Y�����̃X�s�[�h
	, Player_jspd_( 0.0f )				// �W�����v�̏���
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( false )					// false : ��	true : �E
	, Player_acceration( 0.0f )			// �v���C���[�̉����x
{
	Initialize( ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	�f�X�g���N�^
/*/
Player::~Player( )
{
	Finalize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ������
/*/
void Player::Initialize( )
{
	Finalize( ) ;
	printf( "Player -> " ) ;

	/*/
	/*	�v���C���[ �����Z�b�g
	/*/
	Pmode_				= P_init ;		// �����A�N�V�������[�h
	Player_xpos_		= 200.0f ;		// �`�悷�� X �|�W�V����
	Player_ypos_		= 200.0f ;		// �`�悷�� Y �|�W�V����
	Player_xspd_		= 0.0f ;		// X�����̃X�s�[�h
	Player_yspd_		= 0.0f ;		// Y�����̃X�s�[�h
	Player_jspd_		= 0.0f ;		// �W�����v�̏���
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= true ;		// false : ��	true : �E
	Player_acceration	= 4.0f ;		// �v���C���[�̉����x

	Player_.Finalize( ) ;
	Player_.Initialize( ) ;

	Chip::GetInstance()->Finalize( ) ;

	Player_.setMass( 0.08f ) ;

	/*/
	/*	�A�j���[�V�����Z�b�g
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
/*	 �I����
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
	Player_acceration = 0.0f ;

	// �A�j���[�V����
	memset( &Panim_stop_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_walk_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_jump_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_drop_ , 0 , 1 * sizeof( AnimationData ) ) ;

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

		// �Î~�A�N�V���� �����Z�b�g
		case P_sinit :
			Psinit( ) ;
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
	/*	___/ �L�����N�^�[ �����Z�b�g /___________________
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
/*	0 : �~�܂莞 �����Z�b�g
/*/
void Player::Psinit( )
{
	PlayerAnim_.setAnimData( Panim_stop_ ) ;

	Pmode_ = P_stop ;

}

/*/
/*	1 : �~�܂莞
/*/
void Player::Pstop( )
{
	PlayerAnim_.setAnimData( Panim_stop_ ) ;
	float fcheck = FootCheck() ;
	if ( fcheck != 0 )
	{
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
/*	2 : ���E����
/*/
void Player::Pwalk( )
{
	Pmode_ = P_sinit ;

	// ���E�`�F�b�N
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Collision() )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 )
			{
				Player_xspd_ = -Player_acceration ;
				Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
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
				Player_xspd_ = Player_acceration ;
				Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
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
/*	3 : �W�����v������
/*/
void Player::Pjinit( )
{
	Player_jspd_ = -18 ;
	PlayerAnim_.setAnimData( Panim_jump_ ) ;
	Pmode_ = P_jump ;

}

/*/
/*	4 : �W�����v
/*	5 : ����
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
					Player_xspd_ = -Player_acceration ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = Player_acceration ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
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
		// ���E�`�F�b�N
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = -Player_acceration ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
				}
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Collision() )
			{
				if ( Chip::GetInstance()->getScrollX() <= 32 )
				{
					Player_xspd_ = Player_acceration ;
					Chip::GetInstance()->setScrollSize( ( int )-Player_xspd_ , 0 ) ;
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
/*	�����`�F�b�N
/*	�����̍��W��Ԃ�
/*/
float Player::FootCheck( )
{
	float footY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// ���̃t���[���̎����̍��W�ʒu

	/*/
	/*	player ����ʒu�̒���
	/*/
	if ( lrflg_ )
	{
		//  true : �E����
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() ;
	}
	else
	{
		//  false : ������
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() ;
	}
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// �W�����v��
	if ( Player_yspd_ < 0.0f )
	{
		return( 0 ) ;
	}

	// ������Ƃ�͈́@���͑S��
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// ������񂪓����Ă���Ƃ�
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) ;

			switch ( chipTable[ i ] )
			{

				// �ʏ�u���b�N�̏ꍇ
				case 1 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							footY = bt ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;

				case 5 :
				case 7 :
					int slopePosU[ 64 ] ;

					for ( int v = 0 ; v < 64 ; ++v )
					{
						slopePosU[ v ] = v + 12 ;
					}
					slopePosU[ 56 ] = 4 ;
					slopePosU[ 60 ] = 4 ;

					if ( bb - slopePosU[ Chip::GetInstance()->getScrollX() % 64 * -1 ] <= Player_ypos_ )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bb - slopePosU[ Chip::GetInstance()->getScrollX() % 64 * -1 ] ;

							printf( "slope[ %d ] : %d\n" , Chip::GetInstance()->getScrollX() % 64 * -1 , slopePosU[ Chip::GetInstance()->getScrollX() % 64 * -1 ] ) ;
							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					} else if ( (Player_xspd_ <= 0) && (bl <= px) && (px <= br) ) {
						slopePosU[ 56 ] = 56 ;
						slopePosU[ 60 ] = 8 ;
						footY = bb - 64 - slopePosU[ Chip::GetInstance()->getScrollX() % 64 * -1 ] ;
					}
					break  ;

				case 6 :
				case 8 :
					int slopePosD[ 64 ] ;

					for ( int v = 0 ; v < 64 ; ++v )
					{
						slopePosD[ v ] = 64 - v ;
					}
					slopePosD[ 56 ] = 4 ;
					slopePosD[ 60 ] = 60 ;

					if ( bb - slopePosD[ Chip::GetInstance()->getScrollX() % 64 * -1 ] <= Player_ypos_ )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = bb - slopePosD[ Chip::GetInstance()->getScrollX() % 64 * -1 ] ;

							printf( "slope[ %d ] : %d\n" , Chip::GetInstance()->getScrollX() % 64 * -1 , slopePosD[ Chip::GetInstance()->getScrollX() % 64 * -1 ] ) ;
							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;

/*
				case 7 :
					float b_top ;
					Vector2D_compo temp_x ;
					Vector2D_compo temp_y ;

					temp_x.x = ( float )-Chip::GetInstance()->getScrollX() ;
					temp_x.y = 0 ;
					temp_y.x = 64 ;
					temp_y.y = 64 ;
					b_top = Player_.slopePoint( temp_x , temp_y ) + Player_ypos_ + 60 ;

					if ( (b_top - Player_ypos_ - 60 <= 0) && ( Player_xspd_ >= 0 ) )
					{
						if ( (bl <= px) && (px <= br) )
						{
							footY = b_top ;

							printf( "slope : %f\n" , Player_.slopePoint( temp_x , temp_y ) ) ;
							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;
*/
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
/*	���̂����蔻��
/*	���̍��W��Ԃ�
/*/
float Player::HeadCheck( )
{
	float headY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	/*/
	/*	player ����ʒu�̒���
	/*/
	if ( lrflg_ )
	{
		//  true : �E����
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() - 64 ;
	}
	else
	{
		//  false : ������
		px = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_xspd_ - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_yspd_ - Chip::GetInstance()->getScrollY() - 64 ;
	}
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// �W�����v��
	if ( Player_yspd_ > 0.0f )
	{
		return( 0 ) ;
	}

	// ������Ƃ�͈́@���͑S��
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// ������񂪓����Ă���Ƃ�
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) ;

			switch ( chipTable[ i ] )
			{

				// �ʏ�u���b�N�̏ꍇ
				case 1 :
				case 5 :
				case 7 :
				case 6 :
				case 8 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							headY = bb + 64 ;

							printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							printf( "footY = %8.4f \n" , headY ) ;		// block�̍��W�ʒu

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
	/*	___/ �v���C���[ �`�� /___________________
	/*/
	PlayerAction( ) ;

	// ���E�`�F�b�N
	if ( Player_xspd_ < 0 )
	{
		lrflg_ = false ;
	}
	else if ( Player_xspd_ > 0 )
	{
		lrflg_ = true ;
	}

	// �v���C���[�ʒu����
	if ( (-128 < Player_ypos_) && (Player_ypos_ < 800))
	{
		Player_ypos_ += Player_yspd_ ;
		if ( Player_ypos_ <= -64 )
		{
			Player_ypos_ = 0 ;
		}

		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// �z����W�����߂� x
		arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// �z����W�����߂� y
	}

	// �v���C���[�`��	�A�j���[�V����
	PlayerAnim_.playAnim( ) ;
	AnimationData *nowAnim = PlayerAnim_.getNowAnim( ) ;
	Sprite::GetInstance()->setBmpData(
			nowAnim->bmpNo + lrflg_ ,
			7 ,
			Player_xpos_ + 4 ,		// ���S�ʒu�𒲐�
			Player_ypos_ - 54 ,		// ���S�ʒu�𒲐�
			nowAnim->cutRect.left ,
			nowAnim->cutRect.top  ,
			nowAnim->cutRect.right ,
			nowAnim->cutRect.bottom ,
			0.5f , 0.5f ,
			255 ,
			0
		) ;

	// �f�o�b�O�p
	printf( "Player : left   = %d \n" , nowAnim->cutRect.left ) ;
	printf( "Player : top    = %d \n" , nowAnim->cutRect.top ) ;
	printf( "Player : right  = %d \n" , nowAnim->cutRect.right ) ;
	printf( "Player : bottom = %d \n" , nowAnim->cutRect.bottom ) ;
	printf( "Player : Xpos   = %8.4f \n" , Player_xpos_ ) ;
	printf( "Player : Ypos   = %8.4f \n" , Player_ypos_ ) ;
	printf( "Player : Xspd   = %8.4f \n" , Player_xspd_ ) ;
	printf( "Player : Yspd   = %8.4f \n" , Player_yspd_ ) ;

	// �N���A
	Player_xspd_ = 0.0f ;
	Player_yspd_ = 0.0f ;

}



