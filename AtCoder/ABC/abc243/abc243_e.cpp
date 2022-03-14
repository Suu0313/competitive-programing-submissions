#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m; cin >> n >> m;
  vector<tuple<int,int,int>> es(m);
  constexpr int inf = numeric_limits<int>::max()/2;
  vector dist(n, vector(n, inf));

  for(auto&[u, v, d] : es){
    cin >> u >> v >> d; --u; --v;
    dist[u][v] = dist[v][u] = d;
  }

  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i)for(int j = 0; j < n; ++j){
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  int ans = 0;
  for(auto&[u, v, d] : es){
    int nd = d + 1;
    for(int k = 0; k < n; ++k){
      nd = min(nd, dist[u][k] + dist[k][v]);
    }
    ans += d >= nd;
  }
  
  cout << ans << "\n";
}
