/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Gimmick::~Gimmick( )
{
	printf( "Gimmick was end.\n" ) ;
}

/*/
/*	‰Šú‰»
/*/
void Gimmick::Initialize( )
{
	printf( "Gimmick was created.\n" ) ;

	clearGimmickData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	I—¹‰»
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	clearGimmickData( ) ;
}

/*/
/*	‰Šú‰»
/*/
void Gimmick::clearGimmickData( )
{
	for ( int i = 0 ; i < MAX_GIMMICK_NO ; ++i )
	{
		GimmickData_[ i ]._useFlg	= false ;	// •`‰æ‚·‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
		GimmickData_[ i ]._bmpNo	= 0 ;		// ©•ª‚Ì—v‘f”Ô† ( _hBmp ‚ÆŠÖ˜A•t‚¯‚é‚½‚ß )
		GimmickData_[ i ]._anchor	= 0 ;		// ƒAƒ“ƒJ[‚ÌˆÊ’u
		GimmickData_[ i ]._x		= 0 ;
		GimmickData_[ i ]._y		= 0 ;		// ƒOƒ[ƒoƒ‹À•W
		GimmickData_[ i ]._u		= 0 ;
		GimmickData_[ i ]._v		= 0 ;		// Ø‚èæ‚èÀ•W
		GimmickData_[ i ]._w		= 0 ;
		GimmickData_[ i ]._h		= 0 ;		// •‚‚³
		GimmickData_[ i ]._arrayX	= 0 ;
		GimmickData_[ i ]._arrayY	= 0 ;		// ”z—ñÀ•W
		GimmickData_[ i ]._delay	= 0 ;		// ’x‚ê
		GimmickData_[ i ]._spd		= 0 ;		// ‘¬‚³
		GimmickData_[ i ]._Gimmick	= 0 ;		// ƒMƒ~ƒbƒN‚Ìí—Ş
		GimmickData_[ i ]._mode		= 0 ;		// ƒMƒ~ƒbƒN‚Ìƒ‚[ƒh
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// ƒIƒtƒZƒbƒg 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// ƒIƒtƒZƒbƒg 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// ƒIƒtƒZƒbƒg 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// ƒIƒtƒZƒbƒg 4
	}

}

/*/
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	/*/
	/*	‚¬‚Á‚İ‚Á‚­‚Ìí—Ş•ª‚¯
	/*/

	/*/
	/*	___/ “®‚­° /___________________
	/*/
	MoveFloor( ) ;

	/*/
	/*	___/ ‚Ü‚é‚Ì‚± /___________________
	/*/
	CircularSaws( ) ;

	/*/
	/*	___/ U‚èq /___________________
	/*/
	Pendulums( ) ;

	/*/
	/*	___/ “d‹C /___________________
	/*/
	Shockers( ) ;

	/*/
	/*	___/ SPPED UP /___________________
	/*/
	SpeedUp( ) ;

	/*/
	/*	___/ ‚­‚à /___________________
	/*/
	Clouds( ) ;

}



