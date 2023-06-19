#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n,0)), b(n, vector<int>(n,0));
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> a[i][j];
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> b[i][j];

    int flag;
    vector<vector<int>> c(n, vector<int>(n,0));
    for(int m=0; m<4; ++m){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                c[n-1-j][i] = a[i][j];
            }
        }
        a = c;
        flag=1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(a[i][j]==1){
                    if(b[i][j]!=1){
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag==1) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout <<"No" << endl;
}