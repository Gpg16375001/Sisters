
/*
______________________________________________________________________________________________

	FILE	: ConsoleWindow.cpp

	________/ Explanation of file /___________________________________________________________
       
    コンソールウィンドウの生成と破棄を担当するクラス

	--- 主な使い方 ---
	プログラム実行時に１つインスタンス化して使用する。（複数作ってもあまり意味がない）
	必ず一度だけ最初に ConsoleWindow::GetInstance()->Initialize() で初期化する。
	基本的にはprintfを使ったデバッグを可能にするために使用する。

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>	// --- コンソール用

// --- クラスの宣言
class ConsoleWindow
{
	// --- 公開変数とメンバ関数
	public:
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~ConsoleWindow( ) ;	// --- デストラクタ

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static ConsoleWindow* GetInstance( )
		{
			static ConsoleWindow v ;
			return &v ;
		}

	private:
		/*/
		/*	コンストラクタ
		/*/
		ConsoleWindow( ) {
		}

	private :
		FILE *m_fIn ;
		FILE *m_fOut ;
};

