/*
______________________________________________________________________________________________

	FILE	: SceneBase.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBase�N���X


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>

class SceneBase
{
	public :
		/*/
		/*	 �R���X�g���N�^
		/*/
		SceneBase( ) { } ;

		/*/
		/*	 �f�X�g���N�^
		/*/
		virtual ~SceneBase( ) { } ;

		/*/
		/*	 ������
		/*/
		virtual void Initialize( ) = 0 ;

		/*/
		/*	 �X�V
		/*/
		virtual void Update( ) = 0 ;

		/*/
		/*	 �`��
		/*/
		virtual void Render( ) = 0 ;

} ;


