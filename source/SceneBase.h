/*
______________________________________________________________________________________________

	FILE	: SceneBace.h

	________/ Explanation of file /___________________________________________________________
       
    SceneBase�N���X

	�V�[���̑匳������Ă���B��Ɍp�����Ďg��

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <Windows.h>

struct SceneBaseParam
{
	public :
		virtual ~SceneBaseParam( ){ }
} ;

/*/
/*	 �V�[���̊��N���X
/*/
class SceneBase
{
	public :
		virtual ~SceneBase( ){ }

		/*/
		/*	 ������
		/*/
		virtual void Initialize( const SceneBaseParam* param ){ }

		/*/
		/*	 �I����
		/*/
		virtual void Finalize( ){ }

		/*/
		/*	 �X�V
		/*
		/*	 @param df �O�̃t���[���Ƃ̍�������
		/*/
		virtual void Update( ){ }

		/*/
		/*	 �`��
		/*/
		virtual void Render( ){ }

} ;



