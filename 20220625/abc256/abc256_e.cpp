#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n;
int c[maxn], dfn[maxn], low[maxn], dfn_cnt;
bool is_in[maxn];
stack<int> stk;
vector<int> graph[maxn];
long long ans;

void tarjan(int u) {
	dfn[u] = low[u] = ++dfn_cnt;
	stk.push(u); is_in[u] = true;
	for (int v : graph[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (is_in[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int sz = 0, tmp, min_tmp = INT_MAX;
		do {
			sz++;
			tmp = stk.top(); stk.pop();
			min_tmp = min(min_tmp, c[tmp]);
			is_in[tmp] = false;
			//printf("%d ", tmp);
		} while (tmp != u);
		if (sz > 1) ans += min_tmp;
		//putchar('\n');
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		graph[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			while (!stk.empty()) stk.pop();
			tarjan(i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
