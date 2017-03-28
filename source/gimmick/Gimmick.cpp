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
	clearBulletData( ) ;
	setBulletData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	�I����
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

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

}



