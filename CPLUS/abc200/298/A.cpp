#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int flag1=0, flag2=1;
    for(int i=0; i<(int)s.size(); ++i){
        if(s[i]=='o') flag1=1;
        if(s[i]=='x') flag2=0;
    }
    if(flag1 && flag2) cout << "Yes" << endl;
    else cout << "No" << endl;
}