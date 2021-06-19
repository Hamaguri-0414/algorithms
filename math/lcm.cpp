/*
最大公約数と最小公倍数の積の性質により最小公倍数を求める
証明 :
a, b の最大公約数をg としたとき
a = g * a', b = g * b' となる互いに素な整数a', b' が存在する
このとき、最小公倍数 l は定義より l = g * a' * b' なので
g * l = g * (g * a' * b') = g * a' * g * b' = a * b
*/

#include "gcd.cpp"

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}