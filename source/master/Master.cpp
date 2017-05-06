#pragma once

#include <vector>
#include "Master.hpp"
#include <stdio.h>

namespace MasterData
{
	std::vector<ChipDataInfo> ChipData ;
	std::vector<SceneGameInfo> SceneAnim ;
	std::vector<SceneGameInfo> SceneGame01 ;
	std::vector<SceneGameInfo> SceneGame02 ;
	std::vector<SceneGameInfo> SceneGame03 ;
	std::vector<AnimInfo> AnimPlayer ;
	std::vector<AnimInfo> AnimPlayer2 ;
	std::vector<AnimInfo> AnimWaiwai ;
	std::vector<AnimInfo> AnimBoss ;

	/*/
	/*	チップデータのロード
	/*/
	void LoadChipData( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	ChipData
		/*/
		sprintf( path , "data/masterdata/ChipData.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		ChipData.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				ChipDataInfo Info ;

				Info.Load( buf ) ;
				ChipData.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	アニメシーンのロード
	/*/
	void LoadSceneAnim( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	GimmickData
		/*/
		sprintf( path , "data/masterdata/SceneAnim.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		SceneAnim.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				SceneGameInfo Info ;

				Info.Load( buf ) ;
				SceneAnim.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	ゲームシーン01のロード
	/*/
	void LoadSceneGame01( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	GimmickData
		/*/
		sprintf( path , "data/masterdata/SceneGame01.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		SceneGame01.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				SceneGameInfo Info ;

				Info.Load( buf ) ;
				SceneGame01.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	ゲームシーン02のロード
	/*/
	void LoadSceneGame02( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	GimmickData
		/*/
		sprintf( path , "data/masterdata/SceneGame02.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		SceneGame02.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				SceneGameInfo Info ;

				Info.Load( buf ) ;
				SceneGame02.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	ゲームシーン03のロード
	/*/
	void LoadSceneGame03( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	GimmickData
		/*/
		sprintf( path , "data/masterdata/SceneGame03.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		SceneGame03.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				SceneGameInfo Info ;

				Info.Load( buf ) ;
				SceneGame03.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	アニメーション(プレイヤー)のロード
	/*/
	void LoadAnimPlayer( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	AnimPlayer
		/*/
		sprintf( path , "data/masterdata/AnimPlayer.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		AnimPlayer.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				AnimInfo Info ;

				Info.Load( buf ) ;
				AnimPlayer.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	アニメーション(プレイヤー2)のロード
	/*/
	void LoadAnimPlayer2( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	AnimPlayer2
		/*/
		sprintf( path , "data/masterdata/AnimPlayer2.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		AnimPlayer2.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				AnimInfo Info ;

				Info.Load( buf ) ;
				AnimPlayer2.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	アニメーション(リアクション)のロード
	/*/
	void LoadAnimWaiwai( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	AnimWaiwai
		/*/
		sprintf( path , "data/masterdata/AnimWaiwai.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		AnimWaiwai.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				AnimInfo Info ;

				Info.Load( buf ) ;
				AnimWaiwai.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	/*/
	/*	アニメーション(ボス)のロード
	/*/
	void LoadAnimBoss( )
	{
		char path[256] ;
		char buf[1024] ;

		/*/
		/*	AnimBoss
		/*/
		sprintf( path , "data/masterdata/AnimBoss.csv" ) ;
		FILE *fp = fopen( path , "r" ) ;
		if ( fp == nullptr )
		{
			return ;
		}
		AnimBoss.clear( ) ;

		while ( fgets(buf , sizeof(buf) , fp) != nullptr )
		{
			if ( (strlen(buf) >= 3) && (strncmp(buf , "ON," , 3) == 0) )
			{
				AnimInfo Info ;

				Info.Load( buf ) ;
				AnimBoss.push_back( Info ) ;
			}
		}

		fclose( fp ) ;
	}

	void ReLoad( )
	{
		LoadChipData( ) ;
		LoadSceneAnim( ) ;
		LoadSceneGame01( ) ;
		LoadSceneGame02( ) ;
		LoadSceneGame03( ) ;
		LoadAnimPlayer( ) ;
		LoadAnimPlayer2( ) ;
		LoadAnimWaiwai( ) ;
		LoadAnimBoss( ) ;
	}

}


