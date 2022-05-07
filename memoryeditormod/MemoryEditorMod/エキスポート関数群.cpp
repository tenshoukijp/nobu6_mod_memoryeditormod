#include "カスタム駆動関数.h"
#include <map>
#include <time.h>
#include "Menu.h"
#include "ModMode.h."

#include "ProcessHandle.h"

using namespace std;

// 天翔記のウィンドウハンドル
HWND tenshouWND=NULL;

// TSMod.dllのハンドル
HMODULE hModuleTSMod = NULL;



void WINAPI meOnInitialize(HANDLE hCallDLLHandle) {
	// ウィンドウハンドルを確保しておく。フォアグランドなどの情報を使うこともある。
	tenshouWND = ::GetCurrentWindowHandle();
	if ( !tenshouWND ) { tenshouWND = FindWindow("Tenshouki95", NULL); }

	// TSModから呼ばれたか、他から呼ばれたかの判定
	CheckModMode(hCallDLLHandle);

	AddMemoryEditorMenu();

	カスタム駆動関数.On_起動時();
}

void WINAPI meOnMainGameStart() {


	カスタム駆動関数.On_メインゲーム開始();
}

void WINAPI meOnFinalize() {
	カスタム駆動関数.On_終了時();
}


void WINAPI meOnApplicationSelectMenuItem(int 選択メニュー番号) {
	カスタム駆動関数.On_アプリケーションメニュー選択時(選択メニュー番号);
}
