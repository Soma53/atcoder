#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, a, b; cin >> n >> a >> b;
    int c;
    a+=b;
    for(int i=0; i<n; i++){
        cin >> c;
        if(a==c) cout << i+1 << endl;
    }
}