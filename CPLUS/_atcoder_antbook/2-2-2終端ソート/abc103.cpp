#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> war(m, vector<int>(2));
    for(int i=0; i<m; ++i) cin >> war[i][1] >> war[i][0];
    sort(war.begin(), war.end());

    int ans=1, warb=war[0][0];
    for(vector<int> warvec:war){
        if(warb<=warvec[1]){
            ans++;
            warb=warvec[0];
        }
    }
    cout << ans << endl;
}