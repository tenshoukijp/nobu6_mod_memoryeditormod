/*
 * 噴出しなどにおける、｢主体・客体・第３者」のID
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;


typedef vector<string> 文字列リスト型;

// --------------------------------------メッセージ関連情報
struct メッセージ関連情報型 {
	WORD 第１人称【武将番号】;	// 自分のID(通常武将ID)
	WORD 第２人称【武将番号】;	// 相手のID(通常武将ID。イベント顔や商人顔は531,農民顔は532となる)
	WORD 第３人称【武将番号】;	// 第３者のID(通常1stPersonと2ndPersonの会話の中で出てくる人のID);

	// -----------以下予備。将来の拡張に対する互換性確保のため。
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};





// --------------------------------------文字列判定のための正規表現関数

namespace 関数 {

	// 対象文字列に、部分文字列が含まれているかどうかの判定
	int Is_文字列マッチ( string 対象文字列, string 部分文字列);


}