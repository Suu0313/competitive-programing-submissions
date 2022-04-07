#include <bits/stdc++.h>
using namespace std;


int main() {
  int T; cin >> T;
  while(T--){
    int n, m; cin >> n >> m;
    int h = 100;
    vector<int> a(n); for(auto&e : a) cin >> e;

    vector<vector<tuple<int,int,int>>> qs(n);
    for(int i = 0; i < m; ++i){
      int e, t, p; cin >> e >> t >> p; --e;
      qs[e].emplace_back(i, t, p);
    }

    constexpr int64_t inf = numeric_limits<int64_t>::max()/3;

    auto f = [&]{
      vector<int> res;
      int nt = 0;

      for(int i = 0; i < n; ++i){
        int l = int(qs[i].size());
        vector dp(l+1, vector(h+1, inf));
        vector pre(l+1, vector(h+1, -1));
        dp[0][0] = 0;

        for(int j = 0; j < l; ++j){
          auto[q, t, p] = qs[i][j];

          for(int k = 0; k <= h; ++k){
            dp[j+1][k] = min(dp[j+1][k], dp[j][k]);
            
            if(dp[j+1][min(h, k+p)] > dp[j][k]+t){
              dp[j+1][min(h, k+p)] = dp[j][k]+t;
              pre[j+1][min(h, k+p)] = k;
            }
          }
        }

        if(dp[l][h]+nt > a[i]){
          cout << -1 << "\n";
          return 0;
        }
        nt += dp[l][h];

        int nk = h;

        for(int j = l-1; j >= 0; --j){
          auto[q, t, p] = qs[i][j];

          if(dp[j][nk] == dp[j+1][nk]) continue;

          assert(pre[j+1][nk] >= 0);
          nk = pre[j+1][nk];
          res.push_back(q + 1);
        }
      }

      cout << res.size() << "\n";
      for(auto&e : res) cout << e << " ";
      cout << "\n";
      return 0;
    };

    f();
  }
}
