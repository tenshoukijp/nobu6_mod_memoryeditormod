#pragma once

#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> 番号リスト型;

// 浮動小数を四捨五入して、整数とする。
int round《整数化》(double a);

// 小数を、0.5単位に吸着させる。
double round《二分の一吸着化》(double a);