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
    int N; cin >> N;
    vector<ll> a(N);
    ll sum = 0;
    rep(i, N){
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> b(N, sum/N);
    rep(i, sum%N) b[N-i-1]++;

    ll ans = 0;
    rep(i, N) ans += abs(a[i]-b[i]);
    cout << ans/2 << endl;

    return 0;
}