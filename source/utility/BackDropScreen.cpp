/*
______________________________________________________________________________________________

	FILE : BackDropScreen.cpp

	________/ Explanation of file /___________________________________________________________

		BackDropScreen �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
#include "BackDropScreen.h"
#include "Renderer.h"

// �R���X�g���N�^
BackDropScreen::BackDropScreen( )
{
	bmpNo_ = NULL ;
}

// �f�X�g���N�^
BackDropScreen::~BackDropScreen( )
{
}

// �`�悵�����w�i�̔ԍ����Z�b�g
int BackDropScreen::selectBmp( int arg_bmpNo )
{
	bmpNo_ = arg_bmpNo ;

	return ( true ) ;
}

// �o�b�N�h���b�v�`��
int BackDropScreen::Render( )
{

	return ( true ) ;
}


