//再挑戦必要

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> box(n, vector<int>(2));
    for(int i=0; i<n; i++) cin >> box[i][0] >> box[i][1];
    sort(box.begin(), box.end());

    vector<int> count(n, -1);
    count[0]=1;
    int temp, max_c=1;
    for(int i=1; i<n; i++){
        //wはソート済，hについて減少があった場合さらにひとつ前と比較する
        temp=i-1;
        while(box[i][0]<=box[temp][0] || box[i][1]<=box[temp][1]){
            temp--;
            if(temp==-1) break;
        }
        if(temp==-1) count[i] = max(count[i-1], 1);
        else{
            count[i] = max(count[i-1], count[temp]+1);
        } 
    }
    for(int i=0; i<n; i++) cout << box[i][0] << " " << box[i][1] << " " << count[i] << endl;
    cout << count[n-1] << endl;
}
