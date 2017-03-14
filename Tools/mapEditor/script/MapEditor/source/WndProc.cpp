/*
	�E�B���h�E�v���V�[�W��
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"	// --- �S�t�@�C���ł̋��ʃw�b�_�[
#include "LoadMapData.h"

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;			// �f�B�X�v���C�f�o�C�X�R���e�L�X�g
	PAINTSTRUCT			ps;				// �`��\����
	static HBITMAP s_hBackBufBmp ;		// �o�b�N�o�b�t�@
	static OPENFILENAME	 ofn ;			// �t�@�C���̕ۑ�
	char s[512] ;						// �f�o�b�O�p
	static 	int arrayX , arrayY ;
	static 	int index ;
	static	bool dragF = false ;

	g_lParam = lParam ;

	// --- ���b�Z�[�W�ŕ���
	switch ( message )
	{
		/* -------------------------
		|		WM_CREATE
		+ ----------------------- */
		case WM_CREATE:
			printf( "WM_CREATE�C�x���g�����s����܂���\n" );

			// --- �E�B���h�E�n���h���̃R�s�[
			g_hWindow = hWnd;

			// --- �t���[���P�ʂŃ^�C�}�[�C�x���g�𔭐�������
			SetTimer( g_hWindow, 1, GAME_FRAME, NULL );

			// ����ʂ̍쐬
			hDC = GetDC( hWnd ) ;													// �w��E�B���h�E�N���X�̃f�o�C�X�R���e�L�X�g�̎擾
			g_hWorkBuf = CreateCompatibleDC( hDC ) ;								// ���p�̃f�o�C�X�R���e�L�X�g
			s_hBackBufBmp = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;	// �N���C�A���g�̈�̃r�b�g�}�b�v�𐶐�
			g_hBackBuf = CreateCompatibleDC( hDC ) ;								// �o�b�N�o�b�t�@�p�̃f�o�C�X�R���e�L�X�g
			SelectObject( g_hBackBuf , s_hBackBufBmp ) ;							// �o�b�N�o�b�t�@��DC��BMP���Z�b�g����
			ReleaseDC( hWnd , hDC ) ;												// �f�o�C�X�R���e�L�X�g�̉��

			// �摜�̓ǂݍ���
			g_bDataBGTable[ 0 ].loadData( TEXT("source/cg/background01.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 1 ].loadData( TEXT("source/cg/neko.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 2 ].loadData( TEXT("source/cg/background02.bmp") , WINDOW_W , WINDOW_H ) ;
			g_bDataBGTable[ 3 ].loadData( TEXT("source/cg/background03.bmp") , WINDOW_W , WINDOW_H ) ;

			// �X�v���C�g�̓ǂݍ���
			g_bDataSprTable[ 0 ].loadData( TEXT("source/cg/bg01.bmp") , 1000 , 1000 ) ;
			g_bDataSprTable[ 1 ].loadData( TEXT("source/cg/chips/all_grass.bmp") , 320 , 256 ) ;
			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/arrow.bmp") , 32 , 32 ) ;
//			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/.bmp") , 64 , 64 ) ;
//			g_bDataSprTable[ 3 ].loadData( TEXT("source/cg/.bmp") , 64 , 64 ) ;

			// �`�b�v�̃Z�b�g
			g_bDataCBGTable[ 0 ].loadData( TEXT("source/cg/chips/all_grass.bmp") , 320 , 256 ) ;
			
			// pen
			g_redPen = CreatePen( 0 , 1 , RGB(255 , 0 , 0) ) ;

			// brush
			g_brush[ 0 ] = CreateSolidBrush( RGB(153 , 153 , 153) ) ; // �O���[
			g_brush[ 1 ] = CreateSolidBrush( RGB(100 , 100 , 100) ) ; // �����O���[

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMER�C�x���g�����s����܂���\n" );
			g_key.update( );	// --- �L�[���̍X�V

			// --------------
			if ( g_key.getKeyState( VK_F2 ) )
			{
				LoadMapData::ReLoad( ) ;
			}

			SetLoop( ) ;

			// �`��
			DrawLoop( ) ;

			// --------------

			// --- �ĕ`��̗v��
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN :
			// �`�b�v�ύX
			actionLoop( ) ;

			// �h���b�O�t���O�𗧂Ă�
			dragF = true ;

			// �}�E�X�̃N���b�N���W�̎擾
			g_mouseX = LOWORD( lParam ) ;
			g_mouseY = HIWORD( lParam ) ;

			// �N���b�N���W��z����W�ɒ���-
			arrayX = (g_mouseX - 32) / CHIP_W + g_scroll ;
			arrayY = (g_mouseY - 32) / CHIP_H ;

			// �z����W���ꎟ�����W�ɒ���
			index = arrayY * MAP_X + arrayX ;

			if ( (index <= (MAP_X * MAP_Y))					// �v�f�����z��̃T�C�Y���Ŏ��܂��Ă�����
					&& (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// ���������W��
					&& (cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
				)
			{
				// �z����̒l�𔻒�
				if ( g_mapData01[ index ] == 0 ) {
					// �u���b�N��\���l����
					g_mapData01[ index ] = g_chip ;
					printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;

				} else {
					// �u���b�N������
					g_mapData01[ index ] = 0 ;
					printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
					dragF = false ;
				}
			}
			break ;

		/* -------------------------
		|		WM_LBUTTONUP
		+ ----------------------- */
		case WM_LBUTTONUP :
			dragF = false ;
			break ;

		case WM_MOUSEMOVE :
			if ( (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// ���������W��
				&&(cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
				)
			{
			} else {
				dragF = false ;
			}

			// �}�E�X�̃N���b�N���W�̎擾
			g_mouseX = LOWORD( lParam ) ;
			g_mouseY = HIWORD( lParam ) ;

			// �N���b�N���W��z����W�ɒ���
			arrayX = (g_mouseX - 32) / CHIP_W + g_scroll ;
			arrayY = (g_mouseY - 32) / CHIP_H ;

			// �z����W���ꎟ�����W�ɒ���
			index = arrayY * MAP_X + arrayX ;

			if ( dragF )
			{
				// �v�f�����z��̃T�C�Y���Ŏ��܂��Ă�����
				if ( (index <= (MAP_X * MAP_Y))					// �v�f�����z��̃T�C�Y���Ŏ��܂��Ă�����
						&& (cell(2) < g_mouseX) && (g_mouseX < cell(48))	// ���������W��
						&& (cell(2) < g_mouseY) && (g_mouseY < cell(26))	// 
					)
				{
					// �z����̒l�𔻒�
					if ( g_mapData01[ index ] == 0 ) {
						// �u���b�N��\���l����
						g_mapData01[ index ] = g_chip ;
						printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;
					}
				}

			} else if ( (g_mapData01[ index ] != 0) && (g_key.getKeyState(VK_SPACE)) ) {
				// �u���b�N������
				g_mapData01[ index ] = 0 ;
				printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
			}


			break ;

		/* -------------------------
		|		WM_RBUTTONDOWN
		+ ----------------------- */
		case WM_RBUTTONDOWN :
			funcFileSave( hWnd ) ;
			printf( "Created MapData\n" ) ;
			break ;

		/* -------------------------
		|		WM_KEYDOWN
		+ ----------------------- */
		case WM_KEYDOWN :
			break ;

		/* -------------------------
		|		WM_KEYUP
		+ ----------------------- */
		case WM_KEYUP :
			break ;

		/* -------------------------
		|		WM_PAINT
		+ ----------------------- */
		case WM_PAINT:
			//printf( "WM_PAINT�C�x���g�����s����܂���\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ;

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf( "WM_DESTROY�C�x���g�����s����܂���\n" );

			// �I�u�W�F�N�g�̍폜
			DeleteObject( g_redPen ) ;
			DeleteObject( g_brush ) ;

			// --- �^�C�}�[�̍폜
			KillTimer( hWnd, 1 );

			// �o�b�t�@�̍폜
			DeleteDC( g_hWorkBuf ) ;

			// --- �A�v���P�[�V�����I���𔭍s
			PostQuitMessage( 0 );
			break;

		/* -------------------------
		|		default��
		+ ----------------------- */
		default:
			return ( DefWindowProc( hWnd, message, wParam, lParam ) );
	}

	return 0;
}




