#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binaryStringToDecimal(const string &s) {
    ll decimal=0;
    for (size_t i=0; i<s.size(); ++i) {
        decimal = decimal*2+(s[i]-'0');
    }
    return decimal;
}

string padWithZeroes(string &s) {
    while((int)s.size()<60) s='0'+s;
    return s;
}

ll max_value_under_n(string &s, ll n){
    bitset<60> nb(n);
    bool flag=false;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i]=='?'){
            if(flag || nb[59-i]==1) s[i]='1';
            else s[i]='0';
        }

        if(s[i]=='0' && nb[59-i]==1){
            flag=true;
        }
    }

    return binaryStringToDecimal(s);
}


int main(){
    string s;
    ll n;
    cin >> s >> n;
    padWithZeroes(s);

    ll ans = max_value_under_n(s, n);
    if(ans>n) cout << -1 << endl;
    else cout << ans << endl;
}