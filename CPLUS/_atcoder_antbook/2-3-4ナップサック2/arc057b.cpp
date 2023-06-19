//やり直し必要

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for(int i=0; i<n; i++) cin >> a[i];
    vector<ll> suma(n+1); suma[0]=0; for(int i=0; i<n; i++) suma[i+1] = suma[i]+a[i];
    

}