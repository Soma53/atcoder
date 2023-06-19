#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    n=1000-n;

    vector<int> coin={1, 5, 10, 50, 100, 500};
    int ans=0;
    while(n!=0){
        auto ite = upper_bound(coin.begin(), coin.end(), n)-1;
        n-=*ite;
        ans++;
    }
    cout << ans << endl;
}