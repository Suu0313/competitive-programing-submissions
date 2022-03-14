#include <bits/stdc++.h>
using namespace std;

#include "ModInt"
#include "Combination"

int main() {
  int n, m, k; cin >> n >> m >> k;
  Combination<mint> bc;

  vector dp(k+1, vector(m+1, 0_m));
  dp[0][0] = 1;

  vector<mint> ws(n);
  for(auto&w : ws) cin >> w;
  mint sw = accumulate(begin(ws), end(ws), 0_m);


  for(auto&w : ws){
    auto ndp = dp;
    mint dw = w/sw, p = 1;
    for(int i = 1; i <= k; ++i){
      p *= dw;
      for(int j = 0; j <= k-i; ++j){
        for(int l = 0; l < m; ++l){
          dp[j+i][l+1] += ndp[j][l] * bc.com(k-j, i) * p;
        }
      }
    }
  }

  cout << dp[k][m] << "\n";
}
