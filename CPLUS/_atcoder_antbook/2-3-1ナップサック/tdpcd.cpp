//やり直し
//制約に合わない

#include <bits/stdc++.h>
using namespace std;
using ll=long long;



bool isDividedDice(ll d) {
    for(int i=2; i<7; i++){
        while(d%i==0){
            d/=i;
        }
    }
    if(d!=1) return false;
    return true;
}

int main(){
    int n;
    ll d;
    cin >> n >> d;
    
    if(!isDividedDice(d)) {cout << 0 << endl; return 0;}
    //modで管理する．
    vector<vector<float>> dp(n+1, vector<float>(d, 0));
    dp[0][1]=1.0;
    for(int i=1; i<n+1; i++){
        for(int j=0; j<d; j++){
            for(int k=1; k<7; k++){
                dp[i][(j*k)%d] += dp[i-1][j]/6.0;
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << dp[n][0] << endl;
}