#include <cassert>
#include <algorithm>
#include "ゲームデータ構造.h"






namespace 関数 {


// 軍団に所属する兵数を得る
int Get_軍団兵数(int 軍団番号【配列用】) {
	int i兵数 = 0;
	for ( int i=0; i<最大数::武将情報::配列数; i++) {
		if ( p武将情報[i].所属軍団【軍団番号】-1 == 軍団番号【配列用】 ) {
			if ( p武将戸籍情報[i].状態 <= 状態::現役 ) { // 大名, 軍団長, 現役 でカウント
				i兵数 += p武将情報[i].兵数;
			}
		}
	}
	return i兵数;
}

// 全ての有効な軍団リストを得る
番号リスト型 Get_軍団番号リスト【配列用】() {
	番号リスト型 list;

	// 該当の大名ＩＤに属する軍団をリストに加える
	for ( int i軍団ID=0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++ ) {
		if ( p軍団情報[i軍団ID].軍団長【武将番号】 !=  0xFFFF ) {
			list.push_back(i軍団ID);
		}
	}
	
	return list;
}

// 特定の大名麾下の軍団リストを得る
番号リスト型 Get_大名麾下軍団番号リスト【配列用】(int 大名番号【配列用】) {
	番号リスト型 list;

	if ( 0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数 ) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for ( int i軍団ID=0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++ ) {
			if ( p軍団情報[i軍団ID].所属大名【大名番号】-1 ==  大名番号【配列用】) {
				list.push_back(i軍団ID);
			}
		}
	}
	
	return list;
}


// とある大名配下の軍団下にある軍団割当番号のリストを得る。
// (番号と数を両方を得る。昇順)
番号リスト型 Get_軍団割当番号リスト(int 大名番号【配列用】) {

	番号リスト型 list;

	if ( 0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数 ) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for ( int i軍団ID=0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++ ) {
			if ( p軍団情報[i軍団ID].所属大名【大名番号】-1 ==  大名番号【配列用】) {
				list.push_back(p軍団情報[i軍団ID].軍団割当番号);
			}
		}
	}
	
	std::sort(list.begin(),list.end());//昇順ソート

	return list;
}

// とある大名配下の軍団下にある軍団「未」割当番号のリストを得る。
// (番号と数を両方を得る。昇順)
番号リスト型 Get_軍団未割当番号リスト(int 大名番号【配列用】) {

	// 割り当てられてるものに、１を入れる
	int 割当番号配列[8] = {0,0,0,0,0,0,0,0};

	if ( 0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数 ) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for ( int i軍団ID=0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++ ) {
			if ( p軍団情報[i軍団ID].所属大名【大名番号】-1 ==  大名番号【配列用】) {
				int g =  p軍団情報[i軍団ID].軍団割当番号;
				if ( 1 <= g && g <= 8 ) {
					// 割り当てられてるものに、１を入れる
					割当番号配列[g-1] = 1;
				}
			}
		}
	}

	番号リスト型 未割当リスト;
	for ( int ix=0; ix<8; ix++ ) {
		if (割当番号配列[ix] == 0) {
			未割当リスト.push_back(ix+1);
		}
	}

	std::sort(未割当リスト.begin(),未割当リスト.end());//昇順ソート

	return 未割当リスト;
}


bool Set_軍団所属大名(int 軍団番号【配列用】, int 新所属大名番号【配列用】) {

	// 新大名が正当ではない。
	if ( ! (0 <= 新所属大名番号【配列用】 && 新所属大名番号【配列用】 < 最大数::大名情報::配列数) ) {
		return false;
	}

	// 軍団が全部埋まっているならば、
	番号リスト型 glist = Get_軍団割当番号リスト(新所属大名番号【配列用】);
	if ( glist.size() == 8 ) { // 軍団は全部埋まっている
		// 何もできない
		return false;
	}

	int iGundanID = 軍団番号【配列用】;

	if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {

		// 指定の軍団が現在所属している大名番号を求める
		int iDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】-1;
		// 新所属先の大名が、今所属している大名であれば、何もすることはない。
		if ( iDaimyoID == 新所属大名番号【配列用】) {
			return true;
		}

		// 軍団割り当て番号が１番は大名自身。これは固定。この場合、何もせず失敗とする。
		if ( p軍団情報[iGundanID].軍団割当番号 == 1 ) {
			return false;
		}

		// 現在、新大名に所属していて、次の軍団【軍団番号】が0xFFFFになっている軍団が、ぶら下がるべきリンクリストの最後だ。
		// ぶら下がることが出来るか、事前にチェックしておく。
		int iLinkEndGundanID = -1;
		for ( int iGID=0; iGID < 最大数::軍団情報::配列数; iGID++ ) {
			// 
			int iCurDaimyoID = p軍団情報[iGID].所属大名【大名番号】-1;

			// 指定の新大名に所属しているならば、
			if ( iCurDaimyoID == 新所属大名番号【配列用】) {
				// 次の軍団が無いのであれば、そいつが最終軍団番号
				if ( p軍団情報[iGID].次の軍団【軍団番号】 == 0xFFFF ) {
					iLinkEndGundanID = iGID+1;
				}
				
			}

		}

		// それが範囲に入っていないならば、新大名の軍団リンクリストは、改造か何かしらないが情報が壊れている。
		// 処理終了
		if ( ! (0 < iLinkEndGundanID && iLinkEndGundanID <= 最大数::軍団情報::配列数 ) ) {
			return false;
		}

		/* 　自軍団
		      ↓
		   ○-●-○-○

		   というのを

		   ○-○-○

		   とする。
		*/

		int iPrevID =  p軍団情報[iGundanID].前の軍団【軍団番号】;
		int iNextID = p軍団情報[iGundanID].次の軍団【軍団番号】;

		// 自分のprevは有効な軍団だ。
		if ( 0 < iPrevID && iPrevID <= 最大数::軍団情報::配列数 ) {

			// 自分が先頭ではない軍団で、
			// １つ前の軍団の次のリンク先が自軍団の場合
			if ( iPrevID != 0xFFFF && p軍団情報[(iPrevID-1)].次の軍団【軍団番号】 == iGundanID+1 ) {
				// 自軍団ではなく、次の軍団へと繋ぎかえる。
				p軍団情報[(iPrevID-1)].次の軍団【軍団番号】 = iNextID;
			}
		}

		// 自分のnextは有効な軍団だ。
		if ( 0 < iNextID && iNextID <= 最大数::軍団情報::配列数 ) {
			// １つ後の軍団の前のリンク先が自軍団の場合
			if ( iNextID != 0xFFFF && p軍団情報[(iNextID-1)].前の軍団【軍団番号】 == iGundanID+1 ) {
				// 自軍団ではなく、前の軍団へと繋ぎかえる。
				p軍団情報[(iNextID-1)].前の軍団【軍団番号】 = iPrevID;
			}
		}


		/* 　
		     
		   ○-○

		   というのを

		   ○-○-●

		   とする。
		*/



		p軍団情報[iLinkEndGundanID-1].次の軍団【軍団番号】 = iGundanID+1; // リンクリストの最後の軍団のnextを自軍団に

		p軍団情報[iGundanID].前の軍団【軍団番号】 = iLinkEndGundanID; // 自軍団の前の軍団は、軍団のリンクリストの最後の軍団

		// 自軍団は、軍団リストの一番最後にくっつく。自軍団のnextは居ない
		p軍団情報[iGundanID].次の軍団【軍団番号】 = 0xFFFF; // 

		// メモリ書き換え
		{
			p軍団情報[iGundanID].軍団割当番号 = 8; // もう不正になってしまっているがもっとも高い確率でセーフなものを取る

			番号リスト型 milist = Get_軍団未割当番号リスト(新所属大名番号【配列用】);
			if ( milist.size() > 0 ) {
				p軍団情報[iGundanID].軍団割当番号 = milist[0]; // 空番号の最初のものを放り込む
			}

			p軍団情報[iGundanID].所属大名【大名番号】 = 新所属大名番号【配列用】+1;
		}

		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {
			// 指定の軍団に所属している武将は、全て、新大名に所属を変更する。
			if ( p武将情報[iBushouID].所属軍団【軍団番号】== iGundanID+1 ) {
				p武将情報[iBushouID].所属大名【大名番号】 = 新所属大名番号【配列用】+1;
				p武将情報[iBushouID].仕官年数 = 0; // 士官年数リセット
				p武将情報[iBushouID].内応先大名【大名番号】 = 0xFFFF; // 内応先リセット
				p武将情報[iBushouID].内応状態 = 0; // 内応状態なし
				p武将情報[iBushouID].遺恨状態 = 0; // 遺恨なし
			}
		}


		return true;

	}

	return false;
}

}

/*
 軍団番号を引数として、軍師の武将番号を得る
*/
int pCallFromFuncGetGunshiBushouID = 0x454BE9; //

int iReturnOfBushouIDGetGunshiBushou = 0xFFFF;
int iSigOfGundanIDGetGunshiBushou = 0xFFFF;

void _FuncGetGunshiBushouIDAsm() {
	__asm {
		// 軍団番号が引数
		MOV     ESI, iSigOfGundanIDGetGunshiBushou

		// 軍団番号を引数として、軍師番号を得るための関数を呼び出す
		PUSH    ESI
		CALL    pCallFromFuncGetGunshiBushouID
		ADD     ESP, 4

		MOV iReturnOfBushouIDGetGunshiBushou, EAX // 結果のうち、AXの番号を軍師武将番号として保存

	}
}

namespace 関数 {
// 軍団の軍師武将を得る。軍師たる者が居なければ0xFFFFが返ってくる。
int Get_軍師武将番号【配列用】(int 軍団番号【配列用】) {

	if ( 0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数 ) {

		iSigOfGundanIDGetGunshiBushou = 軍団番号【配列用】+1; // 配列用→軍団に変更

		iReturnOfBushouIDGetGunshiBushou = 0xFFFF; // まずは、毎度この値でリセット。

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
		_FuncGetGunshiBushouIDAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		iReturnOfBushouIDGetGunshiBushou = iReturnOfBushouIDGetGunshiBushou & 0xFFFF; // EAXのうち、AXの部分だけ利用する。

		// その軍団に軍師が居たならば
		if ( 0 <= iReturnOfBushouIDGetGunshiBushou-1 && iReturnOfBushouIDGetGunshiBushou-1 < 最大数::武将情報::配列数 ) {
			return iReturnOfBushouIDGetGunshiBushou-1; // 武将番号→武将番号配列用にして返す
		}
	}

	// 居ない場合や不正な場合は全部これ。
	return 0xFFFF;
}



// 対象の大名がプレイヤー担当の大名であるかどうかを判断する。
// 大名番号【配列用】には配列上の番号(attach-1の数)を渡すこと
bool Is_プレイヤ担当大名( WORD 大名番号【配列用】 ) {

	// 大名IDの範囲に収まっていること
	if ( 0 <= 大名番号【配列用】&& 大名番号【配列用】 < 最大数::大名情報::配列数 ) {
		// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
		return Is_プレイヤ担当軍団(p大名情報[大名番号【配列用】].所属軍団【軍団番号】-1);
	} else {
		return false;
	}
}



// 対象の軍団がプレイヤー担当軍団の勢力下の軍団であるかどうかを判断する。
// iTargetGundanIDには配列上の番号(attach-1の数)を渡すこと
bool Is_プレイヤ担当軍団( WORD 軍団番号【配列用】 ) {

	if (軍団番号【配列用】 >= 最大数::軍団情報::配列数 ) { 
		return false;
	}

	WORD ix【軍団番号】 = 0;
	for ( int n番目=0; n番目< 最大数::プレイヤ担当軍団情報::配列数; n番目++) {
		// プレイヤーが担当している軍団のＩＤを確保
		ix【軍団番号】 = pプレイヤ担当軍団情報[n番目].担当軍団【軍団番号】;

		// 0xFFFFならばプレイヤーではない
		if ( ix【軍団番号】 == 0xFFFF ) {
			continue;
		}

		// プレイヤー担当の軍団の大名が、ターゲットとしている対象の軍団の大名と一致するならば、
		// それはプレイヤーの勢力下の軍団である。
		// どうもnb6player8のgundanの値は、内部管理のgundanの値よりも+1されているようである。
		// よってここでは-1する。
		if (ix【軍団番号】 >= 1 && p軍団情報[ix【軍団番号】-1].所属大名【大名番号】 == p軍団情報[軍団番号【配列用】].所属大名【大名番号】 ) {
			return true;
		}
	}
	
	return false;
}


// 対象の武将がいずれかのプレイヤー勢力下の武将である
bool Is_プレイヤ担当武将( WORD 武将番号【配列用】 ) {

	// 武将IDの範囲に収まっていること
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {

		// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
		return Is_プレイヤ担当軍団(p武将情報[武将番号【配列用】].所属軍団【軍団番号】-1);

	} else {
		return false;
	}
}


}


