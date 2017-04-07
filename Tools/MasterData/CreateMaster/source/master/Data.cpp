#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Data.h"

namespace MasterData
{
	void DataInfo::Load( const char* s )
	{
		sscanf( s , "%*[^,],%[^,],%d,%d" , name , &xpos , &ypos ) ;
	}

	void DataInfo::output( )
	{
		printf( "%-20s %6d %6d\n" , name , xpos , ypos ) ;
	}
}
