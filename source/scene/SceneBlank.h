/*
______________________________________________________________________________________________

	FILE	: SceneBlank.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneBlank�N���X

	SceneBlank�N���X�̎�����


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>
#include "Common.h"

class SceneBlank
{
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		SceneBlank( ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		~SceneBlank( ) ;

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

} ;


