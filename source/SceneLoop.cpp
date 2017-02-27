/*
______________________________________________________________________________________________

	FILE	: SceneLoop.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneLoop�N���X

	SceneLoop�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <Windows.h>


/*/
/*	 ������
/*/
void SceneLoop::Initialize( )
{
	printf( "SceneLoop" ) ;
	state_ = SceneBlank ;
}

/*/
/*	 �I����
/*/
void SceneLoop::Finalize( )
{

}

/*/
/*	 �X�V
/*/
void SceneLoop::Update( )
{
	// �V�[�����e
	switch ( state_ )
	{
		case SceneBlank :
			g_chipData.setChip( 1 , 0 , 2 ) ;
			g_chipData.setChip( 2 , 0 , 2 ) ;
			g_chipData.setChip( 3 , 0 , 2 ) ;
			g_chipData.Update( ) ;
			break ;

		case SceneInitTitle :
			break ;

		case ScenePlayTitle :
			break ;

		case SceneInitGame :
			break ;

		case ScenePlayGame :
			break ;

	}
}

/*/
/*	 �`��
/*/
void SceneLoop::Render( )
{
	// �`�悷��`�敨
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BitmapData::GetInstance()->getUseFlg( i ) )
		{
			printf( "�`��      BMP�ԍ� �F%4d \n" , i ) ;
			printf( "��������  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseAlpha( i ) ) ;
			printf( "�����x    alpha   �F%4d \n" , BitmapData::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "��]����  true=1  �F%4d \n" , BitmapData::GetInstance()->getUseRotate( i ) ) ;
			printf( "��]�p�x  angle   �F%4.0f \n" , BitmapData::GetInstance()->getBmpAngle( i ) ) ;
			Renderer::GetInstance()->selectBmp(
					BitmapData::GetInstance()->getBmpData( i ) ,
					BitmapData::GetInstance()->getBmpAnchor( i ) ,
					BitmapData::GetInstance()->getBmpXPos( i ) ,
					BitmapData::GetInstance()->getBmpYPos( i ) ,
					BitmapData::GetInstance()->getBmpUPos( i ) ,
					BitmapData::GetInstance()->getBmpVPos( i ) ,
					BitmapData::GetInstance()->getBmpWidth( i ) ,
					BitmapData::GetInstance()->getBmpHeight( i ) ,
					BitmapData::GetInstance()->getBmpScaleX( i ) ,
					BitmapData::GetInstance()->getBmpScaleY( i ) ,
					BitmapData::GetInstance()->getBmpAlpha( i ) ,
					BitmapData::GetInstance()->getBmpAngle( i )
				) ;
			Renderer::GetInstance()->Render( ) ;
		}
	}

	g_chipData.Render( ) ;


}



