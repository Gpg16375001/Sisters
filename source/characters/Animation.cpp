/*
______________________________________________________________________________________________

	FILE	: Animation.cpp

	________/ Explanation of file /___________________________________________________________
        
		Animationクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/*/
/*	コンストラクタ
/*/
Animation::Animation( )
{
	mp_animData = NULL ;
	memset( &m_nowAnimData, 0, sizeof( AnimationData ) ) ;
	m_animState = ANIM_STATE_STOP ;
	m_animCnt = 0 ;
}

/*/
/*	デストラクタ
/*/
Animation::~Animation( )
{

}

/*/
/*	アニメーションデータのセット
/*/
int Animation::setAnimData( AnimationData *argp_animData )
{
	mp_animData = argp_animData ;
	m_animCnt = 0 ;
	m_nowAnimData = mp_animData[ m_animCnt ] ;
	m_animState = ANIM_STATE_PLAY ;

	return( true );
}

/*/
/*	外部からのアニメーションデータのセット
/*/
int Animation::setAnimData( int arg_no )
{
	auto itplayer1 = MasterData::AnimPlayer.begin() ;
	auto itplayer2 = MasterData::AnimPlayer2.begin() ;
	auto itwaiwai = MasterData::AnimWaiwai.begin() ;
	auto itboss = MasterData::AnimBoss.begin() ;

	if ( arg_no == 0 )
	{
		m_nowAnimation.animMode = modeToNumber( itplayer1->getData()._mode ) ;
		m_nowAnimation.bmpNo = itplayer1->getData()._bmpNo ;
		m_nowAnimation.x = itplayer1->getData()._xpos ;
		m_nowAnimation.y = itplayer1->getData()._ypos ;
		m_nowAnimation.cutRect = itplayer1->getData()._rect ;
		m_nowAnimation.holdTime = itplayer1->getData()._holdTime ;

	}

	if ( arg_no == 1 )
	{
		m_nowAnimation.animMode = modeToNumber( itplayer2->getData()._mode ) ;
		m_nowAnimation.bmpNo = itplayer2->getData()._bmpNo ;
		m_nowAnimation.x = itplayer2->getData()._xpos ;
		m_nowAnimation.y = itplayer2->getData()._ypos ;
		m_nowAnimation.cutRect = itplayer2->getData()._rect ;
		m_nowAnimation.holdTime = itplayer2->getData()._holdTime ;

	}

	if ( arg_no == 2 )
	{
		m_nowAnimation.animMode = modeToNumber( itwaiwai->getData()._mode ) ;
		m_nowAnimation.bmpNo = itwaiwai->getData()._bmpNo ;
		m_nowAnimation.x = itwaiwai->getData()._xpos ;
		m_nowAnimation.y = itwaiwai->getData()._ypos ;
		m_nowAnimation.cutRect = itwaiwai->getData()._rect ;
		m_nowAnimation.holdTime = itwaiwai->getData()._holdTime ;

	}

	if ( arg_no == 3 )
	{
		m_nowAnimation.animMode = modeToNumber( itboss->getData()._mode ) ;
		m_nowAnimation.bmpNo = itboss->getData()._bmpNo ;
		m_nowAnimation.x = itboss->getData()._xpos ;
		m_nowAnimation.y = itboss->getData()._ypos ;
		m_nowAnimation.cutRect = itboss->getData()._rect ;
		m_nowAnimation.holdTime = itboss->getData()._holdTime ;

	}

	m_animCnt = 0 ;
	m_animState = ANIM_STATE_PLAY ;


	return( true );
}

/*/
/*	モードを数字へ変える
/*/
int Animation::modeToNumber( char *arg_mode )
{
	int iRet = -1 ;
	
	if ( _strcmpi("ANIM_MODE_STOP" , arg_mode) == 0 )
	{
		iRet = ANIM_MODE_STOP ;
	}
	if ( _strcmpi("ANIM_MODE_NEXT" , arg_mode) == 0 )
	{
		iRet = ANIM_MODE_NEXT ;
	}
	if ( _strcmpi("ANIM_MODE_LOOP" , arg_mode) == 0 )
	{
		iRet = ANIM_MODE_LOOP ;
	}

	return( iRet );
}

/*/
/*	アニメーションの再生
/*/
int Animation::playAnim( )
{
	if( m_animState == ANIM_STATE_PLAY )
	{
		m_nowAnimData.holdTime-- ;
		if( m_nowAnimData.holdTime == 0 )
		{
			if( m_nowAnimData.animMode == ANIM_MODE_STOP )
			{
				m_animState = ANIM_STATE_STOP ;
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_NEXT )
			{
				m_animCnt++;
				m_nowAnimData = mp_animData[ m_animCnt ] ;
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_LOOP )
			{
				m_animCnt = 0;
				m_nowAnimData = mp_animData[ m_animCnt ] ;
			}
		}
	}

	return( true );
}

/*/
/*	外部データからのアニメーションの再生
/*/
int Animation::_playAnim( int arg_no )
{
	auto itplayer1 = MasterData::AnimPlayer.begin() ;
	auto itplayer2 = MasterData::AnimPlayer2.begin() ;
	auto itwaiwai = MasterData::AnimWaiwai.begin() ;
	auto itboss = MasterData::AnimBoss.begin() ;

	if ( arg_no == 0 )
	{
		if( m_animState == ANIM_STATE_PLAY )
		{
			m_nowAnimation.holdTime-- ;
			if( m_nowAnimation.holdTime == 0 )
			{
				if( m_nowAnimation.animMode == ANIM_MODE_STOP )
				{
					m_animState = ANIM_STATE_STOP ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_NEXT )
				{
					m_animCnt++;
					itplayer1 += m_animCnt ;
					m_nowAnimation.animMode = modeToNumber( itplayer1->getData()._mode ) ;
					m_nowAnimation.bmpNo = itplayer1->getData()._bmpNo ;
					m_nowAnimation.x = itplayer1->getData()._xpos ;
					m_nowAnimation.y = itplayer1->getData()._ypos ;
					m_nowAnimation.cutRect = itplayer1->getData()._rect ;
					m_nowAnimation.holdTime = itplayer1->getData()._holdTime ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_LOOP )
				{
					itplayer1 = MasterData::AnimPlayer.begin() ;
					m_animCnt = 0 ;
					m_nowAnimation.animMode = modeToNumber( itplayer1->getData()._mode ) ;
					m_nowAnimation.bmpNo = itplayer1->getData()._bmpNo ;
					m_nowAnimation.x = itplayer1->getData()._xpos ;
					m_nowAnimation.y = itplayer1->getData()._ypos ;
					m_nowAnimation.cutRect = itplayer1->getData()._rect ;
					m_nowAnimation.holdTime = itplayer1->getData()._holdTime ;
				}
			}
		}

	}
	if ( arg_no == 1 )
	{
		if( m_animState == ANIM_STATE_PLAY )
		{
			m_nowAnimation.holdTime-- ;
			if( m_nowAnimation.holdTime == 0 )
			{
				if( m_nowAnimation.animMode == ANIM_MODE_STOP )
				{
					m_animState = ANIM_STATE_STOP ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_NEXT )
				{
					m_animCnt++;
					itplayer2 += m_animCnt ;
					m_nowAnimation.animMode = modeToNumber( itplayer2->getData()._mode ) ;
					m_nowAnimation.bmpNo = itplayer2->getData()._bmpNo ;
					m_nowAnimation.x = itplayer2->getData()._xpos ;
					m_nowAnimation.y = itplayer2->getData()._ypos ;
					m_nowAnimation.cutRect = itplayer2->getData()._rect ;
					m_nowAnimation.holdTime = itplayer2->getData()._holdTime ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_LOOP )
				{
					itplayer2 = MasterData::AnimPlayer.begin() ;
					m_animCnt = 0 ;
					m_nowAnimation.animMode = modeToNumber( itplayer2->getData()._mode ) ;
					m_nowAnimation.bmpNo = itplayer2->getData()._bmpNo ;
					m_nowAnimation.x = itplayer2->getData()._xpos ;
					m_nowAnimation.y = itplayer2->getData()._ypos ;
					m_nowAnimation.cutRect = itplayer2->getData()._rect ;
					m_nowAnimation.holdTime = itplayer2->getData()._holdTime ;
				}
			}
		}

	}
	if ( arg_no == 2 )
	{
		if( m_animState == ANIM_STATE_PLAY )
		{
			m_nowAnimation.holdTime-- ;
			if( m_nowAnimation.holdTime == 0 )
			{
				if( m_nowAnimation.animMode == ANIM_MODE_STOP )
				{
					m_animState = ANIM_STATE_STOP ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_NEXT )
				{
					m_animCnt++;
					itwaiwai += m_animCnt ;
					m_nowAnimation.animMode = modeToNumber( itwaiwai->getData()._mode ) ;
					m_nowAnimation.bmpNo = itwaiwai->getData()._bmpNo ;
					m_nowAnimation.x = itwaiwai->getData()._xpos ;
					m_nowAnimation.y = itwaiwai->getData()._ypos ;
					m_nowAnimation.cutRect = itwaiwai->getData()._rect ;
					m_nowAnimation.holdTime = itwaiwai->getData()._holdTime ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_LOOP )
				{
					itwaiwai = MasterData::AnimPlayer.begin() ;
					m_animCnt = 0 ;
					m_nowAnimation.animMode = modeToNumber( itwaiwai->getData()._mode ) ;
					m_nowAnimation.bmpNo = itwaiwai->getData()._bmpNo ;
					m_nowAnimation.x = itwaiwai->getData()._xpos ;
					m_nowAnimation.y = itwaiwai->getData()._ypos ;
					m_nowAnimation.cutRect = itwaiwai->getData()._rect ;
					m_nowAnimation.holdTime = itwaiwai->getData()._holdTime ;
				}
			}
		}

	}
	if ( arg_no == 3 )
	{
		if( m_animState == ANIM_STATE_PLAY )
		{
			m_nowAnimation.holdTime-- ;
			if( m_nowAnimation.holdTime == 0 )
			{
				if( m_nowAnimation.animMode == ANIM_MODE_STOP )
				{
					m_animState = ANIM_STATE_STOP ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_NEXT )
				{
					m_animCnt++;
					itboss += m_animCnt ;
					m_nowAnimation.animMode = modeToNumber( itboss->getData()._mode ) ;
					m_nowAnimation.bmpNo = itboss->getData()._bmpNo ;
					m_nowAnimation.x = itboss->getData()._xpos ;
					m_nowAnimation.y = itboss->getData()._ypos ;
					m_nowAnimation.cutRect = itboss->getData()._rect ;
					m_nowAnimation.holdTime = itboss->getData()._holdTime ;
				}
				else if( m_nowAnimation.animMode == ANIM_MODE_LOOP )
				{
					itboss = MasterData::AnimPlayer.begin() ;
					m_animCnt = 0 ;
					m_nowAnimation.animMode = modeToNumber( itboss->getData()._mode ) ;
					m_nowAnimation.bmpNo = itboss->getData()._bmpNo ;
					m_nowAnimation.x = itboss->getData()._xpos ;
					m_nowAnimation.y = itboss->getData()._ypos ;
					m_nowAnimation.cutRect = itboss->getData()._rect ;
					m_nowAnimation.holdTime = itboss->getData()._holdTime ;
				}
			}
		}

	}

	return( true );
}

/*/
/*	アニメーション情報の取得
/*/
int Animation::getAnimState( )
{
	return( m_animState ) ;
}

/*/
/*	現在のアニメーションデータの取得
/*/
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData ) ;
}

/*/
/*	現在のアニメーションデータの取得
/*/
Anim_Data* Animation::getNowAnimation( )
{
	return( &m_nowAnimation ) ;
}



