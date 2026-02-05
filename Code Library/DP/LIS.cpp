ll calculateLIS(const vl& a) {
    if (a.empty()) return 0;
    vl lis;
    for (const auto& x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size();
}
