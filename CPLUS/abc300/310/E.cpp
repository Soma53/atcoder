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

int N;
string S;

int main()
{
    cin >> N >> S;

    ll zero=0, one=0, ans=0;
    for(int i=0; i<N; ++i){
        if(S[i]=='0'){
            one += zero;
            zero = 1;
        }
        else if(S[i]=='1'){
            swap(one, zero);
            one += 1;
        }

        ans += one;
    }

    cout << ans << endl;

    return 0;
}