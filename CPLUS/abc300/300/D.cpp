#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> p;

vector<bool> sieve_of_eratosthenes(ll n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

int main() {
    ll N; cin >> N;
    int n; n=sqrt(N);
    vector<bool> prime = sieve_of_eratosthenes(n);
    for(int i=0; i<n+1; i++) if(prime[i]) p.push_back(i);

    ll count = 0;
    for(int i=0; i<(int)p.size(); i++) for(int j=i+1; j<(int)p.size(); j++){
        auto ite=upper_bound(p.begin(), p.end(), sqrt(N/(pow(p[i], 2)*p[j])));
        if(ite-p.begin()<=j) break;
        count += ite-p.begin()-j-1;
    }

    cout << count << endl;
    return 0;
}