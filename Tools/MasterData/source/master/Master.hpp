#pragma once
#include <vector>
#include "Data.h"
#include "Title.h"

namespace MasterData
{
	extern std::vector<DataInfo> Data ;
	extern std::vector<TitleInfo> Title ;

	void ReLoad(const char* s) ;

}



