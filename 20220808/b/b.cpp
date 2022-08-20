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

int k, ans;
vector<int> pr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
vector<int> tmp;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	while (!read(k)) {
		ans = 1; tmp.clear();
		for (int i : pr) {
			while (k % i == 0) {
				k /= i;
				ans += i - 1;
				tmp.push_back(i - 1);
			}
		}
		write(ans);
		int cnt = 2;
		for (int i : tmp) {
			write(1, ' '); write(cnt);
			for ( ; i > 1; i--, cnt++) {
				write(cnt, ' ');
				write(cnt + 1);
			}
			cnt++;
		}
	}
	return 0;
}
