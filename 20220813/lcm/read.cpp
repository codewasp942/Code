#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("ans", "r", stdin);
	freopen("table", "w", stdout);
	cout << "string ans[] = { \"\", ";
	for (int i = 1; i <= 500; i++) {
		int tmp; string s;
		cin >> tmp >> s;
		cout << "\"" << s << "\", ";
	}
	cout << "\"\" };" << endl;
		
	return 0;
}
