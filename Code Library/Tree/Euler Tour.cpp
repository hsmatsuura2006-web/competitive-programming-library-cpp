struct EulerTour {
    vector<int> first_pos;  
    vector<int> last_pos;   
    int timer = 0;

    EulerTour(int n, const Graph& adj, int root = 0) {
        first_pos.assign(n, -1);
        last_pos.assign(n, -1);
        dfs(root, -1, adj);
    }

    void dfs(int u, int p, const Graph& adj) {
        first_pos[u] = timer++;
        for (auto& e : adj[u]) {
            if (e.to != p) dfs(e.to, u, adj);
        }
        last_pos[u] = timer;
    }
};
