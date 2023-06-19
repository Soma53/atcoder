#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; ++i) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<int> dx={0, 0, 1, -1}, dy={1, -1, 0, 0};
    queue<vector<int>> q;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++){
        if(s[i][j]=='#') q.push({i, j}); dist[i][j]=0;
    }

    while(!q.empty()){
        vector<int> v=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nextvy = v[0] + dy[i];
            int nextvx = v[1] + dx[i];
            
            if(nextvy<0 | nextvy>=h | nextvx<0 | nextvx>=w) continue;
            else if(s[nextvy][nextvx]=='#') continue;

            dist[nextvy][nextvx]=dist[v[0]][v[1]]+1;
            s[nextvy][nextvx]='#';
            q.push({nextvy, nextvx});
        }
    }
    int ans=0;
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) ans=max(ans, dist[i][j]);
    cout << ans << endl;
}