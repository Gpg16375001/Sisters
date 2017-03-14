
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: KeyManager.h
	NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
	�S�Ẵt�@�C���ŋ��ʂ̃w�b�_�[�t�@�C��

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

/* -----------------------------------------------------------------------------------------
|
|       ���ʃw�b�_�[
|
+ --------------------------------------------------------------------------------------- */
#include "ConsoleWindow.h"	// --- �R���\�[���E�B���h�E
#include "KeyManager.h"		// --- �L�[�}�l�[�W���[

#include "BitmapData.h"
#include "Sprite.h"
#include <math.h>
#include "DrawLoop.h"
#include "ChipBackGround.h"
#include "TimeProc.h"
#include "CreateData.h"

/* -----------------------------------------------------------------------------------------
|
|       DEFINE�錾
|
+ --------------------------------------------------------------------------------------- */
#define WINDOW_W 800
#define WINDOW_H 600

#define GAME_FPS	60					// --- �P�b�ԂłU�O��̉�ʍX�V
#define GAME_FRAME	( 1000 / GAME_FPS )	// --- 1000�~���b��FPS�ŏ��Z�łP�t���[���̃X�s�[�h�����߂�

#define BMP_DATA_SPR_MAX	128
#define BMP_DATA_BG_MAX		8
#define BMP_DATA_CBG_MAX	8

#define MAP_X	1024
#define MAP_Y	12

#define ANIM_DATA_MAX	128

#define		cell( arg_cell )	(arg_cell * 16)

/* -----------------------------------------------------------------------------------------
|
|       �^�錾
|
+ --------------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------------------
|
|       �v���g�^�C�v�錾
|
+ --------------------------------------------------------------------------------------- */
VOID funcFileSave( HWND hWnd ) ;
void SetLoop( ) ;
void actionLoop( ) ;

/* -----------------------------------------------------------------------------------------
|
|       �O���Q�Ɛ錾
|
+ --------------------------------------------------------------------------------------- */
// --- �R���\�[���E�B���h�E
extern ConsoleWindow g_cWin;	

// --- �E�B���h�E�Ȃǂ̃^�C�g��
extern TCHAR g_szAppTitle[ ] ;
extern TCHAR g_szWndClass[ ] ;

// --- �C���X�^���X�n���h��
extern HINSTANCE g_hInstance ;

// --- �E�C���h�E�n���h��
extern HWND g_hWindow ;	

// --- lParam
extern LPARAM g_lParam ;	

// --- �L�[�}�l�[�W���[
extern KeyManager g_key ;

// �r�b�g�}�b�v�f�[�^
extern BitmapData g_bDataSprTable[ BMP_DATA_SPR_MAX ] ;	// �X�v���C�g�p
extern BitmapData g_bDataBGTable[ BMP_DATA_BG_MAX ] ;	// �w�i�p

// �o�b�N�o�b�t�@
extern HDC g_hBackBuf ;

// ���L�̃f�o�C�X�R���e�L�X�g
extern HDC g_hWorkBuf ;

// �X�v���C�g
extern Sprite g_Spr[ BMP_DATA_SPR_MAX ] ;

// �}�b�v�f�[�^
extern int g_mapData01[ MAP_X * MAP_Y ] ;

// �`�b�v�e�[�u��
extern BitmapData g_bDataCBGTable[ BMP_DATA_CBG_MAX ] ;

// �`�b�v�e�[�u��
extern ChipBackGround g_CBG ;

// �}�b�v�f�[�^�f���o��
extern CreateData g_cmap ;

// pen
extern HPEN g_redPen ;

// brush
extern HBRUSH g_brush[ 4 ] ;

// scroll
extern int g_scroll ;

// chip select
extern int g_chip ;

// mouse
extern int g_mouseX, g_mouseY ;


