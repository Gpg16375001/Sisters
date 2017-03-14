/*
______________________________________________________________________________________________

	FILE : ChipBackGround.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�`�b�v�w�i��`�悷��N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1�ňꖇ�̃`�b�v�w�i��`�悷��B
			selectBmp�őI�����ꂽ�r�b�g�}�b�v�� 32 * 32 �ŏc�ɐ؂���A
			�`�b�v�e�[�u���̔ԍ��ɏ]���ĕ`����s���B
			����� 32 * 32 �̃`�b�v�e�[�u�����̗p�����B
			�܂� 32 * 32 �� 1024 �Ȃ̂Ł@1024 * 1024 �̃`�b�v�w�i��`��ł���B
			�܂� m_x , m_y �����o���g�p���Ẵ`�b�v�w�i�X�N���[�����\�ł���B
			��������܂��g�����Ƃɂ�薳���X�N���[���≡�X�N���[���A�N�V��������
			�X�e�[�W��\���ł���B


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#define CHIP_X	32
#define CHIP_Y	32
#define CHIP_W	32
#define CHIP_H	32

// �N���X�̐錾
class ChipBackGround
{
	public :
		ChipBackGround( ) ;												// �R���X�g���N�^
		~ChipBackGround( ) ;											// �f�X�g���N�^

		int selectBmp( int arg_bmpNo ) ;								// �`�悵�����w�i�̔ԍ����Z�b�g
		int setPos( int arg_x , int arg_y ) ;							// ���W�̃Z�b�g
		int setChip( int arg_x , int arg_y , int arg_chipNo ) ;			// �`�b�v�̃Z�b�g
		int setFastChip( int *arg_chipData ) ;							// �`�b�v�f�[�^�̍����R�s�[
		int clearChip( ) ;												// �`�b�v�̃N���A
		int draw( ) ;													// �`�b�v�̕`��

	private :
		int	m_bmpNo ;													// �e�[�u���ԍ�
		int	m_x , m_y ;													// �`����W
		int m_chipTable[ CHIP_X * CHIP_Y ] ;

} ;


