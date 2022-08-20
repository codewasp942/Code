#include "perm.h"

std::vector<int> construct_permutation(long long k)
{
	std::vector<int> ans;
	for (int i = k - 2; i >= 0; i--) {
		ans.push_back(i);
	}
	return ans;
}
