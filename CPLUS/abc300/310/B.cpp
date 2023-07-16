#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, bitset<100>>> product;
    for(int i=0; i<n; i++){
        int p, c; cin >> p >> c;
        bitset<100> func=0;
        int f;
        for(int j=0; j<c; j++){
            cin >> f; func |=(1<<(f-1));
        }
        product.push_back({p, func});
    }

    sort(product.begin(), product.end(), [](const auto& a, const auto& b){
        return a.first < b.first;
    });

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            bool flag1=false, flag2=false, flag3=false;

            if(product[i].first>=product[j].first) flag1=true;
            if((product[j].second & product[i].second) == product[i].second) flag2=true;
            if(product[i].first>product[j].first || (product[j].second & ~product[i].second).any()) flag3=true;

            cout << flag1 << ", " << flag2 << ", " << flag3 << endl;
            if(flag1 && flag2 && flag3){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}