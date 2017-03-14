/*
______________________________________________________________________________________________

	FILE : SceneLoop.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SceneLoop �̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

int SceneLoop( )
{

	switch ( g_sceneNo )
	{
		// �u�����N
		case eSceneBlank :
			g_sceneNo++ ;
			break ;

		// �^�C�g��
		case eSceneTitle :
			g_sceneNo++ ;

			// �v���C���[�̃Z�b�g
			g_player.setGPoint( 32 , 32 ) ;
			break ;

		// �v���C��
		case eScenePlay :
			// �Z�b�g
			g_bgScreen[ 0 ].setX( 208 ) ;
			g_bgScreen[ 0 ].setY( 80 ) ;

			g_bgScreen[ 1 ].setX( 100 ) ;
			g_bgScreen[ 1 ].setY( 100 ) ;

			g_bgScreen[ 2 ].setX( -100 ) ;
			g_bgScreen[ 2 ].setY( -100 ) ;

			// �`�b�v�̕`��
			for ( int i = 0 ; i < (MAP_X * MAP_Y) ; i++ ) {
				g_CBG.setChip( (i % MAP_X) , (i / MAP_X) , g_mapData01[ i ] ) ;
			}

			// �v���C���[�̃A�N�V����
			g_player.action( ) ;
			g_player.setAPoint( (g_player.m_gPoint.x / CHIP_X) , (g_player.m_gPoint.y / CHIP_Y) ) ;

			break ;

		// �Q�[���I�[�o�[
		case eSceneOver :
			g_sceneNo = eSceneTitle ;
			break ;

	}
	return( true ) ;
}



