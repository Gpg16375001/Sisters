/*
______________________________________________________________________________________________

	FILE	: SceneAnim01.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneAnim01ƒNƒ‰ƒX

	SceneAnim01ƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>
#include <stdio.h>
#include "Common.h"

class SceneAnim01
{
	public :
		/*/
		/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		SceneAnim01( ) ;

		/*/
		/*	ƒfƒXƒgƒ‰ƒNƒ^
		/*/
		~SceneAnim01( ) ;

		/*/
		/*	 ‰Šú‰»
		/*/
		void Initialize( ) ;

		/*/
		/*	 I—¹‰»
		/*/
		void Finalize( ) ;

		/*/
		/*	 XV
		/*/
		void Update( ) ;

		/*/
		/*	 •`‰æ
		/*/
		void Render( ) ;

		/*/
		/*	ReLoad GimmickData
		/*/
		void Reload( )
		{
			Initialize( ) ;
			Finalize( ) ;
			player_.setAnimData( 0 ) ;
			player2_.setAnimData( 1 ) ;
			waiwai_.setAnimData( 2 ) ;
			boss_.setAnimData( 3 ) ;
		}

	private :
		Animation	player_ ;
		Animation	player2_ ;
		Animation	waiwai_ ;
		Animation	boss_ ;
		float		_sx ;			// ƒXƒNƒ[ƒ‹

} ;


