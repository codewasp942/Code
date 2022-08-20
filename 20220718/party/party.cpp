#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, m, sq;
int bel[maxn], l[325], r[325], cnt[325];
bool bs[maxn], bbs[325];

int main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	scanf("%d %d", &n, &m);
	sq = sqrt(n);
	memset(l, 0x3f, sizeof l);
	for (int i = 1; i <= n; i++) {
		bel[i] = (i - 1) / sq + 1;
		l[bel[i]] = min(l[bel[i]], i);
		r[bel[i]] = max(r[bel[i]], i);
	}
	while (m--) {
		int op, s, e;
		scanf("%d %d %d", &op, &s, &e);
		if (op == 0) {
			for (int i = bel[s] + 1; i < bel[e]; i++) {
				cnt[i] = r[i] - l[i] + 1 - cnt[i];
				bbs[i] ^= 1;
			}
			if (bel[s] == bel[e]) {
				for (int i = s; i <= e; i++) {
					bs[i] ^= 1;
					if (bs[i] ^ bbs[bel[i]]) cnt[bel[i]]++;
					else cnt[bel[i]]--;
				}
			}
			else {
				for (int i = s; i <= r[bel[s]]; i++) {
					bs[i] ^= 1;
					if (bs[i] ^ bbs[bel[i]]) cnt[bel[i]]++;
					else cnt[bel[i]]--;
				}
				for (int i = l[bel[e]]; i <= e; i++) {
					bs[i] ^= 1;
					if (bs[i] ^ bbs[bel[i]]) cnt[bel[i]]++;
					else cnt[bel[i]]--;
				}
			}
		}
		else {
			int ans = 0;
			for (int i = bel[s] + 1; i < bel[e]; i++) ans += cnt[i];
			if (bel[s] == bel[e]) for (int i = s; i <= e; i++) ans += bs[i] ^ bbs[bel[i]];
			else {
				for (int i = s; i <= r[bel[s]]; i++) ans += bs[i] ^ bbs[bel[i]];
				for (int i = l[bel[e]]; i <= e; i++) ans += bs[i] ^ bbs[bel[i]];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
