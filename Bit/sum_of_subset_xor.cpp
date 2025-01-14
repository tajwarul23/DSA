#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // for (int mask = 1; mask < (1 << n); mask++) {
  //   int XOR = 0;
  //   for (int i = 0; i < n; i++) {
  //     if (mask >> i & 1) {
  //       XOR ^= a[i + 1];
  //     }
  //   }
  //   ans += XOR % mod;
  //   ans %= mod;
  // }
  int cnt[30][2];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 30; k++) {
      if (a[i] >> k & 1) {
        cnt[k][1]++;
      }
      else {
        cnt[k][0]++;
      }
    }
  }
  int pw2 = 1;
  for (int i = 1; i < n; i++) {
    pw2 = pw2 * 2 % mod;
  }
  for (int k = 0; k < 30; k++) {
    if (!cnt[k][1]) continue; // if no elements have 1 in the k-th bit then the contribution is 0
    int contrib = pw2; // 2^(n - 1)
    ans += 1LL * contrib * (1 << k) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}