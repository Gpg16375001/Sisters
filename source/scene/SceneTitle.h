/*
______________________________________________________________________________________________

	FILE	: SceneTitle.h

	________/ Explanation of file /___________________________________________________________
       
    SceneTitleNX

	^CgΜV[πμΑΔ’ιB

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <Windows.h>
#include "SceneBase.h"

struct SceneTitleParam : public SceneBaseParam
{

} ;

/*/
/*	 V[ΜξκNX
/*/
class SceneTitle
{
	public :
		~SceneTitle( ){ }

		/*/
		/*	 ϊ»
		/*/
		void Initialize( const SceneBaseParam* param ) ;

		/*/
		/*	 IΉ»
		/*/
		void Finalize( ) ;

		/*/
		/*	 XV
		/*
		/*	 @param df OΜt[ΖΜ·ͺΤ
		/*/
		void Update( ) ;

		/*/
		/*	 `ζ
		/*/
		void Render( ) ;

} ;



