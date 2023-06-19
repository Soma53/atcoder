#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<string> c;

int main(){
    int h, w; cin >> h >> w;
    string cn;
    rep(i, h){
        cin >> cn;
        c.push_back(cn);
    }

    vector<int> n(min(h, w), 0);
    vector<vector<int>> d = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    rep(i, h) rep(j, w){
        if(c[i][j] == '#'){
            queue<vector<int>> q;
            q.push({i, j});
            int size=0;
            while(!q.empty()){
                vector<int> v=q.front();
                q.pop();
                c[v[0]][v[1]] = '.';
                rep(j, 4){
                    int nvx= v[0]+d[j][0];
                    int nvy= v[1]+d[j][1];
                    
                    if(nvx<0 || nvx>=h || nvy<0 || nvy>=w) continue;
                    if(c[nvx][nvy] == '.') continue;

                    q.push({nvx, nvy});
                    size++;
                }
            }
            size/=4;
            n[size-1]++;
        }
    }

    for(int nn: n) cout << nn << " ";
    cout << endl;
}