#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    bool flag=true;
    for(int i=0; i<n; ++i){
        if(s[i]=='|'){
            for(int j=i+1; j<n; j++){
                if(s[j]=='|'){
                    flag=false;
                    goto OUT;
                }else if(s[j]=='*'){
                    flag=true;
                    goto OUT;
                }
            }
        }
    }
OUT:
    if(flag) cout << "in" << endl;
    else cout << "out" << endl;
}