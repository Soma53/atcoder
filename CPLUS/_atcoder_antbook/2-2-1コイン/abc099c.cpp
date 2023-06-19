//貪欲法じゃないやんけこの問題

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a;
    int b[]={1, 6, 9};
    
    for(int bi:b){
        int temp=bi;
        while(temp<100001){
            a.push_back(temp);
            if(temp==1) break;
            temp*=bi;
        }
    }
    sort(a.begin(), a.end());
    for(int ai:a) cout << ai << " ";
    cout << endl;

    int ans=0;
    while(n!=0){
        auto ite = upper_bound(a.begin(), a.end(), n)-1;
        cout << n << " " << *ite << "|";
        n-=*ite;
        ans++;
    }
    cout << ans << endl;
}