#pragma once

namespace MasterData
{
	struct GIMMICKDATA {
		char	_name[ 32 ] ;	// ギミックの名前
		int		_bmpNo ;		// Bmpと対応しているナンバー
		float	_xpos ;			// X軸の位置
		float	_ypos ;			// Y軸の位置
		float	_off[ 2 ] ;		// オフセット
		char	_mode[ 32 ] ;	// ギミックのモード
	} ;

	class SceneGame01Info {
		public :
			void Load( const char* s ) ;
			GIMMICKDATA getData( void ) ;

		private :
			GIMMICKDATA _data ;

	} ;

}


