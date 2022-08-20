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

int n;
bitset<33005> np;
vector<int> p;
set<int> s;

int main() {
	read(n);
	for (int i = 2; i <= 33000; i++) {
		if (!np[i]) p.push_back(i);
		for (int j : p) {
			if (j * i > 33000) break;
			np[j * i] = true;
			if (i % j == 0) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		int a; read(a);
		int t = 1;
		for (int j : p) {
			if (j * j > a) break;
			int tt = 0;
			while (a % j == 0) {
				tt ^= j;
				a /= j;
			}
			if (tt != 0) t *= tt;
		}
		if (a != 0) t *= a;
		s.insert(t);
	}
	printf("%d\n", s.size());
	return 0;
}
