/*
______________________________________________________________________________________________

	FILE	: SceneBace.h

	________/ Explanation of file /___________________________________________________________
       
    SceneBaseクラス

	シーンの大元を作っている。主に継承して使う

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <Windows.h>

struct SceneBaseParam
{
	public :
		virtual ~SceneBaseParam( ){ }
} ;

/*/
/*	 シーンの基底クラス
/*/
class SceneBase
{
	public :
		virtual ~SceneBase( ){ }

		/*/
		/*	 初期化
		/*/
		virtual void Initialize( const SceneBaseParam* param ){ }

		/*/
		/*	 終了化
		/*/
		virtual void Finalize( ){ }

		/*/
		/*	 更新
		/*
		/*	 @param df 前のフレームとの差分時間
		/*/
		virtual void Update( ){ }

		/*/
		/*	 描画
		/*/
		virtual void Render( ){ }

} ;



