/*
______________________________________________________________________________________________

	FILE	: SceneManager.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneManager�N���X

	SceneManager�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "LoadMapData.h"
#include "SceneBlank.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneGame02.h"
#include "SceneGame03.h"
#include "SceneAnim01.h"

#define		MAP01	TEXT("data/map/mapData01.txt")
#define		MAP02	TEXT("data/map/mapData02.txt")
#define		MAP03	TEXT("data/map/mapData03.txt")
#define		MAP04	TEXT("data/map/mapData04.txt")

#define		SCENE_ANIM01	0
#define		SCENE_GAME01	1
#define		SCENE_GAME02	2
#define		SCENE_GAME03	3

/*/
/*	 ������
/*/
void SceneManager::Initialize( )
{
	Finalize( ) ;
	printf( "SceneManager\n" ) ;
	g_state = -1 ;						// ------------------------- Gvl
}

/*/
/*	 �I����
/*/
void SceneManager::Finalize( )
{
	
}

/*/
/*	�f�X�g���N�^
/*/
SceneManager::~SceneManager( )
{
	Finalize( ) ;
}

/*/
/*	 �X�V
/*/
void SceneManager::Update( int arg_state )
{
	SceneBlank blank ;
	SceneTitle title ;
	SceneGame01 game01 ;
	SceneGame02 game02 ;
	SceneGame03 game03 ;
	static SceneAnim01 anim01 ;

	// �V�[�����e
	switch ( arg_state )
	{
		case S_Blank :
			blank.Update( ) ;
			blank.Render( ) ;
			break ;

		case S_InitTitle :
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				g_state++ ;
			}
			break ;

		case S_PlayTitle :
			SceneCut::GetInstance()->fadeOut( ) ;
			title.Update( ) ;
			title.Render( ) ;
			break ;

		case S_InitAnim01 :
			// �t�F�C�h�̃Z�b�g
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// �}�b�v�ǂݍ���
				LoadMapData::ReLoad( MAP04 ) ;

				// �M�~�b�N�̏����Z�b�g
				Gimmick::GetInstance()->Initialize( ) ;

				// �M�~�b�N���Z�b�g
				Gimmick::GetInstance()->setGimmickData( SCENE_ANIM01 ) ;

				// �A�j���̏�����
				anim01.Initialize( ) ;

				g_state++ ;
			}
			break ;

		case S_PlayAnim01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			anim01.Update( ) ;
			anim01.Render( ) ;
			break ;

		case S_InitGame01 :
			// �t�F�C�h�̃Z�b�g
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// �}�b�v�ǂݍ���
				LoadMapData::ReLoad( MAP01 ) ;

				// �M�~�b�N�̏����Z�b�g
				Gimmick::GetInstance()->Initialize( ) ;

				// �M�~�b�N���Z�b�g
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME01 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayGame01 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game01.Update( ) ;
			game01.Render( ) ;
			break ;

		case S_InitGame02 :
			// �t�F�C�h�̃Z�b�g
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// �}�b�v�ǂݍ���
				LoadMapData::ReLoad( MAP02 ) ;

				// �M�~�b�N�̏����Z�b�g
				Gimmick::GetInstance()->Initialize( ) ;

				// �M�~�b�N���Z�b�g
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME02 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayGame02 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game02.Update( ) ;
			game02.Render( ) ;
			break ;

		case S_InitGame03 :
			// �t�F�C�h�̃Z�b�g
			if ( SceneCut::GetInstance()->fadeIn( ) == 1 )
			{
				// �}�b�v�ǂݍ���
				LoadMapData::ReLoad( MAP03 ) ;

				// �M�~�b�N�̏����Z�b�g
				Gimmick::GetInstance()->Initialize( ) ;

				// �M�~�b�N���Z�b�g
				Gimmick::GetInstance()->setGimmickData( SCENE_GAME03 ) ;

				g_state++ ;
			}
			break ;

		case S_PlayGame03 :
			SceneCut::GetInstance()->fadeOut( ) ;
			game03.Update( ) ;
			game03.Render( ) ;
			break ;

	}

	/*/
	/*	�V�[���؂�ւ����̊G��`��
	/*/
	for ( int i = 0 ; i < SceneCut::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( SceneCut::GetInstance()->getUseFlg( i ) )
		{
			Renderer::GetInstance()->selectBmp(
					SceneCut::GetInstance()->getBmpData( i ) ,
					0 ,
					SceneCut::GetInstance()->getBmpXPos( i ) ,
					SceneCut::GetInstance()->getBmpYPos( i ) ,
					0 ,
					0 ,
					SceneCut::GetInstance()->getBmpWidth( i ) ,
					SceneCut::GetInstance()->getBmpHeight( i ) ,
					1.0f ,
					1.0f ,
					SceneCut::GetInstance()->getBmpAlpha( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

}



