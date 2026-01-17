class UnionFind {
private:
    vector<ll> par, siz;
public:
    //初期化
    UnionFind(ll n) : par(n, -1), siz(n, 1){}

    //根を求める
    ll root (ll x) {
        if (par[x] == -1) return x;
        return par[x] = root(par[x]);
    }
    //xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool isSame(ll x, ll y) {
        return root(x) == root(y);
    }

    //xを含むグループとyを含むグループを併合する
    bool unite(ll x, ll y) {
        ll p = root(x), q = root(y);
        if (p == q) return false;
        if (siz[p] < siz[q]) swap(p, q);
        par[q] = p;
        siz[p] += siz[q];
        return true;
    }

    //xを含むグループのサイズ
    ll size(ll x) {
        return siz[root(x)];
    }

    //グループの数
    ll groupCnt() {
        set<ll> s;
        rep(i, par.size()) {
            s.insert(root(i));
        }
        return s.size();
    }

    // 全グループを {根, メンバーのリスト} の形で取得
    vector<vector<ll>> groups() {
        map<ll, vector<ll>> mp;
        rep(i, par.size()) {
            mp[root(i)].push_back(i);
        }
        vector<vector<ll>> res;
        for (auto &v: mp | views::values) res.push_back(v);
        return res;
    }

    // 最大のグループのサイズを取得
    ll maxGroupSize() {
        ll res = 0;
        rep(i, par.size()) {
            if (par[i] == -1) {
                res = max(res, siz[i]);
            }
        }
        return res;
    }
};
//使い方
//UnionFind uf(n)で初期化する
