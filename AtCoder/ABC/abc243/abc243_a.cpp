#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, a, b, c; cin >> v >> a >> b >> c;
  v %= a + b + c;
  if((v -= a) < 0) cout << "F\n";
  else if((v -= b) < 0) cout << "M\n";
  else cout << "T\n";
}
