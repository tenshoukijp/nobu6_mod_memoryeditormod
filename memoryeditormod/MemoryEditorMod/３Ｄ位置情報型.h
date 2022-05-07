
// •’Ê‚Ì‚R‚cƒxƒNƒgƒ‹Œ^B
#pragma once
#pragma pack(1)

#include "•â•ƒ‰ƒCƒuƒ‰ƒŠ.h"


// •’Ê‚Ì‚R‚cˆÊ’uŒ^B
struct ‚R‚cˆÊ’uŒ^ {
	‚R‚cˆÊ’uŒ^(double ‚wˆÊ’u, double ‚xˆÊ’u, double ‚yˆÊ’u) : ‚w(‚wˆÊ’u),‚x(‚xˆÊ’u),‚y(‚yˆÊ’u) {}
	‚R‚cˆÊ’uŒ^() : ‚w(0),‚x(0),‚y(0) {}
	double ‚w;
	double ‚x;
	double ‚y;
	‚R‚cˆÊ’uŒ^& operator=(const ‚R‚cˆÊ’uŒ^& v);
    //”äŠr‰‰Zq
	bool operator==(const ‚R‚cˆÊ’uŒ^& v) const;
	bool operator!=(const ‚R‚cˆÊ’uŒ^& v) const;
};


class ‚R‚cƒxƒNƒgƒ‹Œ^ {
public:
	//ƒƒ“ƒo•Ï”
	double ‚w;
	double ‚x;
	double ‚y;
	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	‚R‚cƒxƒNƒgƒ‹Œ^();
	‚R‚cƒxƒNƒgƒ‹Œ^(double ‚w¬•ª,double ‚x¬•ª,double ‚y¬•ª);
	‚R‚cƒxƒNƒgƒ‹Œ^(‚R‚cˆÊ’uŒ^ pos);
	//‘ã“ü‰‰Zq
	‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
	//’P€‰‰Zq
	‚R‚cƒxƒNƒgƒ‹Œ^& operator+=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
	‚R‚cƒxƒNƒgƒ‹Œ^& operator-=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
	‚R‚cƒxƒNƒgƒ‹Œ^& operator*=(double k);
	‚R‚cƒxƒNƒgƒ‹Œ^& operator/=(double k);
	‚R‚cƒxƒNƒgƒ‹Œ^ operator+()const;
	‚R‚cƒxƒNƒgƒ‹Œ^ operator-()const;
	//“Y‚¦š‰‰Zq
	double& operator[](int i);
    //”äŠr‰‰Zq
	bool operator==(const ‚R‚cƒxƒNƒgƒ‹Œ^& v ) const;
	bool operator!=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v ) const;
	//‚×ƒNƒgƒ‹‚Ì’·‚³
	double ’·‚³()const;
	//³‹K‰»
	void ³‹K‰»();
};

//ƒxƒNƒgƒ‹‰‰Z
//‚R‚cƒxƒNƒgƒ‹Œ^+‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator+(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//‚R‚cƒxƒNƒgƒ‹Œ^-‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator-(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//double*‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator*(double k,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//‚R‚cƒxƒNƒgƒ‹Œ^*double
‚R‚cƒxƒNƒgƒ‹Œ^ operator*(const ‚R‚cƒxƒNƒgƒ‹Œ^& v,double k);
//‚R‚cƒxƒNƒgƒ‹Œ^/double
‚R‚cƒxƒNƒgƒ‹Œ^ operator/(const ‚R‚cƒxƒNƒgƒ‹Œ^& v,double k);
//“àÏ ‚R‚cƒxƒNƒgƒ‹Œ^*‚R‚cƒxƒNƒgƒ‹Œ^
double operator*(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//ŠOÏ ‚R‚cƒxƒNƒgƒ‹Œ^%‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator%(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//‚Q‚Â‚ÌƒxƒNƒgƒ‹‚Ì‚È‚·Šp“x
double Šp“x(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v);
//o—Í
// ‚Q“_ŠÔÀ•W‚Ì·
‚R‚cƒxƒNƒgƒ‹Œ^ operator-(‚R‚cˆÊ’uŒ^ &p1, ‚R‚cˆÊ’uŒ^ &p2);
