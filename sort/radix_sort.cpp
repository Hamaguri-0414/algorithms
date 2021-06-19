#include <vector>
using namespace std;

/*
平均計算量 : O(kn)
最悪計算量 : O(kn)
内部ソート : x
安定ソート : o

前提条件 :
入力データが"3桁の整数"などの決まった形式
*/

void radixSort(vector<int>& a) {
    // 最大値の探索
    int max = a[0];
    for (int i = 0; i < a.size(); ++i)
        if(a[i] > max) max = a[i];

    // 1の位、10の位、100の位...と下位から順にソート
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> buf(a.size());
        // 0 ~ 9 の10種類
        int count[10] = {0};

        // 対象になっている桁をキーとしてカウント
        for (int i = 0; i < a.size(); ++i)
            ++count[(a[i] / exp) % 10];

        // カウントの累積和
        for (int i = 0; i < 10; ++i)
            count[i] += count[i - 1];
        
        // counting_sort 参照
        for (int i = a.size() - 1; i >= 0; --i)
            buf[--count[(a[i] / exp) % 10]] = a[i];

        a = buf;
    }
}