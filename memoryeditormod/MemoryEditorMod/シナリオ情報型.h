/*
 * 部隊名情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>


typedef char** シナリオ説明文型＆;
typedef char *_シナリオ説明文型[3]; 
#define シナリオ説明文型 static _シナリオ説明文型

typedef char** シナリオメニュー型＆;
typedef char *_シナリオメニュー型[6]; 
#define シナリオメニュー型 static _シナリオメニュー型


namespace 関数 {
	// シナリオのタイトル名を得る。
	// シナリオ番号は、１～６の指定のこと。
	string Get_シナリオ名(int シナリオ番号);

	// 現在選択されている(あるいはプレイ中の)シナリオ番号を得る。
	// どのシナリオにも属さない場合、-1が返ってくる。
	int Get_現在のシナリオ番号();
}