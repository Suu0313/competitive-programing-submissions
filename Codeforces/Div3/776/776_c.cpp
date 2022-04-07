#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<int> x(m), w(m), idx(m); iota(begin(idx), end(idx), 0);
    for(int i = 0; i < m; ++i) cin >> x[i] >> w[i];

    sort(begin(idx), end(idx), [&](int i, int j){ return w[i] < w[j]; });
    sort(begin(w), end(w)); w.resize(n * 2); idx.resize(n * 2);
    sort(begin(idx), end(idx), [&](int i, int j){ return x[i] < x[j]; });

    cout << accumulate(begin(w), end(w), 0ll) << "\n";
    for(int i = 0; i < n; ++i) cout << idx[i]+1 << " " << idx[n*2-i-1]+1 << "\n";
    cout << "\n";
  }
}
