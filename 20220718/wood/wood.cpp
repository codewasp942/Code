#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	freopen("wood.in", "r", stdin);
	freopen("wood.out", "w", stdout);
	scanf("%lld", &n);
	long long x = (n + 1) / 2;
	long long res = (2 * x * x * x + 4 * x) / 3 - 2 * x * x;
	if (n % 2 == 0) res += x - 1;
	printf("%lld\n", res);
	return 0;
}
