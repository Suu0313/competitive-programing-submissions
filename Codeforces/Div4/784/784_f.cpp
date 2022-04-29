#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> w(n); for(auto&&e : w) cin >> e;
    int ans = 0;
    int64_t ls = 0, rs = 0;
    for(int l = 0, r = n; ; ++l){
      ls += w[l];
      while(ls > rs) rs += w[--r];
      if(l >= r) break;
      if(ls == rs) ans = l+1 + n-r;
    }
    cout << ans << "\n";
  }
}
