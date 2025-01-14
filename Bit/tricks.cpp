#include <bits/stdc++.h>


#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() {
    fast;
    //1. Even or Odd
    //O(1) much faster than (% 2)
    ll x; cin>>x;
    if(x & 1)cout<<x<<" is odd\n";
    else cout<<x<<" is even\n";

    //2. Check if a number is power of 2
    // O(1) 
    // it doesn't work for x == 0
    ll t = x & (x - 1);
    if(x == 0) cout<<x<<" is not a power of 2\n";
    else if(t == 0){
        cout<<x<<" is a power of 2\n";
    }
    else cout<<x<<" is not a power of 2\n";

    //k'th bit from the right
    //3. check if k'th bit is set
    ll k; cin>>k;
    cout<<(x & (1 << k));

    //4. Toggle the k'th bit
    x = x^(1 << k);

    //5. set the k'th bit
    x = x | (1 << k);

    //6. Unset the k'th bit
    x = x & (~(1 << k));

    //7. x * 2^k
    cout<<(x << k);

    //8. x / 2^k
    cout<<(x>>k);

    //9. x % 2 ^ k
    cout<<(x & ((1<<k)-1));

    //10. swap without temp
    ll y;cin>>y;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    //11. Finding no of set bits
    ll a = __builtin_popcount(a);

    /*-------------------------------------------------BITMASK---------------------------------------------------------*/
    ll n = 5;
    int arr[5] = {1,2,3,4,5};
    for(int mask = 0; mask<(1 << n); mask++){
        for(int i=0; i<n; i++){
            if(mask & (1 << i))cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //12. Bitset
    bitset<8>bs(16);
    cout<<bs<<endl;
    bs.set(0);
    cout<<bs<<endl;
    bs.reset(0);
    cout<<bs<<endl;
    cout<<(7 & 10)<<endl;

    return 0;
}