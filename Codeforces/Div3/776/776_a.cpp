#include <bits/stdc++.h>
using namespace std;

bool check(){
  string s; cin >> s;
  char c; cin >> c;
  int n = int(s.size());

  for(int i = 0; i < n; i += 2)
    if(s[i] == c) return true;

  return false;
}

int main() {
  int t; cin >> t;
  while(t--){
    cout << (check() ? "YES\n" : "NO\n");
  }
}
