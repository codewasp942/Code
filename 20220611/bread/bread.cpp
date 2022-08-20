#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
long long up[70];
int n, ans;

inline long long quick_pow(long long x, int p) {
	long long res = 1;
	while (p) {
		if (p & 1) res *= x;
		p >>= 1;
		if (p) x *= x;
	}
	return res;
}

inline bool check(long long x, int p) {
	long long l = 2, r = up[p], mid, tmp;
	while (l < r) {
		mid = (l + r) >> 1, tmp = quick_pow(mid, p);
		if (tmp < x) l = mid + 1;
		else r = mid;
	}
	return quick_pow(l, p) == x;
}

int main() {
	freopen("bread.in", "r", stdin);
	freopen("bread.out", "w", stdout);
	scanf("%d", &n);
	for (int p : prime) {
		up[p] = (long long)pow(100000000000000LL, 1.0 / p) + 1LL;
	}
	for (int i = 1; i <= n; i++) {
		long long x;
		scanf("%lld", &x);
		if (x < 4) continue;
		for (int p : prime) {
			if (check(x, p)) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
