/*
	�E�B���h�E�v���V�[�W��
*/

#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

#include "Common.h"	// --- �S�t�@�C���ł̋��ʃw�b�_�[

LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC					hDC;			// �f�B�X�v���C�f�o�C�X�R���e�L�X�g
	PAINTSTRUCT			ps;				// �`��\����
	static HBITMAP s_hBackBufBmp ;		// �o�b�N�o�b�t�@
	TCHAR s[512] ;						// �f�o�b�O�p

	static 	int mouseX , mouseY ;
	static 	int arrayX , arrayY ;
	static 	int index ;
	static	bool dragF = false ;


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
			g_bDataSprTable[ 0 ].loadData( TEXT("source/cg/Player.bmp") , 256 , 256 ) ;
			g_bDataSprTable[ 1 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;
			g_bDataSprTable[ 2 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;
			g_bDataSprTable[ 3 ].loadData( TEXT("source/cg/Test.bmp") , 64 , 64 ) ;

			// �摜�̃Z�b�g
			g_bScreen.selectBmp( 0 ) ;
			g_bgScreen[ 0 ].selectBmp( 2 ) ;
			g_bgScreen[ 1 ].selectBmp( 3 ) ;
			g_bgScreen[ 2 ].selectBmp( 1 ) ;

			// �`�b�v�̃Z�b�g
			g_bDataCBGTable[ 0 ].loadData( TEXT("source/cg/Block.bmp") , 32 , 256 ) ;

			// BGM�̃Z�b�g
			g_sBGM.play( BGM_FILE_PASS_01 ) ;
			
			// �A�j���[�V�����̏����Z�b�g
			enum AnimName {
				A_STANDBY ,
			} ;

			break;

		/* -------------------------
		|		WM_TIMER
		+ ----------------------- */
		case WM_TIMER:
			//printf( "WM_TIMER�C�x���g�����s����܂���\n" );
			g_key.update( );	// --- �L�[���̍X�V

			// --------------
			SceneLoop( ) ;
			DrawLoop( ) ;

			// --------------

			// --- �ĕ`��̗v��
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		case MM_MCINOTIFY :
			if ( wParam == MCI_NOTIFY_SUCCESSFUL ) {
				printf( "SE�Đ��I��\n" ) ;
				g_sSE.stop( ) ;
			}
			break ;

		/* -------------------------
		|		WM_LBUTTONDOWN
		+ ----------------------- */
		case WM_LBUTTONDOWN :
			// �h���b�O�t���O�𗧂Ă�
			dragF = true ;

			// �}�E�X�̃N���b�N���W�̎擾
			mouseX = LOWORD( lParam ) ;
			mouseY = HIWORD( lParam ) ;

			// �N���b�N���W��z����W�ɒ���
			arrayX = (mouseX - 738 / 2) / (CHIP_X / 2) ;
			arrayY = (mouseY - 64 / 2) / (CHIP_Y / 2) ;

			// �z����W���ꎟ�����W�ɒ���
			index = arrayY * MAP_X + arrayX ;

			if ( (index <= (MAP_X * MAP_Y))					// �v�f�����z��̃T�C�Y���Ŏ��܂��Ă�����
					&& (MAP_X >= arrayX) && (arrayX >= 0)	// ���������W��
					&& (MAP_Y >= arrayY) && (arrayY >= 0)	// 
				)
			{
				// �z����̒l�𔻒�
				if ( g_mapData01[ index ] == 0 ) {
					// �u���b�N��\���l����
					g_mapData01[ index ] = 1 ;
					printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;

				} else {
					// �u���b�N������
					g_mapData01[ index ] = 0 ;
					printf( "X = %4d , Y = %4d  Delete Chip\n" , arrayX , arrayY ) ;
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
			if ( dragF ) {
				// �}�E�X�̃N���b�N���W�̎擾
				mouseX = LOWORD( lParam ) ;
				mouseY = HIWORD( lParam ) ;

				// �N���b�N���W��z����W�ɒ���
				arrayX = mouseX / CHIP_X ;
				arrayY = mouseY / CHIP_Y ;

				// �z����W���ꎟ�����W�ɒ���
				index = arrayY * MAP_X + arrayX ;

				// �v�f�����z��̃T�C�Y���Ŏ��܂��Ă�����
				if ( index <= (MAP_X * MAP_Y) ) {
					// �z����̒l�𔻒�
					if ( g_mapData01[ index ] == 0 ) {
						// �u���b�N��\���l����
						g_mapData01[ index ] = 1 ;
						printf( "X = %4d , Y = %4d  Set Chip\n" , arrayX , arrayY ) ;
					}
				} 
			}
			break ;

		/* -------------------------
		|		WM_RBUTTONDOWN
		+ ----------------------- */
		case WM_RBUTTONDOWN :
			g_cmap.CreateMapData( "map01" ) ;
			printf( "Created MapData\n" ) ;
			break ;

		/* -------------------------
		|		WM_PAINT
		+ ----------------------- */
		case WM_PAINT:
			//printf( "WM_PAINT�C�x���g�����s����܂���\n" );
			hDC = BeginPaint( hWnd, &ps );

			BitBlt( hDC , 0 , 0 , WINDOW_W , WINDOW_H , g_hBackBuf , 0 , 0 , SRCCOPY ) ;

			// �O���b�h
			for ( int x = 0 ; x < 32 ; x++ ) {
				MoveToEx( hDC , (x * 32) , 0 , 0 ) ;
				LineTo( hDC , (x * 32) , WINDOW_H ) ;
			}
			for ( int y = 0 ; y < 32 ; y++ ) {
				MoveToEx( hDC , 0, (y * 32) , 0 ) ;
				LineTo( hDC , WINDOW_W , (y * 32) ) ;
			}

			EndPaint( hWnd, &ps );
			break;

		/* -------------------------
		|		WM_DESTROY
		+ ----------------------- */
		case WM_DESTROY:
			printf( "WM_DESTROY�C�x���g�����s����܂���\n" );

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
