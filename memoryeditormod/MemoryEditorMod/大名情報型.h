/*
 * 大名情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

/*
			大名(22*72)

			0-1	武将INDEX
			2-3	軍団番号
			4-5	居城
			6-7	隠居リスト先頭
			8	家紋
			9	朝廷
			A	敵対大名
			B	友好大名
			C
			D	商人
			E	000A 000B  A評定 B布教
			F	役職 0x01 将軍 0x02 管領 0x04 関東管領 0x08 奥州探題 0x10 西国探題 0x20 九州探題 0x40 羽州探題　⇒Get_大名役職
				複数兼職にはならないようだ
*/
struct 大名情報型
{
    WORD 大名【武将番号】;		// 大名 武将INDEX
	WORD 所属軍団【軍団番号】;	// 軍団 軍団番号
	WORD 所属居城【城番号】;	// 居城
	WORD 隠居武将【武将番号】;	// あまり使うことはない。隠居リスト先頭
	byte 家紋;					// 家紋番号
    byte 朝廷;					// 朝廷との親密度
	byte 敵対大名【大名番号】;	// 敵対大名
	byte 友好大名【大名番号】;	// 友好大名
	byte _未定義0;				//
	byte 商人;					// 商人との新密度
	byte 布教済:1;				// 布教 :布教済みか否か
	byte _未定義1:3;			// must 0 布教の残り空ビットに過ぎない。勝手に数値入れないこと
	byte 評定済:1;				// 評定 :評定済みかどうか
	byte _未定義2:3;			// must 0 評定の残り空ビットに過ぎない。勝手に数値入れないこと
	byte _役職;					// 役職 0x01 将軍 0x02 管領 0x04 関東管領 0x08 奥州探題 0x10 西国探題 0x20 九州探題 0x40 羽州探題　⇒Get_大名役職
	byte _未定義3[6];
};

namespace 関数 {
	// 現在有効に存在している大名リスト(大名番号【配列用】のリスト)を返す。
	番号リスト型 Get_大名番号リスト【配列用】(BOOL ターン大名を含む=TRUE);
}



// あまり気にしなくて良いが、大名情報型.cppの「 友好値配列[] 」の中身をみれば、
// 友好関係の値は、決して自由なものではなく、元来はいくつかの規定値が指定されていると分かるだろう。
// だが、それら16種類の規定値を覚えて、それを指定したり、それと比較する、というのは、いかにも面倒であったり非直感的なので、
// Set_友好関係では、普通に直感的な値にて、0〜100まで自由に設定して、自動的に規定に値へと変換されるという仕組みとした。
// 例えば友好値として、｢94｣と指定した場合、実際にはそのような友好値(の規定値)は存在し得ない、自動的に90へと(値が小さくなる方向で)変換している。

namespace 関数 {

	// Ａ大名とＢ大名との友好値を得る。
	// p大名情報[***]の***に相当する値(=大名番号【配列用】)を指定すれば良い。
	int Get_友好関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】);

	// Ａ大名とＢ大名との友好値をセットする。
	// 友好値が92のような中途半端な数だった場合90というように切り捨てられる。マイナス値は0に、100オーバーは100となる。
	void Set_友好関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】, int 友好値);

	// Ａ大名とＢ大名が同盟関係かどうかを得る。
	int Is_同盟関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】);

	// Ａ大名とＢ大名が婚姻関係かどうかを得る。
	int Is_婚姻関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】);

	// Ａ大名とＢ大名を同盟状態とする。
	void Set_同盟関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】);

	// Ａ大名とＢ大名を婚姻状態とする。
	void Set_婚姻関係(int 大名Ａ番号【配列用】, int 大名Ｂ番号【配列用】);

}

