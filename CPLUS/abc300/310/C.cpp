#include <bits/stdc++.h>
using namespace std;
 
string reverse_string(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}
 
int main() {
    int N;
    cin >> N;
    set<pair<string, string>> rods;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        string reversed_S = reverse_string(S);
        if (S > reversed_S) swap(S, reversed_S);
        rods.insert({S, reversed_S});
    }
    cout << rods.size() << endl;
    return 0;
}