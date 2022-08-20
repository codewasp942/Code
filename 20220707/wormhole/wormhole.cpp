#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

int w, s, p;
int graph[maxn][maxn];
int a[maxn];
set<int> st;

int dis(int u, int v) {
	if (u == v) return 0;
	if (st.count(u)) return 0x3f3f3f3f;
	int w = v;
	for (int i = 1; i <= p; i++) {
		if (u < a[i] && a[i] < w && (a[i] - u) % s == 0) {
			w = a[i];
		}
	}
	while (w != v && st.count(w)) w--;
	if (w == u) return 0x3f3f3f3f;
	return (w - u + s - 1) / s + dis(w, v);
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	while (scanf("%d %d %d", &w, &s, &p) == 3) {
		memset(graph, 0x3f, sizeof graph);
		st.clear();
		memset(a, 0, sizeof a);
		a[0] = 0;
		a[p * 2 + 1] = w;
		for (int i = 1; i <= p; i++) {
			scanf("%d %d", a + i, a + p + i);
			graph[i][p + i] = 0; st.insert(a[i]);
		}
		for (int i = 0; i <= 2 * p + 1; i++) {
			for (int j = 0; j <= 2 * p + 1; j++) {
				int u = i, v = j;
				if (a[i] > a[j]) swap(u, v);
				graph[u][v] = min(dis(a[u], a[v]), graph[u][v]);
			}
		}
		for (int k = 0; k <= 2 * p + 1; k++) {
			for (int i = 0; i <= 2 * p + 1; i++) {
				for (int j = 0; j <= 2 * p + 1; j++) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
		printf("%d\n", graph[0][2 * p + 1]);
	}
	return 0;
}
