/*
______________________________________________________________________________________________

	FILE : Renderer.h

	________/ Explanation of file /___________________________________________________________

		ƒrƒbƒgƒ}ƒbƒv‚Ì•`‰æ‚ğs‚¤ƒNƒ‰ƒX
		
			--- å‚Èg‚¢•û ---
			ƒCƒ“ƒXƒ^ƒ“ƒX1‚Â‚Å1–‡‚Ìƒrƒbƒgƒ}ƒbƒv‚ğ•`‰æ‚·‚éB
			selectBmp ‚É”wŒi—pƒrƒbƒgƒ}ƒbƒvƒe[ƒuƒ‹“à‚Ì•`‰æ‚µ‚½‚¢ƒrƒbƒgƒ}ƒbƒv‚Ìƒf[ƒ^‚Æ
			‘å‚«‚³‚ğ“n‚·‚±‚Æ‚ÅA•`‰æ‚·‚éƒrƒbƒgƒ}ƒbƒv‚Ì•ÏX‚ªs‚¦‚éB
			•`‰æ‚É‚Í Draw ƒƒ\ƒbƒh‚ğƒtƒŒ[ƒ€–ˆ‚ÉŒÄ‚Ño‚·‚±‚ÆB

			—á1. ‰æ‘œ‚ğƒZƒŒƒNƒg‚·‚é•û–@
			Renderer::GetInstance()->selectBmp( BmpData , width , height ) ;


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <windows.h>

/*/
/*	ƒNƒ‰ƒX‚ÌéŒ¾
/*/
class Renderer
{
	public :
		/*/
		/*	‰Šú‰»
		/*/
		void Initialize( ) ; 

		~Renderer( ) ;

		int selectBmp( HGDIOBJ arg_bmpData , int arg_width , int arg_height ) ;
		int Render( ) ;

		/*/
		/*	Shingleton -> ƒCƒ“ƒXƒ^ƒ“ƒX‚Ìæ“¾
		/*/
		static Renderer* GetInstance( )
		{
			static Renderer v ;
			return &v ;
		}

	private :	
		/*/
		/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		Renderer( ) {	}

		HGDIOBJ bmpData_ ;
		int width_ ;
		int height_ ;

} ;


