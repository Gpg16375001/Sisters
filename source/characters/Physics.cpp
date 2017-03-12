/*
______________________________________________________________________________________________

	FILE	: Physics.cpp

	________/ Explanation of file /___________________________________________________________
    
		Physicsクラスの実装部

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Physics.h"


/*/
/*	デストラクタ
/*/
Physics::~Physics( )
{
	// 終了を出力
	printf( "Management of a physics is ended.\n" ) ;
}

/*/
/*	初期化
/*/
void Physics::Initialize( )
{
	Pi		 = 3.141592654f ;
	RadToDeg = 57.29577951f ;
	DegToRad = 0.017453293f ;
	gravity_ = 9.81f ;
	mass_	 = 1.0f ;
	r2_		 = 1.414213562f ;
	r3_		 = 1.732050807f ;

	// 開始を出力
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	終了化
/*/
void Physics::Finalize( )
{
	Pi		 = 0.0f ;
	RadToDeg = 0.0f ;
	DegToRad = 0.0f ;
	gravity_ = 0.0f ;
	mass_	 = 0.0f ;
	r2_		 = 0.0f ;
	r3_		 = 0.0f ;

	// 開始を出力
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	使い方：加速度を求める
/*	引数　：変化前のスピード , 変化後のスピード , 時間(秒)
/*	返り値：加速度
/*/
float AccelerationSeconds( float arg_v1 , float arg_v2 , float arg_time  )
{
	return( (arg_v2 - arg_v1) / arg_time ) ;
}

/*/
/*	使い方：傾きから高さを求める
/*	引数　：x方向のベクトル と 移動先のベクトル( 角度があるほう )
/*	返り値：Y軸の高さ
/*/
float Physics::slopePoint( Vector2D_compo arg_Xvector , Vector2D_compo arg_Yvector  )
{
	if ( CompoToPolar(arg_Xvector).mag == 0 ) return( 0 ) ;
	return( (arg_Yvector.x * arg_Xvector.y - arg_Yvector.y * arg_Xvector.x) / (CompoToPolar(arg_Xvector).mag) ) ;
}

/*/
/*	使い方：ベクトルを polar から component に変換
/*	引数　：polar 表示のベクトル
/*	返り値：component 表示のベクトル
/*/
Vector2D_compo Physics::PolarToCompo( Vector2D_polar arg_vector2d )
{
	Vector2D_compo temp2d ;

	temp2d.x = arg_vector2d.mag * cos( arg_vector2d.deg * Pi / 180 ) ;
	temp2d.y = arg_vector2d.mag * sin( arg_vector2d.deg * Pi / 180 ) ;

	return( temp2d ) ;
}

/*/
/*	使い方：ベクトルを component から polar に変換
/*	引数　：component 表示のベクトル
/*	返り値：polar 表示のベクトル
/*/
Vector2D_polar Physics::CompoToPolar( Vector2D_compo arg_vector2d )
{
	Vector2D_polar temp2d = { 0 , 0 } ;

	// ピタゴラスの定理で C2 を求める
	temp2d.mag = (arg_vector2d.x * arg_vector2d.x) + (arg_vector2d.y * arg_vector2d.y) ;
	temp2d.mag = sqrt( temp2d.mag ) ;

	// バグ回避 0 で割らないように
	if ( temp2d.mag == 0 )
	{
		return( temp2d ) ;
	}

	// 角度を計算 ( asin() は (90)~(-90)度 を返す )
	temp2d.deg = (180 / Pi) * asin( arg_vector2d.y / temp2d.mag ) ;

	// 上の計算で (90)~(-90)度 ではなかったとき
	if ( arg_vector2d.x < 0 )
	{
		temp2d.deg = 180 - temp2d.deg ;
	}
	// (0)~(-90)度にあった場合
	else if ( (arg_vector2d.x > 0) && (arg_vector2d.y < 0) ) {
		temp2d.deg += 360 ;
	}

	return( temp2d ) ;
}

/*/
/*	使い方：重さ のベクトルに変換
/*	引数　：質量 と 加速度
/*	返り値：その物体に働く 重さ のベクトル
/*/
Vector2D_compo Physics::Weight2D( float arg_mass , float arg_grav )
{
	if ( (arg_mass == 1.0f) && (arg_grav == 0.0f) )
	{
		weight_.y = mass_ * gravity_ ;

	} else {
		weight_.y = arg_mass * arg_grav ;
	}
	return( weight_ ) ;
}


/*/
/*	質量の代入
/*/
int Physics::setMass( float arg_mass )
{
	mass_ = arg_mass ;
	return( true ) ;
}

/*/
/*	キー情報の更新
/*/
void Physics::update( )
{

}


		
