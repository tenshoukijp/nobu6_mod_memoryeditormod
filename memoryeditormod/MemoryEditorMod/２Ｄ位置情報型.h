
// 普通の２Ｄベクトル型。
#pragma once

#include <string>
#include "補助ライブラリ.h"

using namespace std;



// 普通の２Ｄ位置型。
struct ２Ｄ位置型 {
	２Ｄ位置型(double Ｘ位置, double Ｙ位置) : Ｘ(Ｘ位置),Ｙ(Ｙ位置) {}
	２Ｄ位置型() : Ｘ(0),Ｙ(0) {}
	double Ｘ;
	double Ｙ;

	２Ｄ位置型& operator=(const ２Ｄ位置型& v);
    //比較演算子
	bool operator==(const ２Ｄ位置型& v) const;
	bool operator!=(const ２Ｄ位置型& v) const;

};


class ２Ｄベクトル型 {
public:
	//メンバ変数
	double Ｘ;
	double Ｙ;
	//コンストラクタ
	２Ｄベクトル型();
	２Ｄベクトル型(double Ｘ成分,double Ｙ成分);
	２Ｄベクトル型(２Ｄ位置型 pos);
	//代入演算子
	２Ｄベクトル型& ２Ｄベクトル型::operator=(const ２Ｄベクトル型& v);
	//単項演算子
	２Ｄベクトル型& operator+=(const ２Ｄベクトル型& v);
	２Ｄベクトル型& operator-=(const ２Ｄベクトル型& v);
	２Ｄベクトル型& operator*=(double k);
	２Ｄベクトル型& operator/=(double k);
	２Ｄベクトル型 operator+()const;
	２Ｄベクトル型 operator-()const;
	//添え字演算子
	double& operator[](int i);
    //比較演算子
	bool operator==(const ２Ｄベクトル型& v ) const;
	bool operator!=(const ２Ｄベクトル型& v ) const;
	//べクトルの長さ
	double 長さ()const;
	//正規化
	void 正規化();
};

//ベクトル演算
//２Ｄベクトル型+２Ｄベクトル型
２Ｄベクトル型 operator+(const ２Ｄベクトル型& u,const ２Ｄベクトル型& v);
//２Ｄベクトル型-２Ｄベクトル型
２Ｄベクトル型 operator-(const ２Ｄベクトル型& u,const ２Ｄベクトル型& v);
//double*２Ｄベクトル型
２Ｄベクトル型 operator*(double k,const ２Ｄベクトル型& v);
//２Ｄベクトル型*double
２Ｄベクトル型 operator*(const ２Ｄベクトル型& v,double k);
//２Ｄベクトル型/double
２Ｄベクトル型 operator/(const ２Ｄベクトル型& v,double k);
//内積 ２Ｄベクトル型*２Ｄベクトル型
double operator*(const ２Ｄベクトル型& u,const ２Ｄベクトル型& v);
//外積 ２Ｄベクトル型%２Ｄベクトル型
double operator%(const ２Ｄベクトル型& u,const ２Ｄベクトル型& v);
//２つのベクトルのなす角度
double 角度(const ２Ｄベクトル型& u,const ２Ｄベクトル型& v);

// ２点間座標の差
２Ｄベクトル型 operator-(２Ｄ位置型 &p1, ２Ｄ位置型 &p2);

// ベクトルを文字列化するが、東西南北系（８方位）で文字列化。
string Get_８方位文字列(２Ｄベクトル型 v);

// ベクトルを文字列化するが、東西南北系（４方位）で文字列化。
string Get_４方位文字列(２Ｄベクトル型 v);
