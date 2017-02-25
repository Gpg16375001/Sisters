/*
______________________________________________________________________________________________

	FILE : Renderer.cpp

	________/ Explanation of file /___________________________________________________________

		Renderer �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p
// #include "Renderer.h"

#include "Common.h"

/*/
/*	�f�X�g���N�^
/*/
Renderer::~Renderer( )
{
}

/*/
/*	������
/*/
void Renderer::Initialize( )
{
	bmpData_ = NULL ;
	width_ = 0 ;
	height_ = 0 ;
}

/*/
/*	�`�悵�����r�b�g�}�b�v���Z�b�g
/*/
int Renderer::selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height )
{
	bmpData_ = arg_bmpData ;
	width_ = arg_width ;
	height_ = arg_height ;

	return ( true ) ;
}

/*/
/*	�o�b�N�o�b�t�@�֕`��
/*/
int Renderer::Render( )
{
	SelectObject( g_hWorkBuf , bmpData_ ) ;

	BitBlt(
		g_hBackBuf ,
		0 ,
		0 ,
		width_ ,
		height_ ,
		g_hWorkBuf ,
		0 ,
		0 ,
		SRCCOPY
	) ;

	return ( true ) ;
}


