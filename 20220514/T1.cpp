#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
	r = 0; char c = getchar(); bool f = false;
	while (c < 48 || c > 57) { if (c == 45) f ^= 1; c = getchar(); }
	while (c >= 48 && c <= 57) { r = (r << 1) + (r << 3) + c - 48; c = getchar();}
	if (f) r = -r;
}

long long m, n, p;
long long days, now;

int main() {
	read(m); read(n); read(p);
	n++; p = 1;
	days = (m - 2000) * 360 + (n - 1) * 30 + p;
	now = (days - 1) % 7 + 1;
	n += (7 - now) / 2;
	m += (n - 1) / 12;
	n = (n - 1) % 12 + 1;
	printf("%lld %lld %lld\n", m, n, p);
	return 0;
}
