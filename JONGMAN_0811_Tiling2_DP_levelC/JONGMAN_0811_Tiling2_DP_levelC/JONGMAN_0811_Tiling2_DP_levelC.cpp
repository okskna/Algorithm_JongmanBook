#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define M 1000000007

using namespace std;

int cache[101];
int n;

void printCache()
{
	for (int i = 0; i < 101; ++i)
		cout << cache[i] << " ";
	cout << endl;
}

void initCache()
{
	for (int i = 0; i < 101; ++i)
		cache[i] = -1;
}

int Solution(int width)
{
	if (width == 0)
		return 1;

	int& ret = cache[width];

	if (ret != -1)
		return ret;

	ret = 0;
	if(width >= 1)
		ret += Solution(width - 1) % M;
	if(width >= 2)
		ret += Solution(width - 2) % M;

	return ret;
}

int main()
{
	int C, ans = 0;
	cin >> C;
	while (C--)
	{
		initCache();
		cin >> n;

		ans = Solution(n);
		//printCache();
		ans %= M;
		cout << ans << endl;
	}

    return 0;
}

