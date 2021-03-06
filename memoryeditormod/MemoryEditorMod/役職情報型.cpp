#include <cassert>
#include "ゲームデータ構造.h"


namespace 関数 {


// 大名IDから正規化された(0〜7へと振りなおされた)役職IDを得る
int Get_大名役職(int 大名番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::武将情報::配列数 ) { 

		switch ( p大名情報[大名番号【配列用】]._役職) {
			case 0x01:
				return 役職::征夷大将軍;
			case 0x02:
				return 役職::管領;
			case 0x04:
				return 役職::関東管領;
			case 0x08 :
				return 役職::奥州探題;
			case 0x10:
				return 役職::西国探題;
			case 0x20:
				return 役職::九州探題;
			case 0x40:
				return 役職::羽州探題;
			default:
				return 0;
		}
	}
	return 0;
}

// 軍団IDから正規化された役職IDを得る
int Get_軍団役職(int 軍団番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数 ) { 
		return p軍団情報[軍団番号【配列用】]._役職;
	}
	デバッグ出力("指定の軍団番号【配列用】は範囲外");
	return -1;
}



}