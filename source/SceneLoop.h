/*
______________________________________________________________________________________________

	FILE	: SceneLoop.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneLoop�N���X

	SceneLoop�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <Windows.h>

class SceneLoop {
	public :
		/*/
		/*	 ������
		/*/
		void SceneLoop::Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		void SceneLoop::Finalize( ) ;

		/*/
		/*	 �X�V
		/*/
		void SceneLoop::Update( ) ;

		/*/
		/*	 �`��
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


