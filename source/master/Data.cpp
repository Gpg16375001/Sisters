#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Data.h"

namespace MasterData
{
	void DataInfo::Load( const char* s )
	{
		sscanf( s , "%*[^,],%[^,],%d,%d" , _data.name , &_data.xpos , &_data.ypos ) ;
	}

	DATA DataInfo::getData( )
	{
		return( _data ) ;
	}
}
