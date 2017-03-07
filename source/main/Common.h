#pragma once

#include "ConsoleWindow.h"
#include "KeyManager.h"
#include "BitmapData.h"
#include "Renderer.h"
#include "BackGround.h"
#include "Sprite.h"
#include "Chip.h"
#include "SceneManager.h"
#include "../characters/Physics.h"
#include "../characters/Player.h"

extern int g_mapData01[ 64 * 12 ] ;
extern int g_state ;

extern float g_px , g_py ;		// �f�o�b�O�p �v���C���[�̍��W
extern int g_bx1 , g_by1 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 1
extern int g_bx2 , g_by2 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 2
extern int g_bx3 , g_by3 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 3
extern int g_bx4 , g_by4 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 4
extern int g_bx5 , g_by5 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 5
extern int g_bx6 , g_by6 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 6
extern int g_bx7 , g_by7 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 7 
extern int g_bx8 , g_by8 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 8 
extern int g_bx9 , g_by9 ;	// �f�o�b�O�p �u���b�N�̂����蔻��̍��W 9

extern int fpscnt ;



