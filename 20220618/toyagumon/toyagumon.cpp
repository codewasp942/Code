#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int n, c, ans;
int h[maxn], w[maxn], pre[maxn], nxt[maxn], cnt[maxn];
bool flag[maxn];

void merge(int x, int y) {
	nxt[pre[x]] = nxt[x];
	pre[nxt[x]] = pre[x];
	w[y] += w[x];
	cnt[y] += cnt[x];
	flag[x] = true;
}

void debug() {
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) printf("%d %d %d %d %d %d\n", i, h[i], w[i], pre[i], nxt[i], cnt[i]);
	}
	putchar('\n');
}

int main() {
	freopen("toyagumon.in", "r", stdin);
	freopen("toyagumon.out", "w", stdout);
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", h + i);
		w[i] = 1; pre[i] = i - 1; nxt[i] = i + 1; cnt[i] = 1;
		if (i > 1) ans += c * abs(h[i] - h[i - 1]);
	}
	h[0] = h[n + 1] = INT_MAX;
	
	//printf("%d\n", ans);

	for (int i = 2; i <= n; i++) {
		if (h[i] == h[pre[i]]) merge(i, pre[i]);
	}

	//debug();

	for (int i = 1; i <= n; i++) {
		if (flag[i]) continue;
		
		//printf("#%d\n", i);
		
		if (nxt[i] == n + 1 && pre[i] == 0) goto end;
		int p = int(pre[i] != 0) + int(nxt[i] != n + 1);
		while (h[i] < h[nxt[i]] && h[i] < h[pre[i]] && w[i] < c * p) {
			if (!p) goto end;
			h[i]++;
			ans += w[i] - c * p;
			w[i] += 2 * cnt[i];
			if (nxt[i] != n + 1 && h[i] == h[nxt[i]]) merge(nxt[i], i);
			if (pre[i] != 0 && h[i] == h[pre[i]]) merge(pre[i], i);
			p = int(pre[i] != 0) + int(nxt[i] != n + 1);
		}
		//debug();
	}
	goto end;
	end:
	printf("%d\n", ans);
	return 0;
}
