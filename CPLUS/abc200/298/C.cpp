#include <bits/stdc++.h>
using namespace std;

void q2(Box &box, int i){
    for(int j=0; j<200001; ++j){
        for(int k=0; k<box[i][j]; k++) cout << j << " ";
    }
    cout << endl;
    return;
}

void q3(Box &box, int i, int n){
    for(int j=0; j<n; ++j) { 
        if(box[j][i]>0) cout << j+1 << " ";
    }
    cout << endl;
    return;
}

int main(){
    int n, q; cin >> n >> q;
    vector<bitset<200001> box(n, bitset<200001>(0));
    vector<vector<int>> card(n, vector<int>());

    for(int m=0; m<q; m++){
        int query; cin >> query;
        if(query==1){
            int i, j; cin >> i >> j; j--;
            if(box[j].find(i)) card[j]
            box[j].insert(i);
            
            card[j].
        }else if(query==2){
            int i; cin >> i; i--;
            q2(box, i);
        }else if(query==3){
            int i; cin >> i;
            q3(box, i, n);
        }
    }
}