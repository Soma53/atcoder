//fanc1のN≦30のケースに関して再履修
//線形計画法のコードだと場合分けしなくても解ける

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fanc1(int N, ll W, vector<vector<ll>> &value){
    vector<vector<ll>> ans_list(1, vector<ll>(2, 0));
    for(int i=0; i<N; i++){
        for(vector<ll> e: ans_list){
            if(value[i][1]+e[1]>W) continue;
            ans_list.push_back({value[i][0]+e[0], value[i][1]+e[1]});
        }
    }
    ll ans=0;
    for(vector<ll> e:ans_list) ans=max(ans, e[0]);
    cout << ans << endl;
    return;
}

void fanc2(int N, ll W, vector<vector<ll>> &value){
    vector<ll> napsack(W+1, 0);
    for(int i=0; i<N; i++){
        for(int j=W-value[i][1]; j>=0; j--){
            if(j==0 || napsack[j]!=0){
                napsack[j+value[i][1]] = max(napsack[j+value[i][1]], napsack[j]+value[i][0]);
            }
        }
    }
    ll ans =0;
    for(int i=1; i<W+1; i++) ans = max(ans, napsack[i]);
    cout << ans << endl;
    return;
}

void fanc3(int N, ll W, vector<vector<ll>> &value){
    vector<ll> napsack(200001, W+1);
    napsack[0]=0;
    for(int i=0; i<N; i++){
        for(int j=200000; j>=0; j--){
            if(napsack[j]+value[i][1]<=W){
                napsack[j+value[i][0]] = min(napsack[j+value[i][0]], napsack[j]+value[i][1]);
            } 
        }
    }
    ll ans=0;
    for(int i=200000; i>0; i--) if(napsack[i]!=W+1){
        ans=i;
        break;
    }
    cout << ans << endl;
    return;
}

int main(){
    int N; ll W; cin >> N >> W;

    vector<vector<ll>> value(N, vector<ll>(2));
    ll vmax=0, wmax=0;
    for(int i=0; i<N; i++){
        cin >> value[i][0] >> value[i][1];
        vmax=max(vmax, value[i][0]), wmax=max(wmax, value[i][1]);
    }

    if(wmax<=1000) fanc2(N, W, value);
    else if(vmax<=1000) fanc3(N, W, value);
    else fanc1(N, W, value);
}