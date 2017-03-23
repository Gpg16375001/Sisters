/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManager�N���X

	SceneManager�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "LoadMapData.h"
#include "SceneBlank.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneGame02.h"

#define		MAP01	TEXT("data/map/mapData01.txt")
#define		MAP02	TEXT("data/map/mapData02.txt")

/*/
/*	 ������
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
}

/*/
/*	 �I����
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	�f�X�g���N�^
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 �X�V
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;
	SceneTitle title ;
	SceneGame01 game01 ;
	SceneGame02 game02 ;

	if ( KeyManager::GetInstance()->getKeyState( VK_F1 ) )
	{
		Gimmick::GetInstance()->Finalize( ) ;
		Gimmick::GetInstance()->Initialize( ) ;
		g_state = -1 ;
	}

	if ( KeyManager::GetInstance()->getKeyState( VK_F5 ) )
	{
		if ( g_dethflg )
		{
			g_dethflg = false ;
		} else {
			g_dethflg = true ;
		}
	}

	// �V�[�����e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			g_state++ ;
			break ;

		case S_PlayTitle :
			title.Update( ) ;
			title.Render( ) ;
			break ;

		case S_InitGame01 :
			// �}�b�v�ǂݍ���
			LoadMapData::ReLoad( MAP01 ) ;

			// �M�~�b�N�̏����Z�b�g
			Gimmick::GetInstance()->Initialize( ) ;

			// �M�~�b�N���Z�b�g
			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(208) , PTC(8) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �ۋ�
			Gimmick::GetInstance()->setCircularSaws( 11 , PTC(218) , PTC(3) , 360 , 0 , GIMMICK_MODE_CYCLE ) ;		// �ۋ�

			Gimmick::GetInstance()->setClouds( 150 , PTC(232) , PTC(6) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 151 , PTC(235) , PTC(6) ,   0 ,  90 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 152 , PTC(238) , PTC(6) ,   0 ,  40 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 153 , PTC(242) , PTC(6) ,   0 ,  20 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 154 , PTC(246) , PTC(6) ,   0 , 130 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 155 , PTC(255) , PTC(4) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 156 , PTC(278) , PTC(4) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// �_
			Gimmick::GetInstance()->setClouds( 157 , PTC(281) , PTC(1) ,   0 ,  90 , GIMMICK_MODE_STAY ) ;			// �_

			Gimmick::GetInstance()->setShockers( 400 , PTC(234) , PTC(0) , 448 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// �d�C
			Gimmick::GetInstance()->setShockers( 401 , PTC(237) , PTC(0) , 448 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// �d�C

			g_state++ ;
			break ;

		case S_PlayGame01 :
			game01.Update( ) ;
			game01.Render( ) ;
			break ;

		case S_InitGame02 :
			// �}�b�v�ǂݍ���
			LoadMapData::ReLoad( MAP02 ) ;

			// �M�~�b�N�̏����Z�b�g
			Gimmick::GetInstance()->Initialize( ) ;

			// �M�~�b�N���Z�b�g
//			Gimmick::GetInstance()->setCircularSaws( 10 , PTC(70) , PTC(3) , 360 , 0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �ۋ�

			Gimmick::GetInstance()->setMoveBlocks( 50 , PTC(104) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_CYCLE ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 51 , PTC(104) , PTC(3) ,   0 ,  96 , GIMMICK_MODE_CYCLE ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 52 , PTC(104) , PTC(3) ,   0 , 192 , GIMMICK_MODE_CYCLE ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 53 , PTC(104) , PTC(3) ,   0 , 288 , GIMMICK_MODE_CYCLE ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 54 , PTC(108) , PTC(0) , 120 ,   0 , GIMMICK_MODE_DROP ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 55 , PTC(108) , PTC(0) , 120 , 192 , GIMMICK_MODE_DROP ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 56 , PTC(110) , PTC(0) , 120 ,   0 , GIMMICK_MODE_UPPER ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 57 , PTC(110) , PTC(0) , 120 , 192 , GIMMICK_MODE_UPPER ) ;		// ������
			Gimmick::GetInstance()->setMoveBlocks( 58 , PTC( 89) , PTC(3) ,   1 ,   0 , GIMMICK_MODE_WAVE ) ;		// ������

			Gimmick::GetInstance()->setPendulums( 100 , PTC(70) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �U��q
			Gimmick::GetInstance()->setPendulums( 101 , PTC(76) , PTC(3) ,   0 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;	// �U��q
			Gimmick::GetInstance()->setPendulums( 102 , PTC(82) , PTC(3) ,   0 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �U��q

			Gimmick::GetInstance()->setShockers( 400 , PTC(56) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �d�C
			Gimmick::GetInstance()->setShockers( 401 , PTC(53) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �d�C
			Gimmick::GetInstance()->setShockers( 402 , PTC(50) , PTC(6) ,  40 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �d�C
			Gimmick::GetInstance()->setShockers( 403 , PTC(56) , PTC(3) , 512 ,   0 , GIMMICK_MODE_LEFTRIGHT ) ;	// �d�C
			Gimmick::GetInstance()->setShockers( 404 , PTC(56) , PTC(3) , 512 , 192 , GIMMICK_MODE_LEFTRIGHT ) ;	// �d�C

			Gimmick::GetInstance()->setShockers( 405 , PTC(91) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// �d�C
			Gimmick::GetInstance()->setShockers( 407 , PTC(92) , PTC(4) , 256 ,   0 , GIMMICK_MODE_UPDOWN ) ;		// �d�C

			Gimmick::GetInstance()->setSpeedUp( 450 , PTC(45) , PTC(6) ,   0 ,   0 , GIMMICK_MODE_STAY ) ;			// Speed Up

			g_state++ ;
			break ;

		case S_PlayGame02 :
			game02.Update( ) ;
			game02.Render( ) ;
			break ;

		case S_InitGame03 :	
			g_state = S_InitGame02 ;
			break ;

		case S_PlayGame03 :
			break ;

	}
}



