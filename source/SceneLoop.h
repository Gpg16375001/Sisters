/*
______________________________________________________________________________________________

	FILE	: SceneLoop.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneLoopÉNÉâÉX

	SceneLoopÉNÉâÉXÇÃé¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/
#include <Windows.h>

class SceneLoop {
	public :
		/*/
		/*	 èâä˙âª
		/*/
		void SceneLoop::Initialize( ) ;

		/*/
		/*	 èIóπâª
		/*/
		void SceneLoop::Finalize( ) ;

		/*/
		/*	 çXêV
		/*/
		void SceneLoop::Update( ) ;

		/*/
		/*	 ï`âÊ
		/*/
		void SceneLoop::Render( ) ;

	private :
		enum Scenes {
			SceneBlank = -1 ,
			SceneInitTitle = 0 ,
			ScenePlayTitle ,
			SceneInitGame ,
			ScenePlayGame ,
		} ;
		Scenes state_ ;

} ;


