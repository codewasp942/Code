#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, m;
vector<pair<int, int> > graph[maxn], graph2[maxn];
int low[maxn], dfn[maxn], dfn_cnt, bel[maxn], scc_cnt, siz[maxn], dis[maxn];
bool in_s[maxn];
stack<int> st;

void tarjan(int u) {
	dfn[u] = low[u] = ++dfn_cnt;
	st.push(u); in_s[u] = true;
	for (auto e : graph[u]) {
		if (!dfn[e.first]) {
			tarjan(e.first);
			low[u] = min(low[u], low[e.first]);
		}
		else if (in_s[e.first]) low[u] = min(low[u], dfn[e.first]);
	}
	if (dfn[u] == low[u]) {
		scc_cnt++;
		int v;
		do {
			v = st.top(); st.pop();
			in_s[v] = false;
			bel[v] = scc_cnt;
			siz[scc_cnt]++;
		} while (v != u);
	}
}

int main() {
	freopen("gin.in", "r", stdin);
	freopen("gin.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) graph[0].emplace_back(i, 1);
	for (int i = 1; i <= m; i++) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 1) graph[u].emplace_back(v, 0), graph[v].emplace_back(u, 0);
		else if (t == 2) graph[u].emplace_back(v, 1);
		else if (t == 3) graph[v].emplace_back(u, 0);
		else if (t == 4) graph[v].emplace_back(u, 1);
		else graph[u].emplace_back(v, 0);
	}
	tarjan(0);
	for (int u = 0; u <= n; u++) {
		for (auto e : graph[u]) {
			if (bel[u] == bel[e.first]) {
				if (e.second == 1) {
					printf("-1\n");
					return 0;
				}
			}
			else graph2[bel[u]].emplace_back(bel[e.first], e.second);
		}
	}
	for (int u = scc_cnt; u >= 1; u--) {
		for (auto e : graph2[u]) {
			dis[e.first] = max(dis[e.first], dis[u] + e.second);
		}
	}
	long long res = 0;
	for (int i = 1; i <= scc_cnt; i++) {
		res += (long long)dis[i] * (long long)siz[i];
	}
	printf("%lld\n", res);
	return 0;
}
