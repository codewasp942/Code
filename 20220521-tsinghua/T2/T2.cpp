#include <bits/stdc++.h>
using namespace std;

template <class T> 
void read(T &r) {
	r = 0; char ch = getchar(); bool f = false;
	while (ch < 48 || ch > 57) { if (ch == 45) f ^= 1; ch = getchar(); }
	while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
	if (f) r = -r;
}

const int maxn = 1e5 + 5;

int n, m;
int a[maxn], b[maxn], s[maxn];

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]); 
		s[i] = max(a[i], s[i - 1] + a[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(b[i]);
	}
	return 0;
}
