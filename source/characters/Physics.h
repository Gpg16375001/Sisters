/*
______________________________________________________________________________________________

	FILE	: Physics.h

	________/ Explanation of file /___________________________________________________________
 
		物理的なことを行うクラス

			--- 主な使い方 ---


			例・


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>

/*/
/*	ベクトル：成分 component
/*/
struct Vector2D_compo {
	float x , y ;
} ;
/*/
/*	ベクトル：大きさと向き polar
/*/
struct Vector2D_polar {
	// magnitude , degree
	float mag , deg ;
} ;

/*/
/*	クラスの宣言
/*/
class Physics
{
	// 公開変数とメンバ関数
	public:
		/*/
		/*	コンストラクタ
		/*/
		Physics( )
			: Pi		( 3.141592654f )
			, RadToDeg	( 57.29577951f )
			, DegToRad	( 0.017453293f )
			, gravity_	( 9.81f )
			, mass_		( 1.0f )
		{
			
		} ;

		~Physics( ) ;							// デストラクタ
		void update( ) ;						// 情報の更新

		/*/
		/*	初期化
		/*/
		void Initialize( ) ;

		/*/
		/*	終了化
		/*/
		void Finalize( ) ;

		/*/
		/*	使い方：2点間をつなぐ直線を求める
		/*	引数　：座標をあらわすfloat配列２つ
		/*	返り値：直線の傾き
		/*/
		float slopePoint( float *arg_point1 , float *arg_point2  ) ;
		/*/
		/*	使い方：ベクトルを polar から component に変換
		/*	引数　：polar 表示のベクトル
		/*	返り値：component 表示のベクトル
		/*/
		Vector2D_compo PolarToCompo( Vector2D_polar arg_vector2d ) ;
		/*/
		/*	使い方：ベクトルを component から polar に変換
		/*	引数　：component 表示のベクトル
		/*	返り値：polar 表示のベクトル
		/*/
		Vector2D_polar CompoToPolar( Vector2D_compo arg_vector2d ) ;

		/*/
		/*	使い方：重さ のベクトルに変換
		/*	引数　：質量 と 加速度
		/*	返り値：その物体に働く 重さ のベクトル
		/*/
		Vector2D_compo Weight2D( float arg_mass = 1.0f , float arg_grav = 0.0f ) ;

		/*/
		/*	質量の代入
		/*/
		int setMass( float arg_mass ) ;

	private :
		float Pi ;
		float RadToDeg ;
		float DegToRad ;

		float gravity_ ;	// 重力加速度
		float mass_ ;		// 質量

		Vector2D_compo weight_ ;

};


