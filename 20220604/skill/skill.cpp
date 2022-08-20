#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5, maxm = 5e2 + 5;

long long a[maxn][maxn];
long long dp[maxn][maxn][maxm];
int n, m;

int main() {
	freopen("skill.in", "r", stdin);
	freopen("skill.out", "w", stdout);
	scanf("%d %d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			scanf("%lld", &a[i][j]);
		}
	}

	return 0;
}
