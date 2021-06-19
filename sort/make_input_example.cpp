#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    cout << "----- Please copy below this. -----" << endl;

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        // 0 ~ 19 のランダムな整数
        cout << rand() % 20;
        if (i != n - 1) cout << " ";
        else cout << endl;
    }

    return 0;
}