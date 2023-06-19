#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    string ans = "UNRESTORABLE";;

    vector<string> anslist;
    int slen=(int)s.size(), tlen=(int)t.size();
    for(int i=slen-tlen; i>-1; i--){
        for(int j=0; j<tlen; j++){
            if(s[i+j]!=t[j] && s[i+j]!='?') break;
            else {
                if(j==tlen-1){
                    anslist.push_back(s.substr(0, i) + t + s.substr(i+j+1, slen-i-j-1));
                }
            }
        }
    }
    for(string a:anslist){
        for(int i=0; i<slen; i++) if(a[i]=='?') a[i] = 'a';
        if(ans=="UNRESTORABLE"){
            ans=a;
            continue;
        }
        ans = min(ans, a);
    }

    cout << ans << endl;
}