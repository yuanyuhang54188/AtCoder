#include  <bits/stdc++.h>
using namespace std;
#define int long long

signed main(signed argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k1, k2, xy, xpy_2, xpy, x, y;
    cin >> n;
    for (k1 = 1; k1 * k1 * k1 < n; k1++) {
        k2 = n / k1;
        if (k2 * k1 != n) {
            continue;
        }
        xy = (k2 - k1 * k1) / 3;
        if (xy * 3 != k2 - k1 * k1) {
            continue;
        }
        xpy_2 = k1 * k1 + 4 * xy;
        xpy = sqrt(xpy_2);
        if (xpy * xpy != xpy_2) {
            continue;
        }
        x = (xpy - k1) / 2;
        if (x*2 != xpy - k1) {
            continue;
        }
        y = xpy - x;
        if (x <= 0 || y <= 0) {
            continue;
        }
        cout << max(x, y) << ' ' << min(x, y) << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
