#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct node {
	int u, v, w;
	node(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
};

bool compare(node a, node b) {
	return a.w < b.w;
}

vector<node> graph;
int n, m, q;
int fa[maxn], up[maxn][21], f[maxn][21], dep[maxn];
vector<pair<int, int> > tree[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int u) {
	for (auto e : tree[u]) {
		int v = e.first;
		if (v == f[u][0]) continue;
		f[v][0] = u; dep[v] = dep[u] + 1; up[v][0] = e.second;
		for (int i = 1; i <= 18; i++) {
			f[v][i] = f[f[v][i - 1]][i - 1];
			up[v][i] = max(up[v][i - 1], up[f[v][i - 1]][i - 1]);
		}
		dfs(v);
	}
}

int main() {
	freopen("nav.in", "r", stdin);
	freopen("nav.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph.emplace_back(u, v, w);
	}
	sort(graph.begin(), graph.end(), compare);
	for (auto e : graph) {
		int u = find(e.u), v = find(e.v);
		if (u == v) continue;
		tree[e.u].emplace_back(e.v, e.w);
		tree[e.v].emplace_back(e.u, e.w);
		fa[v] = u;
	}
	for (int i = 1; i <= n; i++) {
		if (fa[i] == i) {
			tree[0].emplace_back(i, 0);
			tree[i].emplace_back(0, 0);
		}
	}
	//for (int i = 0; i <= n; i++) {
	//	for (auto e : tree[i]) {
	//		printf("%d -> %d\n", i, e.first);
	//	}
	//}
	dep[0] = 1;
	dfs(0);
	scanf("%d", &q);
	while (q--) {
		int u, v, ans = INT_MIN;
		scanf("%d %d", &u, &v);
		if (find(u) != find(v)) {
			printf("impossible\n");
			continue;
		}
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = 18; i >= 0; i--) {
			if (dep[f[u][i]] >= dep[v]) {
				ans = max(ans, up[u][i]);
				u = f[u][i];
			}
		}
		for (int i = 18; i >= 0; i--) {
			if (f[u][i] != f[v][i]) {
				ans = max(up[v][i], max(ans, up[u][i]));
				u = f[u][i];
				v = f[v][i];
			}
		}
		if (u != v) ans = max(ans, max(up[v][0], up[u][0]));
		printf("%d\n", ans);
	}
	return 0;
}
