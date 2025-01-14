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
    
        int n; cin>>n;
        vector<int>v(n);
        for(int i=0; i<n; i++)cin>>v[i];
        int cnt[32][2];
        /*_________brute-force______________-*/
        // ll ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         ans += v[i] ^ v[j];
        //     }
        // }
        // cout<<ans<<endl;
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<n; i++){
            for(int k=0; k<32; k++){
                if(v[i] & (1 <<k))cnt[k][1]++;
                else cnt[k][0]++;
            }
        }

        ll sum = 0;
        for(int i=0; i<32; i++){
            ll contribute = (cnt[i][0] * cnt[i][1] );
            //if i == j is allowed and (1,2) and (2,1) are counted as 2 separate pair then
            //we have to do --> contribute = (cnt[i][0] * cnt[i][1] * 2 )
            sum += contribute * (1 << i);
        }
        cout<<sum<<endl;
    
    return 0;
}