#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
 
    cout << n + set<char>(begin(s), end(s)).size() << "\n";
  }
}
