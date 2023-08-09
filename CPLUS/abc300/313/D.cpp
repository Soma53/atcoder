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

void out(vector<int> v){
    for(unsigned int i=0; i<v.size(); i++)
        cout << v[i] << " \n"[i+1 == v.size()];
}

int main()
{
    int N, K; cin >> N >> K;
    vector<int> ans(N);

    auto send = [&](vector<int> v){
        cout << "? ", out(v);
        cout.flush();
        int x; cin >> x;
        return x;
    };

    {
        int temp = 0;
        rep(i, K+1){
            vector<int> v;
            rep(j, K+1) if(j != i) v.emplace_back(j+1);
            ans[i] = send(v);
            temp ^= ans[i];
        }
        rep(i, K+1) ans[i] ^= temp;
    }

    int temp = 0;
    vector<int> v(K);
    rep(i, K-1) v[i] = i+1, temp ^= ans[i];
    repp(i, K+2, N){
        v[K-1] = i;
        ans[i-1] = temp ^ send(v);
    }

    cout << "! ", out(ans);
    cout.flush();

    return 0;
}