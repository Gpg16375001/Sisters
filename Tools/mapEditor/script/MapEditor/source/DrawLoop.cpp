/*
______________________________________________________________________________________________

	FILE : DrawLoop.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		DrawLoop �̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

int DrawLoop( )
{
	// �o�b�N�h���b�v�ʂ̕`��
	g_bScreen.draw( ) ;

	// �w�i�̕`�� 
	for ( int i = 0 ; i < BMP_DATA_BG_MAX ; ++i ) {
		g_bgScreen[ i ].draw( ) ;
	}

	// �`�b�v�̕`��
	g_CBG.draw( ) ;

	// �X�v���C�g 128���`��
	for ( int i = 0 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].draw( ) ;
	}

	// �X�v���C�g 128��������
	for ( int i = 0 ; i < BMP_DATA_SPR_MAX ; ++i ) {
		g_Spr[ i ].clearSprite( ) ;
	}

	return( true ) ;
}



