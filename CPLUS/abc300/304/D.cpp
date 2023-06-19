#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll w, h; cin >> w >> h;
    int n; cin >> n;

    vector<vector<ll>> berry(n, vector<ll>(2));
    for(int i=0; i<n; i++) cin >> berry[i][0] >> berry[i][1];

    int A; cin >> A;
    vector<ll> a(A+2, 0);
    for(int i=1; i<=A; i++) cin >> a[i];
    a[A+1]=w;

    int B; cin >> B;
    vector<ll> b(B+2, 0);
    for(int i=1; i<=B; i++) cin >> b[i];
    b[B+1]=h;

    map<pair<ll, ll>, ll> mp;
    for(int i=0; i<n; i++){
        ll x=*lower_bound(a.begin(), a.end(), berry[i][0]);
        ll y=*lower_bound(b.begin(), b.end(), berry[i][1]);
        mp[{x, y}]++;
    }
    
    ll m=n, M=0;
    for(auto p:mp) M=max(M, p.second);
    if(mp.size()==(A+1)*(B+1)) for(auto p:mp) m=min(m, p.second);
    else m=0;
    cout << m << " " << M << endl;
}