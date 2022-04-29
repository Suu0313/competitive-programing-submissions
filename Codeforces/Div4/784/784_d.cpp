#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    s += 'W';

    auto f = [&]{
      string t;
      for(auto&&c : s){
        if(c != 'W') t += c;
        else{
          if(t.empty()) continue;
          if((t.find('R') == string::npos) || (t.find('B') == string::npos)) return false;
          t.clear();
        }
      }
      return true;
    };
    cout << (f() ? "YES\n" : "NO\n");
  }
}
