#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
	r = 0; char c = getchar(); bool f = false;
	while (c < 48 || c > 57) { if (c == 45) f ^= 1; c = getchar(); }
	while (c >= 48 && c <= 57) { r = (r << 1) + (r << 3) + c - 48; c = getchar();}
	if (f) r = -r;
}

const int maxn = 1e5 + 5;

long long m;
long long v[maxn], dp[maxn][2];

int main() {
	read(m);
	for (int i = 1; i <= m; i++) read(v[i]);
	dp[1][0] = 0; dp[1][1] = v[1];
	dp[2][0] = v[1]; dp[2][1] = v[1] + v[2];
	for (int i = 3; i <= m; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 2][1] + v[i], dp[i - 2][0] + v[i - 1] + v[i]);
	}
	printf("%lld\n", max(dp[m][0], dp[m][1]));
	return 0;
}
