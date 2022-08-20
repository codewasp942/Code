#include <bits/stdc++.h>
using namespace std;

template <class T> 
void read(T &r) {
	r = 0; char ch = getchar(); bool f = false;
	while (ch < 48 || ch > 57) { if (ch == 45) f ^= 1; ch = getchar(); }
	while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
	if (f) r = -r;
}

const int maxn = 5e5 + 5;

int n, m, x, l, r;
int f[maxn];
char a[maxn];
int dep[maxn], p[maxn];
char s[maxn], s2[maxn], s3[maxn];

void kmp() {
	int cnt = 0;
	for (int i = 1; i + x - 1 < l; i++) {
		for (int j = i; j <= i + x - 1; j++) {
			if (s2[j] != s[j - i + 1]) break;
			if (j == i + x - 1) cnt++;
		}
	}
	printf("%d\n", cnt);
}

int main() {
	//freopen("../D_tree/1.in", "r", stdin);
	read(n); read(m); read(x);
	for (int i = 2; i <= n; i++) {
		read(f[i]);
		dep[i] = dep[f[i]] + 1;
		
	}
	scanf("%s", a + 2);
	while (m--) {
		int opt, u, v;
		read(opt); read(u); read(v);
		scanf("%s", s + 1);
		//memset(s, 0, sizeof s);
		//memset(s2, 0, sizeof s2);
		//memset(s3, 0, sizeof s3);
		//printf("*%s\n", s + 1);
		if (opt == 1) {
			l = 1, r = x;
			while (dep[u] > dep[v]) {
				a[u] = s[l++];
				u = f[u];
			}
			while (dep[v] > dep[u]) {
				a[v] = s[r--];
				v = f[v];
			}
			while (u != v) {
				a[u] = s[l++];
				u = f[u];
				a[v] = s[r--];
				v = f[v];
			}
		}
		else {
			l = r = 1;
			while (dep[u] > dep[v]) {
				s2[l++] = a[u];
				u = f[u];
			}
			while (dep[v] > dep[u]) {
				s3[r++] = a[v];
				v = f[v];
			}
			while (u != v) {
				s2[l++] = a[u];
				u = f[u];
				s3[r++] = a[v];
				v = f[v];
			}
			while (--r) s2[l++] = s3[r];
			kmp();
		}
	}
	return 0;
}
