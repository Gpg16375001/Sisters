#pragma once
#include <windows.h>

namespace MasterData
{
	struct ANIMDATA {
		int		_bmpNo ;		// Bmpと対応しているナンバー
		int		_holdTime ;		// とどまるフレーム数
		float	_xpos ;			// X軸の位置
		float	_ypos ;			// Y軸の位置
		RECT	_rect ;			// 切り取り位置
		char	_mode[ 32 ] ;	// アニメーションのモード
	} ;

	class AnimInfo {
		public :
			void Load( const char* s ) ;
			ANIMDATA getData( void ) ;

		private :
			ANIMDATA _data ;

	} ;

}


