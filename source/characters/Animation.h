/*
______________________________________________________________________________________________

	FILE	: Animation.h

	________/ Explanation of file /___________________________________________________________
        
		アニメーションを制御するクラスと渡すべきデータ構造体の宣言

		--- 主な使い方 ---
		渡されたアニメーションデータを再生する。
		アニメーションデータ制作にはAnimationData構造体を使用する

￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#pragma once

/*/
/*	アニメーションモード
/*/
#define ANIM_MODE_STOP 0
#define ANIM_MODE_NEXT 1
#define ANIM_MODE_LOOP 2

/*/
/*	アニメーション状態
/*/
#define ANIM_STATE_STOP 0
#define ANIM_STATE_PLAY 1

/*/
/*	アニメーションデータ
/*/
struct AnimationData
{
	int		bmpNo ;		// ビットマップ番号
	int		holdTime ;	// 保持時間
	RECT	cutRect ;	// 切り取り矩形
	int		animMode ;	// アニメーションモード

} ;

/*/
/*	アニメーションデータ
/*/
struct Anim_Data
{
	int		bmpNo ;		// ビットマップ番号
	int		holdTime ;	// 保持時間
	float	x ;			// X
	float	y ;			// Y
	RECT	cutRect ;	// 切り取り矩形
	int		animMode ;	// アニメーションモード

} ;

/*/
/*	クラスの宣言
/*/
class Animation
{
	public :
		Animation( ) ;
		~Animation( ) ;
	
		int setAnimData( AnimationData *argp_animData ) ;	// アニメーションデータのセット
		int setAnimData( ) ;								// 外部からのアニメーションデータのセット
		int playAnim( ) ;									// アニメーションの再生
		int _playAnim( ) ;									// アニメーションの再生
		int getAnimState( ) ;								// アニメーション情報の取得
		int modeToNumber( char *arg_mode ) ;				// モードを数字へ変える
		AnimationData* getNowAnim( ) ;						// 現在のアニメーションデータの取得
		Anim_Data* getNowAnimation( ) ;						// 現在のアニメーションデータの取得

	private :
		AnimationData *mp_animData ;						// 渡されたアニメーションデータ
		AnimationData m_nowAnimData ;						// 現在のアニメーションデータ
		Anim_Data m_nowAnimation ;							// 現在のアニメーションデータ
		int m_animState ;									// 現在のアニメーション状況
		int m_animCnt ;										// 現在のアニメーション再生番号

} ;



