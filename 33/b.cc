#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count_replace = 0;
        int count_stars = 0;
        int last_star_index = 0;
        int prev_x_index;
        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                if (count_replace == 0) {
                    s[i] = 'x';
                    prev_x_index = i;
                    count_replace++;
                }
                count_stars++;
                last_star_index = i;
            }
        }
        if(count_stars >= 2) {
            s[last_star_index] = 'x';
            count_replace++;
        }

        int last_x_index;
        for(int i=0; i<n; i++) {
            if(s[i] == '*' || s[i] == 'x') {
                if(i - prev_x_index > k) {
                    s[last_x_index] = 'x';
                    count_replace++;
                    prev_x_index = last_x_index;
                }

                if(i - prev_x_index == k) {
                    if (s[i] != 'x') {
                        s[i] = 'x';
                        count_replace++;
                        prev_x_index = i;
                    }
                }
                else if(i - prev_x_index < k) {
                    last_x_index = i;
                }
            }
        }
        cout << count_replace << endl;
    }
}