#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, T, M;
vector<vector<int>> teams;

ll dfs(int i, vector<vector<bool>> &relation){
    if(i==N) return (int)teams.size()==T;

    ll count = 0;
    for(int k=0; k<(int)teams.size(); k++){
        bool ok = true;
        for(int mem:teams[k]){
            if(relation[i][mem]) ok = false;
        }
        if(ok){
            teams[k].emplace_back(i);
            count += dfs(i+1, relation);
            teams[k].pop_back();
        }
    }

    if((int)teams.size() < T){
        teams.emplace_back(vector<int> {i});
        count += dfs(i+1, relation);
        teams.pop_back();
    }

    return count;
}

int main(){
    cin >> N >> T >> M;
    vector<vector<bool>> relation(N, vector<bool>(N, false));
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        relation[a][b]=true;
        relation[b][a]=true;
    }

    cout << dfs(0, relation) << endl;
}