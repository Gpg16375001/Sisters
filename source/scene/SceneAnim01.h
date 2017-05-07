/*
______________________________________________________________________________________________

	FILE	: SceneAnim01.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneAnim01�N���X

	SceneAnim01�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>
#include "Common.h"

class SceneAnim01
{
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		SceneAnim01( ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		~SceneAnim01( ) ;

		/*/
		/*	 ������
		/*/
		void Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		void Finalize( ) ;

		/*/
		/*	 �X�V
		/*/
		void Update( ) ;

		/*/
		/*	 �`��
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
		float		_sx ;			// �X�N���[��

} ;


