#include <vector>
using namespace std;

/*
平均計算量 : O(nlog(n))
最悪計算量 : O(nlog(n))
内部ソート : x (工夫次第で内部ソートになる)
安定ソート : x

要素の追加 : O(log(n))
最大値の探索 : O(1)
最大値の削除 : O(log(n))

std::priority_queue
*/

struct Heap {
    vector<int> heap;
    Heap() {}

    void push(int v) {
        heap.push_back(v); // 一旦最後尾に追加

        int i = (int)heap.size() - 1;
        while(i > 0) {
            // ヒープは子(i)の親のノード番号を (i - 1) / 2 で表現できる
            int parent = (i - 1) / 2;

            if (heap[parent] < v) {
                // 親 < 子ならば親子を入れ替える
                heap[i] = heap[parent];
                i = parent;
            } else break;
        }
        // 親 > 子になった位置に v を追加する
        heap[i] = v;
    }

    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    void pop() {
        if (heap.empty()) return;
        int v = heap.back(); // 最後尾の値を根とする
        heap.pop_back(); // 根(最大値)の削除

        int i = 0;
        // 親の子(左側)が存在する間
        while (i * 2 + 1 < (int)heap.size()) {
            int child_left = i * 2 + 1;
            int child_right = i * 2 + 2;

            int max_child;
            // 親の子(右側)が存在しない場合
            if (child_right >= (int)heap.size()) {
                max_child = child_left;
            } else {
                if (heap[child_left] >= heap[child_right]) {
                    max_child = child_left;
                } else {
                    max_child = child_right;
                }
            }
            if (heap[max_child] > v) {
                heap[i] = heap[max_child];
                i = max_child;
            } else break;
        }
        heap[i] = v;
    }
};

void heapSort(vector<int>& a) {
    Heap h;
    for (int i = 0; i < a.size(); ++i) h.push(a[i]);

    for (int i = a.size() - 1; i >= 0; --i) {
        a[i] = h.top();
        h.pop();
    }
}