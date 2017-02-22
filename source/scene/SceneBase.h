/*
______________________________________________________________________________________________

	FILE	: SceneBace.h

	________/ Explanation of file /___________________________________________________________
       
    SceneBaseƒNƒ‰ƒX

	ƒV[ƒ“‚Ì‘åŒ³‚ğì‚Á‚Ä‚¢‚éBå‚ÉŒp³‚µ‚Äg‚¤

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <Windows.h>

struct SceneBaseParam
{
	public :
		virtual ~SceneBaseParam( ){ }
} ;

/*/
/*	 ƒV[ƒ“‚ÌŠî’êƒNƒ‰ƒX
/*/
class SceneBase
{
	public :
		virtual ~SceneBase( ){ }

		/*/
		/*	 ‰Šú‰»
		/*/
		virtual void Initialize( const SceneBaseParam* param ){ }

		/*/
		/*	 I—¹‰»
		/*/
		virtual void Finalize( ){ }

		/*/
		/*	 XV
		/*
		/*	 @param df ‘O‚ÌƒtƒŒ[ƒ€‚Æ‚Ì·•ªŠÔ
		/*/
		virtual void Update( ){ }

		/*/
		/*	 •`‰æ
		/*/
		virtual void Render( ){ }

} ;



