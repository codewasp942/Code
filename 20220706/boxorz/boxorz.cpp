#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 5;

int n, m, t;
long long a[maxn][maxn];

int main() {
	freopen("boxorz.in", "r", stdin);
	freopen("boxorz.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	while (t--) {
		char op[2]; int i1, j1, i2, j2;
		scanf("%s %d %d %d %d", op, &i1, &j1, &i2, &j2);
		if (op[0] == 'A') {
			if (i1 > i2) swap(i1, i2);
			if (j1 > j2) swap(j1, j2);
			long long ans = 0;
			for (int i = i1; i <= i2; i++) {
				for (int j = j1; j <= j2; j++) {
					ans += a[i][j];
				}
			}
			printf("%lld\n", ans);
		}
		else {
			long long m; scanf("%lld", &m);
			a[i1][j1] -= m;
			a[i2][j2] += m;
		}
	}
	return 0;
}
