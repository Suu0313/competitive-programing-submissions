#include <bits/stdc++.h>
using namespace std;

#include "ModInt"

int main() {
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; --s; --t;

    vector<vector<int>> g(n);
    while(m--){
      int u, v; cin >> u >> v; --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> dist(n, -1);
    dist[s] = 0;
    {
      queue<int> qu;
      for(qu.push(s); !qu.empty(); qu.pop()){
        int v = qu.front();

        for(auto&u : g[v]){
          if(dist[u] >= 0) continue;
          dist[u] = dist[v] + 1;
          qu.push(u);
        }
      }
    }

    vector dp(2, vector(n, mint(0)));
    vector seen(2, vector(n, 0));
    dp[0][s] = 1;

    queue<pair<int,int>> qu;
    for(qu.emplace(s, 0); !qu.empty(); qu.pop()){
      auto[v, c] = qu.front();

      if(seen[c][v]) continue;
      seen[c][v] = 1;

      for(auto&u : g[v]){
        int d = dist[u] - dist[v];

        if(c == 0){
          if(d == 1){
            dp[0][u] += dp[0][v];
            qu.emplace(u, 0);
          }
          if(d == 0){
            dp[1][u] += dp[0][v];
            qu.emplace(u, 1);
          }
        }else{
          if(d == 1){
            dp[1][u] += dp[1][v];
            qu.emplace(u, 1);
          }
        }
      }
    }

    cout << dp[0][t] + dp[1][t] << "\n";
  }
}
