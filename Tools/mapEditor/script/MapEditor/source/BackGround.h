/*
______________________________________________________________________________________________

	FILE : BackGround.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�o�b�N�O���E���h�ʂ̕`����s���N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1��1���̃r�b�g�}�b�v��`�悷��(�d�l��ňꖇ�ł悢)
			selectBmp �ɔw�i�p�r�b�g�}�b�v�e�[�u�����̕`�悵�����ԍ���n�����ƂŁA
			�i 0�Ԗڂƌ��߂Ă����Ƃ悢 �j
			�`�悷��w�i�r�b�g�}�b�v�̕ύX���s����B
			�`��ɂ� Draw ���\�b�h���t���[�����ɌĂяo�����ƁB

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class BackGround
{
	public :
		BackGround( ) ;
		~BackGround( ) ;

		int setX( int arg_x ) ;
		int setY( int arg_y ) ;

		int selectBmp( int arg_bmpNo ) ;
		int draw( ) ;

	private :
		int	m_bmpNo ;
		int	m_x, m_y ;

} ;


