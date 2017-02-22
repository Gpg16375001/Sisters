/*
______________________________________________________________________________________________

	FILE	: SceneTitle.h

	________/ Explanation of file /___________________________________________________________
       
    SceneTitleƒNƒ‰ƒX

	ƒ^ƒCƒgƒ‹‚ÌƒV[ƒ“‚ğì‚Á‚Ä‚¢‚éB

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <Windows.h>
#include "SceneBase.h"

struct SceneTitleParam : public SceneBaseParam
{

} ;

/*/
/*	 ƒV[ƒ“‚ÌŠî’êƒNƒ‰ƒX
/*/
class SceneTitle
{
	public :
		~SceneTitle( ){ }

		/*/
		/*	 ‰Šú‰»
		/*/
		void Initialize( const SceneBaseParam* param ) ;

		/*/
		/*	 I—¹‰»
		/*/
		void Finalize( ) ;

		/*/
		/*	 XV
		/*
		/*	 @param df ‘O‚ÌƒtƒŒ[ƒ€‚Æ‚Ì·•ªŠÔ
		/*/
		void Update( ) ;

		/*/
		/*	 •`‰æ
		/*/
		void Render( ) ;

} ;



