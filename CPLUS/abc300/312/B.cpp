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

int N, M;
vector<string> grid;
string takcode[9] = {
    "###.xxxxx",
    "###.xxxxx",
    "###.xxxxx",
    "....xxxxx",
    "xxxxxxxxx",
    "xxxxx....",
    "xxxxx.###",
    "xxxxx.###",
    "xxxxx.###",
};

bool check(int x, int y) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (takcode[i][j] == 'x') continue;
            if (takcode[i][j] != grid[x + i][y + j]) return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; ++i) cin >> grid[i];

    for (int i = 0; i < N - 8; ++i) {
        for (int j = 0; j < M - 8; ++j) {
            if (check(i, j)) cout << i + 1 << " " << j + 1 << endl;
        }
    }

    return 0;
}