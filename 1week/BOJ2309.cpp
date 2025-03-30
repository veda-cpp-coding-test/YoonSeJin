//백준 : 2309 일곱난쟁이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> a(9);
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int diff = sum - 100;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (a[i] + a[j] == diff) {
                
                a.erase(a.begin() + j);
                a.erase(a.begin() + i);
                
                sort(a.begin(), a.end());

                for (int k = 0; k < 7; k++) {
                    cout << a[k] << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}