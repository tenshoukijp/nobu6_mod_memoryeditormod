#pragma once
#pragma pack(1)

#include <windows.h>
#include "デバッグクラス.h"

namespace 関数 {

	/*
	 デバッグ出力に使える変数。

	 　①printf(format, ...);  にそっくりな記法

 　　	 デバッグ出力( "%s", 元メッセージ.c_str() );

	 　②cout << ... << endl;  にそっくりな記法

		 デバッグ出力 << 武将名 << ":" << 元メッセージ << (int)メッセージ関連情報.第１人称【武将番号】 << endl;

		(endl もしくは、デバッグ出力.flush() した段階で出力される。)

	*/

	extern デバッグストリーム型 デバッグ出力;
}