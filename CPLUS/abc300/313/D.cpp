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
    int N, K; cin >> N >> K;
    vector<int> t(N);
    rep(i, N){
        cout << "?";
        rep(j, K) cout << " " << ((i+j)%N+1);
        cout << endl;
        
        cin >> t[i];
        cout << flush;
    }

    vector<bool> ans(N);
    ans[0] = 1;
    rep(i, N-1){
        if(t[(i*K)%N] == t[((i*K)+1)%N]) ans[((i+1)*K)%N] = ans[(i*K)%N];
        else ans[((i+1)*K)%N] = !ans[(i*K)%N];
    }
    
    int temp = 0;
    rep(i, K) temp += ans[i];
    temp %= 2;
    if(temp == t[0]){
        cout << "!";
        rep(i, N) cout << " " << ans[i];
        cout << endl;
    }
    else {
        cout << "!";
        rep(i, N) cout << " " << !ans[i];
        cout << endl;
    }
    return 0;
}