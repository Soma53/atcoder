#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define repp(i, s, n) for (int i=(s); i<=(int)(n); ++i)

using ll = long long;
const ll mod = 1000000007;
const ll INF = numeric_limits<ll>::max();

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}
template <typename T>
bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false;}

int main() {
    int N;
    ll A, B, C;
    cin >> N >> A >> B >> C;

    vector<vector<ll>> D(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> D[i][j];
        }
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (int u = 0; u < N; ++u) {
            if (v == u) continue;        
            ll alt1 = d + D[v][u] * B + C;
            ll alt2 = d + D[v][u] * A;
            ll alt = (v == 0 ? alt1 : min(alt1, alt2));

            if (alt < dist[u]) {
                dist[u] = alt;
                pq.emplace(alt, u);
            }
        }
    }

    cout << dist[N-1] << endl;
    return 0;
}