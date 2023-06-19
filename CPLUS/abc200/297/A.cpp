#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d; cin >> n >> d;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    int ans=-1;
    for(int i=0; i<n-1; i++){
        if(t[i+1]-t[i] <= d){
            ans = t[i+1];
            break;
        }
    }
    cout << ans << endl;
}