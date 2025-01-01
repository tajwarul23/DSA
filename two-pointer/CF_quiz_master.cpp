

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define arrin(arr, n) for (ll i = 0; i < n; i++) cin >> arr[i];
#define arrout(arr, n) for (ll i = 0; i < n; i++) cout << arr[i] << " "; cout << "\n";
#define vin(v, n) for (ll i = 0; n; i++) { ll x; cin >> x; v.pb(x); }
#define vout(v) for (auto it : v) cout << it << " "; cout << "\n";

using namespace std;
using namespace __gnu_pbds;

// Define pbds
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    // Sort by second element in increasing order
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        // If second elements are equal, sort by first element in decreasing order
        return a.first > b.first;
    }
}
int main() {
    fast;
     vector<ll> div[100001];
    for(int i=1; i<=100000; i++){
        for(int j=i; j<=100000; j+=i){
            div[j].pb(i);
        }
    }
    int tc; cin >> tc;
    while (tc--) {
        ll n,m; cin>>n>>m;
        vector<ll>v(n);
        for(int i=0; i<n; i++)cin>>v[i];
        sort(v.begin(), v.end());
        ll ans = LLONG_MAX;
        vector<ll>cnt(m+1, 0);
        ll u = 0;

        ll j=0;
        for(int i=0; i<n; i++){

            while(j < n and u < m){
                for(auto it : div[v[j]]){
                    if(it > m)break;

                    cnt[it]++;

                    if(cnt[it] == 1)u++;
                }
                j++;
            }
            if(u == m){
                ans = min(ans, v[j-1] - v[i]);   
            }

            for(auto it : div[v[i]]){
                if(it > m)break;

                cnt[it]--;

                if(cnt[it] == 0) u--;
            }
        }
        if(ans == LLONG_MAX)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}