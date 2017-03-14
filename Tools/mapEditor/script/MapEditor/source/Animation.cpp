
/* _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

	FILE	: Animation.cpp
	NAME	: Teacher.K

+ ------ Explanation of file --------------------------------------------------------------------------
       
    Animation�N���X�̎�����

+ _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/ */

#include <windows.h>
#include <stdio.h>

#include "Common.h"

// --- �R���X�g���N�^
Animation::Animation( )
{
	mp_animData = NULL;
	memset( &m_nowAnimData, 0, sizeof( AnimationData ) );
	m_animState = ANIM_STATE_STOP;
	m_animCnt = 0;
}

// --- �f�X�g���N�^
Animation::~Animation( )
{

}
	
// --- �A�j���[�V�����f�[�^�̃Z�b�g
int Animation::setAnimData( AnimationData *argp_animData )
{
	mp_animData = argp_animData;
	m_animCnt = 0;
	m_nowAnimData = mp_animData[ m_animCnt ];
	m_animState = ANIM_STATE_PLAY;

	return( true );
}

// --- �A�j���[�V�����̍Đ�
int Animation::playAnim( )
{
	if( m_animState == ANIM_STATE_PLAY )
	{
		m_nowAnimData.holdTime--;
		if( m_nowAnimData.holdTime == 0 )
		{
			if( m_nowAnimData.animMode == ANIM_MODE_STOP )
			{
				m_animState = ANIM_STATE_STOP;
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_NEXT )
			{
				m_animCnt++;
				m_nowAnimData = mp_animData[ m_animCnt ];
			}
			else if( m_nowAnimData.animMode == ANIM_MODE_LOOP )
			{
				m_animCnt = 0;
				m_nowAnimData = mp_animData[ m_animCnt ];
			}
		}
	}

	return( true );
}

// --- �A�j���[�V�������̎擾
int Animation::getAnimState( )
{
	return( m_animState );
}

// --- ���݂̃A�j���[�V�����f�[�^�̎擾
AnimationData* Animation::getNowAnim( )
{
	return( &m_nowAnimData );
}



