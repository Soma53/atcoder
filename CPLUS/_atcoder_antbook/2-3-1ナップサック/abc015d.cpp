#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, n, count; cin >> w >> n >> count;
    
    vector<vector<int>> value(count, vector<int>(w+1, 0));
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        for(int j=count-1; j>=0; j--) for(int k=w-a; k>=0; k--) {
            if(j==0) value[j][a] = max(value[j][a], b);
            else{
                value[j][k+a] = max(value[j][k+a], value[j-1][k]+b);
            }
        }
    }
    int ans=0;
    for(int i=0; i<count; i++) for(int j=0; j<w+1; j++) ans=max(ans, value[i][j]);
    cout << ans << endl;
}