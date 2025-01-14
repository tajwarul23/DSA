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
    int tc; cin >> tc;
    while (tc--) {
        
       ll n; cin>>n;
       
       for(int i=0; i<32; i+=2){
            bool a = (n & (1 << i));
            bool b = (n & (1<< (i+1)));
            if(a != b){
                n = (n ^ (1 << i));
                n = (n ^ (1 << (i+1)));
            }
       }
       cout<<n<<endl;
    }
    return 0;
}