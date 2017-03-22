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
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// �I�t�Z�b�g 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// �I�t�Z�b�g 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// �I�t�Z�b�g 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// �I�t�Z�b�g 4
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

}



