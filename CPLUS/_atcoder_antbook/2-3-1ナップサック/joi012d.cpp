#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, n; cin >> d >> n;
    vector<int> t(d); for(int i=0; i<d; i++) cin >> t[i];
    vector<vector<int>> clothes(n, vector<int>(3));
    for(int i=0; i<n; i++) cin >> clothes[i][0] >> clothes[i][1] >> clothes[i][2];

    vector<vector<int>> c(d, vector<int>(n, 0));
    for(int i=0; i<d; i++){
        for(int j=0; j<n; j++){
            if(t[i]<clothes[j][0] || t[i]>clothes[j][1]){
                c[i][j]=-1;
                continue;
            }else if(i==0){
                continue;
            }
            
            int m=0;
            for(int k=0; k<n; k++){
                if(c[i-1][k]==-1) continue;
                m = max(m, c[i-1][k]+abs(clothes[k][2]-clothes[j][2]));
            }
            c[i][j]=m;
        }
    }

    int ans =0;
    for(int i=0; i<n; i++) ans = max(ans, c[d-1][i]);
    cout << ans << endl;
}