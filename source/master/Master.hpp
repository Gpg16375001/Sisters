#pragma once

#include <vector>
#include "ChipData.h"
#include "SceneGame01Data.h"
#include "AnimData.h"

namespace MasterData
{
	extern std::vector<ChipDataInfo> ChipData ;
	extern std::vector<SceneGame01Info> SceneGame01 ;
	extern std::vector<AnimInfo> AnimPlayer ;

	void ReLoad( ) ;

}



