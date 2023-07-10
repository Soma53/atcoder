#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x=i, y=j;
            if(i==0 && j!=0) y-=1;
            else if(i==n-1 && j!=n-1) y+=1;
            if(j==0 && i!=n-1) x+=1;
            else if(j==n-1 && i!=0) x-=1;
            cout << a[x][y];
        }
        cout << endl;
    }
}