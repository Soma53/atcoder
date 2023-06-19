#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> age(n);
    vector<string> name(n);
    for(int i=0; i<n; i++) cin >> name[i] >> age[i];

    auto min = min_element(age.begin(), age.end());
    for(int i=0; i<n; i++) cout << name[(min-age.begin()+i)%n] << endl;
}