#include <bits/stdc++.h>
using namespace std;

bool can_win(string &S, string &T) {
    vector<int> count_S(26, 0), count_T(26, 0);
    int count_at_S = 0, count_at_T = 0;
    string atcoder = "atcoder";

    for (char c : S) {
        if (c == '@') {
            count_at_S++;
        } else {
            count_S[c - 'a']++;
        }
    }

    for (char c : T) {
        if (c == '@') {
            count_at_T++;
        } else {
            count_T[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count_S[i] != count_T[i]) {
            int diff = abs(count_S[i] - count_T[i]);
            if (count_S[i] < count_T[i]) {
                if (atcoder.find('a' + i) != string::npos && count_at_S >= diff) {
                    count_at_S -= diff;
                } else {
                    return false;
                }
            } else {
                if (atcoder.find('a' + i) != string::npos && count_at_T >= diff) {
                    count_at_T -= diff;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    string S, T; cin >> S >> T;
    if (can_win(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
