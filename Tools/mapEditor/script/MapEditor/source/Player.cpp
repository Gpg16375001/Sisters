/*
______________________________________________________________________________________________

	FILE : Player.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		Player �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include <math.h>

#include "Common.h"

#define FSPD	2
#define FCNT	(32 / FSPD)
#define D_UP	48 * 0
#define D_DOWN	48 * 1
#define D_LEFT	48 * 2
#define D_RIGHT	48 * 3

// �R���X�g���N�^
Player::Player( ) {
	m_actionNo = ePlayerBlank ;
}

// �f�X�g���N�^
Player::~Player( ) {	}

// �A�N�V����
int Player::action( ) {
	static int fcnt = FCNT ;
	static bool wflg = false ;

	// �A�N�V�����ŕ���
	switch ( m_actionNo )
	{
		// ����
		case ePlayerBlank :
			m_actionNo++ ;
			break ;

		// �X�^���o�C
		case ePlayerStandby :
			if ( g_key.getKeyState(VK_LEFT) ) {
				m_actionNo = ePlayerMoveLeft ;
			}
			if ( g_key.getKeyState(VK_RIGHT) ) {
				m_actionNo = ePlayerMoveRight ;
			}
			if ( g_key.getKeyState(VK_UP) ) {
				m_actionNo = ePlayerMoveUp ;
			}
			if ( g_key.getKeyState(VK_DOWN) ) {
				m_actionNo = ePlayerMoveDown ;
			}
			break ;

		// ���ړ�
		case ePlayerMoveLeft :

			if ( (g_mapData01[ (g_player.m_aPoint.y * MAP_X) + (g_player.m_aPoint.x - 1) ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( (g_player.m_gPoint.x - FSPD) , g_player.m_gPoint.y ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// �E�ړ�
		case ePlayerMoveRight :

			if ( (g_mapData01[ (g_player.m_aPoint.y * MAP_X) + (g_player.m_aPoint.x + 1) ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( (g_player.m_gPoint.x + FSPD) , g_player.m_gPoint.y ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// ��ړ�
		case ePlayerMoveUp :

			if ( (g_mapData01[ ((g_player.m_aPoint.y - 1) * MAP_X) + g_player.m_aPoint.x ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( g_player.m_gPoint.x , (g_player.m_gPoint.y - FSPD) ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

		// ���ړ�
		case ePlayerMoveDown :

			if ( (g_mapData01[ ((g_player.m_aPoint.y + 1) * MAP_X) + g_player.m_aPoint.x ] & 0xef) == 0 ) {
				wflg = true ;
			}

			if ( wflg ) {
				g_player.setGPoint( g_player.m_gPoint.x , (g_player.m_gPoint.y + FSPD) ) ;
			}

			fcnt-- ;
			if ( fcnt <= 0 ) {
				fcnt = FCNT ;
				wflg = false ;
				m_actionNo = ePlayerStandby ;
			}
			break ;

	}

	// �v���C���[�̃Z�b�g
	for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
		if ( g_mapData01[ i ] == 16 ) {
//			g_Spr[ 0 ].setSprite( 0 , g_player.m_gPoint.x , g_player.m_gPoint.y - 16 , m_cPoint.left , m_cPoint.top , m_cPoint.right , m_cPoint.bottom ) ;
		}
	}

	return( true ) ;
}

// �O���[�o�����W�̃Z�b�g
int Player::setGPoint( int arg_gX , int arg_gY ) {

	m_gPoint.x = arg_gX ;
	m_gPoint.y = arg_gY ;

	return( true ) ;
}

// �z����W�̃Z�b�g
int Player::setAPoint( int arg_aX , int arg_aY ) {

	m_aPoint.x = arg_aX ;
	m_aPoint.y = arg_aY ;

	return( true ) ;
}



