#include "Common.h"


// マップデータ
int g_mapData01[ CHIP_MAP_SIZE_X * CHIP_MAP_SIZE_Y ] = { 0 } ;

int g_state ;

float g_px , g_py ;		// デバッグ用 プレイヤーの座標

RECT g_ac ;

bool g_dethflg = true ;


