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

const int maxn = 2e5 + 5;

struct node {
	int len, sum, id;
};

node ask[maxn];
int a[maxn], n, q;
int book[maxn], ans[maxn];

bool compare(node a, node b) {
	return a.len < b.len;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	char ch = getchar();
	while (ch != '0' && ch != '1') ch = getchar();
	while (ch == '0' || ch == '1') {
		a[++n] = ch - '0'; a[n] += a[n - 1];
		ch = getchar();
	}
	read(q);
	for (int i = 1; i <= q; i++) {
		while (ch != '0' && ch != '1') ch = getchar();
		while (ch == '0' || ch == '1') {
			ask[i].len++;
			ask[i].sum += ch - '0';
			ch = getchar();
		}
		ask[i].id = i;
	}
	sort(ask + 1, ask + q + 1, compare);
	for (int i = 1; i <= q;) {
		memset(book, 0, sizeof book);
		for (int j = ask[i].len; j <= n; j++) book[a[j] - a[j - ask[i].len]]++;
		int j = i;
		while (ask[j].len == ask[i].len) {
			ans[ask[j].id] = book[ask[j].sum];
			j++;
		}
		i = j;
	}
	for (int i = 1; i <= q; i++) write(ans[i]);
	return 0;
}
