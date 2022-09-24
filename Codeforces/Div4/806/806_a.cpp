#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    for(auto&&e : s) e = tolower(e);
    puts(s == "yes" ? "Yes" : "No");
  }
}
