#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "SceneGameData.h"

namespace MasterData
{
	void SceneGameInfo::Load( const char* s )
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

	GIMMICKDATA SceneGameInfo::getData( )
	{
		return( _data ) ;
	}

}


