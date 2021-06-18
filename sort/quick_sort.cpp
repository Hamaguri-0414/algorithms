#include <vector>
using namespace std;

/*
平均計算量 : O(nlog(n))
最悪計算量 : O(n^2)
内部ソート : o
安定ソート : x
*/

void quick(vector<int>& a, int left, int right) {
    if (right - left <= 1) return;

    int pivot_index = left + (right - left) / 2;
    int pivot = a[pivot_index];

    swap(a[pivot_index], a[right - 1]); // pivot を一旦右端に退避

    int i = left;
    for (int j = left; j < right - 1; ++j)
        // 左から値を確認し、pivot 未満の値を左詰め
        if (a[j] < pivot) swap(a[i++], a[j]);

    swap(a[i], a[right - 1]); // pivot を適切な位置に移動

    // [left, i) をソート
    quick(a, left, i);
    // (i, right) をソート
    quick(a, i + 1, right);
}

void quickSort(vector<int>& a) {
    quick(a, 0, a.size());
}