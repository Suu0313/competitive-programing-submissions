#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector cnt(256, vector(256, 0ll));
    vector cnt0(256, 0ll), cnt1(256, 0ll);
    while(n--){
      string s; cin >> s;
      ++cnt[s[0]][s[1]]; ++cnt0[s[0]]; ++cnt1[s[1]];
    }
    int64_t ans = 0;
    for(int i = 'a'; i <= 'k'; ++i){
      for(int j = 'a'; j <= 'k'; ++j){
        ans += cnt[i][j] * (cnt0[i] - cnt[i][j]);
        ans += cnt[i][j] * (cnt1[j] - cnt[i][j]);
      }
    }
    cout << ans/2 << "\n";
  }
}
