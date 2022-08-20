#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

struct card {
	long long w, a, b;
};

int n;
long long ans;
card c[maxn];

bool compare1(card a, card b) {
	return a.a < b.a;
}

bool compare2(card a, card b) {
	return a.b < b.b;
}

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i].w);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &c[i].a, &c[i].b);
	}
	c[n + 1].a = c[n + 1].b = 99999999999999;
	int now = 1;
	bool czl = true;
	while (now <= n) {
		if (czl) sort(c + now, c + n + 1, compare1);
		else sort(c + now, c + n + 1, compare2);
		long long sum = 0, maxsum = -99999999999999;
		if (czl) {
			for (int i = now + 1; i <= n + 1; i++) {
				sum += c[i - 1].w;
				if (c[i].a != c[i - 1].a) {
					if (sum > maxsum) {
						now = i;
						maxsum = sum;
					}
				}
			}
			ans += maxsum;
		}
		else {
			for (int i = now + 1; i <= n + 1; i++) {
				sum += c[i - 1].w;
				if (c[i].b != c[i - 1].b) {
					if (sum > maxsum) {
						now = i;
						maxsum = sum;
					}
				}
			}
		}
		czl ^= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
