#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define repp(i, s, n) for (int i=(s); i<=(int)(n); ++i)

using ll = long long;
const ll mod = 1000000007;

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}
template <typename T>
bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false;}

int main()
{
    int N, D;
    cin >> N >> D;

    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<bool> free(D, true);
    for (int j = 0; j < D; ++j) {
        for (int i = 0; i < N; ++i) {
            if (S[i][j] == 'x') {
                free[j] = false;
                break;
            }
        }
    }

    int res = 0, count = 0;
    for (int j = 0; j < D; ++j) {
        if (free[j]) {
            ++count;
            res = max(res, count);
        } else {
            count = 0;
        }
    }

    cout << res << endl;
    return 0;
}