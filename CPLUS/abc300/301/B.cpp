#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n-1; i++){
        if(a[i]<a[i+1]){
            for(int j=a[i]; j<a[i+1]; j++) cout << j << " ";
        }
        else if(a[i]>a[i+1]){
            for(int j=a[i]; j>a[i+1]; j--) cout << j << " ";
        }
    }

    cout << a[n-1] << endl;
}