#include <bits/stdc++.h>
using namespace std;

const int mod = 998244853, maxn = 1e4 + 5;

pair<int, int> ask[maxn];
int ans[maxn];
int t;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &ask[i].first);
		ask[i].second = i;
	}
	sort(ask + 1, ask + t + 1);
	int sum = 0, tmp = 0;
	for (int i = 2; i <= ask[t].first; i++) {
		sum = ((sum + tmp) % mod) * 2 % mod;
		tmp += 
	}

	return 0;
}
