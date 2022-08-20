#include <bits/stdc++.h>
using namespace std;

int ve, vc, ce, cc;
char s[20];
long long dp[16][26][5];

int main() {
	scanf("%d %d %d %d", &ve, &vc, &ce, &cc);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		if (s[i] != '*') {
			for (int j = 0; j < 26; j++) {
				

	return 0;
}
