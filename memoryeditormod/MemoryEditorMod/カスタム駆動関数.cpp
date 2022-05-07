#include "カスタム駆動関数.h"
#include "MemoryEditorMod.h"
#include "Menu.h"

extern void _武将関数登録();

void カスタム::On_起動時() {
	if (iCallDLLMODE == kModeTSMod) {
		_武将関数登録();
	}
}

void カスタム::On_メインゲーム開始() {

}

void カスタム::On_終了時() {
	// gcnew していれば、(ウィンドウを閉じて)破棄
	if ( MemoryEditorForm::meForm ) {
		MemoryEditorForm::meForm->Close();
	}
}

void カスタム::On_アプリケーションメニュー選択時(int メニュー番号) {
	if ( メニュー番号 == RESOURCE_MENU_ID_MEMORY_EDITOR_MOD ) {

		// まだgcnew したことがなければ、gcnew
		if ( MemoryEditorForm::meForm == nullptr || MemoryEditorForm::meForm->IsDisposed ) {
			MemoryEditorForm::meForm = gcnew MemoryEditorForm();
			MemoryEditorForm::meForm->Show();
		}
	}
}