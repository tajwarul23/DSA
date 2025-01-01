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
    ll n; cin>>n;
    string s; cin>>s;
    set<char>st(s.begin(), s.end());
    set<char>st2;
    map<char,ll>mp;
    ll j=0, mn = LLONG_MAX;
    for(int i=0; i<n; i++){
        st2.insert(s[i]);
        mp[s[i]]++;

        while (mp[s[j]] > 1)
        {
            mp[s[j]]--;
            j++;
        }
        if(st2.size() == st.size()){
            mn = min(mn, (i-j)+1);
        }
    }
        cout<<mn<<endl;
    return 0;
}