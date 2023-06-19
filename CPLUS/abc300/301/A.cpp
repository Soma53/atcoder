#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int counta=0, countt=0;
    for(int i=0; i<n; i++){
        if(s[i]=='A') counta++;
        else countt++;

        if(counta>=(n+1)/2 || countt>=(n+1)/2) break;
    }

    if(counta>countt) cout << "A" << endl;
    else cout << "T" << endl;
}