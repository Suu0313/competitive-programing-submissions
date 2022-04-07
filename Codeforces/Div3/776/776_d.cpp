#include <bits/stdc++.h>
using namespace std;


int main() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    for(auto&e : a){ cin >> e; --e; };
    vector<int> res(n);

    for(int i = n-1; i >= 0; --i){
      int j = 0;
      while(a[j] != i) ++j;

      res[i] = (j + 1) % (i + 1);
      if(res[i]) rotate(begin(a), begin(a)+j+1, begin(a)+i+1);
    }
    for(auto&e : res) cout << e << " ";
    cout << "\n";
  }
}
