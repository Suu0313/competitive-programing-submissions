#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  string s; cin >> s;
  
  vector<int> idx(n); iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j){
    if(y[i] == y[j]) return x[i] < x[j];
    return y[i] < y[j];
  });

  for(int k = 0; k < n-1; ++k){
    int i = idx[k], j = idx[k+1];
    if(y[i] == y[j] && s[i] == 'R' && s[j] == 'L'){
      cout << "Yes\n"; return 0;
    }
  }

  cout << "No\n";
}
