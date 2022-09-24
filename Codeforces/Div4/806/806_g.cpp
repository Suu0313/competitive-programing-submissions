#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; int64_t k; cin >> n >> k;
    vector<int> a(n); for(auto&&e : a) cin >> e;
    int64_t ans = accumulate(begin(a), end(a), 0ll) - k * n;
    reverse(begin(a), end(a));
    int64_t sum = ans;
    vector<int> b;
 
    for(auto&&e : a){
      sum += k;
      b.push_back(e);
 
      vector<int> c;
      for(auto&&x : b){
        sum -= x - x/2;
        x /= 2;
        if(x) c.push_back(x);
      }
      swap(b, c);
      ans = max(ans, sum);
    }
 
    cout << ans << "\n";
  }
}
