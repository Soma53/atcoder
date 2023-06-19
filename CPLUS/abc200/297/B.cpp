#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    
    string ans="No";
    int temp1=-1, temp2=-1;
    bool flag1=false, flag2=false;
    for(int i=0; i<8; i++){
        if(s[i]=='B'&&temp1==-1) temp1=i;
        else if(s[i]=='B'&& (temp1%2!=i%2)) flag1=true;

        if(s[i]=='K'){
            for(int j=0; j<i; j++){
                if(s[j]=='R') temp2=1;
            }
            for(int j=i+1; j<8; j++){
                if(s[j]=='R' && temp2==1) flag2=true; 
            }
        }
    }

    if(flag1 && flag2) ans="Yes";
    cout << ans << endl;
}