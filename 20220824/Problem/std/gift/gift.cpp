#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int C[MAXN], Fa[MAXN], Size[MAXN], N, M;

int lb (int x) { 
    return x & -x; 
}

void upd(int x, int d) {
    while (x <= 2e5) {
        C[x] += d;
        x += lb(x);
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += C[x];
        x -= lb(x);
    }
    return res;
}

int kth(int k){
	int l = 1, r = 2e5, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (query(mid) >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int Find(int x) {
    return Fa[x] == x ? Fa[x] : Fa[x] = Find(Fa[x]);
}

void Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return;
    Fa[fx] = fy;
    N--;
    upd(Size[fx], -1);
    upd(Size[fy], -1);
    Size[fy] += Size[fx];
    upd(Size[fy], 1);
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        Fa[i] = i;
        Size[i] = 1;
    }
    upd(1, N);

    while (M--) {
        static int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            Merge(x, y);
        } else {
            cin >> x;
            x = N - x + 1;
            cout << kth(x) << endl;
        }
    }
    return 0;
}