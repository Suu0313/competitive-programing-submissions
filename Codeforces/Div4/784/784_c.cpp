#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;

    auto f = [&](const vector<int> &a){
      return any_of(begin(a), end(a), [&](int x){ return x%2 == 0; }) != any_of(begin(a), end(a), [&](int x){ return x%2 == 1; });
    };

    vector<int> a, b;
    for(int i = 0; i < n; ++i){
      int x; cin >> x;
      (i&1 ? a : b).push_back(x);
    }
    
    cout << (f(a) && f(b) ? "YES\n" : "NO\n");
  }
}
