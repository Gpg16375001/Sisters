/*
______________________________________________________________________________________________

	FILE : SoundSE.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		SEの再生を行うクラス
		
			--- 主な使い方 ---
			Win32API の　mciSendString を使用してsEの再生を行う
			mciSendString の対応ファイル形式は .wav .mp3 .MIDI で複数の音を重ねることができる仕様なので、
			SE再生機能として使うこととする。

			例. SEの再生
			インスタンス名.play( TEXT( "ファイルパス" ) ) ;

			例. SEの停止
			インスタンス名.stop( ) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>	// --- コンソール用

// クラスの宣言
class SoundSE
{
	public :
		SoundSE( ) ;													// コンストラクタ
		~SoundSE( ) ;													// デストラクタ
		int play( LPCTSTR arg_pStr , HWND arg_hWindow ) ;				// 音楽再生
		int stop( ) ;													// 音楽停止

} ;


