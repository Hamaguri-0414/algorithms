#include <vector>
using namespace std;

/*
平均計算量 : O(n^2)
最悪計算量 : O(n^2)
内部ソート : o
安定ソート : o
*/

void bubbleSort(vector<int>& a) {
    for (int i = 0; i < a.size() - 1; ++i)
        for (int j = a.size() - 1; j > i; --j)
            // 隣接している左右で大きさが逆転している箇所をswap
            if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
}