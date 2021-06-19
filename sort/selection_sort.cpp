#include <vector>
using namespace std;

/*
平均計算量 : O(n^2)
最悪計算量 : O(n^2)
内部ソート : o
安定ソート : x
*/

void selectionSort(vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        int min = i;
        for (int j = min; j < a.size(); ++j)
            if (a[j] < a[min]) min = j;
        swap(a[i], a[min]); // 最小値を左詰め
    }
}