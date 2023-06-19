#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<string> m(r);
    for(int i=0; i<r; i++) cin >> m[i];

    Graph dist(r, vector<int>(c, -1));
    vector<int> dx={0, 0, 1, -1}, dy={1, -1, 0, 0};
    queue<vector<int>> q;
    q.push({sy, sx});
    dist[sy][sx]=0;

    while(!q.empty()){
        vector<int> v=q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nextvy = v[0] + dy[i];
            int nextvx = v[1] + dx[i];
        
            if(dist[nextvy][nextvx]!=-1) continue;
            else if(m[nextvy][nextvx]=='#') continue;

            dist[nextvy][nextvx] = dist[v[0]][v[1]]+1;
            q.push({nextvy, nextvx});
        }
    }
    
    cout << dist[gy][gx] << endl;
}