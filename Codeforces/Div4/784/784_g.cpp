#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<string> s(n); for(auto&&e : s) cin >> e;

    for(int j = 0; j < m; ++j){
      for(bool f = 1; f; ){
        f = 0;
        for(int i = n-1; i > 0; --i){
          if(s[i][j] == '.' && s[i-1][j] == '*'){
            f = 1;
            swap(s[i][j], s[i-1][j]);
          }
        }
      }
    }

    for(auto&&e : s) cout << e << "\n";
  }
}
