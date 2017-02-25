/*
______________________________________________________________________________________________

	FILE	: KeyManager.h

	________/ Explanation of file /___________________________________________________________
 
		キー入力の管理を行うクラス

			--- 主な使い方 ---
			プログラム実行時に１つインスタンス化される。（ 自動で作られる ）
			かならず一度だけ最初に KeyManager::GetInstance( )->Initialize( ) で初期化する。
			フレームの発生タイミングで一度updateを呼び出しキー情報の更新を行う。
			キー情報の取得には getKeyState( ) に仮想キーコードまたは文字コード（英数）を渡し、
			戻り値を受け取る事ることで実現できる。
			基本的な使い方としては必要なタイミングで getKeyState( ) を呼び出し、
			戻り値を真偽判定することでキー情報での分岐処理が可能である。

			例・Aが押されている場合コンソール画面に出力を行う

			if( KeyManager::GetInstance( )->getKeyState( 'A' ) != 0 )
			{
				printf( "Aが押されています" );
			}

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>

/*/
/*	クラスの宣言
/*/
class KeyManager
{
	// 公開変数とメンバ関数
	public:
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~KeyManager( ) ;						// --- デストラクタ
		int update( ) ;							// --- キー情報の更新
		BYTE getKeyState( BYTE arg_keyCode ) ;	// --- キー情報の取得

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static KeyManager* GetInstance( )
		{
			static KeyManager v ;
			return &v ;
		}

	// 非公開変数とメンバ関数
	private:
		// コンストラクタ
		KeyManager( ) {
		} ;

		BYTE m_bKeyTbl[ 256 ] ;					// --- キーテーブル
};

