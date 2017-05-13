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

#include "SoundSE.h"

// �R���X�g���N�^
SoundSE::SoundSE( ) {
	for ( int i = 0 ; i < 8 ; ++i )
	{
		htrack_[ i ] = 0 ;
	}
}

// �f�X�g���N�^
SoundSE::~SoundSE( ) {

}

// ���y�Đ�
int SoundSE::play( int arg_hSound ) {
	PlaySoundMem( htrack_[ arg_hSound ] , DX_PLAYTYPE_BACK , 0 ) ;
	return( true ) ;
}

// ���y�ǂݍ���
int SoundSE::load( int arg_hSound , const TCHAR* arg_fileName ) {
	htrack_[ arg_hSound ] = LoadSoundMem( arg_fileName ) ;
	return( true ) ;
}



