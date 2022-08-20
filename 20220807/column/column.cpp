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
using io::read;
using io::write;

const int maxn = 1e3 + 5;

int n;
double r[maxn], dis[maxn], ans;

int main() {
	freopen("column.in", "r", stdin);
	freopen("column.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(r[i]);
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = r[i];
		for (int j = 1; j < i; j++) {
			dis[i] = max(dis[j] + 2.0 * sqrt(r[i] * r[j]), dis[i]);
		}
		ans = max(ans, dis[i] + r[i]);
	}
	printf("%.3lf\n", ans);
	return 0;
}
