/*
______________________________________________________________________________________________

	FILE	: Collider.h

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
class Collider
{
	// ŒöŠJ•Ï”‚Æƒƒ“ƒoŠÖ”
	public:
		/*/
		/*	‰Šú‰»
		/*/
		void Initialize( ) ; 

		~Collider( ) ;							// ƒfƒXƒgƒ‰ƒNƒ^
		void update( ) ;						// î•ñ‚ÌXV

		bool getFootCheck( ) ;

		/*/
		/*	Shingleton -> ƒCƒ“ƒXƒ^ƒ“ƒX‚Ìæ“¾
		/*/
		static Collider* GetInstance( )
		{
			static Collider v ;
			return &v ;
		}

	// ”ñŒöŠJ•Ï”‚Æƒƒ“ƒoŠÖ”
	private:
		// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		Collider( )
		{
		} ;

	private :


};

