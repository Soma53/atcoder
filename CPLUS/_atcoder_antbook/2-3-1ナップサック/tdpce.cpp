//わからんすぎだろ
//方針はあってたが実装がむずすぎる

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int d; string n; cin >> d >> n;
    
    int digit=(int)n.size(), m, top_m;
    vector<vector<mint>> dp(digit, vector<mint>(d, 0));
    m=n[0]-'0';
    top_m=m%d;
    for(int i=1; i<m+1; i++) dp[0][i%d] += 1;
    for(int i=1; i<digit; i++){
        m=n[i]-'0';
        for(int j=1; j<=9; j++) dp[i][j%d] += 1;
        for(int j=0; j<d; j++) for(int k=0; k<10; k++) dp[i][(j+k)%d] += dp[i-1][j];
        for(int j=9; j>m; j--) dp[i][(top_m+j)%d]--;
        top_m=(top_m+m)%d;
        
    }
    // for(int i=0; i<digit; i++){
    //     for(int j=0; j<d; j++) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }
    cout << dp[digit-1][0].val() << endl;
}