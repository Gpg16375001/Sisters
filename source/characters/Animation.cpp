/*
______________________________________________________________________________________________

	FILE	: Animation.cpp

	________/ Explanation of file /___________________________________________________________
        
		AnimationNXΜΐ

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/*/
/*	RXgN^
/*/
Animation::Animation( )
{
	mp_animData = NULL ;
	memset( &m_nowAnimData, 0, sizeof( AnimationData ) ) ;
	m_animState = ANIM_STATE_STOP ;
	m_animCnt = 0 ;
}

/*/
/*	fXgN^
/*/
Animation::~Animation( )
{

}

/*/
/*	Aj[Vf[^ΜZbg
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
/*	Aj[VΜΔΆ
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
/*	Aj[VξρΜζΎ
/*/
int Animation::getAnimState( )
{
	return( m_animState ) ;
}

/*/
/*	»έΜAj[Vf[^ΜζΎ
/*/
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData ) ;
}



