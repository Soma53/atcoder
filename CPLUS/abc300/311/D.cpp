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

const int MAX_N = 200;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<string> field(MAX_N);
vector<vector<vector<int>>> visited(MAX_N, vector<vector<int>>(MAX_N, vector<int>(2, 0)));

int main(){
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> field[i];

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1][0] = 1, visited[1][1][1] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x, ny = y;
            while(true){
                nx += dx[i], ny += dy[i];
                visited[nx][ny][1] = 1;
                if(field[nx][ny] == '#'){
                    visited[nx][ny][1] = 0;
                    if(visited[nx-dx[i]][ny-dy[i]][0] == 0) q.push({nx-dx[i], ny-dy[i]});
                    visited[nx-dx[i]][ny-dy[i]][0] = 1;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j][1]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}