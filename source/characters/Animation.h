/*
______________________________________________________________________________________________

	FILE	: Animation.h

	________/ Explanation of file /___________________________________________________________
        
		�A�j���[�V�����𐧌䂷��N���X�Ɠn���ׂ��f�[�^�\���̂̐錾

		--- ��Ȏg���� ---
		�n���ꂽ�A�j���[�V�����f�[�^���Đ�����B
		�A�j���[�V�����f�[�^����ɂ�AnimationData�\���̂��g�p����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#pragma once

/*/
/*	�A�j���[�V�������[�h
/*/
#define ANIM_MODE_STOP 0
#define ANIM_MODE_NEXT 1
#define ANIM_MODE_LOOP 2

/*/
/*	�A�j���[�V�������
/*/
#define ANIM_STATE_STOP 0
#define ANIM_STATE_PLAY 1

/*/
/*	�A�j���[�V�����f�[�^
/*/
struct AnimationData
{
	int		bmpNo ;		// �r�b�g�}�b�v�ԍ�
	int		holdTime ;	// �ێ�����
	RECT	cutRect ;	// �؂����`
	int		animMode ;	// �A�j���[�V�������[�h

} ;

/*/
/*	�A�j���[�V�����f�[�^
/*/
struct Anim_Data
{
	int		bmpNo ;		// �r�b�g�}�b�v�ԍ�
	int		holdTime ;	// �ێ�����
	float	x ;			// X
	float	y ;			// Y
	RECT	cutRect ;	// �؂����`
	int		animMode ;	// �A�j���[�V�������[�h

} ;

/*/
/*	�N���X�̐錾
/*/
class Animation
{
	public :
		Animation( ) ;
		~Animation( ) ;
	
		int setAnimData( AnimationData *argp_animData ) ;	// �A�j���[�V�����f�[�^�̃Z�b�g
		int setAnimData( ) ;								// �O������̃A�j���[�V�����f�[�^�̃Z�b�g
		int playAnim( ) ;									// �A�j���[�V�����̍Đ�
		int _playAnim( ) ;									// �A�j���[�V�����̍Đ�
		int getAnimState( ) ;								// �A�j���[�V�������̎擾
		int modeToNumber( char *arg_mode ) ;				// ���[�h�𐔎��֕ς���
		AnimationData* getNowAnim( ) ;						// ���݂̃A�j���[�V�����f�[�^�̎擾
		Anim_Data* getNowAnimation( ) ;						// ���݂̃A�j���[�V�����f�[�^�̎擾

	private :
		AnimationData *mp_animData ;						// �n���ꂽ�A�j���[�V�����f�[�^
		AnimationData m_nowAnimData ;						// ���݂̃A�j���[�V�����f�[�^
		Anim_Data m_nowAnimation ;							// ���݂̃A�j���[�V�����f�[�^
		int m_animState ;									// ���݂̃A�j���[�V������
		int m_animCnt ;										// ���݂̃A�j���[�V�����Đ��ԍ�

} ;



