/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManagerNX

	SceneManagerNX

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
			S_InitGame ,
			S_PlayGame ,
		} ;

		/*/
		/*	fXgN^
		/*/
		~SceneManager( ) ;

		/*/
		/*	 ú»
		/*/
		static void Initialize( ) ;

		/*/
		/*	 I¹»
		/*/
		static void Finalize( ) ;

		/*/
		/*	 XV V[ÏX
		/*/
		static void Update( int arg_state ) ;

		/*/
		/*	Shingleton -> CX^XÌæ¾
		/*/
		static SceneManager* GetInstance( )
		{
			static SceneManager v ;
			return &v ;
		}

	private :
		/*/
		/*	RXgN^
		/*/
		SceneManager( ) { } ;

} ;


