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

const int MAX_HW = 3005;
int hole[MAX_HW][MAX_HW];
ll sum[MAX_HW][MAX_HW];

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    for(int i = 1; i <= H; i++) fill(hole[i]+1, hole[i]+1 + W, 1);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        hole[a][b] = 0;
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            sum[i][j] = hole[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    cout << sum[H][W] << endl;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
          cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}