#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto&e : a) cin >> e;
  for(auto&e : b) cin >> e;

  int cnt = 0;
  for(int i = 0; i < n; ++i) cnt += a[i] == b[i];
  cout << cnt << "\n";
  cnt = -cnt;
  for(int i = 0; i < n; ++i) cnt += count(begin(a), end(a), b[i]);
  cout << cnt << "\n";
}
