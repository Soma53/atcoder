#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int ans=-1;
    vector<int> a(n+1, 0);
    if(s[0]=='o') a[0]=1;
    for(int i=1; i<n+1; i++){
        if(s[i]=='o') a[i]= a[i-1]+1;
    }
    ans = *max_element(a.begin(), a.end());
    if(ans==0) cout << -1 << endl;
    else if(ans==n) cout << -1 << endl;
    else cout << ans << endl;
}