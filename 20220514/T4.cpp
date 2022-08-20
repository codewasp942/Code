#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
	r = 0; char c = getchar(); bool f = false;
	while (c < 48 || c > 57) { if (c == 45) f ^= 1; c = getchar(); }
	while (c >= 48 && c <= 57) { r = (r << 1) + (r << 3) + c - 48; c = getchar();}
	if (f) r = -r;
}

const int maxn = 5e4 + 5, mod = 1e9 + 7;

vector<int> graph[maxn];
int cnt[maxn];
long long val[maxn], tval[maxn];
int n, m, t;
queue<int> que;

inline void topsort() {
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) que.push(i);
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		val[u] += tval[u];
		for (int v : graph[u]) {
			tval[v] = max(tval[v], val[u]);
			cnt[v]--;
			if (cnt[v] == 0) que.push(v);
		}
	}
}

inline long long cal(long long a, long long b) {
	if (a > b) swap(a, b);
	if (a == b) return 0LL;
	long long ta = 0, tb = 0;
	if (a % 3 == 0) ta = (a / 3) * (a - 1) % mod * (a + 1) % mod;
	if ((a + 1) % 3 == 0) ta = ((a + 1) / 3) * (a - 1) % mod * a % mod;
	if ((a - 1) % 3 == 0) ta = ((a - 1) / 3) * a % mod * (a + 1) % mod;
	if (b % 3 == 0) tb = (b / 3) * (b - 1) % mod * (b + 1) % mod;
	if ((b + 1) % 3 == 0) tb = ((b + 1) / 3) * (b - 1) % mod * b % mod;
	if ((b - 1) % 3 == 0) tb = ((b - 1) / 3) * b % mod * (b + 1) % mod;
	return (tb + mod - ta) % mod;
}

int main() {
	read(n); read(m); read(t);
	for (int i = 1; i <= n; i++) read(val[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		graph[v].push_back(u);
		cnt[u]++;
	}
	topsort();
	while (t--) {
		int q, p;
		read(q); read(p);
		printf("%lld %lld %lld\n", val[q] % mod, val[p] % mod, cal(val[q], val[p]));
	}
	return 0;
}

/*
 * a*(a+1) + (a+1)*(a+2)
 *
 */
