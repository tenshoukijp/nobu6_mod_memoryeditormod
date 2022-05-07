#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <map>

#include "メッセージ関連情報型.h"
#include "デバッグ情報型.h"

using namespace std;
using namespace 関数;


extern HMODULE hModuleTSMod;

typedef int (WINAPI *PFNONIGMATCHALLOC)(char *対象文字列, char *正規表現文字列, int *正規表現マッチ結果);
PFNONIGMATCHALLOC p_OnigMatchAlloc = NULL;
typedef int (WINAPI *PFNONIGMATCHFREE)(int *正規表現マッチ結果);
PFNONIGMATCHFREE p_OnigMatchFree = NULL;

// TSModにしかない正規表現関連ののポインタの登録
void _正規表現関数登録() {
	p_OnigMatchAlloc = (PFNONIGMATCHALLOC)GetProcAddress( hModuleTSMod, "Extern_OnigMatchAlloc" );
	p_OnigMatchFree = (PFNONIGMATCHFREE)GetProcAddress( hModuleTSMod, "Extern_OnigMatchFree" );
}


// 正規表現マッチング用の関数

namespace 関数 {

	int Is_文字列マッチ(  string 対象文字列, string 部分文字列 ) {
		return 対象文字列.find(部分文字列) != string::npos;
	}
} // namespace