#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Only primes up to 53 are needed
    vector<ll> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        ll ans = -1;
        for(ll p : primes) {
            bool exists_not_divisible = false;
            for(int i = 0; i < n; ++i) {
                if(a[i] % p != 0) { // found a[i] with gcd(a[i], p) == 1
                    exists_not_divisible = true;
                    break;
                }
            }
            if(exists_not_divisible) { ans = p; break; }
        }
        cout << ans << '\n';
    }
    return 0;
}
