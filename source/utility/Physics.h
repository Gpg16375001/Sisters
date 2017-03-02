/*
______________________________________________________________________________________________

	FILE	: Physics.h

	________/ Explanation of file /___________________________________________________________
 
		•¨—“I‚È‚±‚Æ‚ğs‚¤ƒNƒ‰ƒX

			--- å‚Èg‚¢•û ---


			—áE


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>

/*/
/*	ƒNƒ‰ƒX‚ÌéŒ¾
/*/
class Physics
{
	// ŒöŠJ•Ï”‚Æƒƒ“ƒoŠÖ”
	public:
		/*/
		/*	‰Šú‰»
		/*/
		void Initialize( ) ; 

		~Physics( ) ;							// ƒfƒXƒgƒ‰ƒNƒ^
		void update( ) ;						// î•ñ‚ÌXV

		float getGravity( )
		{
			return( gravity_ ) ;
		}

		/*/
		/*	Shingleton -> ƒCƒ“ƒXƒ^ƒ“ƒX‚Ìæ“¾
		/*/
		static Physics* GetInstance( )
		{
			static Physics v ;
			return &v ;
		}

	// ”ñŒöŠJ•Ï”‚Æƒƒ“ƒoŠÖ”
	private:
		// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		Physics( )
			: gravity_( 9.81f )
		{
		} ;

	private :
		float gravity_ ;

};

