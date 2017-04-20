#pragma once

namespace MasterData
{
	struct LOOPANIM {
		char	_name[ 32 ] ;	// ギミックの名前
		int		_bmpNo ;		// Bmpと対応しているナンバー
		float	_holdTime ;		// とどまるフレーム数
		float	_RECT ;			// 切り取り位置
		char	_mode[ 32 ] ;	// モード
	} ;

	struct ANIMDATA {
		char	_name[ 32 ] ;	// アニメーションの名前
		int		_bmpNo ;		// Bmpと対応しているナンバー
		float	_holdTime ;		// とどまるフレーム数
		float	_xpos ;			// X軸の位置
		float	_ypos ;			// Y軸の位置
		float	_RECT ;			// 切り取り位置
	} ;

	class AnimInfo {
		public :
			void Load( const char* s ) ;
			ANIMDATA getData( void ) ;

		private :
			ANIMDATA _data ;

	} ;

}


