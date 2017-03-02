/*
______________________________________________________________________________________________

	FILE	: Player.cpp

	________/ Explanation of file /___________________________________________________________
       
    PlayerNX

	PlayerNXΜΐ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include <stdio.h>

class Player
{
	public :
		/*/
		/*	RXgN^
		/*/
		Player( ) ;

		/*/
		/*	fXgN^
		/*/
		~Player( ) ;

		/*/
		/*	 ϊ»
		/*/
		void Initialize( ) ;

		/*/
		/*	 IΉ»
		/*/
		void Finalize( ) ;

		void PlayerAction( ) ;

		void Pinit( ) ;		// ϊ
		void Pstop( ) ;		// ~άθ
		void Pwalk( ) ;		// ΆEΰ«
		void Pjinit( ) ;	// Wvϊ»
		void Pjump( ) ;		// WvΖΊ

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


