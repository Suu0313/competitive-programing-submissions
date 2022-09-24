#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<string> s(n); for(auto&&e : s) cin >> e;
    set<string> ss(begin(s), end(s));
    string res(n, '0');
 
    for(int i = 0; i < n; ++i){
      int m = int(s[i].size());
      for(int j = 1; j < m; ++j){
        if(ss.count(s[i].substr(0, j)) && ss.count(s[i].substr(j))) res[i] = '1';
      }
    }
 
    cout << res << "\n";
  }
}
