/*
______________________________________________________________________________________________

	FILE : TimeProc.cpp
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		TimeProc �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "TimeProc.h"

// �R���X�g���N�^
TimeProc::TimeProc( ) {
	timeBeginPeriod( 1 ) ;												// ���Ԏ擾�̐��x���グ��
}

// �f�X�g���N�^
TimeProc::~TimeProc( ) {
	timeEndPeriod( 1 ) ;												// ���Ԏ擾�̐��x�����ɖ߂�
}

// ���Ԃ̎擾
DWORD TimeProc::getTime( ) {
	return( timeGetTime( ) ) ;											// �V�X�e���^�C�����󂯎��
}

// ����J�n
DWORD TimeProc::startTime( ) {
	m_sTime = timeGetTime( ) ;											// �V�X�e���^�C�����󂯎��
	return( m_sTime ) ;
}

// ����I��
DWORD TimeProc::endTime( ) {
	m_eTime = timeGetTime( ) ;											// �V�X�e���^�C�����󂯎��
	m_pTime = m_eTime - m_sTime ;										// �o�ߎ���
	return( m_pTime ) ;
}

// �X���[�v
int TimeProc::TheWorld( int arg_theWorldTime ) {
	Sleep( arg_theWorldTime ) ;											// �X���b�h���~�߂�
	return( true ) ;
}


