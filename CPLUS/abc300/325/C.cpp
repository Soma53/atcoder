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

int H, W;
vector<string> field;
vector<vector<bool>> visited;

int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
        if (field[nx][ny] == '.' || visited[nx][ny]) continue;

        dfs(nx, ny);
    }
}

int main() {
    cin >> H >> W;

    field.resize(H);
    visited.assign(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        cin >> field[i];
    }

    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j] && field[i][j] == '#') {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}