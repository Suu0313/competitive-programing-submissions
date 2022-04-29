#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 0; i < n; ++i){
      int a; cin >> a; ++cnt[a];
    }

    auto f = [&]{
      for(int i = 1; i <= n; ++i){
        if(cnt[i] >= 3) return i;
      }
      return -1;
    };

    cout << f() << "\n";
  }
}
