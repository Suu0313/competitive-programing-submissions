#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n); for(auto&&e : a) cin >> e;
    int ans = 0, x = n, y = 0;
    a.push_back(0);

    for(int l = 0, r = 0; l < n; l = r){
      while(l < n && a[l] == 0) ++l;
      if(l == n) break;
      r = l;
      while(a[r] != 0) ++r;
      int sgn = 1, cnt = 0, ln = -1, rn = -1, cl = 0, cr = 0;

      for(int i = l; i < r; i++){
        if(abs(a[i]) == 2){
          ++cnt;
          if(ln == -1) ++cl;
          ++cr;
        }
        if(a[i] < 0){
          sgn = -sgn;
          if(ln == -1) ln = i;
          rn = i;
          cr = a[i] == -2;
        }
      }

      if(sgn == -1){
        if(cl < cr){
          if(cnt - cl > ans) ans = cnt - cl, x = ln + 1, y = n - r;
        }else{
          if(cnt - cr > ans) ans = cnt - cr, x = l, y = n - rn;
        }
      }else{
        if(cnt > ans) ans = cnt, x = l, y = n - r;
      }
    }

    cout << x << " " << y << "\n";
  }
}
