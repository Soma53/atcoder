#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

Graph g;
vector<int> dist;
queue<int> q;

int bfs(int root){
    q.push(root);
    dist[root] = 0;

    int distance = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int d = dist[u]+1;
        for(int v: g[u]){
            if(dist[v] <= d) continue;
            q.push(v);
            dist[v] = d;
            distance = max(distance, d);
        }
    }
    return distance;
}

int main(){
    int n1, n2, m; cin >> n1 >> n2 >> m;
    g.resize(n1+n2); dist.resize(n1+n2); fill(dist.begin(), dist.end(), INT_MAX);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << bfs(0)+bfs(n1+n2-1)+1 << endl;
}