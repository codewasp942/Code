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

unsigned X;

void srand1(unsigned S){
	X = S;
}

unsigned nextInteger1(void){
	X = X * 1103515245 + 12345;
	return (X / 65536) % 32768;
}

void generator1(int N, unsigned S, int A[]){
	srand1(S);
	for(int i = 1; i <= N; i++){
		A[i] = nextInteger1() % 2;
	}
}

int t;
char s[200005];
set<long long> st;

int main() {
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	long long tmp; int a[52];
	for (int i = 0; i < (1 << 17); i++) {
		tmp = 0;
		generator1(50, i, a);
		for (int j = 1; j <= 50; j++) {
			if (a[j]) tmp |= (1LL << (j - 1));
		}
		st.insert(tmp);
	}
	read(t);
	while (t--) {
		char ch = getchar();
		int cnt = 0;
		while (ch != '0' && ch != '1') ch = getchar();
		while (ch == '0' || ch == '1') {
			s[++cnt] = ch;
			ch = getchar();
		}
		tmp = 0;
		for (int i = 1; i <= 50; i++) {
			if (s[i] == '1') tmp |= (1LL << (i - 1));
		}
		if (st.count(tmp)) printf("LCG\n");
		else printf("Xorshift\n");
	}
	return 0;
}
