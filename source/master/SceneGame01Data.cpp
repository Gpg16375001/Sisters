#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "SceneGame01Data.h"

namespace MasterData
{
	void SceneGame01Info::Load( const char* s )
	{
		//				ON | name | bmpNo | x | y | off[0] | off[1] | mode
		sscanf( s , "%*[^,],%[^,],%d,%g,%g,%g,%g,%[^,\n]" ,
				_data._name ,
				&_data._bmpNo ,
				&_data._xpos ,
				&_data._ypos ,
				&_data._off[ 0 ] ,
				&_data._off[ 1 ] ,
				_data._mode
			) ;
	}

	GIMMICKDATA SceneGame01Info::getData( )
	{
		return( _data ) ;
	}

}


