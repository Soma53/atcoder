//超難問　やり直し必須

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    string ans, temp=s;
    for(int i=0; i<n; i++){
        auto ite = min_element(temp.begin(), temp.end());
        ans += *ite;

        if(ans[i]!=s[i]) k--;
        temp.erase(ite);

        int count = 0;
        for(int j=0; j<(int)temp.size(); j++){
            if(s)
        }
    }
}