#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    int s;
    int left=1, right=n;
    while(right>=left){
        int mid = left + (right-left)/2;
        cout << "? " << mid << endl;
        cout << flush;
        cin >> s;
        if(s==1){
            right=mid-1;
        }else if(s==0){
            left=mid+1;
        }
    }
    cout << "! " << right << endl;
}