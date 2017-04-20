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
	, arrayX_( 0 )
	, arrayY_( 0 )
	, lrflg_( false )					// false : ��	true : �E
	, Player_acceration_( 0.0f )		// �v���C���[�̉����x
	, scrollx( 0 )
	, flipMag_( false )					// false : �ʏ� true : ���]
	, barrierFlg_( false )				// false : �ʏ�	true : �o���A�W�J��
	, cycleFlg_( false )
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
	Player_ypos_		= 0.0f ;		// �`�悷�� Y �|�W�V����
	arrayX_				= 0 ;
	arrayY_				= 0 ;
	lrflg_				= true ;		// false : ��	true : �E
	Player_acceration_	= 0.098f ;		// �v���C���[�̉����x
	Player_mag_.x		= 0.0f ;		// �v���C���[�̈ړ��� x
	Player_mag_.y		= 0.0f ;		// �v���C���[�̈ړ��� y
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
	flipMag_			= false ;		// false : �ʏ� true : ���]
	barrierFlg_			= false ;		// false : �ʏ�	true : �o���A�W�J��
	cycleFlg_			= true ;		// false : �����̂ڂ�Ȃ�	true : �����̂ڂ��

	Player_hp_			= 3 ;

	Player_.Finalize( ) ;
	Player_.Initialize( ) ;

	Chip::GetInstance()->Finalize( ) ;

	Player_.setMass( 4.5f ) ;

	// �J�n�n�_�̐ݒ�
	Chip::GetInstance()->setScrollSize( -600 + RenderScale , 0 ) ;

	/*/
	/*	�A�j���[�V�����Z�b�g
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
/*	 �I����
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
	Player_mag_.x		= 0.0f ;		// �v���C���[�̈ړ��� x
	Player_mag_.y		= 0.0f ;		// �v���C���[�̈ړ��� y
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
	flipMag_			= false ;		// false : �ʏ� true : ���]
	barrierFlg_			= false ;		// false : �ʏ�	true : �o���A�W�J��
	cycleFlg_			= false ;		// false : �����̂ڂ�Ȃ�	true : �����̂ڂ��

	Player_hp_			= 0 ;

	// �A�j���[�V����
	memset( &Panim_stop_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_walk_ , 0 , 4 * sizeof( AnimationData ) ) ;
	memset( &Panim_jump_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_drop_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_deth_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_damg_ , 0 , 1 * sizeof( AnimationData ) ) ;
	memset( &Panim_ball_ , 0 , 1 * sizeof( AnimationData ) ) ;

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

		// �_���[�W������
		case P_dainit :
			Pdainit( ) ;
			break ;

		// �_���[�W
		case P_damage :
			Pdamage( ) ;
			break ;

		// ���ɏ�����
		case P_deinit :
			Pdeinit( ) ;
			break ;

		// ����
		case P_deth :
			Pdeth( ) ;
			break ;

	}


	if ( g_dethflg )
	{
		
	} else {

		// �R���W�����`�F�b�N
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

	ballAnim_.setAnimData( Panim_ball_ ) ;
	PlayerAnim_.setAnimData( Panim_stop_ ) ;

	Pmode_ = P_sinit ;

}

/*/
/*	0 : �~�܂莞 �����Z�b�g
/*/
void Player::Psinit( )
{
	Pmode_ = P_stop ;

}

/*/
/*	1 : �~�܂莞
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
/*	2 : ���E����
/*/
void Player::Pwalk( )
{
	Pmode_ = P_sinit ;

	// ���E�`�F�b�N
	if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
	{
		if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
		{
			if ( flipMag_ )
			{
				// ���E���]�̏ꍇ
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			} else {
				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			}
			// �����E�ɓ����Ă�����
			if ( Player_mag_.x > 0 )
			{
				Player_mag_.x *= 0.98f ;
				Player_spd_.x *= 0.98f ;
			}
			// ���E�`�F�b�N
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
				// ���E���]�̏ꍇ
				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			} else {
				Player_mag_.x += Player_acceration_ ;
				Player_spd_.x += Player_acceration_ ;
			}
			// �������ɓ����Ă�����
			if ( Player_mag_.x < 0 )
			{
				Player_mag_.x *= 0.98f ;
				Player_spd_.x *= 0.98f ;
			}
			// ���E�`�F�b�N
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
/*	3 : �W�����v������
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
/*	4 : �W�����v
/*	5 : ����
/*/
void Player::Pjump( )
{
	flipMag_ = false ;
	Player_mag_.y += Player_.Weight2D().y / 60 ;

	if ( Pmode_ == P_jump )
	{
		// ���E�`�F�b�N
		if ( KeyManager::GetInstance()->getKeyState( VK_LEFT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				// ���E�`�F�b�N
				lrflg_ = false ;

				Player_mag_.x += -Player_acceration_ ;
				Player_spd_.x += -Player_acceration_ ;
			}
		}

		if ( KeyManager::GetInstance()->getKeyState( VK_RIGHT ) )
		{
			if ( Chip::GetInstance()->getScrollX() <= 32 + RenderScale )
			{
				// ���E�`�F�b�N
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
		// ���E�`�F�b�N
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
/*	6 : �_���[�W �����Z�b�g
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
			//  true : �E����
			Player_mag_.x = -4.0f ;
			Player_spd_.x = -4.0f ;
		}
		else
		{
			//  false : ������
			Player_mag_.x = 4.0f ;
			Player_spd_.x = 4.0f ;
		}
		Player_mag_.y = -16 ;
		PlayerAnim_.setAnimData( Panim_damg_ ) ;
	}

}

/*/
/*	7 : �_���[�W
/*/
void Player::Pdamage( )
{
	Player_mag_.y += Player_.Weight2D().y / 60 ;

	// ���E�`�F�b�N
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
/*	8 : ��	�����Z�b�g
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
/*	9 : ��
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
/*	�����`�F�b�N
/*	�����̍��W��Ԃ�
/*/
float Player::FootCheck( )
{
	if ( Pmode_ == P_deth )
	{
		return 0 ;
	}

	// �W�����v��
	if ( Player_spd_.y < 0.0f )
	{
		return( 0 ) ;
	}

	float footY = 0.0f ;
	float px = 0.0f , py = 0.0f ;
	float pl = 0.0f , pr = 0.0f ;
	float bl = 0.0f , br = 0.0f , bt = 0.0f , bb = 0.0f ;

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	//printf( "arrayX = %d  arrayY = %d \n" , arrayX_ , arrayY_ - 1 ) ;	// ���̃t���[���̎����̍��W�ʒu

	/*/
	/*	player ����ʒu�̒���
	/*/
	if ( lrflg_ )
	{
		//  true : �E����
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y ;
	}
	else
	{
		//  false : ������
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y ;
	}

	// ---+ �f�o�b�O +----------------------------------------------------------------------------------------------- debug
	g_px = px + Chip::GetInstance()->getScrollX() ;
	g_py = py - 54 - 8 ;

	// ������Ƃ�͈́@���͑S��
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// ������񂪓����Ă���Ƃ�
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 ) + Chip::GetInstance()->getScrollY( ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H ) + Chip::GetInstance()->getScrollY( ) ;

			switch ( chipTable[ i ] )
			{
				// �e���|�[�g
				case -1 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							Chip::GetInstance()->setScrollSize( -896 , 0 ) ;
							footY = 1 ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							//printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;

				// �ʏ�u���b�N�̏ꍇ
				case 1 :
				case 9 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							footY = bt ;

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							//printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

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

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							//printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;

				case 7 :
				case 10 :
					Vector2D_compo P1 , P3 ;
					Vector2D_compo P2 ;		// ��_ (br,bb)
					Vector2D_compo P4 ;		// �v���C���[�̍��W
					float s1 , s2 ;			// �ʐ�
					float cross[ 2 ] ;		// ��_
					float ax , ay ;
					float P2a ;				// ��_�܂ł̋���
					float P2p ;				// �v���C���[�܂ł̋���

					// ���ꂼ��ɑ��
					P1.x = bl - 64 ;
					P1.y = bb + 64 ;
					P2.x = br + 64 ;
					P2.y = bb + 64 ;
					P3.x = br + 64 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// ���ꂼ��̖ʐς����߂�
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// �䗦�����_�����߂�
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// ��_�����_�܂ł̋���
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// ��_����v���C���[�܂ł̋���
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

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							//printf( "footY = %8.4f \n" , footY ) ;		// block�̍��W�ʒu

						}
					}
					break ;

				case 8 :
				case 11 :
					// ���ꂼ��ɑ��
					P1.x = br + 64 ;
					P1.y = bb + 64 ;
					P2.x = bl - 64 ;
					P2.y = bb + 64 ;
					P3.x = bl - 64 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// ���ꂼ��̖ʐς����߂�
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// ��_�����߂�
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// ��_�����_�܂ł̋���
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// ��_����v���C���[�܂ł̋���
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
					// ���ꂼ��ɑ��
					P1.x = bl - 64 ;
					P1.y = bb + 32 ;
					P2.x = br + 192 + 4 ;
					P2.y = bb + 32 ;
					P3.x = br + 192 + 4 ;
					P3.y = bt - 64 ;
					P4.x = px ;
					P4.y = py ;

					// ���ꂼ��̖ʐς����߂�
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// �䗦�����_�����߂�
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// ��_�����_�܂ł̋���
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// ��_����v���C���[�܂ł̋���
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
					// ���ꂼ��ɑ��
					P1.x = bl + 192 + 96 ;
					P1.y = bb + 16 ;
					P2.x = br + 32 ;
					P2.y = bb + 16 ;
					P3.x = br + 32 ;
					P3.y = bt - 16 ;
					P4.x = px ;
					P4.y = py ;

					// ���ꂼ��̖ʐς����߂�
					s1 = ((P4.x - P2.x) * (P1.y - P2.y) - (P4.y - P2.y) * (P1.x - P2.x)) * 0.5f ;
					s2 = ((P4.x - P2.x) * (P2.y - P3.y) - (P4.y - P2.y) * (P2.x - P3.x)) * 0.5f ;

					// �䗦�����_�����߂�
					cross[ 0 ] = P1.x + (P3.x - P1.x) * s1 / (s1 + s2) ;
					cross[ 1 ] = P1.y + (P3.y - P1.y) * s1 / (s1 + s2) ;

					// ��_�����_�܂ł̋���
					ax = P2.x - cross[ 0 ] ;
					ay = P2.y - cross[ 1 ] ;
					P2a = ax * ax + ay * ay ;
					P2a = sqrt( P2a ) ;

					// ��_����v���C���[�܂ł̋���
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

				// �E��
				case 14 :
					float brad ;	// �ۋ��̔��a
					float x ;
					float y ;
					float c2 ;
					float c ;		// �v���C���[�Ɗۋ��̋���
					float rad ;		// �ۋ��̒��S����̍���( Y�� )

					if (cycleFlg_)
					{
					} else {
						break ;
					}

					bl -= 256 + 64 ;
					bt -= 384 + 64 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;	// �ۋ��̔��a�����߂�
					x = br - brad - px ;		// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
					y = bb - brad - py ;		// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
					c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
					c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

					// ���a�����v���C���[�܂ł̋������Z���ꍇ
					if ( (bl+brad < px) && (px < br + 64) && (bt + 256 + 32 < py) )
					{
						if ( brad <= c )
						{
							if ( flipMag_ != true )
							{
								Player_vec_.deg = -90.0f ;

								rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�
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

				// ����
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

					brad = (br - bl) / 2 - 50 ;	// �ۋ��̔��a�����߂�
					x = br - brad - px ;		// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
					y = bb - brad - py ;		// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
					c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
					c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

					// ���a�����v���C���[�܂ł̋������Z���ꍇ
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

							rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�

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

				// �E��
				case 16 :
					bl -= 256 + 64 + 32 ;
					bt -= 384 + 32 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;		// �ۋ��̔��a�����߂�
					x = br - brad - px ;		// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
					y = bb - py ;				// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
					c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
					c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

					// ���a�����v���C���[�܂ł̋������Z���ꍇ
					if ( (bl+brad+128 < px) && (px < br + 32 + 32) && (bt + 256 - 16 < py) && (py < bt + 256 + brad + 16) )
					{
						if ( brad < c+20 )
						{
							// �X�s�[�h������ĂȂ��Ƃ�
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

							rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�

							footY = bt + c - rad - 8 + 256 ;
							//printf( " c  : %f \n" , c ) ;
							//printf( "rad : %f \n" , rad ) ;
							//printf( "brad : %f \n" , brad ) ;
							//printf( "On Hit !! \n" ) ;

						}
					}
					break ;

				// ����
				case 17 :
					bl += 0 ;
					bt -= 384 + 40 ;
					br = bl + 512 ;
					bb = bt + 512 ;

					brad = (br - bl) / 2 - 50 ;		// �ۋ��̔��a�����߂�
					x = br - brad - px ;			// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
					y = bb - py ;					// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
					c2 = x * x + y * y ;			// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
					c = sqrt( c2 ) ;				// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

					// ���a�����v���C���[�܂ł̋������Z���ꍇ
					if ( (bl-128 < px) && (px < br-brad) && (bt + 256 - 16 < py) && (py < bt + 256 + brad) )
					{
						if ( brad <= c )
						{
							if ( flipMag_ != false )
							{
								cycleFlg_ = false ;

								rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�

								// �������܂̎��X�s�[�h����Ȃ��Ƃ�
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

				// �j�u���b�N�̏ꍇ
				case 27 :
					if ( (bt <= py) && (py < bb) )
					{
						if ( (bl <= pr) && (pl <= br) )
						{
							Player_vec_.deg = 0.0f ;
							footY = bt ;
							Pmode_ = P_dainit ;	// ------------ �ύX�\�� ( ���� )
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

	float brad ;	// �ۋ��̔��a
	float x ;
	float y ;
	float c2 ;
	float c ;		// �v���C���[�Ɗۋ��̋���
	float rad ;		// �ۋ��̒��S����̍���( Y�� )

	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	�����݂����̎�ޕ���
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ �܂�̂� /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

				brad = br - bl ;			// �ۋ��̔��a�����߂�
				x = br - (br - bl) - px ;	// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
				y = bb - (bb - bt) - py ;	// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
				c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
				c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

				// ���a�����v���C���[�܂ł̋������Z���ꍇ
				if ( brad >= c )
				{
					rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�
//					footY = bt + c - rad - 60 ;

					//printf( "px  : %f \n" , px ) ;
					//printf( "rad : %f \n" , rad ) ;
					//printf( "On Hit !! \n" ) ;
				}
				break ;

			/*/
			/*	___/ ������ /___________________
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
			/*	___/ �U��q /___________________
			/*/
			case GIMMICK_NAME_PENDULUM :
				bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
				br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
				bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
				bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

				brad = br - bl ;			// �ۋ��̔��a�����߂�
				x = br - (br - bl) - px ;	// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
				y = bb - (bb - bt) - py ;	// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
				c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
				c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

				// ���a�����v���C���[�܂ł̋������Z���ꍇ
				if ( brad+8 >= c )
				{
					rad = sqrt( (c2 - x * x) ) ;	// ���������ʒu�̍��������߂�
					footY = bt + c - rad - 66 ;

					//printf( "px  : %f \n" , px ) ;
					//printf( "rad : %f \n" , rad ) ;
					//printf( "On Hit !! \n" ) ;
				}
				break ;

			/*/
			/*	___/ ���� /___________________
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
						Player_mag_.x *= 0.965f ;			// ������
						Player_spd_.x *= 0.965f ;			// ������
						if ( Gimmick::GetInstance()->getGimmickData( g )._off[ 3 ] == 0 )
						{
							Gimmick::GetInstance()->getGimmickData( g )._off[ 3 ] = 1 ;
						}
						footY = bt ;

					}
				}
				break ;

			/*/
			/*	___/ �Ă� POD /___________________
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
/*	���̂����蔻��
/*	���̍��W��Ԃ�
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

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	/*/
	/*	player ����ʒu�̒���
	/*/
	if ( lrflg_ )
	{
		//  true : �E����
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 16 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 64 ;
	}
	else
	{
		//  false : ������
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 12 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 64 ;
	}

	// �W�����v��
	if ( Player_spd_.y > 0.0f )
	{
		return( 0 ) ;
	}

	// ������Ƃ�͈́@���͑S��
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// ������񂪓����Ă���Ƃ�
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 + Chip::GetInstance()->getScrollY( ) ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H + Chip::GetInstance()->getScrollY( ) ) ;

			switch ( chipTable[ i ] )
			{
				// �ʏ�u���b�N�̏ꍇ
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

							//printf( "chipTable = %d : x = %d y = %d \n" , i , i % CHIP_X , i / CHIP_X ) ;	// �����̍��W�ʒu�̔ԍ�
							//printf( "footY = %8.4f \n" , headY ) ;		// block�̍��W�ʒu

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

	float brad ;	// �ۋ��̔��a
	float x ;
	float y ;
	float c2 ;
	float c ;		// �v���C���[�Ɗۋ��̋���
	float rad ;		// �ۋ��̒��S����̍���( Y�� )

	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	�����݂����̎�ޕ���
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ �U��q /___________________
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
			/*	___/ �Ă� POD /___________________
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
/*	�����蔻��
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

	// �����蔻����Ƃ邽�߂̃`�b�v�f�[�^
	int *chipTable = Chip::GetInstance()->getChipTable( ) ;

	/*/
	/*	player ����ʒu�̒���
	/*/
	if ( lrflg_ )
	{
		//  true : �E����
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 20 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 22 ;
		py = Player_ypos_ + Player_mag_.y - 48 ;
	}
	else
	{
		//  false : ������
		px = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 8 ;
		pl = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() - 20 ;
		pr = Player_xpos_ + Player_mag_.x - Chip::GetInstance()->getScrollX() + 16 ;
		py = Player_ypos_ + Player_mag_.y - 48 ;
	}

	// ������Ƃ�͈́@���͑S��
	for( int i = 0 ; i < (CHIP_X * CHIP_Y) ; ++i )
	{
		// ������񂪓����Ă���Ƃ�
		if ( chipTable[ i ] != NULL )
		{
			bl = ( float )( (i % CHIP_X) * CHIP_W ) - RenderScale ;
			br = ( float )( (i % CHIP_X) * CHIP_W + CHIP_W ) - RenderScale ;
			bt = ( float )( (i / CHIP_X) * CHIP_H - 64 + Chip::GetInstance()->getScrollY( ) ) ;
			bb = ( float )( (i / CHIP_X) * CHIP_H - 64 + CHIP_H + Chip::GetInstance()->getScrollY( ) ) ;
			float center = bl + (br - bl) / 2 ;

			switch ( chipTable[ i ] )
			{

				// �ʏ�u���b�N�̏ꍇ
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

	float brad ;	// �ۋ��̔��a
	float x ;
	float y ;
	float c2 ;
	float c ;		// �v���C���[�Ɗۋ��̋���
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	�����݂����̎�ޕ���
		/*/
		switch ( Gimmick::GetInstance( )->getGimmickData( g )._Gimmick )
		{
			/*/
			/*	___/ �܂�̂� /___________________
			/*/
			case GIMMICK_NAME_CIRCULARSAWS :

				if ( Pmode_ != P_damage )
				{
					bl = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 ;
					br = Sprite::GetInstance()->getBmpXPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) - Chip::GetInstance()->getScrollX( ) + 64 + 64 ;
					bt = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 - 64 + Chip::GetInstance()->getScrollY( ) ;
					bb = Sprite::GetInstance()->getBmpYPos( Gimmick::GetInstance()->getGimmickData( g )._bmpNo ) + 192 + Chip::GetInstance()->getScrollY( ) ;

					brad = br - bl ;			// �ۋ��̔��a�����߂�
					x = br - (br - bl) - px ;	// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
					y = bb - (bb - bt) - py ;	// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
					c2 = x * x + y * y ;		// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
					c = sqrt( c2 ) ;			// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

					// ���a�����v���C���[�܂ł̋������Z���ꍇ
					if ( brad >= c )
					{
						// �Փ�
						Pmode_ = P_dainit ;
					}
				}
				break ;

			/*/
			/*	___/ �d�C /___________________
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
							// �Փ�
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
		// �e�����̂����蔻��
		for ( int g = 500 ; g < 1000 ; ++g )
		{
			bl = Sprite::GetInstance()->getBmpXPos( g ) - Chip::GetInstance()->getScrollX( ) ;
			br = Sprite::GetInstance()->getBmpXPos( g ) - Chip::GetInstance()->getScrollX( ) + 45 ;
			bt = Sprite::GetInstance()->getBmpYPos( g ) + Chip::GetInstance()->getScrollY( ) ;
			bb = Sprite::GetInstance()->getBmpYPos( g ) + 45 + Chip::GetInstance()->getScrollY( ) ;

			brad = br - bl ;					// �ۋ��̔��a�����߂�
			x = br - (br - bl) - (px - 32) ;	// �ۋ��̒��S�_����v���C���[�܂ł� X�� �̋���
			y = bb - (bb - bt) - (py - 96) ;	// �ۋ��̒��S�_����v���C���[�܂ł� Y�� �̋���
			c2 = x * x + y * y ;				// �s�^�S���X�̒藝���Εӂ̒���(�v���C���[�܂ł̋���)�����߂�
			c = sqrt( c2 ) ;					// ���̒l�Ȃ̂Œʏ�̒l�ɖ߂�

			// ���a�����v���C���[�܂ł̋������Z���ꍇ
			if ( brad >= c )
			{
				// �Փ�
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
/*	 �X�V
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
	/*	___/ �v���C���[ �`�� /___________________
	/*/
	PlayerAction( ) ;

	// �v���C���[�ʒu����
	Player_spd_.y += Player_mag_.y ;
	Player_ypos_ += Player_spd_.y ;
	if ( -128 < Player_ypos_ )
	{
		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// �z����W�����߂� x
		arrayY_ = ( int )( (Player_ypos_) / CHIP_H ) ;		// �z����W�����߂� y

	} else {
		arrayX_ = ( int )( (Player_xpos_) / CHIP_W ) ;		// �z����W�����߂� x
		arrayY_ = 0 ;										// �z����W�����߂� y
	}

	// ���x����
	float camera_y = 0.0f ;
	if ( KeyManager::GetInstance()->getKeyState( VK_UP ) )
	{
//		camera_y++ ;
	}
	if ( KeyManager::GetInstance()->getKeyState( VK_DOWN ) )
	{
//		camera_y-- ;

		/*/
		/*	�c�ɓ��������̃M�~�b�N��
		/*	�����蔻�肪�I����Ă��Ȃ�
		/*/
	}
	Player_spd_.x = Player_mag_.x ;
	Chip::GetInstance()->setScrollSize( ( int )-Player_mag_.x , (int)-camera_y ) ;
	Player_mag_.x *= DECELERATION_RATE ;			// ������

	// �J�����̈ʒu����
	if ( lrflg_ )
	{
		// �E����
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
		//������
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


	// �X������
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

	// �Q�[���I�[�o�[����
	if ( Player_ypos_ >= 1000 )
	{
		Pmode_ = P_deth ;
	}

	// �v���C���[�`��	�A�j���[�V����
	PlayerAnim_.playAnim( ) ;
	AnimationData *nowAnim = PlayerAnim_.getNowAnim( ) ;
	Sprite::GetInstance()->setBmpData(
			nowAnim->bmpNo + (lrflg_ * 11) ,
			7 ,
			Player_xpos_ + 4 ,							// ���S�ʒu�𒲐�
			Player_ypos_ - 54 + (flipMag_ * 72) ,		// ���S�ʒu�𒲐�
			(float)nowAnim->cutRect.left ,
			(float)nowAnim->cutRect.top ,
			(float)nowAnim->cutRect.right ,
			(float)nowAnim->cutRect.bottom ,
			0.5f , 0.5f ,
			255 ,
			flipMag_ * 180//Player_vec_.deg
		) ;

	// �o���A�̓W�J���邩�ǂ���
	barrierFlg_ = false ;
	if ( (Player_spd_.x >= 8.0f) || ((Player_spd_.x <= -8.0f)) )
	{
		barrierFlg_ = true ;
		ballAnim_.playAnim( );
		AnimationData *nowball = ballAnim_.getNowAnim( ) ;
		Sprite::GetInstance()->setBmpData(
				nowball->bmpNo ,
				7 ,
				Player_xpos_ + 4 ,							// ���S�ʒu�𒲐�
				Player_ypos_ - 54 + (flipMag_ * 72) ,		// ���S�ʒu�𒲐�
				(float)nowball->cutRect.left ,
				(float)nowball->cutRect.top ,
				(float)nowball->cutRect.right ,
				(float)nowball->cutRect.bottom ,
				0.5f , 0.5f ,
				255 ,
				0
			) ;
	}

	// �f�o�b�O�p
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

	// �N���A
//	Player_spd_.x = 0.0f ;
	Player_spd_.y = 0.0f ;

}



