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
    int N, M; cin >> N >> M;
    vector<int> edge(N, 0);
    vector<vector<int>> G(N);
    rep(i, M){
        int A, B; cin >> A >> B;
        A--; B--;
        G[A].emplace_back(B);
        edge[B]++;
    }

    vector<int> saikyo_list;
    rep(i, N) if(edge[i]==0) saikyo_list.emplace_back(i);
    if(saikyo_list.size()==1) cout << (saikyo_list[0] + 1) << endl;
    else cout << -1 << endl;
    
    return 0;
}