#include <bits/stdc++.h>
using namespace std;

long long denom = 998244353;

long long mod(long long x){
    lldiv_t ans = lldiv(x, denom);
    return ans.rem;
}

int main(){
    int q; cin >> q;

    string s="1";
    for(int i=0; i<q; ++i){
        int query; cin >> query;
        if(query==1){
            char x; cin >> x;
            s+=x;
        }else if(query==2){
            s=s.substr(1, s.size()-1);
        }else if(query==3){
            long long temp=0;
            while((int)s.size()>18){
                int ss = (int)s.size();
                temp = mod(s.substr(0, 18));
                s=s.substr(0, s.size()-18);
                temp = s.substr(s.size()-18);
                
                temp += mod()
            }
            long long x=stoll(s);
            mod(x);
        }
    }
}