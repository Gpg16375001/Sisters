/*
______________________________________________________________________________________________

	FILE	: SceneLoop.cpp

	________/ Explanation of file /___________________________________________________________
       
    SceneLoopNX

	SceneLoopNXΜΐ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
#include <Windows.h>


/*/
/*	 ϊ»
/*/
void SceneLoop::Initialize( )
{
	printf( "SceneLoop" ) ;
	state_ = SceneBlank ;
}

/*/
/*	 IΉ»
/*/
void SceneLoop::Finalize( )
{

}

/*/
/*	 XV
/*/
void SceneLoop::Update( )
{
	// V[ΰe
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
/*	 `ζ
/*/
void SceneLoop::Render( )
{
	// `ζ·ι`ζ¨
	for ( int i = 0 ; i < BitmapData::GetInstance()->getMaxBmp( ) ; ++i )
	{
		if ( BitmapData::GetInstance()->getUseFlg( i ) )
		{
			printf( "`ζ      BMPΤ F%4d \n" , i ) ;
			printf( "§Ύ  true=1  F%4d \n" , BitmapData::GetInstance()->getUseAlpha( i ) ) ;
			printf( "§Ύx    alpha   F%4d \n" , BitmapData::GetInstance()->getBmpAlpha( i ) ) ;
			printf( "ρ]  true=1  F%4d \n" , BitmapData::GetInstance()->getUseRotate( i ) ) ;
			printf( "ρ]px  angle   F%4.0f \n" , BitmapData::GetInstance()->getBmpAngle( i ) ) ;
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



