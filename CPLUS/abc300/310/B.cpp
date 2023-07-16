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
            if((product[i].second & product[j].second) == product[j].second){
                if(product[i].first < product[j].first){
                    cout << "Yes" << endl;
                    return 0;
                }
                else if(product[i].first == product[j].first){
                    if((product[i].second ^ product[j].second).any()){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}