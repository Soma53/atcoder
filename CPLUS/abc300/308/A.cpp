#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> s(9);
    for(int i=0; i<8; i++) cin >> s[i+1];
    
    bool flag = true;
    for(int i=0; i<8; i++){
        if(s[i] > s[i+1] || (s[i+1]<100 || s[i+1]>675) || s[i+1]%25!=0){
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}