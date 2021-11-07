#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    uint64_t n, m, x, colomn, row, result;
    while(t--) {
        cin >> n >> m >> x;
        colomn = (x-1) / n + 1;
        row = x - (colomn - 1) * n;
        result = (row - 1) * m + colomn;
        cout << result << endl;
    }
}