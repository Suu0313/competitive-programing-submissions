#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n); for(auto&&e : a) cin >> e;
    sort(rbegin(a), rend(a));
    auto f = [&]{
      if(n == 1) return a[0] <= 1;
      return a[0] <= a[1]+1;
    };
    cout << (f()? "YES" : "NO") << "\n";
  }
}
