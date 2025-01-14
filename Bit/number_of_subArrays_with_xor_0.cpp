#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int a[N], p[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] ^ a[i];
  }
  map<int, int> mp;
  long long ans = 0;
  mp[p[0]]++; // don't forget to add this (why?)
  for (int i = 1; i <= n; i++) {
    ans += mp[p[i]];
    mp[p[i]]++;
  }
  cout << ans << '\n';
  return 0;
}