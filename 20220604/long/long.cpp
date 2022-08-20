#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e2 + 5;

int n, m;
long long s[maxn][maxn], tmp[maxn];
int ans;
vector<int> stk;

bool compare(int a, int b) {
	return tmp[a] >= tmp[b];
}

int main() {
	freopen("long.in", "r", stdin);
	freopen("long.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &s[i][j]);
			s[i][j] += s[i - 1][j];
		}
	}
	for (int i1 = 1; i1 <= n; i1++) {
		for (int i2 = i1; i2 <= n; i2++) {
			//printf("i1: %d i2: %d\n", i1, i2);
			stk.clear();
			stk.push_back(0);
			for (int j = 1; j <= m; j++) {
				tmp[j] = tmp[j - 1] + s[i2][j] - s[i1 - 1][j];
				//printf("j: %d tmp[j]: %lld\n", j, tmp[j]);
				//for (int x : stk) printf("%d ", x);
				auto pos = lower_bound(stk.begin(), stk.end(), j, compare);
				//printf("\npos: %d\n", pos == stk.end() ? 0 : *pos);
				if (pos != stk.end()) ans = max(ans, (j - *pos) * (i2 - i1 + 1));
				if (tmp[stk.back()] > tmp[j]) stk.push_back(j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
