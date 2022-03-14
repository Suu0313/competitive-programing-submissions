#include <bits/stdc++.h>
using namespace std;

template< int mod >
struct ModInt {
  int x;

  constexpr ModInt() : x(0) {}

  constexpr ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  
  constexpr ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  constexpr ModInt operator-() const { return ModInt(-x); }
  constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  constexpr bool operator==(const ModInt &p) const { return x == p.x; }
  constexpr bool operator!=(const ModInt &p) const { return x != p.x; }
  constexpr bool operator<(const ModInt &p) const { return x < p.x; }

  constexpr ModInt& operator++() { (*this).x+=1; return (*this); }
  constexpr ModInt& operator--() { (*this).x-=1; return (*this); }
  constexpr ModInt operator++(int) { ModInt tmp(*this); ++(*this); return tmp; }
  constexpr ModInt operator--(int) { ModInt tmp(*this); --(*this); return tmp; }

  constexpr ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  constexpr ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul; n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
  constexpr static int get_mod() { return mod; }
};
template< int mod >
constexpr ModInt<mod> operator+(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) + m; };
template< int mod >
constexpr ModInt<mod> operator-(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) - m; };
template< int mod >
constexpr ModInt<mod> operator*(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) * m; };
template< int mod >
constexpr ModInt<mod> operator/(const int64_t &p, const ModInt<mod> &m){ return ModInt<mod>(p) / m; };

//constexpr int MOD = 1e9 + 7;
constexpr int MOD = 998244353;
using mint = ModInt< MOD >;
using VM = vector<mint>;
using VVM = vector<VM>;
constexpr mint operator""_m(unsigned long long x) { return mint(x); }

template<typename T>
struct Combination{
  // T は mint の想定です
  int N;
  vector<T> fact_, inv_, finv_;

  Combination(int n = 10):N(n+1), fact_(N,1), inv_(N,1), finv_(N,1){
    int mod = fact_.at(0).get_mod();

    for (int i = 2; i < N; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }
  }

  void init(int n) {
    N = n+1;
    fact_.assign(N, 1);
    inv_.assign(N, 1);
    finv_.assign(N, 1);

    int mod = fact_.at(0).get_mod();

    for (int i = 2; i < N; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }
  }

  T fact(int n){
    if(n < 0) return 0;
    append(n);
    return fact_.at(n);
  }
  T inv(int n){
    if(n < 0) return 0;
    append(n);
    return inv_.at(n);
  }
  T finv(int n){
    if(n < 0) return 0;
    append(n);
    return finv_.at(n);
  }

  T com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    append(n);
    return fact_.at(n) * finv_.at(k) * finv_.at(n-k);
  }

  T parm(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    append(n);
    return fact_.at(n) *finv_.at(n-k);
  }

  T hom(int n, int k){
    if(n < 0 || k < 0) return 0;
    if(k == 0) return 1;
    append(n+k-1);
    return com(n+k-1, k);
  }

  T Catalan(int n){
    return Catalan(n, n, 1);
  }

  T Catalan(int n, int k){
    return Catalan(n, k, 1);
  }

  T Catalan(int n, int k, int m){
    if(k < m) return com(n+k, k);
    if(k < n+m-1) return com(n+k, k) - com(n+k, k-m);
    return 0;
  }
  
  T random_walk(int n, int x){
    if(n < abs(x) || n%2 != abs(x)%2) return 0;
    return com(n, (n + x)/2);
  }

  T random_walk(int n, int x, int y){
    return random_walk(n, x+y) * random_walk(n, x-y);
  }

private:
  void append(int n){
    if(n < N) return;
    fact_.resize(n+1);
    inv_.resize(n+1);
    finv_.resize(n+1);

    int mod = fact_.at(0).get_mod();

    for (int i = N; i < n+1; i++){
      fact_.at(i) = fact_.at(i-1) * i;
      inv_.at(i) = -inv_.at(mod%i) * (mod/i);
      finv_.at(i) = finv_.at(i-1) * inv_.at(i);
    }

    N = n+1;
  }
};


int main() {
  int n, m, k; cin >> n >> m >> k;
  Combination<mint> bc;

  vector dp(k+1, vector(m+1, 0_m));
  dp[0][0] = 1;

  vector<mint> ws(n);
  for(auto&w : ws) cin >> w;
  mint sw = accumulate(begin(ws), end(ws), 0_m);


  for(auto&w : ws){
    auto ndp = dp;
    mint dw = w/sw, p = 1;
    for(int i = 1; i <= k; ++i){
      p *= dw;
      for(int j = 0; j <= k-i; ++j){
        for(int l = 0; l < m; ++l){
          dp[j+i][l+1] += ndp[j][l] * bc.com(k-j, i) * p;
        }
      }
    }
  }

  cout << dp[k][m] << "\n";
}
