/*
______________________________________________________________________________________________

	FILE : Chip.h
	NAME : Teacher.K

	________/ Explanation of file /___________________________________________________________

		チップ背景を描画するクラス
		
			--- 主な使い方 ---
			インスタンス1つで一枚のチップ背景を描画する。
			もらったデータをグリッドを基準に配置する。
			selectBmpで選択されたビットマップを CHIP_X * CHIP_Y で縦に切り取り、
			チップテーブルの番号に従って描画を行う。
			また m_x , m_y メンバを使用してのチップ背景スクロールが可能である。
			これをうまく使うことにより無限スクロールや横スクロールアクション等の
			ステージを表現できる。

			かならず一度だけ最初に Sprite::GetInstance( )->Initialize( ) で初期化し、
			setMapSize( ) と RenderMapSize( ) を指定しなくてはいけない。

			setMapSize はマップデータの配列の幅と高さを指定する。
			RenderMapSize は一画面に描画できる 横 と 縦 のグリッド数を受け取る。


￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
*/
#include <windows.h>
#include <stdio.h>
#include <math.h>

#define CHIP_X	128
#define CHIP_Y	32
#define CHIP_W	64
#define CHIP_H	64

struct ChipData {
	HBITMAP _hBmp ;
	int		_bmpNo ;				// 自分の要素番号 ( _hBmp と関連付けるため )
	bool	_useFlg ;				// 描画するかどうかのフラグ
	int		_anchor ;				// アンカーの位置
	float	_x , _y ;				// グローバル座標
	int		_u , _v ;				// 切り取り座標
	int		_w , _h ;				// 幅高さ
	int		_arrayX , _arrayY ;		// 配列座標
	float	_scaleX , _scaleY ;		// 拡大率
	bool	_useAlpha  ;			// 透明処理を行うかどうかのフラグ
	int		_alpha ;				// 透明度
	bool	_useRotate ;			// 回転処理を行うかどうかのフラグ
	float	_degree ;				// 角度
} ;

// クラスの宣言
class Chip
{
	static const int MAX_BMP_CBG = 4096 ;

	public :
		/*/
		/*	初期化
		/*/
		void Initialize( ) ; 
		/*/
		/*	終了化
		/*/
		void Finalize( ) ; 

		~Chip( ) ;

		int RenderMapSize( int arg_w , int arg_h ) ;
		int setMapSize( int arg_w , int arg_h ) ;
		int loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp ) ;			// bmp画像の読み込み
		int loadBmpDataAll( HBITMAP arg_hbmp ) ;						// 一括読み込み
		int clearData( int arg_bmpNo ) ;

		int setChipMap( int arg_x , int arg_y , int arg_chipNo ) ;		// チップマップをセット
		int clearChipMap( ) ;											// チップマップをクリア

		int setUseFlg( int arg_bmpNo , bool arg_useFlg ) ;				// 描画するかどうかのフラグをセット
		int setUseAlpha( int arg_bmpNo , bool arg_useAlpha ) ;			// 透明処理をするかどうかのフラグをセット
		int setUseRotate( int arg_bmpNo , bool arg_useRotate ) ;		// 回転処理するかどうかのフラグをセット
		int setBmpXY( int arg_bmpNo , float arg_x , float arg_y ) ;		// ポジションのセット
		int setBmpUV( int arg_bmpNo , int arg_u , int arg_v ) ;			// 切り取り位置のセット
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;			// 幅、高さのセット
		int setBmpScale( int arg_bmpNo , float arg_w , float arg_h ) ;	// 拡大率のセット
		int setAnchor( int arg_bmpNo , int arg_anchor ) ;				// アンカーのセット
		int setAlpha( int arg_bmpNo , int arg_alpha ) ;					// 透明度のセット
		int setAngle( int arg_bmpNo , float arg_angle ) ;				// 角度のセット
		int setArray( int arg_bmpNo , int arg_ax , int arg_ay  ) ;		// 配列座標のセット
		int setChipData(												// すべてのセット
				int arg_bmpNo ,
				int arg_anchor ,
				int arg_arrayX , int arg_arrauY ,
				float arg_x , float arg_y ,
				int arg_u , int arg_v ,
				int arg_w , int arg_h ,
				float arg_scaleX , float arg_scaleY ,
				int arg_alpha = 255 ,
				float arg_degree = 0
			) ;
		void Update( ) ;												// チップの更新
		int setScrollSize( int arg_x , int arg_y ) ;					// スクロール

		/*/
		/*	チップテーブルの取得
		/*/
		int* getChipTable( )
		{
			return( m_chipTable_ ) ;
		}

		/*/
		/*	最大描画数の取得
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_CBG ) ;
		}
		/*/
		/*	描画するかの取得
		/*/
		int getUseFlg( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useFlg ) ;
		}
		/*/
		/*	透明処理するかの取得
		/*/
		int getUseAlpha( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useAlpha ) ;
		}
		/*/
		/*	回転処理するかの取得
		/*/
		int getUseRotate( int arg_bmpNo ) const
		{
			return(bmpCBGTable_[ arg_bmpNo ]._useRotate ) ;
		}

		/*/
		/*	ビットマップのハンドルのアクセッサ
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	アンカーを取得
		/*/
		int getBmpAnchor( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._anchor ) ;
		}
		/*/
		/*	グローバル座標 X軸の取得
		/*/
		float getBmpXPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._x ) ;
		}
		/*/
		/*	グローバル座標 Y軸の取得
		/*/
		float getBmpYPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._y ) ;
		}
		/*/
		/*	配列座標 X軸の取得
		/*/
		int getArrayX( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._arrayX ) ;
		}
		/*/
		/*	配列座標 Y軸の取得
		/*/
		int getArrayY( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._arrayY ) ;
		}
		/*/
		/*	X軸の切り取り位置の取得
		/*/
		int getBmpUPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._u ) ;
		}
		/*/
		/*	Y軸の切り取り位置の取得
		/*/
		int getBmpVPos( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._v ) ;
		}
		/*/
		/*	幅の取得
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	高さの取得
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._h ) ;
		}
		/*/
		/*	幅の拡大率の取得
		/*/
		float getBmpScaleX( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._scaleX ) ;
		}
		/*/
		/*	高さの拡大率の取得
		/*/
		float getBmpScaleY( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._scaleY ) ;
		}
		/*/
		/*	透明度の取得
		/*/
		int getBmpAlpha( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._alpha ) ;
		}
		/*/
		/*	回転角度の取得
		/*/
		float getBmpAngle( int arg_bmpNo ) const
		{
			return ( bmpCBGTable_[ arg_bmpNo ]._degree ) ;
		}
		/*/
		/*	スクロールの取得
		/*/
		int getScrollX( ) const
		{
			return ( scrollX_ ) ;
		}
		/*/
		/*	スクロールの取得
		/*/
		int getScrollY( ) const
		{
			return ( scrollY_ ) ;
		}
		/*/
		/*	RENDER MAP SIZE X の取得
		/*/
		int getRenderMapSizeX( ) const
		{
			return ( renderMap_w_ ) ;
		}
		/*/
		/*	RENDER MAP SIZE Y の取得
		/*/
		int getRenderMapSizeY( ) const
		{
			return ( renderMap_h_ ) ;
		}
		/*/
		/*	MAP SIZE X の取得
		/*/
		int getMapSizeX( ) const
		{
			return ( map_w_ ) ;
		}
		/*/
		/*	MAP SIZE Y の取得
		/*/
		int getMapSizeY( ) const
		{
			return ( map_h_ ) ;
		}

		/*/
		/*	sin の取得
		/*/
		float sinWave( float arg_time , int arg_width , int arg_strength = 180 )
		{
			return( (float)(sin( arg_time * 3.14 / arg_strength ) * arg_width) ) ;
		}
		/*/
		/*	cos の取得
		/*/
		float cosWave( float arg_time , int arg_width , int arg_strength = 180 )
		{
			return( (float)(cos( arg_time * 3.14 / arg_strength ) * arg_width) ) ;
		}

		/*/
		/*	Shingleton -> インスタンスの取得
		/*/
		static Chip* GetInstance( )
		{
			static Chip v ;
			return &v ;
		}

	private :
		/*/
		/*	コンストラクタ
		/*/
		Chip( ) {	} ;

		ChipData bmpCBGTable_[ MAX_BMP_CBG ] ;							// 画像データ
		int m_chipTable_[ CHIP_X * CHIP_Y ] ;							// ChipBgData内のマップデータ
		int map_w_ , map_h_ ;											// マップの幅と高さ
		int renderMap_w_ , renderMap_h_ ;								// 一画面上のマップの幅と高さ
		int scrollX_ , scrollY_ ;										// スクロール座標


} ;


