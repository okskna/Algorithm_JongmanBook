#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int triangle[101][101];
int cache[101][101];
int cache2[101][101];
int cnt, maximum;

void printCache()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << cache2[i][j] << " ";
		cout << endl;
	}
}

void initCache()
{
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
		{
			cache[i][j] = -1;
			cache2[i][j] = -1;
		}
}

int tracking(int x, int y)
{
	if (x == N || y == N)
		return 1;
	int& ret  = cache2[y][x];
	if (ret != -1)
		return ret;
	ret = 0;

	if (cache[y + 1][x] >= cache[y + 1][x + 1])
		ret += tracking(x, y + 1);
	if (cache[y + 1][x] <= cache[y + 1][x + 1])
		ret += tracking(x + 1, y + 1);

	return ret;
}

int Solution(int x, int y)
{
	if (x > N || y > N)
		return 0;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	ret = triangle[y][x];
	ret += max(Solution(x, y + 1), Solution(x + 1, y + 1));

	return ret;
}

int main()
{
	int C;
	int ans;
	cin >> C;
	while (C--)
	{
		initCache();
		cin >> N;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= i; ++j)
				cin >> triangle[i][j];

		Solution(1, 1);
		ans = tracking(1, 1);
		//printCache();
		cout << ans << endl;
		//cout << cnt << endl;
	}

    return 0;
}

