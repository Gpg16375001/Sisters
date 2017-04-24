#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "AnimData.h"

namespace MasterData
{
	void AnimInfo::Load( const char* s )
	{
		//				ON | bmpNo | holdTime | x | y | (RECT)Left | (R)Top | (R)Right  | (R)Bottom  | mode
		sscanf( s , "%*[^,],%d,%d,%g,%g,%d,%d,%d,%d,%[^,\n]" ,
				&_data._bmpNo ,
				&_data._holdTime ,
				&_data._xpos ,
				&_data._ypos ,
				&_data._rect.left ,		// UPos
				&_data._rect.top ,		// VPos
				&_data._rect.right ,	// Width
				&_data._rect.bottom ,	// Height
				_data._mode
			) ;
	}

	ANIMDATA AnimInfo::getData( )
	{
		return( _data ) ;
	}

}


