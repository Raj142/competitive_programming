#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const long long mod = 1e9 + 7;
                        // find factorial of large numbers
ll fact(ll n) {
    ll f = 1; 
    for(ll i = 1;i<=n;i++) {
        f = (f * i)%mod; 
    }
    
    return f; 
}

                        // Power function used in modulo division

ll power(ll base, ll n, ll mod) {
    ll ans = 1; 
    while(n) {
        if(n%2) {
            ans = (ans * base) % mod; 
            n = n - 1; 
        }
        else {
            base = (base * base) % mod; 
            n = n / 2; 
        }
    }
    return ans; 
}

                        // brute function to find our nCr 
ll nCr1(ll n, ll r) {
    ll ans = fact(n); 
    ll denominator = (fact(r) * fact(n-r))%mod;
    ans = (ans * power(denominator, mod-2, mod))%mod; 
    return ans; 
}

                       // Precomputate function to store fact of all numbers


ll fact[100005];
void precomputeFactorial(){
    fact[0] = 1;
    for(ll i=1;i<=100000;i++)
        fact[i] = (i * fact[i-1])%mod;
}



                     // improved algo with time complexity O(1)

ll nCr2(ll n,ll r)
{
    ll ans = fact[n];
    ll denominator = (fact[r] * fact[n-r])%mod;
    ans = (ans * power(denominator, mod-2, mod))%mod; 
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("op.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    precomputeFactorial();
    while(t--){
        int n,r;
        cin >> n>> r;
        cout<< nCr2(n,r) << endl;
        
    }

    return 0;
}
