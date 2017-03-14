/*
______________________________________________________________________________________________

	FILE : Player.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�v���C���[�̃N���X�錾��
		
			�Q�[���̃L�����N�^�[���m( �v���C���[��G�l�~�[�A�A�C�e���� )
			�͑��݊֌W���������̂ŏ_����o�����߂ɂ��ׂĂ����J�����o�Ƃ����B
			�{���̓I�u�W�F�N�g���m�̃��\�b�h�ő��݊֌W���C�t���Ă������Ƃ����z�I�����A
			�Q�[���̂悤�ɑ���̏��ɑ��X�A�N�Z�X����悤�ȏꍇ�͊J�������̓p�u���b�N��
			�A�N�Z�X�������������J�����X���[�Y�ł��邱�Ƃ������B
			�������A�N�Z�b�T����Ȃ��ꍇ�̊댯���͏\���ɍl������K�v������B
			���Ƃł͂ł�����胁�\�b�h�ł̑��݊֌W��ڎw�����������ʂɕ��G������ꍇ��
			�����̃p�u���b�N�A�N�Z�X�����e���Ă����B


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// enum
enum PlayerActionName
{
	ePlayerBlank = -1,
	ePlayerStandby,
	ePlayerMoveLeft,
	ePlayerMoveRight,
	ePlayerMoveUp,
	ePlayerMoveDown,
} ;

// �N���X�̐錾
class Player
{
	public :
		Player( ) ;														// �R���X�g���N�^
		~Player( ) ;													// �f�X�g���N�^

		int action( ) ;													// �A�N�V����
		int setGPoint( int arg_gX , int arg_gY ) ;						// �O���[�o�����W�̃Z�b�g
		int setAPoint( int arg_aX , int arg_aY ) ;						// �z����W�̃Z�b�g

	public :
		int m_actionNo ;												// �A�N�V�����ԍ�
		POINT m_gPoint ;												// �v���C���[�̃O���[�o�����W
		POINT m_aPoint ;												// �v���C���[�̔z����W

} ;


