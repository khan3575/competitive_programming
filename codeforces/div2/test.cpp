#include <iostream>
#include <vector>
#include <set>       // For multiset
#include <algorithm> // For sort

using namespace std;

// A struct to store monster data
struct Monster {
    int b, c; // b = life, c = reward
    
    // Custom comparator to sort by life (b)
    bool operator<(const Monster& other) const {
        return b < other.b;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Use a multiset to store the damage of available swords.
    // Use long long for potential 10^9 damage values.
    multiset<long long> swords;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        swords.insert(a);
    }
    
    vector<Monster> monsters(m);
    // Read monster life values
    for (int i = 0; i < m; ++i) {
        cin >> monsters[i].b;
    }
    // Read monster reward values
    for (int i = 0; i < m; ++i) {
        cin >> monsters[i].c;
    }
    
    // Sort monsters by their life value (b)
    sort(monsters.begin(), monsters.end());
    
    int killed_count = 0;
    
    // Iterate through all monsters, from weakest to strongest
    for (int i = 0; i < m; ++i) {
        int b = monsters[i].b;
        int c = monsters[i].c;
        
        // Find the weakest sword that can kill this monster
        // (i.e., the first sword with damage >= b)
        auto it = swords.lower_bound(b);
        
        // If we found a sword
        if (it != swords.end()) {
            killed_count++; // We kill the monster
            
            // Get the sword's damage
            long long sword_damage = *it;
            
            // The sword is used, remove it
            swords.erase(it);
            
            // If c > 0, we get a new sword
            if (c > 0) {
                // The new sword's damage is max(old_sword_damage, c)
                swords.insert(max(sword_damage, (long long)c));
            }
        }
        // If it == swords.end(), we have no sword strong enough.
        // We just skip this monster and move to the next.
    }
    
    cout << killed_count << "\n";
}

int main() {
    // Optimize C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}