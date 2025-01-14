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

bool check(ll x){
    int seven = 0, four = 0;
    while (x)
    {
        int di = x % 10;
        if(di == 7)seven++;
        else four++;
        x /=10;
    }
    return (seven == four);
    
}
int main() {
    fast;
   ll n; cin>>n;
   vector<ll>v;
   for(int len = 1; len <=12; len++){

    for(int mask = 0; mask < (1 << len); mask++){
    string s;
        for(int i=0; i<len; i++){
            if(mask & (1 << i))s.pb('7');
            else s.pb('4');
        }
        v.pb(stoll(s));

        
    }
   }
   sort(v.begin(), v.end());
   for(auto it : v){
    if(it >= n and check(it)){
        cout<<it<<endl;
        break;
    }
   }
    return 0;
}