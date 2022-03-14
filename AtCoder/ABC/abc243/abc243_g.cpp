#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int64_t x; cin >> x;
    int64_t sx = sqrtl(x);
    int64_t ssx = sqrtl(sx);

    vector<int64_t> dp(ssx + 1);

    for(int64_t i = 1; i <= ssx; ++i) dp[i] = sx - i*i + 1;

    while(int(dp.size()) > 2){
      int y = int(dp.size()) - 1;
      int sy = sqrtl(y);

      vector<int64_t> ndp(sy + 1); swap(dp, ndp);
      int64_t sum = 0;

      for(int64_t i = sy; i > 0; --i){
        while(i*i <= y){
          sum += ndp[y]; --y;
        }
        dp[i] = sum;
      }
    }

    cout << dp[1] << "\n";
  }
}
