#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int l, r, a; cin >> l >> r >> a;
    auto f = [&](int x){ return x/a + x%a; };

    cout << max(f(r), f(max(l, (r+1)/a * a - 1))) << "\n";
  }
}
