#include <bits/stdc++.h>
using namespace std;

template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    int sx, sy, gx, gy;
    for(int i=0; i<h; i++){
        cin >> c[i];
        if(contain(c[i], 's')) for(int j=0; j<w; j++) if(c[i][j]=='s') sy=i, sx=j;
        if(contain(c[i], 'g')) for(int j=0; j<w; j++) if(c[i][j]=='g') gy=i, gx=j;
    }

    vector<vector<int>> dist(h, vector<int>(w, 1000));
    vector<int> dx={0, 0, 1, -1}, dy={1, -1, 0, 0};
    deque<vector<int>> q;
    q.push_front({sy, sx});
    dist[sy][sx]=0;

    while(!q.empty()){
        vector<int> v=q.front();
        q.pop_front();

        for(int i=0; i<4; i++){
            int nextvy = v[0] + dy[i];
            int nextvx = v[1] + dx[i];

            if(nextvy<0 || nextvy>=h || nextvx<0 || nextvx>=w) continue;

            if(c[nextvy][nextvx]!='#'){
                if(dist[nextvy][nextvx] > dist[v[0]][v[1]]){
                    dist[nextvy][nextvx] = dist[v[0]][v[1]];
                    q.push_front({nextvy, nextvx});
                }
            }else{
                if(dist[nextvy][nextvx] > dist[v[0]][v[1]]+1){
                    dist[nextvy][nextvx] = dist[v[0]][v[1]]+1;
                    q.push_back({nextvy, nextvx});
                }
            }
        }
    }

    if(dist[gy][gx]<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
}