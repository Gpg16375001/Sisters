#pragma once

namespace MasterData
{
	struct CHIPDATA {
		int		_mapNo ;		// MAP�ƑΉ����Ă���i���o�[
		float	_upos ;			// U���̈ʒu
		float	_vpos ;			// V���̈ʒu
		float	_width ;		// ��
		float	_height ;		// ����
		float	_off[ 3 ] ;		// �I�t�Z�b�g
	} ;

	class ChipDataInfo {
		public :
			void Load( const char* s ) ;
			CHIPDATA getData( void ) ;

		private :
			CHIPDATA _data ;

	} ;

}


