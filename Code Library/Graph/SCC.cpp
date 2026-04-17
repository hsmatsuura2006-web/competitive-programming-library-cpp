struct SCC {
    int n;
    std::vector<std::vector<int>> adj;     // 元のグラフ
    std::vector<std::vector<int>> rev_adj; // 逆向きグラフ
    std::vector<int> order;                // 帰りがけ順の記録
    std::vector<bool> used;
    std::vector<int> component;            // 各頂点が属する強連結成分のID
    int group_count;                       // 強連結成分の総数

    SCC(int _n) : n(_n), adj(_n), rev_adj(_n), used(_n), component(_n, -1), group_count(0) {}

    void add_edge(int from, int to) {
        adj[from].push_back(to);
        rev_adj[to].push_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        for (int next : adj[v]) {
            if (!used[next]) dfs(next);
        }
        order.push_back(v);
    }

    void rdfs(int v, int k) {
        component[v] = k;
        for (int next : rev_adj[v]) {
            if (component[next] == -1) rdfs(next, k);
        }
    }

    void build() {
        std::fill(used.begin(), used.end(), false);
        order.clear();
        for (int i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }
        std::reverse(order.begin(), order.end());
        int k = 0;
        for (int v : order) {
            if (component[v] == -1) rdfs(v, k++);
        }
        group_count = k;
    }

    vector<vector<long long>> get_groups() {
        vector<vector<long long>> groups(group_count);
        for (int i = 0; i < n; i++) {
            groups[component[i]].push_back(i);
        }
        return groups;
    }
};
