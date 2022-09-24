#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n); for(auto&&e : a) cin >> e;
    for(auto&&e : a){
      int b; cin >> b;
      string s; cin >> s;
      for(auto&&c : s){
        if(c == 'D') ++e;
        else --e;
      }
 
      cout << (e%10 + 10)%10 << " ";
    }
    cout << "\n";
  }
}
