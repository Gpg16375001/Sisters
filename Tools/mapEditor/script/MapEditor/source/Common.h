
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
#include "BackDropScreen.h"
#include "BackGround.h"
#include "Sprite.h"
#include <math.h>
#include "SoundBGM.h"
#include "SoundSE.h"
#include "SceneLoop.h"
#include "DrawLoop.h"
#include "ChipBackGround.h"
#include "TimeProc.h"
#include "Player.h"
#include "Animation.h"
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

#define BGM_FILE_PASS_01 ( TEXT( "source/sound/bgm01.wav" ) )
#define SE_FILE_PASS_01 ( TEXT( "open source/sound/se01.wav alias se" ) )
#define SE_FILE_PASS_02 ( TEXT( "open source/sound/bomb1.wav alias se" ) )

#define MAP_X	25
#define MAP_Y	18

#define ANIM_DATA_MAX	128

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

/* -----------------------------------------------------------------------------------------
|
|       �O���Q�Ɛ錾
|
+ --------------------------------------------------------------------------------------- */
// --- �R���\�[���E�B���h�E
extern ConsoleWindow g_cWin;	

// --- �E�B���h�E�Ȃǂ̃^�C�g��
extern TCHAR g_szAppTitle[ ];
extern TCHAR g_szWndClass[ ];

// --- �C���X�^���X�n���h��
extern HINSTANCE g_hInstance;

// --- �E�C���h�E�n���h��
extern HWND g_hWindow;	

// --- �L�[�}�l�[�W���[
extern KeyManager g_key;

// �r�b�g�}�b�v�f�[�^
extern BitmapData g_bDataSprTable[ BMP_DATA_SPR_MAX ] ;	// �X�v���C�g�p
extern BitmapData g_bDataBGTable[ BMP_DATA_BG_MAX ] ;	// �w�i�p

// �o�b�N�o�b�t�@
extern HDC g_hBackBuf ;

// ���L�̃f�o�C�X�R���e�L�X�g
extern HDC g_hWorkBuf ;

// �o�b�N�h���b�v
extern BackDropScreen g_bScreen ;

// �o�b�N�O���E���h
extern BackGround g_bgScreen[ BMP_DATA_BG_MAX ] ;

// �X�v���C�g
extern Sprite g_Spr[ BMP_DATA_SPR_MAX ] ;

// BGM
extern SoundBGM g_sBGM ;

// SE
extern SoundSE g_sSE ;

// �V�[�����[�v
extern int g_sceneNo ;

// �}�b�v�f�[�^
extern int g_mapData01[ MAP_X * MAP_Y ] ;

// �`�b�v�e�[�u��
extern BitmapData g_bDataCBGTable[ BMP_DATA_CBG_MAX ] ;

// �`�b�v�e�[�u��
extern ChipBackGround g_CBG ;

// �v���C���[
extern Player g_player ;

// �}�b�v�f�[�^�f���o��
extern CreateData g_cmap ;


