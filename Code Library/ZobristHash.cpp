struct ZobristHash {
    mt19937_64 engine;
    unordered_map<ll, ull> val_to_hash;

    ZobristHash() : engine(chrono::steady_clock::now().time_since_epoch().count()) {}

    ull get_id(ll x) {
        if (val_to_hash.find(x) == val_to_hash.end()) {
            val_to_hash[x] = engine();
        }
        return val_to_hash[x];
    }

    vector<ull> build_prefix_hashes(const vl& a) {
        int n = a.size();
        vector<ull> res(n);
        set<ll> seen;
        ull cur = 0;
        for (int i = 0; i < n; i++) {
            if (seen.find(a[i]) == seen.end()) {
                cur ^= get_id(a[i]);
                seen.insert(a[i]);
            }
            res[i] = cur;
        }
        return res;
    }
};
