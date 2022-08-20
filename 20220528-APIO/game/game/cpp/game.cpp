#include "game.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> graph[maxn];
int n, k;

void init(int n, int k) {
	::n = n, ::k = k;
	for (int i = 0; i < k - 1; i++) {
		graph[i].push_back(i + 1);
	}
}

int dfn[maxn], low[maxn], cnt, ans;
bool vis[maxn];
stack<int> stk;

void tarjan(int u) {
	low[u] = dfn[u] = ++cnt;
	vis[u] = true;
	stk.push(u);
	for (int v : graph[u]) {
		if (!dfn[v]) {
			tarjan(v);
			if (ans == 1) return;
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int v, tot = 0;
		bool flag = false;
		do {
			v = stk.top(); tot++;
			stk.pop(); vis[v] = false;
			if (v < k) flag = true;
			if (flag && tot > 1) {
				ans = 1;
				return;
			}
		} while (u != v);
	}
}


int add_teleporter(int u, int v) {
  	if (u == v) return u < k;
	graph[u].push_back(v);
	ans = cnt = 0;
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(vis, 0, sizeof vis);
	while (!stk.empty()) stk.pop();
	tarjan(0);
	return ans;
}
