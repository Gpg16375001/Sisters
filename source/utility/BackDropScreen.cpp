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
#include "WinMain.h"

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
int BackDropScreen::draw()
{
/*
	SelectObject( hWork , bDataBGTable_[ bmpNo_ ].getBmpData( ) ) ;

	BitBlt(
		hDCBack_ ,
		0 ,
		0 ,
		bDataBGTable_[ bmpNo_ ].getBmpWidth( ) ,
		bDataBGTable_[ bmpNo_ ].getBmpHeight( ) ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;
*/
	return ( true ) ;
}


