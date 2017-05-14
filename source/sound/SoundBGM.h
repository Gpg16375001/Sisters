/*
______________________________________________________________________________________________

	FILE : SoundBGM.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BGM�̍Đ����s���N���X
		
			--- ��Ȏg���� ---
			Win32API �́@PlaySound ���g�p����BGM�̍Đ����s��
			PlaySound �̑Ή��t�@�C���`���� .wav �ŕ����̉����d�˂邱�Ƃ��ł��Ȃ��d�l�Ȃ̂ŁA
			BGM�Đ��@�\�Ƃ��Ďg�����ƂƂ���B

			��. BGM�̍Đ�
			�C���X�^���X��.play( TEXT( "�t�@�C���p�X" ) ) ;

			��. BGM�̒�~
			�C���X�^���X��.stop( ) ;


�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include <stdio.h>	// --- �R���\�[���p

// �N���X�̐錾
class SoundBGM
{
	public :
		SoundBGM( ) ;													// �R���X�g���N�^
		~SoundBGM( ) ;													// �f�X�g���N�^
		int play( int arg_hSound ) ;									// ���y�Đ�
		int load( int arg_hSound , const TCHAR* arg_fileName ) ;		// ���y�ǂݍ���

	private :
		int htrack_ ;

} ;


