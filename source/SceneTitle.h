/*
______________________________________________________________________________________________

	FILE	: SceneTitle.h

	________/ Explanation of file /___________________________________________________________
       
    SceneTitle�N���X

	�^�C�g���̃V�[��������Ă���B

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <Windows.h>
#include "SceneBase.h"

struct SceneTitleParam : public SceneBaseParam
{

} ;

/*/
/*	 �V�[���̊��N���X
/*/
class SceneTitle
{
	public :
		~SceneTitle( ){ }

		/*/
		/*	 ������
		/*/
		void Initialize( const SceneBaseParam* param ) ;

		/*/
		/*	 �I����
		/*/
		void Finalize( ) ;

		/*/
		/*	 �X�V
		/*
		/*	 @param df �O�̃t���[���Ƃ̍�������
		/*/
		void Update( ) ;

		/*/
		/*	 �`��
		/*/
		void Render( ) ;

} ;



