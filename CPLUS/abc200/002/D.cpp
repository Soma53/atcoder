#include <bits/stdc++.h>
using namespace std;

int flagcheck(bitset<12> flag){
  int re=0;
  for(int i=0; i<12; i++){
    if(flag[i]) re+=1;
  }
  return re;
}

int main(){
  int n, m; cin >> n >> m;
  vector<int> x(m, 0), y(m, 0);
  for(int i=0; i<m; i++){
    cin >> x[i] >> y[i];
    x[i] -= 1;
    y[i] -= 1;
  }
  
  vector<bitset<12>> g(n, 0);
  for(int i=0; i<n; i++) g[i][i] = 1;
  for(int i=0; i<m; i++){
    g[x[i]][y[i]] = 1;
    g[y[i]][x[i]] = 1;
  }
  
  //全探索部分
  int party=1;
  for(int i=1; i<(1<<n); i++){
    bitset<12> check(i), flag((1<<n)-1);
    int crite = 0;
    for(int j=0; j<n; j++){
      if(check[j]){
        flag = flag & g[j];
        crite += 1;
      }
    }
    if(crite>=2) party = max(party, flagcheck(flag));
  }
  cout << party << endl;
}
