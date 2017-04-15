#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ChipData.h"

namespace MasterData
{
	void DataInfo::Load( const char* s )
	{
		//				ON | mapNo | u | v | width | height | off[0] | off[1] | off[2]
		sscanf( s , "%*[^,],%d,%g,%g,%g,%g,%g,%g,%g" ,
				&_data._mapNo ,
				&_data._upos ,
				&_data._vpos ,
				&_data._width ,
				&_data._height ,
				&_data._off[ 0 ] ,
				&_data._off[ 1 ] ,
				&_data._off[ 2 ]
			) ;
	}

	CHIPDATA DataInfo::getData( )
	{
		return( _data ) ;
	}

}


