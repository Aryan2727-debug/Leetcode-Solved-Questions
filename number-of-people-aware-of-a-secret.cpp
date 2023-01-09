class Solution {
public:

    #define ll long long int
    ll mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> vec(n,0);
        vec[0] = 1;

        for(int i=0;i<n;i++){
            for(int j=i+delay;j<i+forget && j<n;j++){
                vec[j] = (vec[i] % mod + vec[j] % mod) % mod;
            }
        }

        ll ans = 0;

        for(int i=n-forget;i<n;i++){
            ans = (ans % mod + vec[i] % mod) % mod;
        }

        return ans;
    }
};