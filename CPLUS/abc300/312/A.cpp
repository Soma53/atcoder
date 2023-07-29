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
    vector<string> s = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    string S; cin >> S;
    if(find(s.begin(), s.end(), S) != s.begin() + (int)s.size()){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}