#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> seen, finished;

void dfs(Graph &g, int v, int &count, int p, int &cycle){
    //フラグを立てる
    seen[v] = 1;

    //子ノードに対して処理
    for(int nextv: g[v]){
        //逆流の禁止
        if(nextv==p) continue;
        //サイクルの判定
        else if(finished[nextv]) continue;
        else if(seen[nextv] && !finished[nextv]){
            cycle=1;
            return;
        }
        dfs(g, nextv, count, v, cycle);
        if(cycle==1) return;
    }
    if(cycle==0 && p == -1) count++;

    //フラグを回収する
    finished[v]=1;
    return;
}

int main(){
    int n, m; cin >> n >> m;
    Graph g(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    int count=0, p=-1, cycle=0;
    seen.assign(n, 0);
    finished.assign(n, 0);

    for(int v=0; v<n; v++){
        if(seen[v]==1) continue;
        dfs(g, v, count, p, cycle);
        cycle=0;
    }

    cout << count << endl;
}