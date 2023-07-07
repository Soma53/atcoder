#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Person{
    int id;
    ll a, ab;

    bool operator < (const Person& rhs) const{
        if(a*rhs.ab == ab*rhs.a) return id < rhs.id;
        return a*rhs.ab > ab*rhs.a;
    }
};

int main(){
    int n; cin >> n;

    vector<Person> people(n);
    for(int i=0; i<n; ++i){
        ll A, B;
        cin >> A >> B;

        people[i].id = i+1;
        people[i].a = A;
        people[i].ab = A+B;
    }

    sort(people.begin(), people.end());

    for(const auto& person : people) cout << person.id << " ";
    cout << endl;

    return 0;
}