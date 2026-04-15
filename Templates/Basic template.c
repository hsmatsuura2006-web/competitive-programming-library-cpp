#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define yes() printf("Yes\n")
#define no() printf("No\n")
inline ll min(ll a, ll b) { return (a < b) ? a : b; }
inline ll max(ll a, ll b) { return (a > b) ? a : b; }
inline bool chmin(ll *a, ll b) { if (*a > b) { *a = b; return true; } return false; }
inline bool chmax(ll *a, ll b) { if (*a < b) { *a = b; return true; } return false; }
bool out_grid(ll i, ll j, ll h, ll w) {return (!(0 <= i && i < h && 0 <= j && j < w));}
typedef struct {ll to, cost;} Edge;
void solve();

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
void solve() {
  
}
