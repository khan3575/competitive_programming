struct DSU {
    vector<int> parent;
    vector<int> sz; // 'sz' for "size"
    int num_components;

    // Constructor: Initialize n items, each in its own group.
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Fills parent[i] = i
        sz.resize(n + 1, 1);
        num_components = n;
    }

    // Find the representative of item 'i' (with path compression)
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression: set parent to the root
        return parent[i] = find(parent[i]); 
    }

    // Merge the groups of 'u' and 'v' (union by size)
    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            // Attach the smaller tree to the larger one
            if (sz[root_u] < sz[root_v])
                swap(root_u, root_v);
            parent[root_v] = root_u;
            sz[root_u] += sz[root_v];
            num_components--; // One less component
        }
    }
};

// In your solve() function:
int n, m;
cin >> n >> m;
DSU dsu(n); // Create the DSU
for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
}
// Now you can check dsu.find(a) == dsu.find(b)
// or print dsu.num_components


// ===============================================
// === BINARY SEARCH (ON THE ANSWER) ===
// ===============================================
// Solved: CF 1612C (Chat Ban), Nov 5-6
// Template for finding the FIRST (minimum) 'x' 
// that satisfies can(x) in a F...F[T]...T pattern.

/*
ll l = 1, r = 1e18; // Set your answer range
ll ans = r;

auto can = [&](ll x) -> bool {
    // Logic to check if 'x' is a valid answer
    // Must be monotonic (F F F T T T)
    // return (total >= required);
};

while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (can(mid)) {
        ans = mid;    // This 'mid' works, try to find a smaller one
        r = mid - 1;
    } else {
        l = mid + 1;  // This 'mid' doesn't work, need a larger value
    }
}
// 'ans' now holds the minimum 'x' for which can(x) is true
cout << ans << endl;
*/

// ===============================================
// === GRAPH: STANDARD TRAVERSAL ===
// ===============================================
// Solved: Building Roads, Message Route
// ---
// vector<int> adj[N];
// bool visited[N];
// ---

// 1. Standard DFS
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// 2. Standard BFS (for shortest path in unweighted graph)
// vector<int> dist[N];
// vector<int> parent[N];
//
// queue<int> q;
// for(int i=1; i<=n; i++) dist[i] = -1; // Init distances
//
// q.push(start_node);
// dist[start_node] = 0;
//
// while (!q.empty()) {
//     int u = q.front();
//     q.pop();
//
//     for (int v : adj[u]) {
//         if (dist[v] == -1) { // Not visited
//             dist[v] = dist[u] + 1;
//             parent[v] = u;
//             q.push(v);
//         }
//     }
// }
// 'dist[end_node]' has the shortest path length


// ===============================================
// === GRAPH: GRID TRAVERSAL (4-DIR) ===
// ===============================================
// Solved: Counting Rooms, Labyrinth
// ---
// int n, m; // Grid dimensions
// char grid[N][N];
// bool visited[N][N];
// int dist[N][N];
//
// int dx[] = {0, 0, 1, -1}; // R, L, D, U
// int dy[] = {1, -1, 0, 0};
//
// bool is_valid(int r, int c) {
//     return (r >= 0 && r < n && c >= 0 && c < m);
// }
// ---

// 1. Grid DFS
void grid_dfs(int r, int c) {
    if (!is_valid(r, c) || grid[r][c] == '#' || visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        grid_dfs(r + dx[i], c + dy[i]);
    }
}

// 2. Grid BFS (for shortest path)
// queue<pair<int, int>> q;
// q.push({start_r, start_c});
// dist[start_r][start_c] = 0;
// visited[start_r][start_c] = true;
//
// while (!q.empty()) {
//     pair<int, int> u = q.front();
//     q.pop();
//
//     for (int i = 0; i < 4; i++) {
//         int nr = u.first + dx[i];
//         int nc = u.second + dy[i];
//
//         if (is_valid(nr, nc) && grid[nr][nc] != '#' && !visited[nr][nc]) {
//             visited[nr][nc] = true;
//             dist[nr][nc] = dist[u.first][u.second] + 1;
//             q.push({nr, nc});
//         }
//     }
// }


// ===============================================
// === GRAPH: BIPARTITE CHECK (2-COLORING) ===
// ===============================================
// Solved: Building Teams
// ---
// vector<int> adj[N];
// int color[N]; // 0 = unvisited, 1 = color 1, 2 = color 2
// bool is_bipartite = true;
// ---
//
// void bfs_color(int start_node) {
//     queue<int> q;
//     q.push(start_node);
//     color[start_node] = 1;
//
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//
//         for(int v : adj[u]) {
//             if(color[v] == 0) {
//                 color[v] = (color[u] == 1) ? 2 : 1;
//                 q.push(v);
//             } else if (color[v] == color[u]) {
//                 is_bipartite = false;
//                 return;
//             }
//         }
//     }
// }
//
// // In solve():
// for(int i=1; i<=n; i++) {
//     if(color[i] == 0) {
//         bfs_color(i);
//     }
// }
// if(is_bipartite) ... else ...


// ===============================================
// === GRAPH: DIJKSTRA (SHORTEST PATH) ===
// ===============================================
// Solved: Flight Discount, Shortest Route I
// ---
// using pll = pair<ll, ll>;
// const ll INF = 1e18;
// vector<pair<int, int>> adj[N]; // adj[u] = {v, cost}
// ll dist[N];
// ---
//
// void dijkstra(int start_node) {
//     for(int i=1; i<=n; i++) dist[i] = INF;
//
//     priority_queue<pll, vector<pll>, greater<pll>> pq; // min-heap
//
//     dist[start_node] = 0;
//     pq.push({0, start_node}); // {distance, node}
//
//     while(!pq.empty()) {
//         ll d = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();
//
//         // Optimization: if we already found a shorter path
//         if(d > dist[u]) continue; 
//
//         for(auto& edge : adj[u]) {
//             int v = edge.first;
//             int cost = edge.second;
//
//             if(dist[u] + cost < dist[v]) {
//                 dist[v] = dist[u] + cost;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }


// ===============================================
// === GRAPH: CYCLE DETECTION ===
// ===============================================
// Solved: Round Trip (Undirected), Round Trip II (Directed)

// 1. Undirected Cycle (DFS)
// ---
// bool visited[N];
// ---
// bool dfs_cycle_undirected(int u, int parent) {
//     visited[u] = true;
//     for(int v : adj[u]) {
//         if(v == parent) continue; // Don't go back
//         if(visited[v]) {
//             return true; // Found a back-edge to an already visited node
//         }
//         if(dfs_cycle_undirected(v, u)) {
//             return true;
//         }
//     }
//     return false;
// }
// // In solve(): check dfs_cycle_undirected(i, -1) for all unvisited 'i'


// 2. Directed Cycle (DFS with 3 states)
// ---
// int visited[N]; // 0=unvisited, 1=visiting(in stack), 2=visited(finished)
// ---
// bool dfs_cycle_directed(int u) {
//     visited[u] = 1; // Mark as "visiting"
//     for(int v : adj[u]) {
//         if(visited[v] == 1) {
//             return true; // Back-edge to a node in our current path
//         }
//         if(visited[v] == 0) {
//             if(dfs_cycle_directed(v)) return true;
//         }
//         // if visited[v] == 2, do nothing (finished path)
//     }
//     visited[u] = 2; // Mark as "finished"
//     return false;
// }


// ===============================================
// === GRAPH: TOPOLOGICAL SORT (KAHN'S) ===
// ===============================================
// Solved: Course Schedule
// ---
// vector<int> adj[N];
// int in_degree[N];
// vector<int> topo_order;
// ---
//
// queue<int> q;
// for(int i=1; i<=n; i++) {
//     if(in_degree[i] == 0) {
//         q.push(i);
//     }
// }
//
// while(!q.empty()) {
//     int u = q.front();
//     q.pop();
//     topo_order.push_back(u);
//
//     for(int v : adj[u]) {
//         in_degree[v]--;
//         if(in_degree[v] == 0) {
//             q.push(v);
//         }
//     }
// }
//
// if(topo_order.size() < n) {
//     // Graph has a cycle, no valid topological sort
// } else {
//     // topo_order contains the valid sort
// }