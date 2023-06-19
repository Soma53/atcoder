#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m, b, bf; cin >> t >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    if(n<m){
        cout << "no" << endl;
        return 0;
    }
    for(int i=0; i<m; i++){
        cin >> b;
        bf = max(b-t, 1);
        auto ite1 = lower_bound(a.begin(), a.end(), bf);
        auto ite2 = upper_bound(a.begin(), a.end(), b);
        if(ite1==ite2){
            cout << "no" << endl;
            return 0;
        }else{
            a[ite1-a.begin()] = -1;
        }
    }
    cout << "yes" << endl;
}