#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ChipData.h"

namespace MasterData
{
	void DataInfo::Load( const char* s )
	{
		//				ON | mapNo | x | y | u | v | width | height
		sscanf( s , "%*[^,],%d,%g,%g,%g,%g,%g,%g" ,
				&_data._mapNo ,
				&_data._xpos ,
				&_data._ypos ,
				&_data._upos ,
				&_data._vpos ,
				&_data._width ,
				&_data._height
			) ;
	}

	CHIPDATA DataInfo::getData( )
	{
		return( _data ) ;
	}

}


