#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int a[N], pw[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
 
//Precomputing all power of 2
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = (pw[i - 1] * 2) % mod;
  }

  for (int k = 0; k < 30; k++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >> k & 1) {
        cnt++;
      }
    }
    int contrib = pw[cnt] - 1;
    ans += 1LL * contrib * (1 << k) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}