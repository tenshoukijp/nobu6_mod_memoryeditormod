#pragma once
#pragma pack(1)

#include <windows.h>
#include "デバッグクラス.h"

namespace 関数 {

	// ファイル名にはフルパスを指定すること。ファイル名の拡張子に応じて、png, jpg, bmp の画像フォーマットに振り分けられる。
	void デバッグ画像出力(string ファイル名);
}