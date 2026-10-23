#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int zerosRight = 0;

        for (char c : s) {
            if (c == '0') {
                zerosRight++;
            }
        }

        int onesLeft = 0;
        int ans = n;

        for (int boundary = 0; boundary <= n; boundary++) {
            int cost = onesLeft + zerosRight;
            ans = min(ans, cost);

            if (boundary < n) {
                if (s[boundary] == '1') {
                    onesLeft++;
                } else {
                    zerosRight--;
                }
            }
        

        cout << ans << '\n';
    }

    return 0;
}