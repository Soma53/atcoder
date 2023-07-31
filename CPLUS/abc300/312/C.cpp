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

// f(x)-g(x)の単調性から以下のコードが簡潔
// int main(){
//     int N, M;
//     cin >> N >> M;
//     vector<int> A(N+M);
//     for(int i=0; i<N; i++) cin >> A[i];
//     for(int i=0; i<M; i++){cin >> A[i+N]; A[i+N]++;}

//     sort(A.begin(), A.end());
//     cout << A[M-1] << endl;
// }

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int l = 0, r = 1e9+7;
    while(l+1<r){
        int mid = (l+r)/2;
        int i=0, j=0;
        for(int a:A) if(a <= mid) i++;
        for(int b:B) if(b >= mid) j++;

        if(i >= j) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}