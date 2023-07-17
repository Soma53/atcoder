#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, bitset<128>>> product;
    for(int i=0; i<n; i++){
        int p, c; cin >> p >> c;
        bitset<128> func=0;
        int f;
        for(int j=0; j<c; j++){
            cin >> f; func[f-1] = 1;
        }
        product.push_back({p, func});
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bool flag1=false, flag2=false, flag3=false;

            if(product[i].first>=product[j].first) flag1=true;
            if((product[j].second & product[i].second) == product[i].second) flag2=true;
            if(product[i].first>product[j].first || (product[j].second & ~product[i].second).any()) flag3=true;

            if(flag1 && flag2 && flag3){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}