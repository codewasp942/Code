#include <bits/stdc++.h>
using namespace std;

mt19937_64 rd(time(NULL));

int main() {
	freopen("bread.in", "w", stdout);
	printf("1000000\n");
	for (int i = 1; i <= 1000000; i++) {
		printf("%lld\n", (long long)pow(rd() % 11 + 2, rd() % 8 + 4));
	}
}
