#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> arm;
    for(int i=0; i<n; i++){
        int x, l; cin >> x >> l;
        arm.push_back({x+l, x-l});
    }
    sort(arm.begin(), arm.end());

    int ans=1, armend=arm[0][0];
    for(vector<int> ar: arm){
        if(armend<=ar[1]){
            armend=ar[0];
            ans++;
        }
    }
    cout << ans << endl;
}