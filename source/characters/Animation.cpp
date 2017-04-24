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
int Animation::setAnimData( )
{
	auto it = MasterData::AnimPlayer.begin() ;

	m_nowAnimation.animMode = modeToNumber( it->getData()._mode ) ;
	m_nowAnimation.bmpNo = it->getData()._bmpNo ;
	m_nowAnimation.x = it->getData()._xpos ;
	m_nowAnimation.y = it->getData()._ypos ;
	m_nowAnimation.cutRect = it->getData()._rect ;
	m_nowAnimation.holdTime = it->getData()._holdTime ;
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
int Animation::_playAnim( )
{
	auto it = MasterData::AnimPlayer.begin() ;

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
				it += m_animCnt ;
				m_nowAnimation.animMode = modeToNumber( it->getData()._mode ) ;
				m_nowAnimation.bmpNo = it->getData()._bmpNo ;
				m_nowAnimation.x = it->getData()._xpos ;
				m_nowAnimation.y = it->getData()._ypos ;
				m_nowAnimation.cutRect = it->getData()._rect ;
				m_nowAnimation.holdTime = it->getData()._holdTime ;
			}
			else if( m_nowAnimation.animMode == ANIM_MODE_LOOP )
			{
				it = MasterData::AnimPlayer.begin() ;
				m_animCnt = 0 ;
				m_nowAnimation.animMode = modeToNumber( it->getData()._mode ) ;
				m_nowAnimation.bmpNo = it->getData()._bmpNo ;
				m_nowAnimation.x = it->getData()._xpos ;
				m_nowAnimation.y = it->getData()._ypos ;
				m_nowAnimation.cutRect = it->getData()._rect ;
				m_nowAnimation.holdTime = it->getData()._holdTime ;
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



