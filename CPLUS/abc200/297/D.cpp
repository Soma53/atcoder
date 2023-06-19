#include <bits/stdc++.h>
using namespace std;

long long ans=0;

int main(){
    long long a, b; cin >> a>> b;

    while(a!=b){
        if(a<b) swap(a,b);
        ans+=a/b;
      	if(a%b==0){
          ans-=1;
          break;
        }
        long long temp = a;
        a=b;
        b=temp%a;
    }

    cout << ans << endl;
}