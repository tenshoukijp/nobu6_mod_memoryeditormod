/*
 * 軍団情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>



/*			軍団情報(21*214)

			[21バイト]

			0-1	前の軍団
			2-3 後ろの軍団
			4-5	居城名ナンバー
			6-7	軍団長ナンバー(武将名前テーブルの順番)
			8-9	大名
			10	行動力
			11-12	金
			13-14	米
			15-16	騎馬
			17-18	鉄砲
			19	？
			20	aaaabbbb A 役職 B 軍団番号
				0 無し 1 征夷大将軍 2 管領 3 関東管領 4 奥州探題 5 西国探題 6 九州探題 7 羽州探題 ⇒ Get_軍団役職

 */
struct 軍団情報型
{
	WORD 前の軍団【軍団番号】;	// あまり使わない。前の軍団
	WORD 次の軍団【軍団番号】;	// とくに使わない。次の軍団
	WORD 所属居城【城番号】;	// 軍団長が居る城の城番号
	WORD 軍団長【武将番号】;	// 軍団長の武将番号(武将名前テーブルの順番)
	WORD 所属大名【大名番号】;	// 所属(大名)
	byte 行動力;				// 行動力
	WORD 金;					// 金
	WORD 米;					// 米
	WORD 馬;					// 馬
	WORD 鉄砲;					// 鉄砲
	byte _未定義1;				// must 0?
	byte 軍団割当番号:4;		// 1-8 ⇒ 軍団割り当て番号
	byte _役職:4;				// 役職  (0 無し 1 征夷大将軍 2 管領 3 関東管領 4 奥州探題 5 西国探題 6 九州探題 7 羽州探題) ⇒ Get_軍団役職
};

namespace 関数 {
	// とある軍団に所属する、兵士総数を得る
	int Get_軍団兵数(int 軍団番号【配列用】);

	// 指定の軍団の所属する大名を勢力を越えて、変更する。
	bool Set_軍団所属大名(int 軍団番号【配列用】, int 新所属大名番号【配列用】);

	// 全ての有効な軍団のリストを得る
	番号リスト型 Get_軍団番号リスト【配列用】() ;

	// 特定の大名麾下の軍団リストを得る
	番号リスト型 Get_大名麾下軍団番号リスト【配列用】(int 大名番号【配列用】) ;

	// とある大名配下の軍団下にある軍団割当番号のリストを得る。
	// (番号と数を両方を昇順に得ることが出来る)
	番号リスト型 Get_軍団割当番号リスト(int 大名番号【配列用】);

	// とある大名配下の軍団で、まだ未割り当ての番号のリストを得る。
	番号リスト型 Get_軍団未割当番号リスト(int 大名番号【配列用】);
}

namespace 関数 {
	// 軍団の軍師武将を得る。軍師たる者が居なければ0xFFFFが返ってくる。
	int Get_軍師武将番号【配列用】(int 軍団番号【配列用】);
}

/*
	プレイヤの担当軍団(大名番号ではなく軍団番号)。最大８つ。
*/
struct プレイヤ担当軍団情報型
{
	WORD 担当軍団【軍団番号】;
};


namespace 関数 {

	// 対象の大名IDがプレイヤー担当の大名であるかどうかを判断する。
	// 大名番号【配列用】には配列上の番号(attach-1の数)を渡すこと
	bool Is_プレイヤ担当大名( WORD 大名番号【配列用】 );

	// 対象の軍団IDがプレイヤー担当軍団の勢力下の軍団であるかどうかを判断する。
	// 軍団番号【配列用】には配列上の番号(attach-1の数)を渡すこと
	bool Is_プレイヤ担当軍団( WORD 軍団番号【配列用】 );

	// 対象の武将IDがいずれかのプレイヤー勢力下の武将である
	bool Is_プレイヤ担当武将( WORD 武将番号【配列用】 );


}



