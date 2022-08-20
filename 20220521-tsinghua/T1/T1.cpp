#include <bits/stdc++.h>
using namespace std;

template <class T> 
void read(T &r) {
	r = 0; char ch = getchar(); bool f = false;
	while (ch < 48 || ch > 57) { if (ch == 45) f ^= 1; ch = getchar(); }
	while (ch >= 48 && ch <= 57) { r = (r << 1) + (r << 3) + ch - 48; ch = getchar(); }
	if (f) r = -r;
}


int main() {
	
	return 0;
}
