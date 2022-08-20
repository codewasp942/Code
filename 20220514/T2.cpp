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

int x, y, n, m, ans = 0x3f3f3f3f;
int a[maxn], b[maxn];

int main() {
	read(x); read(y); read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		a[i] += a[i - 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		a[i] = min(a[i], a[i + 1]);
	}

	//for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);

	for (int i = 1; i <= m; i++) {
		read(b[i]);
		b[i] += b[i - 1];
	}
	for (int i = m - 1; i >= 1; i--) {
		b[i] = min(b[i], b[i + 1]);
	}

	//for (int i = 1; i <= m; i++) printf("%d%c", b[i], " \n"[i == m]);

	int l = max(x - n, y - m), r = (min(x + n, y + m));
	for (int i = max(1, l); i <= r; i++) {
		ans = min(ans, max(a[abs(x - i)], b[abs(y - i)]));
	}
	printf("%d\n", ans);
	return 0;
}
