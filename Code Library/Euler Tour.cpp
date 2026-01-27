struct EulerTour {
    vector<int> tour;           
    vector<int> depths;       
    vector<int> first_pos;//クエリの範囲を記録  
    vector<int> last_pos;  
    EulerTour(int n, const vector<vector<int>>& adj, int root = 0) {
        tour.reserve(2 * n);
        depths.reserve(2 * n);
        first_pos.assign(n, -1);
        last_pos.assign(n, -1);
        dfs(root, -1, 0, adj);
    }
    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        first_pos[u] = tour.size();
        tour.push_back(u);
        depths.push_back(d);
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
                tour.push_back(u);
                depths.push_back(d);
            }
        }
        last_pos[u] = tour.size() - 1; 
    }
};
