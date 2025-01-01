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
    ll n,x; cin>>n>>x;
    vector<pair<ll,ll>>vp(n);
    for(int i=0; i<n; i++){
        cin>>vp[i].first;
        vp[i].second = i+1;
    }
 
    sort(vp.begin(), vp.end());
    // for(auto it : vp)cout<<it.first<<" ";
    // cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll need = x - (vp[i].first + vp[j].first);
                
            ll l=j+1,r=n-1;
            while (l < r)
            {
                if(i != l and i != r and j != l and j != r and vp[l].first + vp[r].first == need){
                    // cout<<need+vp[l].first + vp[r].first<<endl;
                    cout<<vp[i].second<<" "<<vp[j].second<<" "<<vp[l].second<<" "<<vp[r].second<<endl;
                    return 0;
                }
 
                if(vp[l].first + vp[r].first > need)r--;
                else l++;
            }
            
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}