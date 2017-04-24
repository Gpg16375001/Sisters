/*
______________________________________________________________________________________________

	FILE	: Animation.cpp

	________/ Explanation of file /___________________________________________________________
        
		Animation�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>

#include "Common.h"

/*/
/*	�R���X�g���N�^
/*/
Animation::Animation( )
{
	mp_animData = NULL ;
	memset( &m_nowAnimData, 0, sizeof( AnimationData ) ) ;
	m_animState = ANIM_STATE_STOP ;
	m_animCnt = 0 ;
}

/*/
/*	�f�X�g���N�^
/*/
Animation::~Animation( )
{

}

/*/
/*	�A�j���[�V�����f�[�^�̃Z�b�g
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
/*	�O������̃A�j���[�V�����f�[�^�̃Z�b�g
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
/*	���[�h�𐔎��֕ς���
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
/*	�A�j���[�V�����̍Đ�
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
/*	�O���f�[�^����̃A�j���[�V�����̍Đ�
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
/*	�A�j���[�V�������̎擾
/*/
int Animation::getAnimState( )
{
	return( m_animState ) ;
}

/*/
/*	���݂̃A�j���[�V�����f�[�^�̎擾
/*/
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData ) ;
}

/*/
/*	���݂̃A�j���[�V�����f�[�^�̎擾
/*/
Anim_Data* Animation::getNowAnimation( )
{
	return( &m_nowAnimation ) ;
}



