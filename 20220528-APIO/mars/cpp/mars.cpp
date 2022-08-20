#include "mars.h"
#include <bits/stdc++.h>
using namespace std;

char mp[102][102];
bool vis[102][102];

int n;

inline void draw(string s, int i, int j) {
	int id = 0, l = 1;
	if (i == j) {
		for (int ii = i; ii <= n * 2; ii += 2) {
			mp[ii][ii] = s[id++];
		}
	}
	else if (i > j) {
		for (int ii = i; ii <= n * 2; ii += 2, l += 2) {
			for (int jj = j; jj <= j + l - 1; jj++) {
				mp[ii][jj] = s[id++];
			}
		}
	}
	else {
		for (int jj = j; jj <= n * 2; jj += 2, l += 2) {
			for (int ii = i; ii <= i + l - 1; ii++) {
				mp[ii][jj] = s[id++];
			}
		}
	}
}

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int ii = 0; ii < 4; ii++) {
		int tx = x + d[ii][0], ty = y + d[ii][1];
		if (tx < 0 || tx > n * 2 || ty < 0 || ty > n * 2 || vis[tx][ty]  == true || mp[tx][ty] == '0') continue;
		dfs(tx, ty);
	}
}

string process(vector <vector<string> > a, int i, int j, int k, int n) {
	//printf("%d: %d %d\n", k, i, j);
	::n = n;
	if (i < 2 * (n - k - 1) - 1 && j < 2 * (n - k - 1) - 1) return a[0][0];
	memset(mp, '0', sizeof mp);
	mp[i][j] = a[0][0][0];
	string res(100, '0');
	int id = 0, l = 1;
	if (k == n - 1) {
		for (int ii = 0; ii < 3; ii++) {
			for (int jj = 0; jj < 3; jj++) {
				if (ii == 0 && jj == 0) continue;
				draw(a[ii][jj], i + ii, j + jj);
			}
		}
		memset(vis, 0, sizeof vis);
		int ans = 0;
		for (int ii = 0; ii <= n * 2; ii++) {
			for (int jj = 0; jj <= n * 2; jj++) {
				//putchar(mp[ii][jj]);
				if (mp[ii][jj] == '1' && vis[ii][jj] == false) {
					ans++;
					dfs(ii, jj);
				}
			}
			//putchar('\n');
		}
		while (ans) {
			res[id++] = '0' + (ans & 1);
			ans >>= 1;
		}
		return res;
	}
	if (i == j) {
		draw(a[2][2], i + 2, j + 2);
		for (int ii = i; ii <= n * 2; ii += 2) {
			res[id++] = mp[ii][ii];
		}
	}
	else if (i > j) {
		for (int ii = 0; ii < 3; ii++) {
			draw(a[2][ii], i + 2, j + ii);
		}
		for (int ii = i; ii <= n * 2; ii += 2, l += 2) {
			for (int jj = j; jj <= j + l - 1; jj++) {
				res[id++] = mp[ii][jj];
			}
		}
	}
	else {
		for (int ii = 0; ii < 3; ii++) {
			draw(a[ii][2], i + ii, j + 2);
		}
		for (int jj = j; jj <= n * 2; jj += 2, l += 2) {
			for (int ii = i; ii <= i + l - 1; ii++) {
				res[id++] = mp[ii][jj];
			}
		}
	}
	//cout << res << endl;
	return res;
}
