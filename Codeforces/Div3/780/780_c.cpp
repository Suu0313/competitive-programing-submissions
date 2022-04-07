#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    int ans = int(s.size()), pre = 0;

    for(auto&&c : s){
      if(pre >> (c - 'a') & 1) pre = 0, ans -= 2;
      else pre |= 1 << (c - 'a');
    }

    cout << ans << "\n";
  }
}
