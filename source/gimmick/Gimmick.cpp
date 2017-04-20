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
#include <locale.h>

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
	printf( "Gimmick -> " ) ;

	clearGimmickData( ) ;
	clearBulletData( ) ;
	setBulletData( ) ;
	physic_.Initialize( ) ;
	MasterData::ReLoad( ) ;

	GimmickNo_ = 0 ;

}

/*/
/*	終了化
/*/
void Gimmick::Finalize( )
{
	Initialize( ) ;

	physic_.Finalize( ) ;
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
/*	ギミックデータのロード
/*/
void Gimmick::setGimmickData( int arg_SceneNo )
{	
	printf( "GimmickData was loaded.\n" ) ;

	if ( arg_SceneNo == 1 )
	{
		for ( auto it = MasterData::SceneGame01.begin() ; it != MasterData::SceneGame01.end() ; ++it )
		{
			// 動く床の時
			if ( _strcmpi("MoveFloor" , it->getData()._name) == 0 )
			{
				setMoveBlocks( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// まるのこの時
			if ( _strcmpi("CircularSaws" , it->getData()._name) == 0 )
			{
				setCircularSaws( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// 振り子の時
			if ( _strcmpi("Pendulum" , it->getData()._name) == 0 )
			{
				setPendulums( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// 電気の時
			if ( _strcmpi("Shocker" , it->getData()._name) == 0 )
			{
				setShockers( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// スピードアップの時
			if ( _strcmpi("SpeedUp" , it->getData()._name) == 0 )
			{
				setSpeedUp( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// 雲の時
			if ( _strcmpi("Cloud" , it->getData()._name) == 0 )
			{
				setClouds( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// 射撃物の時
			if ( _strcmpi("Shooter" , it->getData()._name) == 0 )
			{
				setShooter( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

			// 草の時
			if ( _strcmpi("Grass" , it->getData()._name) == 0 )
			{
				setGrass( it->getData()._bmpNo , PTC(it->getData()._xpos) , PTC(it->getData()._ypos) , it->getData()._off[ 0 ] , it->getData()._off[ 1 ] , strToDefineName(it->getData()._mode) ) ;
			}

		}
	}


}

/*/
/*	defineにある文字と同じ場合登録されている数字を返す
/*/
int	Gimmick::strToDefineName( const char* arg_mode )
{
	int iRet = 1 ;

	if ( _strcmpi("GIMMICK_MODE_STAY" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_STAY ;
	}

	if ( _strcmpi("GIMMICK_MODE_UPDOWN" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_UPDOWN ;
	}

	if ( _strcmpi("GIMMICK_MODE_LEFTRIGHT" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_LEFTRIGHT ;
	}

	if ( _strcmpi("GIMMICK_MODE_CYCLE" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_CYCLE ;
	}

	if ( _strcmpi("GIMMICK_MODE_WAVE" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_WAVE ;
	}

	if ( _strcmpi("GIMMICK_MODE_DROP" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_DROP ;
	}

	if ( _strcmpi("GIMMICK_MODE_UPPER" , arg_mode) == 0 )
	{
		iRet = GIMMICK_MODE_UPPER ;
	}

	return( iRet ) ;
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

	/*/
	/*	___/ くさ /___________________
	/*/
	Grass( ) ;

}



