#include <bits/stdc++.h>
using namespace std;

void init() {
}

double solve(string s) {
	int len = s.size();
	while (s[0] == '(' && s[len - 1] == ')') {
		s = string(s.begin() + 1, s.end() - 1);
		len -= 2;
	}
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') cnt++;
		if (s[i] == ')') cnt--;
		if (cnt) continue;



void work() {
	printf("Cal: ");
	string s = ""; char ch = getchar();
	while (ch != '\n') {
		ch = getchar();
		if (ch != ' ' && ch != '\t') s += ch;
	}
	printf("Ans: %lf\n", solve(s));

int main() {
	init();
	work();
	return 0;
}
