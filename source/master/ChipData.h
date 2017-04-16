#pragma once

namespace MasterData
{
	struct CHIPDATA {
		int		_mapNo ;		// MAPと対応しているナンバー
		float	_upos ;			// U軸の位置
		float	_vpos ;			// V軸の位置
		float	_width ;		// 幅
		float	_height ;		// 高さ
		float	_off[ 3 ] ;		// オフセット
	} ;

	class ChipDataInfo {
		public :
			void Load( const char* s ) ;
			CHIPDATA getData( void ) ;

		private :
			CHIPDATA _data ;

	} ;

}


