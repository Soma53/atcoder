#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; ++i) cin >> s[i];

    Graph dist(h, vector<int>(w, -1));
    vector<int> dx={0, 0, 1, -1}, dy={1, -1, 0, 0};
    queue<vector<int>> q;
    q.push({0, 0});
    dist[0][0]=1;

    while(!q.empty()){
        vector<int> v=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nextvy = v[0] + dy[i];
            int nextvx = v[1] + dx[i];
            
            if(nextvy<0 | nextvy>=h | nextvx<0 | nextvx>=w) continue;

            if(dist[nextvy][nextvx]!=-1) continue;
            else if(s[nextvy][nextvx]=='#') continue;

            dist[nextvy][nextvx] = dist[v[0]][v[1]]+1;
            q.push({nextvy, nextvx});
        }
    }
    if(dist[h-1][w-1]==-1) cout << -1 << endl;
    else{
        int black=0;
        for(int i=0; i<h; i++) for(int j=0; j<w; j++) if(s[i][j]=='#') black++;
        int ans = h*w-dist[h-1][w-1]-black;
        cout << ans << endl;
    }
}