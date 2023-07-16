#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, q; cin >> n >> p >> q;
    int d;
    for(int i=0; i<n; i++){
        cin >> d;
        if(q+d <p) p = q+d;
    }
    cout << p << endl;
}