/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManager�N���X

	SceneManager�N���X

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
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
		/*	�f�X�g���N�^
		/*/
		~SceneManager( ) ;

		/*/
		/*	 ������
		/*/
		static void Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		static void Finalize( ) ;

		/*/
		/*	 �X�V �V�[���ύX
		/*/
		static void Update( int arg_state ) ;

		/*/
		/*	Shingleton -> �C���X�^���X�̎擾
		/*/
		static SceneManager* GetInstance( )
		{
			static SceneManager v ;
			return &v ;
		}

	private :
		/*/
		/*	�R���X�g���N�^
		/*/
		SceneManager( ) { } ;

} ;


