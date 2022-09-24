#include <bits/stdc++.h>
using namespace std;
 
#include "FenwickTree.cpp"
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int64_t ans = 0;
    FenwickTree<int> fw(n);
 
    for(int i = 0; i < n; ++i){
      int a; cin >> a; --a;
      if(i <= a) continue;
      ans += fw.sum(a);
      fw.add(i, 1);
    }
 
    cout << ans << "\n";
  }
}
