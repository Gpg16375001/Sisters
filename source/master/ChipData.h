#pragma once

namespace MasterData
{
	struct CHIPDATA {
		int		_mapNo ;		// MAP�ƑΉ����Ă���i���o�[
		float	_xpos ;			// X���̈ʒu
		float	_ypos ;			// Y���̈ʒu
		float	_upos ;			// U���̈ʒu
		float	_vpos ;			// V���̈ʒu
		float	_width ;		// ��
		float	_height ;		// ����
	} ;

	class DataInfo {
		public :
			void Load( const char* s ) ;
			CHIPDATA getData( void ) ;

		private :
			CHIPDATA _data ;

	} ;

}


