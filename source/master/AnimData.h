#pragma once

namespace MasterData
{
	struct LOOPANIM {
		char	_name[ 32 ] ;	// �M�~�b�N�̖��O
		int		_bmpNo ;		// Bmp�ƑΉ����Ă���i���o�[
		float	_holdTime ;		// �Ƃǂ܂�t���[����
		float	_RECT ;			// �؂���ʒu
		char	_mode[ 32 ] ;	// ���[�h
	} ;

	struct ANIMDATA {
		char	_name[ 32 ] ;	// �A�j���[�V�����̖��O
		int		_bmpNo ;		// Bmp�ƑΉ����Ă���i���o�[
		float	_holdTime ;		// �Ƃǂ܂�t���[����
		float	_xpos ;			// X���̈ʒu
		float	_ypos ;			// Y���̈ʒu
		float	_RECT ;			// �؂���ʒu
	} ;

	class AnimInfo {
		public :
			void Load( const char* s ) ;
			ANIMDATA getData( void ) ;

		private :
			ANIMDATA _data ;

	} ;

}


