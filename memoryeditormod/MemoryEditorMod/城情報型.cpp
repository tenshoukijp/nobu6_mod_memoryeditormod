#include <cassert>
#include "ゲームデータ構造.h"

namespace 関数 {



// 城名を取得する
string Get_城名( int 城番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) { 

		return string( p城情報[城番号【配列用】]._城名 );
	} else {
		デバッグ出力("城番号【配列用】は範囲外");
		return string("");
	}
}


// 城名を設定する
void   Set_城名( int 城番号【配列用】, string 城名 ) {

	// 範囲チェック
	if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) { 

		strncpy_s( p城情報[城番号【配列用】]._城名, 城名.c_str(), 8 );
		p城情報[城番号【配列用】]._城名[8] = NULL;
	} else {
		デバッグ出力("城番号【配列用】は範囲外");
	}
}

}

// 勝手に文字列を決めうちせずに、TENSHOU.EXE内のポインタ配列から引っ張るようにした方が、他者の改造への耐久力が増すかも。
char nb6CastleTypeName[最大数::城情報::配列数][5] = {
	"城",
	"御坊",
	"寺",
	"御所",
	"館",
	"", // 町
	"城"
};

// 城のタイプIDから具体的な文字列を得る
char *getCastleTypeName(int iCastleType) {
	if ( iCastleType == 0x00 ) {
		return nb6CastleTypeName[0];
	}
	else if (iCastleType == 0x01 ) {
		return nb6CastleTypeName[1];
	}
	else if (iCastleType == 0x02 ) {
		return nb6CastleTypeName[2];
	}
	else if (iCastleType == 0x04 ) {
		return nb6CastleTypeName[3];
	}
	else if (iCastleType == 0x08 ) {
		return nb6CastleTypeName[4];
	}
	else if (iCastleType == 0x10 ) {
		return nb6CastleTypeName[5];
	}
	else if (iCastleType == 0x20 ) {
		return nb6CastleTypeName[6];
	}
	return "";
}


namespace 関数 {

string Get_城称(int 城番号【配列用】) {
	if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) {
		string 城称 = getCastleTypeName( p城情報[城番号【配列用】]._城称);
		return 城称;
	}
	else {
		デバッグ出力("城番号【配列用】は範囲外");
	}
	return "";
}

/* 
 * 武将の姓名から武将番号を取得する。存在しない場合は、｢0xFFFF｣が返ってくる。
 */
int Get_城番号【配列用】(string 城名) {

	for (int 城番号【配列用】=0; 城番号【配列用】 < 最大数::城情報::配列数; 城番号【配列用】++ ) {
		if ( 城名 == Get_城名(城番号【配列用】) || 城名 == Get_城名(城番号【配列用】)+Get_城称(城番号【配列用】) ) {
			return 城番号【配列用】;
		}
	}

	return 0xFFFF;
}

// 指定の軍団が所持している城の数。
int Get_軍団所持城数(int 軍団番号【配列用】) {
	int iGundanID = 軍団番号【配列用】;

	int iHasCastleCnt = 0;
	if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
		for ( int iCastleID=0; iCastleID < 最大数::城情報::配列数; iCastleID++ ) {
			// 軍団番号が一致するものをカウント
			if ( iGundanID == p城情報[iCastleID].所属軍団【軍団番号】-1 ) {
				iHasCastleCnt++;
			}
		}
	} else {
		デバッグ出力("軍団番号【配列用】は範囲外");
	}
	return iHasCastleCnt;
}

// 指定の大名が所持している城の数。
int Get_大名所持城数(int 大名番号【配列用】) {
	int iDaimyoID = 大名番号【配列用】;
	int iHasCastleCnt = 0;
	
	if ( 0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数 ) {
		for ( int iCastleID=0; iCastleID < 最大数::城情報::配列数; iCastleID++ ) {
			int iGundanID = p城情報[iCastleID].所属軍団【軍団番号】-1;

			if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
				// 大名番号が一致するものをカウント
				if ( iDaimyoID == p軍団情報[iGundanID].所属大名【大名番号】-1 ) {
					iHasCastleCnt++;
				}
			}
		}
	} else {
		デバッグ出力("軍団番号【配列用】は範囲外");
	}
	return iHasCastleCnt;
}

// 城を移動する。
void Set_城位置(int 城番号【配列用】, int Ｘ位置, int Ｙ位置) {
	// 範囲チェック
	if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) { 

		p城付加情報[城番号【配列用】].Ｘ位置 = Ｘ位置;
		p城付加情報[城番号【配列用】].Ｙ位置 = Ｙ位置;
	} else {
		デバッグ出力("城番号【配列用】は範囲外");
	}
}


}


// 以下、メインマップのグリッド線で区切られた城グリッドの位置の計算

// グリッド座標同志の減算。座標Ａ→座標Ｂのベクトルを求めるのに、通常、Ｂ－Ａをするだろうから。
城グリッドベクトル型 operator-(城グリッド位置型 &p1, 城グリッド位置型 &p2);


// グリッドポジションクラス
城グリッド位置型::城グリッド位置型(int _Ｘ, int _Ｙ) {
	Ｘ = _Ｘ,
	Ｙ = _Ｙ;

	北西【城番号】= 0xFFFF;
	北【城番号】  = 0xFFFF;
	北東【城番号】= 0xFFFF;
	西【城番号】  = 0xFFFF;
	東【城番号】  = 0xFFFF;
	南西【城番号】= 0xFFFF;
	南【城番号】  = 0xFFFF;
	南東【城番号】= 0xFFFF;
}

namespace 関数 {

// グリッド座標同志の減算。座標Ａ→座標Ｂのベクトルを求めるのに、通常、Ｂ－Ａをするだろうから。
城グリッドベクトル型 operator-(城グリッド位置型 &位置１, 城グリッド位置型 &位置２) {
	城グリッドベクトル型 Ｖ;
	Ｖ.Ｘ = 位置１.Ｘ - 位置２.Ｘ;
	Ｖ.Ｙ = 位置１.Ｙ - 位置２.Ｙ;
	return Ｖ;
}


// 城ＩＤから、メイングリッド上のポジションを得る。左上グリッドが0,0。mapdataobgkのグリッドを見ればわかりやすい。
// １つのグリッドには、１つの城しかない。
城グリッド位置型 Get_城グリッド位置(int 城番号【配列用】) {
	城グリッド位置型 位置(0, 0);

	if ( 0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数 ) {
		// まずは、対象位置のグリッド位置を求める。
		int iGridX = (p城付加情報[城番号【配列用】].Ｘ位置 + 1) / 5; // ０オリジンなので＋１して５で割る。Ｘ方向は１つのグリッドの中に５つの場所がある。
		int iGridY = (p城付加情報[城番号【配列用】].Ｙ位置 + 1) / 3; // ０オリジンなので＋１して３で割る。Ｙ方向は１つのグリッドの中に３つの場所がある。

		位置.Ｘ = iGridX;
		位置.Ｙ = iGridY;

		// 隣接する城のＩＤも入れておく。
		for (int iCastleID = 0; iCastleID < 最大数::城情報::配列数; iCastleID++) {
			int iFX = (p城付加情報[iCastleID].Ｘ位置 + 1) / 5; // ０オリジンなので＋１して５で割る。Ｘ方向は１つのグリッドの中に５つの場所がある。
			int iFY = (p城付加情報[iCastleID].Ｙ位置 + 1) / 3; // ０オリジンなので＋１して３で割る。Ｙ方向は１つのグリッドの中に３つの場所がある。

			if ( iFX - 位置.Ｘ == -1 && iFY - 位置.Ｙ == -1 ) { // 北西
				位置.北西【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == 0 && iFY - 位置.Ｙ == -1 ) { // 北
				位置.北【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == 1 && iFY - 位置.Ｙ == -1 ) { // 北東
				位置.北東【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == -1 && iFY - 位置.Ｙ == 0 ) { // 西
				位置.西【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == 1 && iFY - 位置.Ｙ == 0 ) { // 東
				位置.東【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == -1 && iFY - 位置.Ｙ == 1 ) { // 南西
				位置.南西【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == 0 && iFY - 位置.Ｙ == 1 ) { // 南
				位置.南【城番号】 = iCastleID + 1;
			} else if ( iFX - 位置.Ｘ == 1 && iFY - 位置.Ｙ == 1 ) { // 南東
				位置.南東【城番号】 = iCastleID + 1;
			}
		}

		return 位置;
	}
	return 位置;
}

// ２つの城のグリッド位置が、隣接位置かどうか。
bool Is_隣接城( 城グリッド位置型 &位置１, 城グリッド位置型 &位置２) {
	城グリッドベクトル型 v;
	v.Ｘ = 位置１.Ｘ - 位置２.Ｘ;
	v.Ｙ = 位置１.Ｙ - 位置２.Ｙ;
	if ( v.Ｘ == 0 && v.Ｙ == 0 ) { return false; } // 同じ城
	return ( abs( v.Ｘ ) <= 1 && abs( v.Ｙ) <= 1);
}

bool Is_隣接城( int 城Ａ番号【配列用】, int 城Ｂ番号【配列用】) {
	if ( (0 <= 城Ａ番号【配列用】&& 城Ａ番号【配列用】< 最大数::城情報::配列数 ) &&
		 (0 <= 城Ｂ番号【配列用】&& 城Ｂ番号【配列用】< 最大数::城情報::配列数 ) ) {
		城グリッド位置型 posA = Get_城グリッド位置( 城Ａ番号【配列用】);
		城グリッド位置型 posB = Get_城グリッド位置( 城Ｂ番号【配列用】);
		return Is_隣接城( posA, posB );
	}
	return false;
}


}


