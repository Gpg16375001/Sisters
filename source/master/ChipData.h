#pragma once

namespace MasterData
{
	struct CHIPDATA {
		int		_mapNo ;		// MAPと対応しているナンバー
		float	_xpos ;			// X軸の位置
		float	_ypos ;			// Y軸の位置
		float	_upos ;			// U軸の位置
		float	_vpos ;			// V軸の位置
		float	_width ;		// 幅
		float	_height ;		// 高さ
	} ;

	class DataInfo {
		public :
			void Load( const char* s ) ;
			CHIPDATA getData( void ) ;

		private :
			CHIPDATA _data ;

	} ;

}


