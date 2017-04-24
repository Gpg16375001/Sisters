#pragma once
#include <windows.h>

namespace MasterData
{
	struct ANIMDATA {
		int		_bmpNo ;		// Bmp�ƑΉ����Ă���i���o�[
		int		_holdTime ;		// �Ƃǂ܂�t���[����
		float	_xpos ;			// X���̈ʒu
		float	_ypos ;			// Y���̈ʒu
		RECT	_rect ;			// �؂���ʒu
		char	_mode[ 32 ] ;	// �A�j���[�V�����̃��[�h
	} ;

	class AnimInfo {
		public :
			void Load( const char* s ) ;
			ANIMDATA getData( void ) ;

		private :
			ANIMDATA _data ;

	} ;

}


