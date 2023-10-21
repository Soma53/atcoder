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
    cin >> N;
    vector<vector<ll>> items(N, vector<ll>(5, 0));
    for (int i = 0; i < N; i++) {
        cin >> items[i][0] >> items[i][1];
        items[i][1] += items[i][0];
    }

    sort(items.begin(), items.end(), [](const vector<ll>& a, const vector<ll>& b) {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });

    ll earlier = INF;
    int idx = N-1;
    for(int i=N-1; i>=0; i--){
        if(earlier > items[i][0]){
            earlier = items[i][0];
            idx = i;
        }
        items[i][2] = earlier;
        items[i][3] = idx;
    }

    cout << "=========" << endl;
    for(int i=0; i<N; ++i) cout << items[i][0] << " " << items[i][1] << endl;
    cout << "=========" << endl;

    ll last_printed = 0;
    int count = 0;
    for (int i = 0; i < N; i++){
        if(items[i][4] == 1) continue;
        if(items[i][0] >= last_printed){
            if(items[i][2] < items[i][0]){
                count++;
                last_printed = items[i][2] >= last_printed ? items[i][2] + 1 : last_printed + 1;
                items[items[i][3]][4] = 1;
            }
            else{
                count++;
                last_printed = items[i][0] + 1;
                items[i][4] = 1;
                cout << i << endl;
            }
        } else if (items[i][1] >= last_printed) {
            count++;
            last_printed++;
            items[i][4] = 1;
            cout << i << endl;
        }
    }

    cout << "========" << endl;
    cout << count << endl;
    return 0;
}