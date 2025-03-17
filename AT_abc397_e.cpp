#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define No cout << "No" << endl; exit(0)

int N, K;
unordered_map<int, vector<int> > e;     // 这样存不会炸时空

inline int dfs(int u, int fa) {
    int ret = 1, cu = 0;        // s_u 和 c_u
    for (int v : e[u]) {
        if (v == fa)        // 歧视父节点
            continue;
        int m = dfs(v, u);      // 子节点子树大小
        ret += m;   // 有 0 也没关系
        if (m)      // 没被包含到某条链里才算子节点
            cu++;
    }
    if (ret < K) {
        if (cu >= 2) {
            No;     // 顶上有 #define, 功能是输出 "No" 并终止程序
        }
        return ret;
    } else if (ret == K) {
        if (cu > 2) {
            No;
        }
        return 0;
    } else {
        No;
    }
}

signed main(signed argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1, u, v; i < N * K; i++) { // 读入
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, -1);     // 递归判断是否可以构成 N 条链
    cout << "Yes" << endl;  // 没有特殊情况, 最后进行到了这里说明可以构成 N 条链
    return 0;
}
