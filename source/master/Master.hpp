#pragma once

#include <vector>
#include "ChipData.h"
#include "SceneGameData.h"
#include "AnimData.h"

namespace MasterData
{
	extern std::vector<ChipDataInfo> ChipData ;
	extern std::vector<SceneGameInfo> SceneAnim ;
	extern std::vector<SceneGameInfo> SceneGame01 ;
	extern std::vector<SceneGameInfo> SceneGame02 ;
	extern std::vector<SceneGameInfo> SceneGame03 ;
	extern std::vector<AnimInfo> AnimPlayer ;
	extern std::vector<AnimInfo> AnimPlayer2 ;
	extern std::vector<AnimInfo> AnimWaiwai ;
	extern std::vector<AnimInfo> AnimBoss ;

	void ReLoad( ) ;

}



