#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> re(n, vector<int>(n, 1));
    for(int i=0; i<n; i++) re[i][i]=0;

    vector<int> a(n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin >> a[j];
        for(int j=0; j<n-1; j++){
            re[a[j]-1][a[j+1]-1]=0;
            re[a[j+1]-1][a[j]-1]=0;
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans+=re[i][j];
        }
    }
    cout << ans/2 << endl;
}