#include <cassert>
#include "ゲームデータ構造.h"





	//---------------------フェイドアウト-------------------------
	int _pCallFromFuncFadeOut = 0x4232EE; // 元々TENSHOU.EXE内にあったCALL先

namespace 関数 {
	void フェイドアウト() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			// 引数なし
			call _pCallFromFuncFadeOut
			// 引数なしなのでスタックのずれ込みは無し
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}
	//---------------------フェイドイン-------------------------
	int _pCallFromFuncFadeIn = 0x4232D4; // 元々TENSHOU.EXE内にあったCALL先
	
namespace 関数 {
	void フェイドイン() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			// 引数なし
			call _pCallFromFuncFadeIn
			// 引数なしなのでスタックのずれ込みは無し
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}






	int _pCallFromFuncMoveCamera = 0x48728F; // 元々TENSHOU.EXE内にあったCALL先

	WORD _iCastleIdInFuncMoveCamera = 1L;

	// メイン画面でのカメラ移動
	void _FuncMoveCameraAsm() {
		__asm {
			push ecx  // ecx の値を保存

			// 引数1〜3 2バイトずつ
			mov ecx, 0x4DC218  // (中身は2710=10000か。なにやら必要らしい);
			push 1
			push 1
			push dword ptr _iCastleIdInFuncMoveCamera;
			call _pCallFromFuncMoveCamera

			pop ecx  // ecxの値を元へと戻す
		}
	}


namespace 関数 {
	// カメラを指定の城IDへと移動
	void カメラ移動(int 城番号【配列用】) {

		// 範囲チェック
		assert ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 );

		if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) {

			// 関数用のやつは、城番号そのものなので、1つ足しこみ
			_iCastleIdInFuncMoveCamera = (WORD)城番号【配列用】+1;
		
			__asm {
				push eax
				push ebx
				push ecx
				push edx
				push esp
				push esi
				push edi
			}

			// TENSHOU.EXE内の関数呼び出し
			_FuncMoveCameraAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}
		}
	}

}





