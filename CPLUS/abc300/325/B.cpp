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

int main() {
    int N;
    cin >> N;

    vector<vector<int>> blunch(N, vector<int>(2));
    for(int i=0; i<N; ++i) cin >> blunch[i][0] >> blunch[i][1];

    ll ans = 0;
    for(int t=0; t<24; ++t){
        ll tempans = 0;
        for(int i=0; i<N; ++i){
            if(9 <= (t + blunch[i][1])%24 && 18 > (t + blunch[i][1])%24) tempans += blunch[i][0];
        }
        chmax(ans, tempans);
    }

    cout << ans << endl;
    return 0;
}