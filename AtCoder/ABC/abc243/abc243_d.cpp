#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; int64_t x; cin >> n >> x;
  string t = bitset<64>(x).to_string();

  string s; cin >> s;
  for(auto&c : s){
    if(c == 'U') t.pop_back();
    if(c == 'L') t.push_back('0');
    if(c == 'R') t.push_back('1');
  }

  cout << stoll(t, nullptr, 2) << "\n";
}
