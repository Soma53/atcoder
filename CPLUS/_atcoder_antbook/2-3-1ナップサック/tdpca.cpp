#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p; cin >> n;
    vector<bool> point(10001, false);

    point[0] = true;
    for(int i=0; i<n; i++){
        cin >> p;
        for(int j=10000; j>=0; j--){
            if(point[j] && j+p<10001) point[j+p]=true;
        }
    }


    int ans = 0;
    for(int i=0; i<10001; i++) cout << point[i] <<" ";//if(point[i]) ans++;
    cout << ans << endl;

}