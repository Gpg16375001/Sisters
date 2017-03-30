/*
______________________________________________________________________________________________

	FILE : Gimmick.h

	________/ Explanation of file /___________________________________________________________

		チップ背景を描画するクラス
		
			--- 主な使い方 ---


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "../characters/Animation.h"

#define		MAX_GIMMICK_NO				256

#define		GIMMICK_MODE_STAY			1
#define		GIMMICK_MODE_UPDOWN			2
#define		GIMMICK_MODE_LEFTRIGHT		3
#define		GIMMICK_MODE_CYCLE			4
#define		GIMMICK_MODE_WAVE			5
#define		GIMMICK_MODE_DROP			6
#define		GIMMICK_MODE_UPPER			7

#define		GIMMICK_NAME_CIRCULARSAWS	1
#define		GIMMICK_NAME_MOVEFLOOR		2
#define		GIMMICK_NAME_PENDULUM		3
#define		GIMMICK_NAME_SHOCKER		4
#define		GIMMICK_NAME_SPEEDUP		5
#define		GIMMICK_NAME_CLOUD			6
#define		GIMMICK_NAME_SHOOTER		7

/* Pos To Cell */
#define		PTC( arg_cell )	( (arg_cell * 64) )

struct GimmickData {
	int				_bmpNo ;				// 自分の要素番号 ( _hBmp と関連付けるため )
	bool			_useFlg ;				// 描画するかどうかのフラグ
	int				_anchor ;				// アンカーの位置
	float			_x , _y ;				// グローバル座標
	int				_u , _v ;				// 切り取り座標
	float			_w , _h ;				// 幅高さ
	int				_arrayX , _arrayY ;		// 配列座標
	float			_delay ;				// 遅れ
	float			_spd ;					// 速さ
	int				_Gimmick ;				// ギミックの種類
	int				_mode ;					// ギミックのモード
	float			_off[ 8 ] ;				// オフセット
	Animation		_gAnim ;				// animation
	AnimationData	_gAnim_01[ 4 ] ;		// anim 01
	AnimationData	_gAnim_02[ 4 ] ;		// anim 02
	AnimationData	_gAnim_03[ 4 ] ;		// anim 03
} ;

// クラスの宣言
class Gimmick
{
	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 
		/*/
		/*	終了化
		/*/
		void Finalize( ) ; 

		~Gimmick( ) ;
		void Update( ) ;												// チップの更新
		void clearGimmickData( ) ;
		void clearBulletData( ) ;
		void setBulletData( ) ;

		/*/
		/*	動く床のデータをセット
		/*/
		int setMoveBlocks( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int arg_mode ) ;
		/*/
		/*	動く床：動き
		/*/
		void moveFloor01( int arg_g ) ;
		void moveFloor02( int arg_g ) ;
		void moveFloor03( int arg_g ) ;
		void moveFloor04( int arg_g ) ;


		/*/
		/*	まるのこのデータをセット
		/*/
		int setCircularSaws( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;
		/*/
		/*	まるのこ：動き
		/*/
		void moveSaws01( int arg_g ) ;
		void moveSaws02( int arg_g ) ;
		void moveSaws03( int arg_g ) ;
		void moveSaws04( int arg_g ) ;

		/*/
		/*	振り子のデータをセット
		/*/
		int setPendulums( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	電気のデータをセット
		/*/
		int setShockers( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	SpeedUpのデータをセット
		/*/
		int setSpeedUp( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	雲のデータをセット
		/*/
		int setClouds( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;

		/*/
		/*	射撃物のデータをセット
		/*/
		int setShooter( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_delay , int aeg_mode ) ;
		int nullCheck( ) ;
		int useCheck( int arg_used ) ;
		/*/
		/*	射撃物：種類
		/*/
		void blockShot01( int arg_g ) ;
		void blockShot02( int arg_g ) ;
		void blockShot03( int arg_g ) ;
		void blockShot04( int arg_g ) ;

		/*/
		/*	それぞれのアップデート内処理
		/*/
		void MoveFloor( ) ;
		void CircularSaws( ) ;
		void Pendulums( ) ;
		void Shockers( ) ;
		void SpeedUp( ) ;
		void Clouds( ) ;
		void Shooter( ) ;

		/*/
		/*	ギミックのデータをゲット
		/*/
		GimmickData getGimmickData( int arg_GimmickNo ) {
			return( GimmickData_[ arg_GimmickNo ] ) ;
		}

		/*/
		/*	バレットを消滅
		/*/
		int deleteBullet( int arg_GimmickNo ) {
			BulletData_[ arg_GimmickNo ]._useFlg	= false ;
			BulletData_[ arg_GimmickNo ]._x			= 0.0f ;
			BulletData_[ arg_GimmickNo ]._y			= 0.0f ;
			BulletData_[ arg_GimmickNo ]._off[ 0 ]	= 0.0f ;
			BulletData_[ arg_GimmickNo ]._off[ 1 ]	= 0.0f ;
			BulletData_[ arg_GimmickNo ]._delay		= 0 ;
			return( true ) ;
		}

		/*/
		/*	off[ 3 ]のデータを直接セット
		/*/
		int setOff_3( int arg_GimmickNo , float arg_no ) {
			GimmickData_[ arg_GimmickNo ]._off[ 3 ] = arg_no ;
			return( true ) ;
		}

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static Gimmick* GetInstance( )
		{
			static Gimmick v ;
			return &v ;
		}

	private :
		/*/
		/*	コンストラクタ
		/*/
		Gimmick( ) {
			Initialize( ) ;
		} ;

		int				GimmickNo_ ;
		GimmickData		GimmickData_[ MAX_GIMMICK_NO ] ;					// データ
		GimmickData		BulletData_[ 500 ] ;								// 弾だけのデータ

} ;


