/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	�f�X�g���N�^
/*/
Gimmick::~Gimmick( )
{
	printf( "Gimmick was end.\n" ) ;
}

/*/
/*	������
/*/
void Gimmick::Initialize( )
{
	printf( "Gimmick was created.\n" ) ;

	clearGimmickData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	�I����
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	clearGimmickData( ) ;
}

/*/
/*	������
/*/
void Gimmick::clearGimmickData( )
{
	for ( int i = 0 ; i < MAX_GIMMICK_NO ; ++i )
	{
		GimmickData_[ i ]._useFlg	= false ;	// �`�悷�邩�ǂ����̃t���O
		GimmickData_[ i ]._bmpNo	= 0 ;		// �����̗v�f�ԍ� ( _hBmp �Ɗ֘A�t���邽�� )
		GimmickData_[ i ]._anchor	= 0 ;		// �A���J�[�̈ʒu
		GimmickData_[ i ]._x		= 0 ;
		GimmickData_[ i ]._y		= 0 ;		// �O���[�o�����W
		GimmickData_[ i ]._u		= 0 ;
		GimmickData_[ i ]._v		= 0 ;		// �؂�����W
		GimmickData_[ i ]._w		= 0 ;
		GimmickData_[ i ]._h		= 0 ;		// ������
		GimmickData_[ i ]._arrayX	= 0 ;
		GimmickData_[ i ]._arrayY	= 0 ;		// �z����W
		GimmickData_[ i ]._delay	= 0 ;		// �x��
		GimmickData_[ i ]._spd		= 0 ;		// ����
		GimmickData_[ i ]._Gimmick	= 0 ;		// �M�~�b�N�̎��
		GimmickData_[ i ]._mode		= 0 ;		// �M�~�b�N�̃��[�h
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// �I�t�Z�b�g
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// �I�t�Z�b�g
	}

}

/*/
/*	--+ �M�~�b�N�̃f�[�^���Z�b�g +-----
/*/

/*/
/*	�������F�ʏ�
/*/
int Gimmick::setMoveBlock( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode )
{
	GimmickData_[ GimmickNo_ ]._Gimmick	= GIMMICK_NAME_MOVEFLOOR ;
	GimmickData_[ GimmickNo_ ]._bmpNo	= arg_bmpNo ;
	GimmickData_[ GimmickNo_ ]._x		= arg_x ;
	GimmickData_[ GimmickNo_ ]._y		= arg_y ;
	GimmickData_[ GimmickNo_ ]._spd		= arg_spd ;
	GimmickData_[ GimmickNo_ ]._delay	= arg_delay ;
	GimmickData_[ GimmickNo_ ]._mode	= arg_mode ;
	GimmickNo_++ ;

	return( true ) ;
}

/*/
/*	seetGimmicks
/*/
void Gimmick::setGimmicks( )
{

}

/*/
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	for ( int g = 0 ; g < MAX_GIMMICK_NO ; ++g )
	{
		/*/
		/*	�X�v���C�g�f�[�^
		/*/
		switch ( GimmickData_[ g ]._Gimmick )
		{
			/*/
			/*	___/ �܂�̂� /___________________
			/*/
			case GIMMICK_NAME_MARU :
				// ���ړ��̊ۋ�

				// �~�ړ��̊ۋ�

				// �~�ړ��̊ۋ�

				break ;

			/*/
			/*	___/ ������ /___________________
			/*/
			case GIMMICK_NAME_MOVEFLOOR :
				/*/
				/*	�������F�Î~
				/*/
				printf( "GIMMICK_NAME_MOVEFLOOR\n" ) ;
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_STAY )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
						printf( "GIMMICK_MODE_STAY\n" ) ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y ,
								0 , 0 ,
								256 , 64 ,
								0.5f , 0.5f ,
								255 ,
								0
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

					} else {
						GimmickData_[ g ]._delay-- ;
						if ( GimmickData_[ g ]._delay <= 0 )
						{
							GimmickData_[ g ]._useFlg = true ;
						}
					}

				}

				/*/
				/*	�������F�㉺
				/*/
				if ( GimmickData_[ g ]._mode == GIMMICK_MODE_UPDOWN )
				{
					if ( GimmickData_[ g ]._useFlg )
					{
						printf( "GIMMICK_MODE_UPDOWN\n" ) ;

						GimmickData_[ g ]._off[ 0 ]++ ;
						Sprite::GetInstance()->setBmpData(
								GimmickData_[ g ]._bmpNo ,
								0 ,
								GimmickData_[ g ]._x + Chip::GetInstance()->getScrollX( ) ,
								GimmickData_[ g ]._y + Chip::GetInstance()->sinWave( GimmickData_[ g ]._off[ 0 ] , 128 , GimmickData_[ g ]._spd ) ,
								0 , 0 ,
								256 , 64 ,
								0.5f , 0.5f ,
								255 ,
								0
							) ;
						GimmickData_[ g ]._w = GimmickData_[ g ]._x + 128 ;
						GimmickData_[ g ]._h = GimmickData_[ g ]._y + 32 ;

					} else {
						GimmickData_[ g ]._delay-- ;
						if ( GimmickData_[ g ]._delay <= 0 )
						{
							GimmickData_[ g ]._useFlg = true ;
						}
					}

				}

				/*/
				/*	�������F�~
				/*/

				break ;
		}
	}

}


