#include <bits/stdc++.h>
using namespace std;

string ans = "NO";

void dfs(int i, int j, vector<string> &a){
    if(i<0 || i>=10 || j<0 || j>=10) return;
    if(a[i][j]=='x') return;

    a[i][j]='x';

    dfs(i-1, j, a);
    dfs(i+1, j, a);
    dfs(i, j-1, a);
    dfs(i, j+1, a);
}

void search(int x, int y, vector<string> a){
    a[x][y]='o';
    int count=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j]=='o'){
                count++;
                dfs(i, j, a);
            }
        }
    }
    if(count==1) ans="YES";
    a[x][y]='x';
}

int main(){
    vector<string> a(10);
    for(int i=0; i<10; i++) cin >> a[i];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j]=='x') search(i, j, a);
            if(ans=="YES") goto OUT;
        }
    }
OUT:
    cout << ans << endl;
}