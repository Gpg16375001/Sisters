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

#define		MAX_GIMMICK_NO			256

#define		GIMMICK_MODE_STAY		1
#define		GIMMICK_MODE_UPDOWN		2
#define		GIMMICK_MODE_LEFTRIGHT	3
#define		GIMMICK_MODE_CYCLE		4
#define		GIMMICK_MODE_WAVE		5

#define		GIMMICK_NAME_MARU		1
#define		GIMMICK_NAME_MOVEFLOOR	2

struct GimmickData {
	int		_bmpNo ;				// 自分の要素番号 ( _hBmp と関連付けるため )
	bool	_useFlg ;				// 描画するかどうかのフラグ
	int		_anchor ;				// アンカーの位置
	float	_x , _y ;				// グローバル座標
	int		_u , _v ;				// 切り取り座標
	float	_w , _h ;				// 幅高さ
	int		_arrayX , _arrayY ;		// 配列座標
	float	_delay ;				// 遅れ
	float	_spd ;					// 速さ
	int		_Gimmick ;				// ギミックの種類
	int		_mode ;					// ギミックのモード
	float	_off[ 2 ] ;				// オフセット
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

		void setGimmicks( ) ;

		/*/
		/*	ギミックのデータをセット
		/*/
		int setMoveBlock( int arg_bmpNo , float arg_x , float arg_y , float arg_spd , float arg_Delay , int _mode ) ;

		/*/
		/*	ギミックのデータをゲット
		/*/
		GimmickData getMoveBlock( int arg_GimmickNo ) {
			return( GimmickData_[ arg_GimmickNo ] ) ;
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

		int			GimmickNo_ ;
		GimmickData	GimmickData_[ MAX_GIMMICK_NO ] ;							// データ

} ;


