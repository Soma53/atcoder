#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Kyujin = vector<vector<vector<ll>>>;

Kyujin kyujin(101, vector<vector<ll>>(101, vector<ll>(101, 0)));

int main(){
    int n, m; cin >> n >> m;

    int a, b, c;
    ll w;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> w;
        kyujin[a][b][c]=max(kyujin[a][b][c], w);
    }
    for(int i=0; i<=100; i++) for(int j=0; j<=100; j++) for(int k=0; k<=100; k++){
        if(i) kyujin[i][j][k] = max(kyujin[i][j][k], kyujin[i-1][j][k]);
        if(j) kyujin[i][j][k] = max(kyujin[i][j][k], kyujin[i][j-1][k]);
        if(k) kyujin[i][j][k] = max(kyujin[i][j][k], kyujin[i][j][k-1]);
    }

    int x, y, z;
    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        cout << kyujin[x][y][z] << endl;
    }
}