#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Medicine {
    ll dose_day;
    ll daily_dose;
};

bool compareMedicine(const Medicine &a, const Medicine &b) {
    return a.dose_day > b.dose_day;
}

int main(){
    ll n, k; cin >> n >> k;
    vector<Medicine> medicines(n);
    ll daily_total=0;

    for(ll i=0; i<n; ++i){
        ll a, b;
        cin >> a >> b;
        daily_total+=b;
        medicines[i].dose_day=a;
        medicines[i].daily_dose=b;
    }

    sort(medicines.begin(), medicines.end(), compareMedicine);

    ll day=0;
    while(daily_total>k){
        Medicine m=medicines.back(); medicines.pop_back();
        daily_total -= m.daily_dose;
        day = m.dose_day;
    }
    cout << day+1 << endl;
    return 0;
}