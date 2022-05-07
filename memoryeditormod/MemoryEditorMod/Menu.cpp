#include <windows.h>
#include <string>

#include "カスタム駆動関数.h"

#include "ModMode.h"
#include "Menu.h"

using namespace std;

// グローバル。メニューのハンドル。
static HMENU hMenu;

extern HWND tenshouWND; // 天翔記のウィンドウハンドル


// メニューアイテムの追加
// menuname メニューアイテムの文字列。"---"だとセパレータとなる。
BOOL AddMenuItem(string menuname, int position, int wID) {

	MENUITEMINFO info;

	// 作成したメニュー項目を追加する
	ZeroMemory( &info, sizeof(info) );
	info.cbSize = sizeof( info );

	// ID番号の指定が無い場合
	if ( wID == -1 ) {
		info.fMask = MIIM_TYPE;
		// ID番号の指定がある場合
	} else {
		info.fMask = MIIM_TYPE | MIIM_ID;
		info.wID = wID;
	}
	if ( menuname == "---" ) {
		info.fType = MFT_SEPARATOR;
	} else {
		info.fType = MFT_STRING;
	}
	info.dwTypeData =(LPSTR)menuname.c_str();
	BOOL success = InsertMenuItem( hMenu, position, FALSE, &info );
	DrawMenuBar( tenshouWND );

	return success;
}



void AddMemoryEditorMenu() {

	// ------------------------------ メニューハンドル確保と、メニュー追加
	hMenu = GetMenu(tenshouWND);
	if ( iCallDLLMODE == kModePluginMod ) {
		AddMenuItem( "メモリエディタ", RESOURCE_MENU_ID_SPECIAL_EFFECTS_OF_SCREEN_DRAWING, RESOURCE_MENU_ID_MEMORY_EDITOR_MOD );
	}
}



