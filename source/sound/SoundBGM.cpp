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
#include <DxLib.h>
#include "SoundBGM.h"

// �R���X�g���N�^
SoundBGM::SoundBGM( ) {
	htrack_ = 0 ;
}

// �f�X�g���N�^
SoundBGM::~SoundBGM( ) {

}

// ���y�Đ�
int SoundBGM::play( int arg_hSound ) {
	PlaySoundMem( htrack_ , DX_PLAYTYPE_LOOP , 1 ) ;
	return( true ) ;
}

// ���y�ǂݍ���
int SoundBGM::load( int arg_hSound , const TCHAR* arg_fileName ) {
	StopSoundMem( htrack_ ) ;
	htrack_ = LoadSoundMem( arg_fileName ) ;
	play( htrack_ ) ;
	return( true ) ;
}



