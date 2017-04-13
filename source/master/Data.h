#pragma once

namespace MasterData
{
	struct DATA {
		char name[80] ;
		int xpos ;
		int ypos ;
	} ;

	class DataInfo {
		public :
			void Load( const char* s ) ;
			DATA getData( void ) ;

		private :
			DATA _data ;

	} ;

}


