# ソートアルゴリズムテスト
## テスト用main関数
```cpp
#include <iostream>

int main() {
    int n; // 要素数
    cin >> n;
    vector<int> a(n); // 整列したい配列ベクトル (サイズ を n に初期化)
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // 整列したい配列を取得
    }

    // 実装した関数を呼ぶ

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
```

## 入力サンプル
make_input_example.cpp を使用するか以下をコピペしてください
### 入力例 1
```
10
9 5 8 3 0 7 6 2 4 1
```

### 入力例 2
```
20
7 9 13 18 10 12 4 18 3 9 0 5 12 2 7 3 7 9 0 12
```

### 入力例 3
```
100
7 9 13 18 10 12 4 18 3 9 0 5 12 2 7 3 7 9 0 12 3 9 9 17 0 13 19 18 16 15 17 6 12 7 10 13 19 9 19 1 7 12 13 16 5 5 8 11 14 17 1 13 8 4 8 10 4 16 10 3 2 6 9 4 1 13 17 8 8 13 18 1 15 13 5 14 3 16 5 9 15 14 9 1 17 15 5 4 11 18 8 3 5 2 12 6 16 17 18 4
```