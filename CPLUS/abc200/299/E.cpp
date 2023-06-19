#include <bits/stdc++.h>
using namespace std;
using Tree = vector<vector<int>>;

void coloring(Tree &tree, vector<int> &color, int p, int v, int d){
    if(d<=0) return;
    color[v]=0;
    for(int nv:tree[v]){
        if(p==nv) continue;
        coloring(tree, color, v, nv, d-1);
    }
    return;
}

int main(){
    int n, m; cin >> n >> m;

    Tree tree(n, vector<int>());
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--, v--; tree[u].push_back(v), tree[v].push_back(u);
    }

    vector<int> color(n, -1);
    int k; cin >> k;
    for(int i=0; i<k; i++){
        int v, d; cin >> v >> d; v--;
        coloring(tree, color, -1, v, d);
        for(int i=0; i<n; i++) cout << color[i];
        cout << endl;
    }

    bool flag=false;
    for(int i=0; i<n; i++) if(color[i]==-1) color[i]=1, flag=true;
    if(flag){
        cout << "Yes" << endl;
        for(int i=0; i<n; i++) cout << color[i];
        cout << endl;
    }else{
        cout << "No" << endl;
    }
}