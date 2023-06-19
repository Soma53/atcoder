#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n>> m;
    vector<vector<int>> p(n, vector<int>());
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--, b--; p[a].push_back(b), p[b].push_back(a);
    }

    vector<int> array(n);
    for(int i=0; i<n; i++) array[i] = i;
    int ans=0;
    do{
        bool flag = true;
        for(int i=0; i<n-1; i++){
            if(count(p[array[i]].begin(), p[array[i]].end(), array[i+1])==0){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(array.begin()+1, array.end()));

    cout << ans << endl;
}