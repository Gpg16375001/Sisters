/*
______________________________________________________________________________________________

	FILE	: Afterimage.cpp

	________/ Explanation of file /___________________________________________________________
       
    Afterimage�N���X

	Afterimage�N���X�̎�����


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "Common.h"

/*/
/*	�R���X�g���N�^
/*/
Afterimage::Afterimage( )
	: mode_( e_init )					// �����A�N�V�������[�h
	, Afterimage_xpos_( 0.0f )			// �`�悷�� X �|�W�V����
	, Afterimage_ypos_( 0.0f )			// �`�悷�� Y �|�W�V����
	, alpha_( 255.0f )					// �����x
	, flipMag_( false )					// false : �ʏ� true : ���]
	, create_flg_( false )
{
	Initialize( ) ;
	printf( "Afterimage -> " ) ;
	printf( "Start.\n" ) ;

}

/*/
/*	�f�X�g���N�^
/*/
Afterimage::~Afterimage( )
{
	Initialize( ) ;
	Finalize( ) ;
	printf( "End.\n" ) ;

}

/*/
/*	 ������
/*/
void Afterimage::Initialize( )
{
	Finalize( ) ;

	/*/
	/*	�v���C���[ �����Z�b�g
	/*/
	mode_				= e_init ;		// �����A�N�V�������[�h
	Afterimage_xpos_	= 0.0f ;		// �`�悷�� X �|�W�V����
	Afterimage_ypos_	= 0.0f ;		// �`�悷�� Y �|�W�V����
	alpha_				= 255.0f ;		// �����x
	flipMag_			= false ;		// false : �ʏ� true : ���]
	create_flg_			= false ;

}

/*/
/*	 �I����
/*/
void Afterimage::Finalize( )
{
	Afterimage_xpos_	= 0.0f ;
	Afterimage_ypos_	= 0.0f ;
	alpha_				= 0.0f ;
	mode_				= e_init ;
	flipMag_			= false ;		// false : �ʏ� true : ���]
	create_flg_			= false ;

}

/*/
/*	�v���C���[�̃A�N�V����
/*/
void Afterimage::AfterimageAction( int arg_bmpno , float arg_xpos , float arg_ypos , RECT arg_rc , bool arg_flip )
{

	// �e�A�N�V������
	switch( mode_ )
	{
		// �����Z�b�g
		case e_init :
			Initialize( ) ;

			Afterimage_bmpno_ = arg_bmpno ;
			Afterimage_xpos_ = arg_xpos ;
			Afterimage_ypos_ = arg_ypos ;
			Afterimage_rc_ = arg_rc ;
			flipMag_ = arg_flip ;
			create_flg_ = true ;
			mode_ = e_anim ;
			break ;

		// �c����
		case e_anim :
			printf( "e_anim\n" ) ;
			break ;

	}

}

/*/
/*	 �X�V
/*/
void Afterimage::Update( )
{
	alpha_ -= 16.0f ;
	if ( alpha_ <= 0.0f )
	{
		Finalize( ) ;
		return ;
	}

	// �c���A�j���[�V����
	Sprite::GetInstance()->setBmpData(
			Afterimage_bmpno_ ,
			7 ,
			Afterimage_xpos_  + Chip::GetInstance()->getScrollX( ),
			Afterimage_ypos_ ,
			(float)Afterimage_rc_.left ,
			(float)Afterimage_rc_.top ,
			(float)Afterimage_rc_.right ,
			(float)Afterimage_rc_.bottom ,
			1.0f , 1.0f ,
			( int )alpha_ ,
			flipMag_ * 180//Afterimage_vec_.deg
		) ;

}



