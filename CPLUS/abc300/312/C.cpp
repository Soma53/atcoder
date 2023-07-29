#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define repp(i, s, n) for (int i=(s); i<=(int)(n); ++i)

using ll = long long;
const ll mod = 1000000007;

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}
template <typename T>
bool chmin(T &a, const T& b) {if (a > b) {a = b;return true;}return false;}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0; i<N; i++){
        auto it = upper_bound(B.begin(), B.end(), A[i]);
        int j = B.end() - it;
        // cout << i+1 << ", " << j << endl;
        if(A[i] > B[M-1]){
            cout << B[M-1] + 1 << endl;
            return 0;
        };
        if(i + 1 >= j){
            cout << A[i] << endl;
            return 0;
        }
    }
    return 0;
}