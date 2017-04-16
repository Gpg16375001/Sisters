#pragma once

namespace MasterData
{
	struct GIMMICKDATA {
		char	_name[ 32 ] ;	// �M�~�b�N�̖��O
		int		_bmpNo ;		// Bmp�ƑΉ����Ă���i���o�[
		float	_xpos ;			// X���̈ʒu
		float	_ypos ;			// Y���̈ʒu
		float	_off[ 2 ] ;		// �I�t�Z�b�g
		char	_mode[ 32 ] ;	// �M�~�b�N�̃��[�h
	} ;

	class SceneGame01Info {
		public :
			void Load( const char* s ) ;
			GIMMICKDATA getData( void ) ;

		private :
			GIMMICKDATA _data ;

	} ;

}


