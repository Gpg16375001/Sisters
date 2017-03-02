/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    PlayerƒNƒ‰ƒX

	PlayerƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include <stdio.h>

class Player
{
	public :
		/*/
		/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		Player( ) ;

		/*/
		/*	ƒfƒXƒgƒ‰ƒNƒ^
		/*/
		~Player( ) ;

		/*/
		/*	 ‰Šú‰»
		/*/
		void Initialize( ) ;

		/*/
		/*	 I—¹‰»
		/*/
		void Finalize( ) ;

		void PlayerAction( ) ;

		void Pinit( ) ;		// ‰Šú
		void Pstop( ) ;		// ~‚Ü‚è
		void Pwalk( ) ;		// ¶‰E•à‚«
		void Pjinit( ) ;	// ƒWƒƒƒ“ƒv‰Šú‰»
		void Pjump( ) ;		// ƒWƒƒƒ“ƒv‚Æ—‰º

		/*/
		/*	 XV
		/*/
		void Update( ) ;

	private :
		enum PlayerMode {
			P_init = -1 ,
			P_stop = 0 ,
			P_walk ,
			P_jinit ,
			P_jump ,
			P_drop ,
		} ;
		PlayerMode Pmode_ ;

} ;


