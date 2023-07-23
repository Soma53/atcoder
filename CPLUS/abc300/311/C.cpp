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

const int MAX_N = 200005;

vector<int> G[MAX_N];
vector<int> path;
int visited[MAX_N];

bool dfs(int v) {
    visited[v] = 1;
    path.push_back(v);
    for (int next_v : G[v]) {
        if (visited[next_v] == 0) {
            if (dfs(next_v)) return true;
        }
        else if (visited[next_v] == 1) {
            while (path[0] != next_v) {
                path.erase(path.begin());
            }
            return true;
        }
    }
    visited[v] = 2;
    path.pop_back();
    return false;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        G[i].push_back(A);
    }
    dfs(1);
    int M = path.size();
    cout << M << endl;
    for (int i = 0; i < M; i++) {
        cout << path[i];
        if (i != M - 1) cout << " ";
    }
    cout << endl;
    return 0;
}