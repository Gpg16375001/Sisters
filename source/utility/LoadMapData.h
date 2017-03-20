#include <vector>
																					
namespace LoadMapData																
{
	class DataInfo {
		public :
			void Load( const char* s )
			{
				sscanf( s , "%d," , &chipNo_ ) ;
			}

			int getChipNo( void ) const {
				return( chipNo_ ) ;
			}

		private :																	
			int chipNo_ ;

	} ;																				

	void ReLoad( TCHAR *arg_path ) ;

}


