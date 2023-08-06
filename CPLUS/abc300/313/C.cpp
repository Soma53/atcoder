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
    vector<ll> a(N), b(N);
    ll mean = 0;
    rep(i, N){
        cin >> a[i];
        b[i] = a[i];
        mean += a[i];
    }
    mean /= N;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    

    ll ans = 0;
    bool flag = true;
    while(flag){
        flag = false;
        int idx = 0;
        while(a[idx] < b[idx]){
            ll temp = abs(a[idx]-b[idx])/2;
            if(temp > abs(a[idx]-mean)) temp = abs(a[idx]-mean);
            a[idx] += temp; b[N-idx-1] += temp;
            b[idx] -= temp; a[N-idx-1] -= temp;
            if(temp != 0){
                ans += temp;
                flag = true;
            }
            idx++;
        }
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
    }

    cout << ans << endl;

    return 0;
}