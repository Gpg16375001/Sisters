/*
______________________________________________________________________________________________

	FILE : SoundSE.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SoundSE �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

// �R���X�g���N�^
SoundSE::SoundSE( ) {		}

// �f�X�g���N�^
SoundSE::~SoundSE( ) {
	// SE�̏I��
	stop( ) ;
}

// ���y�Đ�
int SoundSE::play( LPCTSTR arg_pStr ) {
	mciSendString( arg_pStr , NULL , 0 , NULL ) ;
	mciSendString( TEXT( "play se notify" ) , NULL , 0 , g_hWindow ) ;
	return( true ) ;
}

// ���y��~
int SoundSE::stop( ) {
	mciSendString( TEXT( "stop se" ) , NULL , 0 , NULL ) ;
	mciSendString( TEXT( "close se" ) , NULL , 0 , NULL ) ;
	return( true ) ;
}



