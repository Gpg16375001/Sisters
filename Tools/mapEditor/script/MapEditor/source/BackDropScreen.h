/*
______________________________________________________________________________________________

	FILE : BackDropScreen.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�o�b�N�h���b�v�ʂ̕`����s���N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X1��1���̃r�b�g�}�b�v��`�悷��(�d�l��ňꖇ�ł悢)
			selectBmp �ɔw�i�p�r�b�g�}�b�v�e�[�u�����̕`�悵�����ԍ���n�����ƂŁA
			�i 0�Ԗڂƌ��߂Ă����Ƃ悢 �j
			�`�悷��w�i�r�b�g�}�b�v�̕ύX���s����B
			�`��ɂ� Draw ���\�b�h���t���[�����ɌĂяo�����ƁB

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class BackDropScreen
{
	public :
		BackDropScreen( ) ;
		~BackDropScreen( ) ;

		int selectBmp( int arg_bmpNo ) ;
		int draw( ) ;

	private :
		int m_bmpNo ;

} ;


