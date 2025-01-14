#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//         if(i == j)continue;
//         ans += (a[i] | a[j]);
//         // cout<<a[i]<<" "<<a[j]<<endl;
//     }
//   }
//   cout<<ans<<endl;
  ans = 0;
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
  for (int k = 0; k < 30; k++) {
    long long contrib = cnt[k][1] * (n-1) + (cnt[k][0] * cnt[k][1]);
    ans += contrib * (1 << k);
  }
  cout << ans << '\n';
  return 0;
}