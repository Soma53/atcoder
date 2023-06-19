//やり直し　この実装だとupper_boundでおそらく詰まっている．
//原因は推測だと二部探索で実行されるところにcustome_compareを行っている点．これだと正しくない．

#include <bits/stdc++.h>
using namespace std;

bool custom_sort(const pair<int, int> &p1, const pair<int, int> &p2){
    return min(p1.first, p1.second) < min(p2.first, p2.second);
}

bool custom_compare(const pair<int, int> &p1, const pair<int, int> &p2){
    if(p1.first < p2.first && p1.second < p2.second) return true;
    return false;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> a(n, pair<int, int>()), b(n, pair<int, int>());
    for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    for(int i=0; i<n; i++) cin >> b[i].first >> b[i].second;

    sort(a.begin(), a.end(), custom_sort);
    sort(b.begin(), b.end(), custom_sort);
    int ans=0;
    for(int i=0; i<n; i++){
        auto ite = upper_bound(b.begin(), b.end(), a[i], custom_compare);
        if(ite==b.end()){
            cout << i << endl;
            continue;
        }
        else {
            cout << b[ite-b.begin()].first << " " << b[ite-b.begin()].second << endl;
            b[ite-b.begin()].first = -1, b[ite-b.begin()].second = -1;
            ans++;
        }
    }
    for(pair<int,int> p:b) cout << p.first << p.second<< endl;
    cout << ans << endl;
}

