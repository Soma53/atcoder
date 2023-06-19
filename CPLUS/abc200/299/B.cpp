#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long t, r; cin >> n >> t;
    vector<long long> c(n);
    
    int player=0, ans=0;
    bool flag=false;
    for(int i=0; i<n; i++){
        cin >> c[i];
        if(c[i] == t) flag=true;
    }
    if(flag){
        for(int i=0; i<n; i++){
            cin >> r;
            if(c[i]!=t) continue;
            if(ans<r){
                player=i;
                ans=r;
            }
        }
    }else{
        for(int i=0; i<n; i++){
            cin >> r;
            if(c[i]!=c[0]) continue;
            if(ans<r){
                player=i;
                ans=r;
            }
        }
    }
    cout << player+1 << endl;
}