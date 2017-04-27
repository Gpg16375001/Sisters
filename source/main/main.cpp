
#include <Windows.h>
#include "main.h"
#include "Common.h"

int WINAPI WinMain( HINSTANCE , HINSTANCE , LPSTR , int )
{
	// クラス名とタイトルの設定
	MainApp app( TEXT("Sisters") , TEXT("Sisters") ) ;

	// アプリをスタート
	app.Start( ) ;

	return 0;
}


/*/
/*	コンストラクタ
/*/
MainApp::MainApp( TCHAR* szClassName , TCHAR* szTitleName )
	: WinMain( szClassName , szTitleName )
	, is_debug_render_( true )
{
	printf( "始まったよ!\n" ) ;

}

/*/
/*	デストラクタ
/*/
MainApp::~MainApp( )
{

}

/*/
/*	<-継承-> ウインドプロシージャ
/*/
LRESULT MainApp::WndProc( HWND hWnd , UINT msg , UINT wParam , LONG lParam )
{
	/*/
	/*	WinMainのプロシージャで処理をするのでここは関係ない。
	/*	WinMainのプロシージャが終わり次第呼ばれる。
	/*/
//	printf( "MainAppのプロシージャが発行されました。\n" ) ;

	return DefWindowProc( hWnd , msg , wParam , lParam ) ;
}

/*/
/*	<-継承-> 初期化
/*	WM_CREATE と同じ。( こちらの方が早い )
/*/
void MainApp::Initalize( )
{
	printf( "//-----------------------------------\n" ) ;
	printf( "Initialize が発行されました\n" );

	// 描画場所の確保
	Renderer::GetInstance()->Initialize( ) ;
	Renderer::GetInstance()->setHDC( GetHWindow( ) , GetHDCBack( ) , GetHDCWork() ) ;

	// Key 情報の取得 初期化
	KeyManager::GetInstance()->Initialize( ) ;

	// 画像データ庫の初期化
	BitmapData::GetInstance()->Initialize( ) ;
	BackGround::GetInstance()->Initialize( ) ;
	Chip::GetInstance()->Initialize( ) ;
	Sprite::GetInstance()->Initialize( ) ;

	// 画像の読み込み
	BitmapData::GetInstance()->loadData(  0 , TEXT("data/image/bgs/bg01.bmp") , 2000 , 1000 ) ;						// 背景01
	BitmapData::GetInstance()->loadData(  1 , TEXT("data/image/bgs/bg04.bmp") , 2000 , 1000 ) ;						// 背景02
	BitmapData::GetInstance()->loadData(  2 , TEXT("data/image/chips/all_grass.bmp") , 1024 , 512 ) ;				// 地面 ( チップ )
	BitmapData::GetInstance()->loadData(  3 , TEXT("data/image/sprites/gimic/marunoko.bmp") , 128 , 128 ) ;			// 丸鋸
	BitmapData::GetInstance()->loadData(  5 , TEXT("data/image/sprites/gimic/movefloor.bmp") , 256 , 64 ) ;			// 動く床
	BitmapData::GetInstance()->loadData(  6 , TEXT("data/image/bgs/bg02.bmp") , 2000 , 1000 ) ;						// 背景02
	BitmapData::GetInstance()->loadData(  7 , TEXT("data/image/sprites/gimic/huriko.bmp") , 128 , 128 ) ;			// 振り子 ( 本体 )
	BitmapData::GetInstance()->loadData(  8 , TEXT("data/image/sprites/gimic/rope.bmp") , 320 , 320 ) ;				// 振り子 ( 鎖 )
	BitmapData::GetInstance()->loadData(  9 , TEXT("data/image/sprites/gimic/shock.bmp") , 128 , 64 ) ;				// 電気
	BitmapData::GetInstance()->loadData( 10 , TEXT("data/image/sprites/gimic/speedup.bmp") , 128 , 64 ) ;			// スピードアップ
	BitmapData::GetInstance()->loadData( 11 , TEXT("data/image/sprites/PlayerDeth.bmp") , 200 , 178 ) ;				// プレイヤーの死に絵
	BitmapData::GetInstance()->loadData( 12 , TEXT("data/image/sprites/hp.bmp") , 200 , 178 ) ;						// ハート
	BitmapData::GetInstance()->loadData( 13 , TEXT("data/image/sprites/gimic/cloud.bmp") , 128 , 64 ) ;				// 雲
	BitmapData::GetInstance()->loadData( 14 , TEXT("data/image/sprites/vball.bmp") , 200 , 178 ) ;					// バリア
	BitmapData::GetInstance()->loadData( 15 , TEXT("data/image/sprites/gimic/ammo.bmp") , 64 , 64 ) ;				// 弾
	BitmapData::GetInstance()->loadData( 16 , TEXT("data/image/sprites/gimic/enemy_pod.bmp") , 256 , 64 ) ;			// 敵Pod
	BitmapData::GetInstance()->loadData( 17 , TEXT("data/image/bgs/bg03.bmp") , 1000 , 800 ) ;						// 背景03 ( 真っ黒 )
	BitmapData::GetInstance()->loadData( 18 , TEXT("data/image/sprites/object/grass.bmp") , 200 , 64 ) ;			// くさ
	BitmapData::GetInstance()->loadData( 19 , TEXT("data/image/sprites/Enemy/Enemy.bmp") , 900 , 80 ) ;				// てき

	BitmapData::GetInstance()->loadData( 20 , TEXT("data/image/sprites/player/PlayerR01.bmp") , 100 , 89 ) ;		// プレイヤー右向き 静止01
	BitmapData::GetInstance()->loadData( 21 , TEXT("data/image/sprites/player/PlayerR02.bmp") , 100 , 89 ) ;		// プレイヤー右向き 静止02
	BitmapData::GetInstance()->loadData( 22 , TEXT("data/image/sprites/player/PlayerR03.bmp") , 100 , 89 ) ;		// プレイヤー右向き 静止03
	BitmapData::GetInstance()->loadData( 23 , TEXT("data/image/sprites/player/PlayerR04.bmp") , 100 , 89 ) ;		// プレイヤー右向き 静止04
	BitmapData::GetInstance()->loadData( 24 , TEXT("data/image/sprites/player/PlayerR05.bmp") , 100 , 89 ) ;		// プレイヤー右向き 歩き01
	BitmapData::GetInstance()->loadData( 25 , TEXT("data/image/sprites/player/PlayerR06.bmp") , 100 , 89 ) ;		// プレイヤー右向き 歩き02
	BitmapData::GetInstance()->loadData( 26 , TEXT("data/image/sprites/player/PlayerR07.bmp") , 100 , 89 ) ;		// プレイヤー右向き 歩き03
	BitmapData::GetInstance()->loadData( 27 , TEXT("data/image/sprites/player/PlayerR08.bmp") , 100 , 89 ) ;		// プレイヤー右向き 歩き04
	BitmapData::GetInstance()->loadData( 28 , TEXT("data/image/sprites/player/PlayerR09.bmp") , 100 , 89 ) ;		// プレイヤー右向き ジャンプ
	BitmapData::GetInstance()->loadData( 29 , TEXT("data/image/sprites/player/PlayerR10.bmp") , 100 , 89 ) ;		// プレイヤー右向き 落ち
	BitmapData::GetInstance()->loadData( 30 , TEXT("data/image/sprites/player/PlayerL01.bmp") , 100 , 89 ) ;		// プレイヤー左向き 静止01
	BitmapData::GetInstance()->loadData( 31 , TEXT("data/image/sprites/player/PlayerL02.bmp") , 100 , 89 ) ;		// プレイヤー左向き 静止02
	BitmapData::GetInstance()->loadData( 32 , TEXT("data/image/sprites/player/PlayerL03.bmp") , 100 , 89 ) ;		// プレイヤー左向き 静止03
	BitmapData::GetInstance()->loadData( 33 , TEXT("data/image/sprites/player/PlayerL04.bmp") , 100 , 89 ) ;		// プレイヤー左向き 静止04
	BitmapData::GetInstance()->loadData( 34 , TEXT("data/image/sprites/player/PlayerL05.bmp") , 100 , 89 ) ;		// プレイヤー左向き 歩き01
	BitmapData::GetInstance()->loadData( 35 , TEXT("data/image/sprites/player/PlayerL06.bmp") , 100 , 89 ) ;		// プレイヤー左向き 歩き02
	BitmapData::GetInstance()->loadData( 36 , TEXT("data/image/sprites/player/PlayerL07.bmp") , 100 , 89 ) ;		// プレイヤー左向き 歩き03
	BitmapData::GetInstance()->loadData( 37 , TEXT("data/image/sprites/player/PlayerL08.bmp") , 100 , 89 ) ;		// プレイヤー左向き 歩き04
	BitmapData::GetInstance()->loadData( 38 , TEXT("data/image/sprites/player/PlayerL09.bmp") , 100 , 89 ) ;		// プレイヤー左向き ジャンプ
	BitmapData::GetInstance()->loadData( 39 , TEXT("data/image/sprites/player/PlayerL10.bmp") , 100 , 89 ) ;		// プレイヤー左向き 落ち
	BitmapData::GetInstance()->loadData( 40 , TEXT("data/image/sprites/player/PlayerRDamage.bmp") , 100 , 89 ) ;	// プレイヤー右向き ダメージ
	BitmapData::GetInstance()->loadData( 41 , TEXT("data/image/sprites/player/PlayerLDamage.bmp") , 100 , 89 ) ;	// プレイヤー左向き ダメージ

	BitmapData::GetInstance()->loadData( 60 , TEXT("data/image/sprites/start2.bmp") , 256 , 40 ) ;					// スタート
	BitmapData::GetInstance()->loadData( 61 , TEXT("data/image/sprites/object/hunsui.bmp") , 1600 , 178 ) ;			// 噴水
	BitmapData::GetInstance()->loadData( 62 , TEXT("data/image/sprites/object/kanban.bmp") , 200 , 178 ) ;			// 看板
	BitmapData::GetInstance()->loadData( 63 , TEXT("data/image/sprites/waiwai.bmp") , 200 , 89 ) ;					// リアクション（わいわい）

	// 背景読み込み
	BackGround::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 0 ) ) ;
	BackGround::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 6 ) ) ;
	BackGround::GetInstance()->loadBmpData( 2 , BitmapData::GetInstance()->getBmpData( 1 ) ) ;

	SceneCut::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 17 ) ) ;

	// チップ読み込み
	Chip::GetInstance()->setMapSize( CHIP_MAP_SIZE_X , CHIP_MAP_SIZE_Y ) ;
	Chip::GetInstance()->RenderMapSize( 12 + 10 , 10 + 4 ) ;
	Chip::GetInstance()->loadBmpDataAll( BitmapData::GetInstance()->getBmpData( 2 ) ) ;

	// Sprite の読み込み
//	Sprite::GetInstance()->loadBmpData( 0 , BitmapData::GetInstance()->getBmpData( 4 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1 , BitmapData::GetInstance()->getBmpData( 60 ) ) ;	// スタート
	Sprite::GetInstance()->loadBmpData( 3 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 4 , BitmapData::GetInstance()->getBmpData( 11 ) ) ;
	Sprite::GetInstance()->loadBmpData( 5 , BitmapData::GetInstance()->getBmpData( 14 ) ) ;
	Sprite::GetInstance()->loadBmpData( 8 , BitmapData::GetInstance()->getBmpData( 12 ) ) ;
	Sprite::GetInstance()->loadBmpDataFor( 10 , BitmapData::GetInstance()->getBmpData( 3 ) , 40 ) ;		// 10 ~ 49 まで　まるのこ
	Sprite::GetInstance()->loadBmpDataFor( 50 , BitmapData::GetInstance()->getBmpData( 5 ) , 40 ) ;		// 50 ~ 89 まで　動く床
	Sprite::GetInstance()->loadBmpDataFor( 90 , BitmapData::GetInstance()->getBmpData( 8 ) , 10 ) ;		// 90 ~ 99 まで　振り子のくさり
	Sprite::GetInstance()->loadBmpDataFor( 100 , BitmapData::GetInstance()->getBmpData( 7 ) , 10 ) ;	// 100 ~ 109 まで　振り子
	Sprite::GetInstance()->loadBmpDataFor( 150 , BitmapData::GetInstance()->getBmpData( 13 ) , 20 ) ;	// 150 ~ 199 まで　雲
	Sprite::GetInstance()->loadBmpDataFor( 200 , BitmapData::GetInstance()->getBmpData( 16 ) , 20 ) ;	// 200 ~ 219 まで　敵ポッド

	Sprite::GetInstance()->loadBmpDataFor( 250 , BitmapData::GetInstance()->getBmpData( 18 ) , 50 ) ;	// 250 ~ 299 まで　草
	Sprite::GetInstance()->loadBmpDataFor( 300 , BitmapData::GetInstance()->getBmpData( 61 ) , 10 ) ;	// 300 ~ 309 まで　噴水
	Sprite::GetInstance()->loadBmpDataFor( 310 , BitmapData::GetInstance()->getBmpData( 62 ) , 10 ) ;	// 310 ~ 319 まで　看板
	Sprite::GetInstance()->loadBmpDataFor( 320 , BitmapData::GetInstance()->getBmpData( 63 ) , 10 ) ;	// 320 ~ 329 まで　わいわい
	Sprite::GetInstance()->loadBmpDataFor( 330 , BitmapData::GetInstance()->getBmpData( 19 ) , 10 ) ;	// 330 ~ 339 まで　敵

	Sprite::GetInstance()->loadBmpDataFor( 400 , BitmapData::GetInstance()->getBmpData( 9 ) , 50 ) ;	// 400 ~ 449 まで　電気
	Sprite::GetInstance()->loadBmpDataFor( 450 , BitmapData::GetInstance()->getBmpData( 10 ) , 10 ) ;	// 450 ~ 459 まで　SpeedUp
	Sprite::GetInstance()->loadBmpDataFor( 500 , BitmapData::GetInstance()->getBmpData( 15 ) , 500 ) ;	// 500 ~ 999 まで　弾

	Sprite::GetInstance()->loadBmpData( 2000 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2001 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2002 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2003 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2004 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2005 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2006 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2007 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2008 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2009 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2010 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 2011 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2012 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2013 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2014 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2015 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2016 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2017 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2018 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2019 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2020 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 2021 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	// 残像たち
	Sprite::GetInstance()->loadBmpData( 1100 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1101 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1102 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1103 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1104 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1105 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1106 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1107 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1108 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1109 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1110 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1111 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1112 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1113 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1114 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1115 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1116 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1117 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1118 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1119 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1120 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1121 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1200 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1201 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1202 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1203 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1204 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1205 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1206 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1207 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1208 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1209 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1210 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1211 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1212 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1213 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1214 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1215 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1216 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1217 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1218 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1219 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1220 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1221 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1300 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1301 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1302 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1303 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1304 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1305 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1306 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1307 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1308 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1309 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1310 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1311 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1312 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1313 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1314 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1315 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1316 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1317 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1318 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1319 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1320 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1321 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1400 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1401 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1402 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1403 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1404 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1405 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1406 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1407 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1408 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1409 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1410 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1411 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1412 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1413 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1414 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1415 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1416 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1417 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1418 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1419 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1420 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1421 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1500 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1501 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1502 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1503 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1504 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1505 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1506 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1507 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1508 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1509 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1510 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1511 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1512 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1513 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1514 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1515 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1516 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1517 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1518 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1519 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1520 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1521 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1600 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1601 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1602 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1603 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1604 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1605 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1606 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1607 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1608 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1609 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1610 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1611 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1612 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1613 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1614 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1615 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1616 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1617 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1618 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1619 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1620 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1621 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1700 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1701 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1702 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1703 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1704 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1705 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1706 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1707 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1708 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1709 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1710 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1711 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1712 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1713 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1714 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1715 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1716 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1717 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1718 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1719 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1720 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1721 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1800 , BitmapData::GetInstance()->getBmpData( 30 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1801 , BitmapData::GetInstance()->getBmpData( 31 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1802 , BitmapData::GetInstance()->getBmpData( 32 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1803 , BitmapData::GetInstance()->getBmpData( 33 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1804 , BitmapData::GetInstance()->getBmpData( 34 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1805 , BitmapData::GetInstance()->getBmpData( 35 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1806 , BitmapData::GetInstance()->getBmpData( 36 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1807 , BitmapData::GetInstance()->getBmpData( 37 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1808 , BitmapData::GetInstance()->getBmpData( 38 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1809 , BitmapData::GetInstance()->getBmpData( 39 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1810 , BitmapData::GetInstance()->getBmpData( 41 ) ) ;

	Sprite::GetInstance()->loadBmpData( 1811 , BitmapData::GetInstance()->getBmpData( 20 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1812 , BitmapData::GetInstance()->getBmpData( 21 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1813 , BitmapData::GetInstance()->getBmpData( 22 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1814 , BitmapData::GetInstance()->getBmpData( 23 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1815 , BitmapData::GetInstance()->getBmpData( 24 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1816 , BitmapData::GetInstance()->getBmpData( 25 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1817 , BitmapData::GetInstance()->getBmpData( 26 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1818 , BitmapData::GetInstance()->getBmpData( 27 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1819 , BitmapData::GetInstance()->getBmpData( 28 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1820 , BitmapData::GetInstance()->getBmpData( 29 ) ) ;
	Sprite::GetInstance()->loadBmpData( 1821 , BitmapData::GetInstance()->getBmpData( 40 ) ) ;

	// シーン
	SceneManager::GetInstance()->Initialize() ;
}

/*/
/*	<-継承-> 終了化
/*/
void MainApp::Finalize( )
{

}

/*/
/*	<-継承-> メインループ
/*/
void MainApp::Update( )
{
	//printf( "//-----------------------------------\n" ) ;
	//printf( "メインループ : Updateイベントが発行されました\n" );
	// キー情報更新
	KeyManager::GetInstance()->update( ) ;

	// 更新
	Update_( ) ;

	// 描画
	Render_( ) ;
}

/*/
/*	更新 ( セット )
/*/
void MainApp::Update_( )
{
	// シーンの更新
	SceneManager::GetInstance()->Update( g_state ) ;			// -------------------------------------- Gvl

}

/*/
/*	描画
/*/
void MainApp::Render_( )
{
	//printf( "Main::Render_ が発行されました\n" ) ;

	// シーン描画の配置
//	SceneManager::GetInstance()->Render( ) ;

	// デバッグの表示


}



