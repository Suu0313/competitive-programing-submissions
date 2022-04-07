#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector a(n, vector(n, 0));
    int cnt = 0;

    for(int i = 0; i < n; i++){
      string s; cin >> s;
      for(int j = 0; j < n; j++) cnt += a[i][j] = s[j] - '0';
    }
    
    int ans = n + cnt;

    for(int i = 0; i < n; i++){
      int ncnt = 0;
      for(int j = 0; j < n; j++) ncnt += a[j][(i + j)%n];

      ans = min(ans, n + cnt - ncnt * 2);
    }

    cout << ans << "\n";
  }
}
