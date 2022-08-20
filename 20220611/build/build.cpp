#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxm = 1e6 + 5;

struct node {
	int v, id;
	node(int _v, int _id) {
		v = _v, id = _id;
	}
};

vector<node> ask[maxn];
int n, m, q;
int x[maxm], y[maxm], fa[maxn], ans[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void uni(int u, int v, int id) {
	u = find(u), v = find(v);
	if (ask[u].size() < ask[v].size()) swap(u, v);
	fa[v] = u;
	for (node &x : ask[v]) {
		if (ans[x.id] != -1) continue;
		x.v = find(x.v);
		if (x.v == u) ans[x.id] = id;
		else ask[u].push_back(x);
	}
	vector<node> tmp;
	ask[v].swap(tmp);
}

int main() {
	freopen("build.in", "r", stdin);
	freopen("build.out", "w", stdout);
	memset(ans, -1, sizeof ans);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", x + i, y + i);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		ask[u].push_back(node(v, i));
		ask[v].push_back(node(u, i));
	}
	for (int i = 1; i <= m; i++) {
		uni(x[i], y[i], i);
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
