//https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

bool customComparator(const pair<ll, ll>& a, const pair<ll, ll>& b) {
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
    ll tc; 
    tc=1;
    // cin >> tc;
    while (tc--) {
        ll n,m; cin>>n>>m;
        vector<ll>a(n),b(m),c;
        for(ll i=0; i<n; i++)cin>>a[i];
        for(ll i=0; i<m; i++)cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
       ll ap = 0, bp = 0;
       while (ap < n or bp < m)
       {
           if(ap<n and (bp >=m or a[ap] <= b[bp])){
            c.pb(a[ap]);
            ap++;
           }
            else{
                c.pb(b[bp]);
                bp++;
            }
       }
       
       for(int i=0; i<c.size(); i++)
       cout<<c[i]<<" ";

        
    }
    return 0;
}