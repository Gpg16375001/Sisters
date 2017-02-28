/*
______________________________________________________________________________________________

	FILE	: SceneBase.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBaseƒNƒ‰ƒX


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>

class SceneBase
{
	public :
		/*/
		/*	 ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		SceneBase( ) { } ;

		/*/
		/*	 ƒfƒXƒgƒ‰ƒNƒ^
		/*/
		virtual ~SceneBase( ) { } ;

		/*/
		/*	 ‰Šú‰»
		/*/
		virtual void Initialize( ) = 0 ;

		/*/
		/*	 XV
		/*/
		virtual void Update( ) = 0 ;

		/*/
		/*	 •`‰æ
		/*/
		virtual void Render( ) = 0 ;

} ;


