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
    string S; cin >> S;
    vector<bool> b(3, false);
    for(int i=0; i<N; i++){
        b[S[i]-'A'] = true;
        if (std::all_of(b.begin(), b.end(), [](bool v) { return v; })) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}