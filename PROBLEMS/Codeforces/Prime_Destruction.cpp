#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> spf(MAXN + 1);

    for (int i = 0; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> dp(n + 1, 0);

        for (int x = k + 1; x <= n; x++) {
            dp[x] = LLONG_MAX;

            int temp = x;

            while (temp > 1) {
                int p = spf[temp];

                dp[x] = min(
                    dp[x],
                    1LL + 1LL * p * dp[x / p]
                );

                while (temp % p == 0)
                    temp /= p;
            }
        }

        long long answer = 0;

        for (int x : a)
            answer += dp[x];

        cout << answer << '\n';
    }

    return 0;
}