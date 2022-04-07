#include <bits/stdc++.h>
using namespace std;

#include "BIT"

int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int sum = n;
    vector<BIT<int>> fw(3, n*2 + 1);
    fw[n%3].add(n, 1);
    int64_t ans = 0;

    for(auto&&c : s){
      sum += 44 - c;
      ans += fw[sum%3].query(sum, n*2 + 1);
      fw[sum%3].add(sum, 1);
    }

    cout << ans << "\n";
  }
}
