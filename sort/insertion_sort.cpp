#include <vector>
using namespace std;

/*
平均計算量 : O(n^2)
最悪計算量 : O(n^2)
内部ソート : o
安定ソート : o
*/

void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        int v = a[i]; // 挿入する値

        int j = i;
        // v を挿入する場所 j を探索
        while(j > 0) {
            // v より大きいやつはひとつ後ろにずらす
            if (a[j - 1] > v) a[j] = a[j - 1];
            // v 以下になったら抜ける
            else break;

            --j;
        }
        a[j] = v; // 最後に j 番目に v を挿入
    }
}