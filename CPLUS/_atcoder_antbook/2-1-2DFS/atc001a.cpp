#include <bits/stdc++.h>
using namespace std;

int h, w;
string ans="No";

void dfs(int x, int y, vector<vector<char>> &c, vector<vector<bool>> &cb){
    if(x>=h || x<0 || y>=w || y<0 || c[x][y]=='#') return;
    if(cb[x][y]==true) return;

    cb[x][y]=true;

    dfs(x-1, y, c, cb);
    dfs(x+1, y, c, cb);
    dfs(x, y-1, c, cb);
    dfs(x, y+1, c, cb);
}

int main(){
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    vector<vector<bool>> cb(h, vector<bool>(w, false));
    
    int sx, sy, gx, gy;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++){
        cin >> c[i][j];
        if(c[i][j]=='s'){
            sx=i; sy=j; //cb[i][j]=true;
        } else if(c[i][j]=='g'){
            gx=i; gy=j;
        }
    }

    dfs(sx, sy, c, cb);
    if(cb[gx][gy]) ans="Yes";

    cout << ans << endl;
}