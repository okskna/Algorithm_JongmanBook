#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//  n: depth, m: days
int n, m;

//  cache[days][climbed distances] -> maximum distances are days * 2.
double cache[1001][2001];

void printCache()
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout.width(3);
			cout << cache[i][j] << " ";
		}
		cout << endl;
	}
}

void initCache()
{
	for (int i = 0; i < 1001; ++i)
		for (int j = 0; j < 2001; ++j)
			cache[i][j] = -1;
}

double Solution(int day, int distance)
{
	if (day == m)
		return (distance >= n) ? 1 : 0;
	double& ret = cache[day][distance];
	if (ret != -1)
		return ret;

	ret = Solution(day + 1, distance + 1) / 4 + 3 * Solution(day + 1, distance + 2) / 4;
	return ret;
}

int main()
{
	int C;
	long double ans;
	long int divider;

	cin >> C;
	while (C--)
	{
		cin >> n >> m;
		initCache();
		divider = pow(2, m) * 4;

		ans = Solution(0, 0);
		cout << fixed;
		cout.precision(10);
		cout << ans << endl;
	}
    return 0;
}

