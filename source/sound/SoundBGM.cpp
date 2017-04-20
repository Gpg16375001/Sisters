/*
______________________________________________________________________________________________

	FILE : SoundBGM.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SoundBGM �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"

// �R���X�g���N�^
SoundBGM::SoundBGM( ) {		}

// �f�X�g���N�^
SoundBGM::~SoundBGM( ) {
	// BGM�̏I��
	stop( ) ;
}

// ���y�Đ�
int SoundBGM::play( LPCTSTR arg_pStr ) {
	PlaySound( arg_pStr , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP ) ;
	return( true ) ;
}

// ���y��~
int SoundBGM::stop( ) {
	PlaySound( NULL , NULL , SND_PURGE ) ;
	return( true ) ;
}



