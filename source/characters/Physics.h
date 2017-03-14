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
	// magnitude , degree 度
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
			, r2_		( 1.414213562f )
			, r3_		( 1.732050807f )
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
		/*	使い方：斜面をすべるかどうかを調べる
		/*	引数　：地面の角度 , 物体の重さ , 摩擦係数
		/*	返り値：true or false
		/*/
		bool checkMotion( float arg_angle , float arg_weight , float arg_coeff ) ;
		/*/
		/*	使い方：斜面をすべる
		/*	引数　：地面の角度 , 物体の重さ , 動摩擦係数 , 質量
		/*	返り値：物体の加速度
		/*/
		float calcAccel( float arg_angle , float arg_weight , float arg_coeff , float arg_mass ) ;
		/*/
		/*	使い方：加速度を求める
		/*	引数　：変化前のスピード , 変化後のスピード , 時間(秒)
		/*	返り値：加速度
		/*/
		float AccelerationSeconds( float arg_v1 , float arg_v2 , float arg_time  ) ;
		/*/
		/*	使い方：２点間の傾きを求める
		/*	引数　：点１ と 点２
		/*	返り値：傾き
		/*/
		float slopeTilt( float *arg_p1 , float *arg_p2 ) ;
		/*/
		/*	使い方：２つの直線の交点を求める
		/*	引数　：点１ , 点１の傾き と 点２ , 点2の傾き
		/*	返り値：交点
		/*/
		float *linePoint( float *arg_p1 , float arg_a1 , float *arg_p2 , float arg_a2 ) ;
		/*/
		/*	使い方：傾きから高さを求める
		/*	引数　：x方向のベクトル と 移動移動方向のベクトル
		/*	返り値：Y軸の高さ
		/*/
		float slopePoint( Vector2D_compo arg_Xvector , Vector2D_compo arg_Yvector ) ;
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
		/*/
		/*	質量を取得
		/*/
		float getMass( ) const {
			return( mass_ ) ;
		} ;

		/*/
		/*	√2 を取得
		/*/
		float r2( ) const {
			return( r2_ ) ;
		} ;

		/*/
		/*	√3 を取得
		/*/
		float r3( ) const {
			return( r3_ ) ;
		} ;

	private :
		float Pi ;
		float RadToDeg ;
		float DegToRad ;

		float r2_ ;
		float r3_ ;

		float gravity_ ;	// 重力加速度
		float mass_ ;		// 質量

		Vector2D_compo weight_ ;

};


