//https://codeforces.com/contest/702/problem/C
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
typedef tree<ll , null_type, less<ll >, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

bool customComparator(const pair<ll , ll >& a, const pair<ll , ll >& b) {
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
    
    
        ll n,m; cin>>n>>m;
        vector<ll>c(n),t(m);
        for(ll  i=0; i<n; i++)cin>>c[i];

        for(ll  i=0; i<m; i++)cin>>t[i];
        sort(c.begin(), c.end());
        sort(t.begin(), t.end());
        ll mx = 0;
        for(ll  i=0; i<n; i++){
            auto lower = lower_bound(t.begin(), t.end(), c[i]);
            ll x = abs(c[i]) - 1;
            // cout<<x<<endl;
            auto lower2 = lower--;
            ll dis = LLONG_MAX;
            if(lower != t.end()){
                dis = min(dis,abs(c[i] - *(lower)) );
            }

            if(lower2 != t.end()){
                dis = min(dis,abs(c[i] - *(lower2)) );
            }
            mx = max(mx, dis);

            
        }

        cout<<mx<<endl;

        
        
    
    return 0;
}