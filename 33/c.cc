#include <iostream>
#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    for(int i=0; i<n; i++) {
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i=2; i<n; i++) {
        dp[i] = INT_MAX;
        for(int j=max(i-k, 0); j<i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
        }
    }

    cout << dp[n-1] << endl;

    // vector<vector<int>> a(n, vector<int>(n, 0));

    // for(int d=1; d<n; d++) {
    //     for(int i=0; i<n-d; i++) {
    //         int min;
    //         if(d<=k) {
    //             min = abs(h[i] - h[i+d]);
    //         } else {
    //             min = INT_MAX;
    //         }
            
    //         for(int j=1; j<d; j++) {
    //             int temp = a[i][i+j] + a[i+j][i+d];
    //             if (temp < min) {
    //                 min = temp;
    //             }
    //         }
    //         a[i][i+d] = min;
    //     }
    // }

    // cout << a[0][n-1] << endl;
}