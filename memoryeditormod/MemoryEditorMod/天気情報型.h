/*
 * 天気報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>


struct 天気情報型 {
	byte _天気;				// Get_天気で得ること
};

// 天気情報を得る《戦場限定》 0:晴れ 1:曇り 2:雨 3:雪
namespace 天気 {
	enum { 晴れ=0, 曇り=1, 雨=2, 雪=3 };
};


namespace 関数 {
	// 天気情報を得る《戦場限定》 0:晴れ 1:曇り 2:雨 3:雪
	byte Get_天気();

	// 次のターンの天気を予約する。デフォルトでは２ターン継続する。
	void Set_天気予約(int i天気, int 継続ターン=2);
}