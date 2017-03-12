/*
______________________________________________________________________________________________

	FILE	: Animation.cpp

	________/ Explanation of file /___________________________________________________________
        
		AnimationƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/*/
/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
/*/
Animation::Animation( )
{
	mp_animData = NULL ;
	memset( &m_nowAnimData, 0, sizeof( AnimationData ) ) ;
	m_animState = ANIM_STATE_STOP ;
	m_animCnt = 0 ;
}

/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Animation::~Animation( )
{

}
	
/*/
/*	ƒAƒjƒ[ƒVƒ‡ƒ“ƒf[ƒ^‚ÌƒZƒbƒg
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
/*	ƒAƒjƒ[ƒVƒ‡ƒ“‚ÌÄ¶
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
/*	ƒAƒjƒ[ƒVƒ‡ƒ“î•ñ‚Ìæ“¾
/*/
int Animation::getAnimState( )
{
	return( m_animState ) ;
}

/*/
/*	Œ»İ‚ÌƒAƒjƒ[ƒVƒ‡ƒ“ƒf[ƒ^‚Ìæ“¾
/*/
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData ) ;
}



