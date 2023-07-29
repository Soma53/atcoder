#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;
// using mint = modint1000000007;

#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define repp(i, s, n) for (int i=(s); i<=(int)(n); ++i)

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}
template <typename T>
bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false;}

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            if(S[i] == '(' || S[i] == '?') {
                if(j + 1 <= n) {
                    dp[i + 1][j + 1] += dp[i][j];
                }
            }
            if(S[i] == ')' || S[i] == '?') {
                if(j - 1 >= 0) {
                    dp[i + 1][j - 1] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n][0].val() << endl;
    return 0;
}