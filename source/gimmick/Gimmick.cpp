/*
________________________________________________________________________________________________________________

	FILE : Gimmick.cpp

	________/ Explanation of file /___________________________________________________________

		Gimmick クラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include "Renderer.h"
#include "Gimmick.h"
#include "Chip.h"
#include "Sprite.h"
#include "KeyManager.h"

/*/
/*	デストラクタ
/*/
Gimmick::~Gimmick( )
{
	printf( "Gimmick was end.\n" ) ;
}

/*/
/*	初期化
/*/
void Gimmick::Initialize( )
{
	printf( "Gimmick was created.\n" ) ;

	clearGimmickData( ) ;
	clearBulletData( ) ;
	setBulletData( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	終了化
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	clearGimmickData( ) ;
	clearBulletData( ) ;
}

/*/
/*	初期化
/*/
void Gimmick::clearGimmickData( )
{
	for ( int i = 0 ; i < MAX_GIMMICK_NO ; ++i )
	{
		GimmickData_[ i ]._useFlg	= false ;	// 描画するかどうかのフラグ
		GimmickData_[ i ]._bmpNo	= 0 ;		// 自分の要素番号 ( _hBmp と関連付けるため )
		GimmickData_[ i ]._anchor	= 0 ;		// アンカーの位置
		GimmickData_[ i ]._x		= 0 ;
		GimmickData_[ i ]._y		= 0 ;		// グローバル座標
		GimmickData_[ i ]._u		= 0 ;
		GimmickData_[ i ]._v		= 0 ;		// 切り取り座標
		GimmickData_[ i ]._w		= 0 ;
		GimmickData_[ i ]._h		= 0 ;		// 幅高さ
		GimmickData_[ i ]._arrayX	= 0 ;
		GimmickData_[ i ]._arrayY	= 0 ;		// 配列座標
		GimmickData_[ i ]._delay	= 0 ;		// 遅れ
		GimmickData_[ i ]._spd		= 0 ;		// 速さ
		GimmickData_[ i ]._Gimmick	= 0 ;		// ギミックの種類
		GimmickData_[ i ]._mode		= 0 ;		// ギミックのモード
		GimmickData_[ i ]._off[ 0 ] = 0 ;		// オフセット 1
		GimmickData_[ i ]._off[ 1 ] = 0 ;		// オフセット 2
		GimmickData_[ i ]._off[ 2 ] = 0 ;		// オフセット 3
		GimmickData_[ i ]._off[ 3 ] = 0 ;		// オフセット 4
		GimmickData_[ i ]._off[ 4 ] = 0 ;		// オフセット 5
		GimmickData_[ i ]._off[ 5 ] = 0 ;		// オフセット 6
		GimmickData_[ i ]._off[ 6 ] = 0 ;		// オフセット 7
		GimmickData_[ i ]._off[ 7 ] = 0 ;		// オフセット 8

		// アニメーション
		memset( &GimmickData_[ i ]._gAnim_01 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &GimmickData_[ i ]._gAnim_02 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &GimmickData_[ i ]._gAnim_03 , 0 , 4 * sizeof( AnimationData ) ) ;
	}

}

/*/
/*	初期化
/*/
void Gimmick::clearBulletData( )
{
	for ( int i = 0 ; i < 500 ; ++i )
	{
		BulletData_[ i ]._useFlg	= false ;	// 描画するかどうかのフラグ
		BulletData_[ i ]._bmpNo		= 0 ;		// 自分の要素番号 ( _hBmp と関連付けるため )
		BulletData_[ i ]._anchor	= 0 ;		// アンカーの位置
		BulletData_[ i ]._x			= 0 ;
		BulletData_[ i ]._y			= 0 ;		// グローバル座標
		BulletData_[ i ]._u			= 0 ;
		BulletData_[ i ]._v			= 0 ;		// 切り取り座標
		BulletData_[ i ]._w			= 0 ;
		BulletData_[ i ]._h			= 0 ;		// 幅高さ
		BulletData_[ i ]._arrayX	= 0 ;
		BulletData_[ i ]._arrayY	= 0 ;		// 配列座標
		BulletData_[ i ]._delay		= 0 ;		// 遅れ
		BulletData_[ i ]._spd		= 0 ;		// 速さ
		BulletData_[ i ]._Gimmick	= 0 ;		// ギミックの種類
		BulletData_[ i ]._mode		= 0 ;		// ギミックのモード
		BulletData_[ i ]._off[ 0 ]	= 0 ;		// オフセット 1
		BulletData_[ i ]._off[ 1 ]	= 0 ;		// オフセット 2
		BulletData_[ i ]._off[ 2 ]	= 0 ;		// オフセット 3
		BulletData_[ i ]._off[ 3 ]	= 0 ;		// オフセット 4
		BulletData_[ i ]._off[ 4 ] = 0 ;		// オフセット 5
		BulletData_[ i ]._off[ 5 ] = 0 ;		// オフセット 6
		BulletData_[ i ]._off[ 6 ] = 0 ;		// オフセット 7
		BulletData_[ i ]._off[ 7 ] = 0 ;		// オフセット 8

		// アニメーション
		memset( &BulletData_[ i ]._gAnim_01 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &BulletData_[ i ]._gAnim_02 , 0 , 4 * sizeof( AnimationData ) ) ;
		memset( &BulletData_[ i ]._gAnim_03 , 0 , 4 * sizeof( AnimationData ) ) ;
	}

}

/*/
/*	Update
/*
/*	
/*/
void Gimmick::Update( )
{
	/*/
	/*	ぎっみっくの種類分け
	/*/

	/*/
	/*	___/ 動く床 /___________________
	/*/
	MoveFloor( ) ;

	/*/
	/*	___/ まるのこ /___________________
	/*/
	CircularSaws( ) ;

	/*/
	/*	___/ 振り子 /___________________
	/*/
	Pendulums( ) ;

	/*/
	/*	___/ 電気 /___________________
	/*/
	Shockers( ) ;

	/*/
	/*	___/ SPPED UP /___________________
	/*/
	SpeedUp( ) ;

	/*/
	/*	___/ くも /___________________
	/*/
	Clouds( ) ;

	/*/
	/*	___/ 敵POD /___________________
	/*/
	Shooter( ) ;

}



