#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, mx = INT_MIN;
vector<int> graph[maxn], ans;
queue<int> q;
int pre[maxn], nxt[maxn];

int main() {
	freopen("ele.in", "r", stdin);
	freopen("ele.out", "w", stdout);
	scanf("%d", &n);
	pre[0] = n + 1;
	nxt[0] = 1;
	pre[n + 1] = n;
	nxt[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = i - 1; nxt[i] = i + 1;
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int x; scanf("%d", &x);
			graph[i].push_back(x);
		}

		mx = max(mx, (int)graph[i].size());
	}
	for (int i = 1; i <= n; i++) {
		if ((int)graph[i].size() == mx) {
			ans.push_back(i);
			q.push(i);
			pre[nxt[i]] = pre[i];
			nxt[pre[i]] = nxt[i];
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int id = graph[u].size() - 1, now = pre[n + 1];
		while (now > 0) {
			while (id >= 0 && now < graph[u][id]) id--;
			if (id == -1 || now != graph[u][id]) {
				ans.push_back(now);
				nxt[pre[now]] = nxt[now];
				pre[nxt[now]] = pre[now];
				q.push(now);
			}
			now = pre[now];
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d", (int)ans.size());
	for (int i : ans) {
		printf(" %d", i);
	}
	putchar('\n');
	return 0;
}
