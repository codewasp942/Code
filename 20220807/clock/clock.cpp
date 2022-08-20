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
        r = 0; static char ch = getchar(); static bool f = false;
        while (ch < 48 || ch > 57) { if (ch == EOF) return true; if (ch == 45) f ^= 1; ch = getchar(); }
        while (ch >= 48 && ch <= 57) { r = r * 10 + ch - 48; ch = getchar(); }
        if (f) r = -r; return false;
    }
    template <class T> void write(T w, char end = '\n') {
        static char write_buf[55], *pos = write_buf;
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

const int maxn = 1e3 + 5;

struct node {
	int l, r;
};

int n, xx, yy, ans = INT_MAX;
node a[maxn * 2];

int cal(int x, int y) {
	if (x == 0) return y;
	else if (y == yy) return yy + x;
	else if (x == xx) return xx + yy * 2 - y;
	else return xx * 2 + yy * 2 - x;
}

bool compare(node a, node b) {
	return a.l != b.l ? a.l < b.l : a.r < b.r;
}

int main() {
	freopen("clock.in", "r", stdin);
	freopen("clock.out", "w", stdout);
	read(n); read(xx); read(yy);
	for (int i = 1; i <= n; i++) {
		int x, y; read(x); read(y);
		char ch = getchar();
		while (ch != 'W' && ch != 'S' && ch != 'E' && ch != 'N') ch = getchar();
		if (ch == 'W') {
			a[i].l = cal(x - min(x, y), y - min(x, y));
			a[i].r = cal(x - min(x, yy - y), y + min(x, yy - y));
		}
		else if (ch == 'S') {
			a[i].l = cal(x + min(xx - x, y), y - min(xx - x, y));
			a[i].r = cal(x - min(x, y), y - min(x, y));
		}
		else if (ch == 'E') {
			a[i].l = cal(x + min(xx - x, yy - y), y + min(xx - x, yy - y));
			a[i].r = cal(x + min(xx - x, y), y - min(xx - x, y));
		}
		else {
			a[i].l = cal(x - min(x, yy - y), y + min(x, yy - y));
			a[i].r = cal(x + min(xx - x, yy - y), y + min(xx - x, yy - y));
		}
		if (a[i].l > a[i].r) a[i].l -= xx * 2 + yy * 2;
	}
	sort(a + 1, a + n + 1, compare);
	for (int i = 1; i <= n; i++) {
		a[i + n] = a[i];
		a[i + n].l += xx * 2 + yy * 2;
		a[i + n].r += xx * 2 + yy * 2;
	}
	for (int ii = 1; ii <= n; ii++) {
		int tmp = 0;
		for (int i = ii; i <= ii + n - 1; i++) {
			int j = i + 1;
			while (a[j].l <= a[i].r && a[j].r >= a[i].r && j <= ii + n - 1) j++;
			if (j == ii + n) { tmp++; break; }
			if (a[j].r <= a[i].r) i = j, tmp++;
			else i = j - 1, tmp++;
		}
		ans = min(ans, tmp);
	}
	write(ans);
	return 0;
}
