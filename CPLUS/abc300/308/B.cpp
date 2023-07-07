#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<string> dishes(n); for(int i=0; i<n; i++) cin >> dishes[i];

    map<string, int> prices;
    vector<string> colors(m+1);
    vector<int> price_list(m+1);

    for(int i=0; i<m+1; ++i){
        if(i==0) colors[i] = "*";
        else cin >> colors[i];
    }
    for(int i=0; i<m+1; ++i) cin >> price_list[i];
    for(int i=0; i<m+1; ++i) prices[colors[i]] = price_list[i];

    int sum = 0;
    for(const auto& dish : dishes){
        if(prices.count(dish) > 0) sum += prices[dish];
        else sum += prices["*"];
    }

    cout << sum << endl;

    return 0;
}