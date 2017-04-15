/*
______________________________________________________________________________________________

	FILE : Sprite.h

	________/ Explanation of file /___________________________________________________________

		Sprite の描画に必要なデータを保持するするするクラス
		
			--- 主な使い方 ---
			1つのインスタンスで4枚の Sprite を保持することができる。
			つまり、画像の情報を補完するクラスなのでほしい画像の番号から呼び出すことになる。
			かならず一度だけ最初に Sprite::GetInstance( )->Initialize( ) で初期化する。

			例1. 画像の読み込み方法
			Sprite::GetInstance( )->loadBmpData( bmpNo , hBITMAP ) ;

			例2. 画像をセット
			Sprite::GetInstance()->setBmpData(
					bmpNo ,
					anchor ,
					x , y ,
					u , v ,
					width , height ,
					scaleX , scaleY
				) ;


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>

// クラスの宣言
class Sprite
{
	static const int MAX_BMP_SPRITE = 1024 ;

	public :
	struct SpriteData {
		HBITMAP _hBmp ;
		bool	_useFlg ;				// 描画するかどうかのフラグ
		int		_anchor ;				// アンカーの位置
		float	_x , _y ;				// 座標
		float	_u , _v ;				// 切り取り座標
		float	_w , _h ;				// 幅高さ
		float	_scaleX , _scaleY ;		// 拡大率
		bool	_useAlpha  ;			// 透明処理を行うかどうかのフラグ
		int		_alpha ;				// 透明度
		bool	_useRotate ;			// 回転処理を行うかどうかのフラグ
		float	_degree ;				// 角度
		bool	_useRender ;			// スプライトが描画されているか
	} ;
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 

		~Sprite( ) ;

		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;
		int loadBmpDataFor( int arg_bmpNo , HBITMAP arg_hbmp , int arg_no ) ;	// いくつまで入れるかの指定
		int clearData( int arg_bmpNo ) ;

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;						// 描画するかどうかのフラグをセット
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;					// 透明処理をするかどうかのフラグをセット
		int setUseRotate( int arg_bmpNo , bool arg_useRotate ) ;				// 回転処理するかどうかのフラグをセット
		int setBmpXY( int arg_bmpNo , float arg_x , float arg_y ) ;			// ポジションのセット
		int setBmpUV( int arg_bmpNo , float arg_u , float arg_v ) ;			// 切り取り位置のセット
		int setBmpWH( int arg_bmpNo , float arg_w , float arg_h ) ;			// 幅、高さのセット
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;		// 拡大率のセット
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;						// アンカーのセット
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;							// 透明度のセット
		int setAngle( int arg_bmpNo , float arg_angle ) ;						// 角度のセット
		int setUseRender( int arg_bmpNo , bool arg_flg ) ;
		int setBmpData(															// すべてのセット
				int arg_bmpNo ,
				int arg_anchor ,
				float arg_x , float arg_y ,
				float arg_u , float arg_v ,
				float arg_w , float arg_h ,
				float arg_scaleX , float arg_scaleY ,
				int arg_alpha = 255 ,
				float arg_degree = 0
			) ;

		/*/
		/*	最大描画数の取得
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_SPRITE ) ;
		}
		/*/
		/*	描画するかの取得
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	透明処理するかの取得
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useAlpha ) ;
		}
		/*/
		/*	回転処理するかの取得
		/*/
		int getUseRotate( int arg_bmpNo ) const
		{
			return(bmpBGTable_[ arg_bmpNo ]._useRotate ) ;
		}

		/*/
		/*	ビットマップのハンドルのアクセッサ
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	アンカーを取得
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	X軸の取得
		/*/
		float getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	Y軸の取得
		/*/
		float getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	X軸の切り取り位置の取得
		/*/
		float getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y軸の切り取り位置の取得
		/*/
		float getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	幅の取得
		/*/
		float getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	高さの取得
		/*/
		float getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	幅の拡大率の取得
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	高さの拡大率の取得
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._scaleY ) ;
		}
		/*/
		/*	透明度の取得
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._alpha ) ;
		}
		/*/
		/*	回転角度の取得
		/*/
		float getBmpAngle( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._degree ) ;
		}
		/*/
		/*	UseRenderの取得
		/*/
		bool getUseRender( int arg_bmpNo ) const
		{
			return ( bmpBGTable_[ arg_bmpNo ]._useRender ) ;
		}


		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static Sprite* GetInstance( )
		{
			static Sprite v ;
			return &v ;
		}

	private :
		/*/
		/*	コンストラクタ
		/*/
		Sprite( ) {	} ;

		SpriteData bmpBGTable_[ MAX_BMP_SPRITE ] ;			// 画像データ


} ;


