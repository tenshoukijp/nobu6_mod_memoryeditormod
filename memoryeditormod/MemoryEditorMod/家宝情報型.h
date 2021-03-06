/*
 * 家宝情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

/*
			[家宝(19*120)]

			0-12	名前
			13	分類
				  0 茶碗     1 茶壺     2 茶入    3 茶釜        4 花入    5 刀剣      6 槍        7 具足   8 馬 
				  9 鞍       A 陣羽織   B 巻子本  C 明朝綴本    D 香木    E 地球儀    F 南蛮時計 10 水墨画
				 11 十字架  12 聖書    13 玉手箱 14 ビードロ杯 15 遠眼鏡 16 ルソン壺 17 煙草
			14	画像
			15-16	所持武将
			17	0000AAAA A = 上昇値
			18	AB000000 A = 消失  B = 未登場
*/
struct 家宝情報型
{
	char _家宝名[13];			// 名前
	byte 家宝分類;				// 分類番号
	byte 家宝画像;				// 画像番号
	WORD 所有武将【武将番号】;	// 所有者
	byte 上昇値:4;				// 上昇値 (1〜10なので気をつけること)
	byte _未定義0:4;			// 0
	byte _未定義1:6;			//
	byte 未登場:1;				// 未登場(1=未登場 0=登場)
	byte 消失:1;				// 消失(1=消失 0=存在)
};


namespace 家宝分類 {
	enum {
		茶碗		= 0x0 ,
		茶壺		= 0x1 ,
		茶入		= 0x2 ,
		茶釜		= 0x3 ,
		花入		= 0x4 ,
		刀剣		= 0x5 ,
		槍			= 0x6 ,
		具足		= 0x7 ,
		馬			= 0x8 ,
		鞍			= 0x9 ,
		陣羽織		= 0xA ,
		巻子本		= 0xB ,
		明朝綴本	= 0xC ,
		香木		= 0xD ,
		地球儀		= 0xE ,
		南蛮時計	= 0xF ,
		水墨画		= 0x10,
		十字架		= 0x11,
		聖書		= 0x12,
		玉手箱		= 0x13,
		ビードロ杯	= 0x14,
		遠眼鏡		= 0x15,
		ルソン壺	= 0x16,
		煙草		= 0x17,
	};
};


namespace 関数 {


	// 家宝名を取得する
	string Get_家宝名( int 家宝番号【配列用】);

	// 家宝名を設定する
	void   Set_家宝名( int 家宝番号【配列用】, string 家宝名 );


}

