#include <iostream>
#include <vector>
using namespace std;

/*
平均計算量 : O(n + A)
最悪計算量 : O(n + A)
内部ソート : x
安定ソート : o

0 ~ A(最大でMAX = 100009)の整数をソートできる
複数のキーに対応
*/

const int MAX = 100009;

void countingSort(vector<int>& a) {
    // num に各要素の個数をカウント
    int num[MAX] = {0};
    for (int i = 0; i < a.size(); ++i) {
        ++num[a[i]];
    }

    // num の累積和
    int sum[MAX] = {0};
    for (int v = 0; v < a.size(); ++v) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sum を元にソートする
    // sum[a[i]] はソート後の a[i] の"次のindex"を指す
    // (例) a = {1, 3, 4, 5, 5, 6} のとき
    // a[3] と a[4] は 5 であり
    // sum[a[3]] と sum[a[4]] は 5 (6のindex) を指す
    // そのため --a[i] とすることで 5 のindex を指すことができる
    vector<int> buf(a.size());
    for (int i = a.size() - 1; i >= 0; --i) {
        buf[--sum[a[i]]] = a[i];
    }

    a = buf;
}