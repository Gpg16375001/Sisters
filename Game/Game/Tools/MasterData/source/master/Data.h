#pragma once

namespace MasterData
{
	class DataInfo {
		public :
			void Load( const char* s ) ;
			void output( void ) ;

		private :
			char name[80] ;
			int xpos ;
			int ypos ;
	} ;
}
