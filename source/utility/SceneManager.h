/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerƒNƒ‰ƒX

	SceneManagerƒNƒ‰ƒX

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include <stdio.h>

class SceneManager
{
	public :
		enum Scenes {
			S_Blank = -1 ,
			S_InitTitle = 0 ,
			S_PlayTitle ,
			S_InitGame01 ,
			S_PlayGame01 ,
			S_InitGame02 ,
			S_PlayGame02 ,
			S_InitGame03 ,
			S_PlayGame03 ,
		} ;

		/*/
		/*	ƒfƒXƒgƒ‰ƒNƒ^
		/*/
		~SceneManager( ) ;

		/*/
		/*	 ‰Šú‰»
		/*/
		static void Initialize( ) ;

		/*/
		/*	 I—¹‰»
		/*/
		static void Finalize( ) ;

		/*/
		/*	 XV ƒV[ƒ“•ÏX
		/*/
		static void Update( int arg_state ) ;

		/*/
		/*	Shingleton -> ƒCƒ“ƒXƒ^ƒ“ƒX‚Ìæ“¾
		/*/
		static SceneManager* GetInstance( )
		{
			static SceneManager v ;
			return &v ;
		}

	private :
		/*/
		/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		SceneManager( ) { } ;

} ;


