/*
______________________________________________________________________________________________

	FILE : Sprite.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		�X�v���C�g��`�悷��N���X
		
			--- ��Ȏg���� ---
			�C���X�^���X 1�� �� 1�� �̃X�v���C�g��`�悷��
			��{�I�ȗ���Ƃ��Ă� �y setSprite -> draw -> clearSprite -> Next_Frame �z �ƂȂ�B
			�ʂɃZ�b�g�������ꍇ�͊e�����o�̑Ή����\�b�h���g�p����B

			��1. �X�v���C�g�N���X�̊�{�I�ȗ���
			�C���X�^���X.setSprite( 0 , 128 , 96 , 0 , 0 , 64 , 64 ) ;
			�C���X�^���X.draw( ) ;
			�C���X�^���X.clearSprite( ) ;

			��2. 2�{�ł̕\�����s�������ꍇ
			�C���X�^���X.setScaleXY( 2.0 , 2.0 ) ;

			��3. �A���t�@50% �ŕ\�����s�������ꍇ
			�C���X�^���X.setAlpha( 0.5 ) ;

			��4. 45�x��]�������s�������ꍇ
			�C���X�^���X.setRotate( 45.0f ) ;

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class Sprite
{
	public :
		Sprite( ) ;														// �R���X�g���N�^
		~Sprite( ) ;													// �f�X�g���N�^

		int setSprite(													// �X�v���C�g�̃Z�b�g
				int arg_bmpNo ,											 // . �X�v���C�g�̔ԍ�
				int arg_x , int arg_y ,									 // . ����̍��W
				int arg_u , int arg_v ,									 // . �؂�o�����W
				int arg_w , int arg_h									 // . ���ƍ���
			) ;
		int clearSprite( ) ;											// �X�v���C�g�̃N���A
		int setFlg( int arg_flg ) ;										// �t���O�̃Z�b�g
		int selectBmp( int arg_bmpNo ) ;								// �X�v���C�g�̃Z�b�g
		int setPos( int arg_x , int arg_y ) ;							// ���W�̃Z�b�g
		int setUV( int arg_u , int arg_v ) ;							// �؂�o�����W�̃Z�b�g
		int setWH( int arg_w , int arg_h ) ;							// �؂�o���������̃Z�b�g
		int draw( ) ;													// �X�v���C�g�̕`��
		int setScaleFlg( int arg_scaleFlg ) ;							// �X�P�[���g�p�t���O�̃Z�b�g
		int setScaleXY( float arg_scaleX , float arg_scaleY ) ;			// �X�P�[���{���̃Z�b�g
		int setAlphaFlg( int arg_alphaFlg ) ;							// �A���t�@�����t���O�̃Z�b�g
		int setAlpha( float arg_alpha ) ;									// �A���t�@�����̃Z�b�g
		int setRotateFlg( int arg_rotateFlg ) ;							// ��]�����t���O�̃Z�b�g
		int setRotate( float arg_degree ) ;								// ��]�����̃Z�b�g

	private :
		int m_useFlg ;													// �g�p�t���O
		int	m_bmpNo ;													// �e�[�u���ԍ�
		int	m_x , m_y ;													// �`����W
		int	m_u , m_v ;													// �؂�o�����W
		int	m_w , m_h ;													// �؂�o��������
		int m_scaleFlg ;												// �X�P�[���g�p�t���O
		float m_scaleX , m_scaleY ;										// �{��
		int m_alphaFlg ;												// �������g�p�t���O
		int m_alpha ;													// �������̒l
		int m_rotateFlg ;												// ��]�g�p�t���O
		float m_degree ;												// ��]�̊p�x(�x���@)

} ;


