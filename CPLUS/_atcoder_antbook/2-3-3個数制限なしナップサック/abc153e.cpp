#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = numeric_limits<ll>::max();

int main(){
    int h, n; cin >> h >> n;
    vector<ll> damage(h+10000, inf);
    int a, b;
    damage[0]=0;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        for(int j=0; j<h; j++){
            if(damage[j]==inf) continue;
            damage[j+a] = min(damage[j+a], damage[j]+b);
        }
    }
    ll ans;
    for(int i=h; i<h+10000; i++) ans=min(ans, damage[i]);
    cout << ans << endl;
}