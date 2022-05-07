/*
 * コマンド名情報
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>

using namespace std;

typedef int メニュー番号型;

namespace 関数 {

	namespace アプリケーション {

		// 返り値がメニューアイテムに割り当てられた「番号」
		// この番号をどこかに保存しておき、、「On_アプリケーションのメニューアイテムのクリック時」に判定用として利用する。
		int メニューアイテム追加( string メニュー文字列 );
	}
}