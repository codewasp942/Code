#include <bits/stdc++.h>
using namespace std;

#define FILE_IO
namespace io {
	#ifdef FILE_IO
	#define FREAD
	#define FWRITE
	#endif

	#ifdef FREAD
	static char buf[100000], *p1 = buf, *p2 = buf;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
	#endif
	
	#ifdef FWRITE
	static char obuf[100000], *p3 = obuf;
	#define putchar(x) ((p3 - obuf < 100000) ? (*p3++ = (x)) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = (x)))
	struct flasher { ~flasher() { fwrite(obuf, p3 - obuf, 1, stdout); } }flash;
	#endif
	
	//读入失败返回true
	template <class T> bool read(T &r) {
		r = 0; char ch = getchar(); bool f = false;
		while (ch < 48 || ch > 57) { if (ch == EOF) return true; if (ch == 45) f ^= 1; ch = getchar(); }
		while (ch >= 48 && ch <= 57) { r = r * 10 + ch - 48; ch = getchar(); }
		if (f) r = -r; return false;
	}
	template <class T> void write(T w, char end = '\n') {
		char write_buf[55], *pos = write_buf;
		if (w == 0) { putchar('0'); putchar(end); return; }
		if (w < 0) { putchar('-'); w = -w; }
		while (w) {
			*(pos++) = w % 10 + '0';
			w /= 10;
		}
		while (pos != write_buf) putchar(*(--pos));
		putchar(end);
	}
};
using namespace io;

const int maxn = 2e5 + 5;

long long gcd(long long a, long long b) {
	while (a ^= b ^= a ^= b %= a);
	return b;
}

struct flt {
	long long a, b;
	flt() { a = 0, b = 1; }
	flt(long long x) { a = x, b = 1; }
	flt(long long x, long long y) { a = x, b = y; }
	bool operator < (const flt &x) const {
		long long d = gcd(b, x.b);
		return a * (x.b / d) < x.a * (b / d);
	}
	void operator += (flt x) {
		a = a * x.b + x.a * b;
		b *= x.b;
		long long d = gcd(a, b);
		a /= d;
		b /= d;
	}
	void operator *= (flt x) {
		a *= x.a;
		b *= x.b;
		long long d = gcd(a, b);
		a /= d;
		b /= d;
	}
};

flt operator + (flt x, flt y) {
	x += y;
	return x;
}

flt operator * (flt x, flt y) {
	x *= y;
	return x;
}

struct node {
	int a, pre;
	flt b;
};

int n;
node a[maxn];
bool isend[maxn];

int main() {
	freopen("difference.in", "r", stdin);
	freopen("difference.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].a); a[i].pre = i; a[i].b = flt(a[i].a); isend[i] = true;
		while (a[i].b < a[a[i].pre - 1].b) {
			isend[a[i].pre - 1] = false;
			a[i].pre = a[a[i].pre - 1].pre;
			int tot = i - a[i].pre + 1;
			a[i].b = (a[i - 1].b * flt(tot - 1) + a[i].b) * flt(1, tot);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isend[i]) {
			for (int j = a[i].pre; j <= i; j++) {
				write(a[i].b.a, '/');
				write(a[i].b.b, " \n"[j == n]);
			}
		}
	}
	return 0;
}

