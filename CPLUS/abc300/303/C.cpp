#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    vector<pair<int,int>> items(M);
    for (int i = 0; i < M; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    map<pair<int, int>, bool> item_map;
    for (int i = 0; i < M; ++i) {
        item_map[items[i]] = true;
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') ++x;
        else if (S[i] == 'L') --x;
        else if (S[i] == 'U') ++y;
        else if (S[i] == 'D') --y;
        --H;
        if (H < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (item_map[{x, y}] && H < K) {
            H = K;
            item_map[{x, y}] = false;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
