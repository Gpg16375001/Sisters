/*
______________________________________________________________________________________________

	FILE : TimeProc.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�����x�Ȏ��Ԋ֌W�̏�����񋟂���N���X
		
			--- ��Ȏg���� ---
			�v���O�������s����1�̃C���X�^���X�����Ďg�p����B( �������Ӗ����Ȃ� )
			��{�I�ɂ͊֐��̃��b�p�[�Ƃ��Ď��������B
			�C���X�^���X�������ۂɎ��Ԃ̐��x��1�ʕb�ɐݒ肵�Ă��܂��B

			�ł��邱��
			�EgetTime() ���g�p���� windows�N��������̎��Ԏ擾�@�\
			�EstartTime() �� endTime() ���g�p�����������x����@�\
			�ETheWorld() ���g�p�����X���[�v�@�\( ���̏�Œ�~���� )


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class TimeProc
{
	public :
		TimeProc( ) ;													// �R���X�g���N�^
		~TimeProc( ) ;													// �f�X�g���N�^
		DWORD getTime( ) ;												// ���Ԃ̎擾
		DWORD startTime( ) ;											// ����J�n
		DWORD endTime( ) ;												// ����I��
		int TheWorld( int arg_theWorldTime ) ;							// �X���[�v

	private :
		DWORD m_sTime , m_eTime , m_pTime ;								// �J�n���� , �I������ , ������������ �̎��Ԃ�����ϐ�

} ;


