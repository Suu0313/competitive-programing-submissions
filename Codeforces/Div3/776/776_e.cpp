#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n, d; cin >> n >> d;
    vector<int> a(n); for(auto&e : a) cin >> e;

    auto f = [&](int i){
      if(i == -1) return 0;
      int x = a[i]; a.erase(begin(a) + i);

      valarray<int> ds(n-1); ds[0] = a[0] - 1;

      for(int i = 1; i < n-1; ++i) ds[i] = a[i] - a[i-1] - 1;
      int mx = max((ds.max() - 1)/2, d - a.back() - 1);

      a.insert(begin(a)+i, x);
      return min(mx, ds.min());
    };

    int mn = a[0], p = 0;
    for(int i = 1; i < n; ++i){
      if(mn > a[i] - a[i-1]){
        mn = a[i] - a[i-1];
        p = i;
      }
    }

    cout << max(f(p), f(p-1)) << "\n";
  }
}
