#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i, h) cin >> a[i];
    rep(i, h) cin >> b[i];

    bool flag;
    rep(i, h) a[i]+=a[i];
    rep(i, h) rep(j, w){
        flag=true;
        rep(k, h){
            if(b[k]!=a[(k+i)%h].substr(j, w)){
                flag=false;
                break;
            }
        }
        if(flag) goto OUT;
    }

OUT:
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}