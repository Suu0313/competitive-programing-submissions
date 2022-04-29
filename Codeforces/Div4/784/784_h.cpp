#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    int p = 31;
    vector<int> zero(p, n);
    while(n--){
      int a; cin >> a;
      for(int i = 0; i < p; ++i){
        if(a>>i & 1) --zero[i];
      }
    }

    int ans = 0;
    
    for(int i = p-1; i >= 0; --i){
      if(k >= zero[i]){
        k -= zero[i];
        ans |= 1 << i;
      }
    }

    cout << ans << "\n";
  }
}
