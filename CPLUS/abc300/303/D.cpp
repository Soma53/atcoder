#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;

int main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        int c = (S[i] == 'A' ? 1 : 0);
        for (int j = 0; j < 2; ++j) {    
            dp[i + 1][c] = min(dp[i + 1][c], dp[i][j] + (j == c ? X : X + Z));
            dp[i + 1][1 - c] = min(dp[i + 1][1 - c], dp[i][j] + Y + (j == c ? 0 : Z));
        }
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
    return 0;
}
