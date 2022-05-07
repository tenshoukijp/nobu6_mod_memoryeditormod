/*
 * ターン情報
 */
#pragma once
#pragma pack(1)

#include <windows.h>


/*
	[ 現在のターンの情報]

	W 大名
	W 軍団
	W 城
*/
struct ターン情報型
{
	WORD 現在のターン【大名番号】;	// 現在のターンの大名番号
	WORD 現在のターン【軍団番号】;	// 現在のターンの軍団番号
	WORD 現在のターン【城番号】;	// 現在のターンの城番号
};

