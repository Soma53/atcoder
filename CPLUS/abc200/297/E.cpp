#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n>> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    set<long long> q;
    q.insert(0);
    vector<long long> ans;
    for(int i=0; i<k+1; i++){
        // auto it = min_element(q.begin(), q.end());
        // int v = *min_element(q.begin(), q.end());
        // iter_swap(it, q.end()-1);
        // q.pop_back();

        long long v=*q.begin();
        if(i>0 && ans[i-1]==v){
            q.erase(q.begin());
            i--;
            continue;
        }
        ans.push_back(v);
        q.erase(q.begin());

        for(int j=0; j<n; j++){
            q.insert(v+a[j]);
        }
    }
    cout << ans[k] << endl;
}