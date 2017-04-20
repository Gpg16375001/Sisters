/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"
#include <locale.h>

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
	printf( "Gimmick -> " ) ;

	clearGimmickData( ) ;
	clearBulletData( ) ;
	setBulletData( ) ;
	physic_.Initialize( ) ;
	MasterData::ReLoad( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	�I����
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	physic_.Finalize( ) ;
	clearGimmickData( ) ;
	clearBulletData( ) ;
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
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// �I�t�Z�b�g 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// �I�t�Z�b�g 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// �I�t�Z�b�g 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// �I�t�Z�b�g 4
		GimmickData_[ i ]._off[ 4 ] = 0 ;		// �I�t�Z�b�g 5
		GimmickData_[ i ]._off[ 5 ] = 0 ;		// �I�t�Z�b�g 6
		GimmickData_[ i ]._off[ 6 ] = 0 ;		// �I�t�Z�b�g 7
		GimmickData_[ i ]._off[ 7 ] = 0 ;		// �I�t�Z�b�g 8

		// �A�j���[�V����
		memset( &GimmickData_[ i ]._gAnim_01 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &GimmickData_[ i ]._gAnim_02 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &GimmickData_[ i ]._gAnim_03 , 0 , 4 * sizeof( AnimationData ) ) ;

	}

}

/*/
/*	�M�~�b�N�f�[�^�̃��[�h
/*/
void Gimmick::setGimmickData( int arg_SceneNo )
{	
	printf( "GimmickData was loaded.\n" ) ;

	if ( arg_SceneNo == 1 )
	{
		for ( auto it = MasterData::SceneGame01.begin() ; it != MasterData::SceneGame01.end() ; ++it )
		{
			// �������̎�
			if ( _strcmpi("MoveFloor" , it->getData()._name) == 0 )
			{
				setMoveBlocks( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �܂�̂��̎�
			if ( _strcmpi("CircularSaws" , it->getData()._name) == 0 )
			{
				setCircularSaws( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �U��q�̎�
			if ( _strcmpi("Pendulum" , it->getData()._name) == 0 )
			{
				setPendulums( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �d�C�̎�
			if ( _strcmpi("Shocker" , it->getData()._name) == 0 )
			{
				setShockers( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �X�s�[�h�A�b�v�̎�
			if ( _strcmpi("SpeedUp" , it->getData()._name) == 0 )
			{
				setSpeedUp( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �_�̎�
			if ( _strcmpi("Cloud" , it->getData()._name) == 0 )
			{
				setClouds( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// �ˌ����̎�
			if ( _strcmpi("Shooter" , it->getData()._name) == 0 )
			{
				setShooter( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// ���̎�
			if ( _strcmpi("Grass" , it->getData()._name) == 0 )
			{
				setGrass( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

		}
	}


}

/*/
/*	define�ɂ��镶���Ɠ����ꍇ�o�^����Ă��鐔����Ԃ�
/*/
int	Gimmick::strToDefineName( const char* arg_mode )
{
	int iRet = 1 ;

	if ( _strcmpi("GIMMICK_MODE_STAY" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_STAY ;
	}

	if ( _strcmpi("GIMMICK_MODE_UPDOWN" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_UPDOWN ;
	}

	if ( _strcmpi("GIMMICK_MODE_LEFTRIGHT" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_LEFTRIGHT ;
	}

	if ( _strcmpi("GIMMICK_MODE_CYCLE" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_CYCLE ;
	}

	if ( _strcmpi("GIMMICK_MODE_WAVE" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_WAVE ;
	}

	if ( _strcmpi("GIMMICK_MODE_DROP" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_DROP ;
	}

	if ( _strcmpi("GIMMICK_MODE_UPPER" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_UPPER ;
	}

	return( iRet ) ;
}

/*/
/*	������
/*/
void Gimmick::clearBulletData( )
{
	for ( int i = 0 ; i < 500 ; ++i )
	{
		BulletData_[ i ]._useFlg	= false ;	// �`�悷�邩�ǂ����̃t���O
		BulletData_[ i ]._bmpNo		= 0 ;		// �����̗v�f�ԍ� ( _hBmp �Ɗ֘A�t���邽�� )
		BulletData_[ i ]._anchor	= 0 ;		// �A���J�[�̈ʒu
		BulletData_[ i ]._x			= 0 ;
		BulletData_[ i ]._y			= 0 ;		// �O���[�o�����W
		BulletData_[ i ]._u			= 0 ;
		BulletData_[ i ]._v			= 0 ;		// �؂�����W
		BulletData_[ i ]._w			= 0 ;
		BulletData_[ i ]._h			= 0 ;		// ������
		BulletData_[ i ]._arrayX	= 0 ;
		BulletData_[ i ]._arrayY	= 0 ;		// �z����W
		BulletData_[ i ]._delay		= 0 ;		// �x��
		BulletData_[ i ]._spd		= 0 ;		// ����
		BulletData_[ i ]._Gimmick	= 0 ;		// �M�~�b�N�̎��
		BulletData_[ i ]._mode		= 0 ;		// �M�~�b�N�̃��[�h
		BulletData_[ i ]._off[ 0 ]	= 0 ;		// �I�t�Z�b�g 1
		BulletData_[ i ]._off[ 1 ]	= 0 ;		// �I�t�Z�b�g 2
		BulletData_[ i ]._off[ 2 ]	= 0 ;		// �I�t�Z�b�g 3
		BulletData_[ i ]._off[ 3 ]	= 0 ;		// �I�t�Z�b�g 4
		BulletData_[ i ]._off[ 4 ] = 0 ;		// �I�t�Z�b�g 5
		BulletData_[ i ]._off[ 5 ] = 0 ;		// �I�t�Z�b�g 6
		BulletData_[ i ]._off[ 6 ] = 0 ;		// �I�t�Z�b�g 7
		BulletData_[ i ]._off[ 7 ] = 0 ;		// �I�t�Z�b�g 8

		// �A�j���[�V����
		memset( &BulletData_[ i ]._gAnim_01 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &BulletData_[ i ]._gAnim_02 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &BulletData_[ i ]._gAnim_03 , 0 , 4 * sizeof( AnimationData ) ) ;
	}

}

/*/
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	/*/
	/*	�����݂����̎�ޕ���
	/*/

	/*/
	/*	___/ ������ /___________________
	/*/
	MoveFloor( ) ;

	/*/
	/*	___/ �܂�̂� /___________________
	/*/
	CircularSaws( ) ;

	/*/
	/*	___/ �U��q /___________________
	/*/
	Pendulums( ) ;

	/*/
	/*	___/ �d�C /___________________
	/*/
	Shockers( ) ;

	/*/
	/*	___/ SPPED UP /___________________
	/*/
	SpeedUp( ) ;

	/*/
	/*	___/ ���� /___________________
	/*/
	Clouds( ) ;

	/*/
	/*	___/ �GPOD /___________________
	/*/
	Shooter( ) ;

	/*/
	/*	___/ ���� /___________________
	/*/
	Grass( ) ;

}



