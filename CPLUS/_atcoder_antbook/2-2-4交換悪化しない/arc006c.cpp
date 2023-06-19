#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    int w, flag, len=0;
    vector<int> st;
    for(int i=0; i<n; i++){
        cin >> w;
        flag = 1;
        auto ite = lower_bound(st.begin(), st.end(), w);
        if(st.end()==ite){
            st.push_back(w);
            len++;
        }else{
            st[ite-st.begin()] = w;
        }
    }
    int ans = 0;
    for(int top:st) ans++;
    cout << ans << endl;
}