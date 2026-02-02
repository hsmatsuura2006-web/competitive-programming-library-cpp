ll safe_sqrt(ll n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    ll ok = 0, ng = 2000000000LL;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid <= n) ok = mid;
        else ng = mid;
    }
    return ok;
}
