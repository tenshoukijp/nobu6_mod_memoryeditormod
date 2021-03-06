/*
 * 音楽情報、いわゆるＢＧＭ関連
 */
#pragma once
#pragma pack(1)

#include <windows.h>



// 指定の音楽(ＢＧＭ)を再生する(この音楽番号は、神パッチで指定する番号と合致してると考えて良い)
namespace 関数 {

	// 再生中のBGMのIDを得る。1以上の値が返ってくる(実際は2以上かも？)。0xFFFFだと何も再生していない。
	// 環境設定の｢音楽｣の項目がＯＦＦの時も、全て0xFFFFとなる。
	int Get_再生音楽番号();

	// _INMMを利用したモードか？ INMMを適用しているかどうかで、再生音楽番号などの振り分けを、変えたい場合に利用すれば良い。
	bool Is_INMMモード();

	// ＢＧＭを再生する。
	void 音楽再生(int 音楽番号);

	// ＢＧＭを停止する。
	void 音楽停止();
}