#include <vector>
using namespace std;

/*
平均計算量 : O(nlog(n))
最悪計算量 : O(nlog(n))
内部ソート : x
安定ソート : o
*/

void merge(vector<int>& a, int left, int right) {
    if (right - left == 1) return;

    int mid = left + (right - left) / 2;

    // [left, mid) をソート
    merge(a, left, mid);
    // [mid, right) をソート
    merge(a, mid, right);

    // [0, mid)　と反転させた[mid, right) を連結させて buf に格納
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

    int itr_left = 0;
    int itr_right = (int)buf.size() - 1;
    for (int i = left; i < right; ++i) {
        // 両端を比較し、小さい値から a に格納
        if (buf[itr_left] <= buf[itr_right]) {
            a[i] = buf[itr_left++];
        } else {
            a[i] = buf[itr_right--];
        }
    }
}

void mergeSort(vector<int>& a) {
    merge(a, 0, a.size());
}