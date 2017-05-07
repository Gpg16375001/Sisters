/*
______________________________________________________________________________________________

	FILE : SoundBGM.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		BGMの再生を行うクラス
		
			--- 主な使い方 ---
			Win32API の　PlaySound を使用してBGMの再生を行う
			PlaySound の対応ファイル形式は .wav で複数の音を重ねることができない仕様なので、
			BGM再生機能として使うこととする。

			例. BGMの再生
			インスタンス名.play( TEXT( "ファイルパス" ) ) ;

			例. BGMの停止
			インスタンス名.stop( ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>	// --- コンソール用

// クラスの宣言
class SoundBGM
{
	public :
		SoundBGM( ) ;													// コンストラクタ
		~SoundBGM( ) ;													// デストラクタ
		int play( LPCTSTR arg_pStr ) ;									// 音楽再生
		int stop( ) ;													// 音楽停止

} ;


