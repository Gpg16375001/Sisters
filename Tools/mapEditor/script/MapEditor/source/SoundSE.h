/*
______________________________________________________________________________________________

	FILE : SoundSE.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SE�̍Đ����s���N���X
		
			--- ��Ȏg���� ---
			Win32API �́@mciSendString ���g�p����sE�̍Đ����s��
			mciSendString �̑Ή��t�@�C���`���� .wav .mp3 .MIDI �ŕ����̉����d�˂邱�Ƃ��ł���d�l�Ȃ̂ŁA
			SE�Đ��@�\�Ƃ��Ďg�����ƂƂ���B

			��. SE�̍Đ�
			�C���X�^���X��.play( TEXT( "�t�@�C���p�X" ) ) ;

			��. SE�̒�~
			�C���X�^���X��.stop( ) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

// �N���X�̐錾
class SoundSE
{
	public :
		SoundSE( ) ;													// �R���X�g���N�^
		~SoundSE( ) ;													// �f�X�g���N�^
		int play( LPCTSTR arg_pStr ) ;									// ���y�Đ�
		int stop( ) ;													// ���y��~

} ;


