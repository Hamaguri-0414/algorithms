#include <vector>
using namespace std;

/*
平均計算量 : O(nlog(n))
最悪計算量 : O(nlog(n))
内部ソート : o (ヒープソートの改良版)
安定ソート : x
*/

// aのうちn番目までをヒープとする
// i番目のノードとその子を比較し逆転していたら修正する
void heapify(vector<int>& a, int i, int n) {
    int child_left = i * 2 + 1;
    int child_right = i * 2 + 2;

    int max_child;
    // 親の子(右側)が存在しない場合終了
    if (child_left >= n) {
        return;
    // 左右の子のうち大きい方を選択する
    } else {
        if (child_right >= n) {
            max_child = child_left;
        } else {
            if (a[child_left] >= a[child_right]) {
                max_child = child_left;
            } else {
                max_child = child_right;
            }
        }
    }
    if (a[max_child] > a[i]) {
        swap(a[i], a[max_child]);
    } else return;

    heapify(a, max_child, n);
}

void inPlaceHeapSort(vector<int>& a) {
    // 受け取った配列を後ろからヒープにする
    for (int i = a.size() / 2 - 1; i >= 0; --i) {
        heapify(a, i, a.size());
    }

    // 根の最大値を右詰めする
    for (int i = a.size() - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}