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

		bool FootCheck( ) ;	// «³`FbN
		bool Collision( ) ;	//  ½θ»θ

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

		float	Player_xpos_ ;
		float	Player_ypos_ ;
		float	Player_xspd_ ;
		float	Player_yspd_ ;
		int		arrayX_ ;
		int		arrayY_ ;

} ;


