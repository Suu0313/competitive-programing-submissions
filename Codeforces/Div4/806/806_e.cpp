#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector a(n, vector<int>(n));
    for(auto&&e : a){
      string s; cin >> s;
      for(int i = 0; i < n; ++i) e[i] = s[i] - '0';
    }
 
    int ans = 0;
    for(int i = 0; i < n/2; ++i){
      for(int j = 0; j < (n + 1)/2; ++j){
        int c = a[i][j] + a[j][n - 1 - i] + a[n - 1 - i][n - 1 - j] + a[n - 1 - j][i];
        ans += min(c, 4 - c);
      }
    }
 
    cout << ans << "\n";
  }
}
